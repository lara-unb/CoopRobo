// codigo para configuração da comunicação serial

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>

void main()
{
    struct termios cUART1;

    int UART1 = open("/dev/ttyO0", O_RDWR); // opens the file specified to read/write
    if (tcgetattr(UART1, &cUART1))  // gets the parameters associated with the object referred by fd and stores them in the termios structure referenced by termios_p
        printf("Erro tcgetattr");   // responds in case of execution error

    cfmakeraw(&cUART1); // configures operation without parity bit and with 8 data bits
    cfsetspeed(&cUART1, B115200);   // sets both input and output speed to 115200 baud
    cUART1.c_cflag &= ~CSTOPB;  // Set two stop bits, rather than one.

    cUART1.c_cc[VMIN] = 1;  // minimum number of bits expected to be read
    cUART1.c_cc[VTIME] = 1; // maximum wait time for the next bit in tenths of a second
    if (tcsetattr(UART1, TCSANOW, &cUART1)) // sets the parameters associated with the terminal
        printf("Erro tcsetattr");

    close(UART1);   // opens the file specified
}