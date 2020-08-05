#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>

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

#define u32 volatile unsigned long
u32 *A;
u32 *B;

int main(){
    unsigned long i;
    int fd;
    int j;

    fd = open("/dev/mem", O_RDWR | O_SYNC); 
    A = (u32 *)mmap(NULL, MAP_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd, SCM_INTERFACE_BASE & ~MAP_MASK);
    *(u32 *)((u32)A + 0x30 + CONTROL_PADCONF_SYS_NIRQ_OFFSET) |= (0x00040000);
    close(fd);

    fd = open("/dev/mem", O_RDWR | O_SYNC);
    B = (volatile unsigned long *)mmap(NULL, MAP_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd, GPIO6_BASE & ~MAP_MASK);

    *(u32 *)((u32)B + GPIO6_SYSCONFIG_OFFSET) |= 0x00000004; 

    //*(u32 *)((u32)B + GPIO6_CTRL_OFFSET) &= 0xfffffffe; 

    *(u32 *)((u32)B+GPIO6_CTRL_OFFSET)&= 0xfffffff8;  
    *(u32 *)((u32)B + GPIO6_OE_OFFSET) &= 0xfbffffff; 


    for (j = 0; j < 1000000; j++)
    {
        *(u32 *)((u32)B + (GPIO6_CLEARDATAOUT_OFFSET)) |= 0x04000000;
        //printf("Saida = 0\n");
        //usleep(1000000);


        *(u32 *)((u32)B + (GPIO6_SETDATAOUT_OFFSET)) |= 0x04000000;
        //printf("Saida = 1\n");
        //usleep(1000000);
    }
    close(fd);
    return 0;
}