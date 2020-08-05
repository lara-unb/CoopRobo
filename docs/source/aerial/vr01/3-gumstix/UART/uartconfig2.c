// codigo "uartconfig.c" com algumas simplificações

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>

int main()
{
    struct termios cUART1;

    int UART1 = open("/dev/ttyO0", O_RDWR);
    if (tcgetattr(UART1, &cUART1))
    {
        printf("Erro tcgetattr");
        return -1:
    }

    cfsetspeed(&cUART1, B115200);   // sets both input and output speed to 115200 baud

    cfmakeraw(&cUART1);
    cUART1.c_cflag &= ~CSTOPB; //1 stop bit
    cUART1.c_cflag &= ~PARENB; //No parity
    cUART1.c_cflag &= ~CSIZE;
    cUART1.c_cflag |= CS8; // 8 bits
    cUART1.c_cc[VMIN] = 1;
    cUART1.c_cc[VTIME] = 1;

    //Set the new attributes
    if (tcsetattr(UART1, TCSANOW, &cUART1))
    {
        printf("Erro tcsetattr");
        return -1;
    }
    close(UART1);
    return EXIT_SUCCESS;
}