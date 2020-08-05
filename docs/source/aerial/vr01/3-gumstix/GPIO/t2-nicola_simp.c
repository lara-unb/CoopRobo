/*
Codigo do Nicola um pouco simplificado, ativa o gpio-186 (pino 17 da placa Tobi)

http://gumstix.8.x6.nabble.com/Direct-register-access-control-of-GPIO-ARM-interface-on-Overo-Water-TOBI-SOLVED-td4965117.html
*/

// LOCAL INCLUDES DEFINITION 
#include <stdio.h>    // for lprint instruction
#include <fcntl.h>    // ok for mmap 
#include <sys/mman.h> // ok for mmap
#include <unistd.h>

// LOCAL PARAMETERS DEFINITION 
#define SCM_INTERFACE_BASE 0x48002000
#define SCM_PADCONFS_BASE 0x48002030
#define CONTROL_PADCONF_SYS_NIRQ (*(volatile unsigned long *)0x480021E0)
#define CONTROL_PADCONF_SYS_NIRQ_OFFSET 0x1B0

#define GPIO6_BASE 0x49058000
#define GPIO6_SYSCONFIG_OFFSET 0x10
#define GPIO6_CLEARDATAOUT_OFFSET 0x90
#define GPIO6_SETDATAOUT_OFFSET 0x94
#define GPIO6_OE_OFFSET 0x34
#define GPIO6_CTRL_OFFSET 0x30

#define MAP_SIZE (volatile unsigned long)4 * 1024
#define MAP_MASK (volatile unsigned long)(MAP_SIZE - 1)

// COMMON VARIABLES DEFINITION 
#define u32 volatile unsigned long
u32 *A;
u32 *B;
 
// LOCAL FUNCTIONS DEFINITION 
int main(void)
{
    unsigned long i;
    int fd;
    
    printf("\n\n");
    printf("   ------------------------------------------\n");
    printf("   |               SPI Sample                |\n");
    printf("   ------------------------------------------\n");
    printf("   |   Direct Register Access GPIO           |\n");
    printf("   ------------------------------------------\n");
    printf("Base address  GPIO6: 0x%04x\n", (GPIO6_BASE)); // OK

    fd = open("/dev/mem", O_RDWR | O_SYNC);
    if (fd < 0)
    {
        printf("Could not open file\n");
        return 0;
    }
    A = (u32 *)mmap(NULL, MAP_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd, SCM_INTERFACE_BASE & ~MAP_MASK);
    if (A == MAP_FAILED)
    {
        printf("Mapping failed    value 0x%04x\n", A);
        close(fd);
        return 0;
    } 
    // %d.\n
    if (A <= 0)
    {
        printf("Mapping failed\n");
        close(fd);
        return 0;
    }
    printf("SCM_SCM_BASE 0x%08x\n", SCM_INTERFACE_BASE);
    printf("SCM_PADCONFS_BASE 0x%08x\n", SCM_INTERFACE_BASE + 0x30);
    printf("SCM_PADCONFS offset 0x%08x\n", CONTROL_PADCONF_SYS_NIRQ_OFFSET);
    printf("Pointer: 0x%08x\n", (u32)A);
    printf("Pointer+offset: 0x%08x\n", (u32)A + 0x30 + CONTROL_PADCONF_SYS_NIRQ_OFFSET);
    printf("Pointer+offset content: 0x%08x\n", *(u32 *)((u32)A + 0x30 + CONTROL_PADCONF_SYS_NIRQ_OFFSET));
    *(u32 *)((u32)A + 0x30 + CONTROL_PADCONF_SYS_NIRQ_OFFSET) |= (0b100 << 16); // imposta mode 4 sul registro configurazione pad 186; abilita uso pin digitale
    close(fd);
    printf("PAD configuration done.\n", MAP_SIZE);
    /************************************************/

    fd = open("/dev/mem", O_RDWR | O_SYNC);
    if (fd < 0)
    {
        printf("Could not open file\n");
        return 0;
    }

    B = (volatile unsigned long *)mmap(NULL, MAP_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd, GPIO6_BASE & ~MAP_MASK); // COM1 0x4806A000
    if (B == MAP_FAILED)
    {
        printf("Mapping failed    value 0x%04x\n", B);
        close(fd);
        return 0;
    } 
    // %d.\n
    if (B <= 0)
    {
        printf("Mapping failed\n");
        close(fd);
        return 0;
    }

    printf("Map_Size: 0x%08x     ", MAP_SIZE);
    printf("Map_Mask: 0x%08x     ", MAP_MASK);
    printf("Map_Mask: Reverse 0x%08x\n", ~MAP_MASK);
    printf("Base address: 0x%08x     ", (GPIO6_BASE & ~MAP_MASK));
    printf("Offset: 0x%08x     ", GPIO6_CTRL_OFFSET);
    printf("Base address+offset: 0x%08x\n", (GPIO6_BASE + GPIO6_CTRL_OFFSET));
    printf("Pointer: 0x%08x\n", (u32)B);

    // gpio_186 handling
    printf("Pointer+offset: 0x%08x     ", (u32)B + (GPIO6_SYSCONFIG_OFFSET));
    printf("Pointer+offset content: 0x%08x     ", *(u32 *)((u32)B + GPIO6_SYSCONFIG_OFFSET));
    *(u32 *)((u32)B + GPIO6_SYSCONFIG_OFFSET) |= 0x00000004; // bit2=1 enable/wake up, free running  clock
    printf("Pointer+offset content: 0x%08x\n", *(u32 *)((u32)B + GPIO6_SYSCONFIG_OFFSET));
    printf("***\n");
    printf("Pointer+offset: 0x%08x     ", (u32)B + (GPIO6_CTRL_OFFSET));
    printf("Pointer+offset content: 0x%08x     ", *(u32 *)((u32)B + GPIO6_CTRL_OFFSET));
    *(u32 *)((u32)B + GPIO6_CTRL_OFFSET) &= 0xfffffffe; // bit0=0 module enabled, clock not gated , clock=interface clock divided by 8
    //*(u32 *)((u32)B+GPIO6_CTRL_OFFSET)&= 0xfffffff8;  // bit0=0,bit1=0,bit2=0 module enabled, clock not gated , clock=interface clock not divided
    printf("Pointer+offset content mod: 0x%08x\n", *(u32 *)((u32)B + GPIO6_CTRL_OFFSET));
    printf("***\n");
    printf("Pointer+offset: 0x%08x     ", (u32)B + (GPIO6_OE_OFFSET));
    printf("Pointer+offset content: 0x%08x     ", *(u32 *)((u32)B + GPIO6_OE_OFFSET));
    *(u32 *)((u32)B + GPIO6_OE_OFFSET) &= 0xfbffffff; // bit26=0, gpio_186 output
    printf("Pointer+offset content mod: 0x%08x\n", *(u32 *)((u32)B + GPIO6_OE_OFFSET));
    printf("***\n");

    // generate a pulse stream on gpio_186 pin output
    for (i = 0; i < 100; i++)
    {
        *(u32 *)((u32)B + (GPIO6_CLEARDATAOUT_OFFSET)) |= 0x04000000;
        printf("Saida = 1\n");
        usleep(1000000);

        *(u32 *)((u32)B + (GPIO6_SETDATAOUT_OFFSET)) |= 0x04000000;
        printf("Saida = 0\n");
        usleep(1000000);
    }
    close(fd);
    printf("pointers to memory are ok\n");
    return 0;
} // eof