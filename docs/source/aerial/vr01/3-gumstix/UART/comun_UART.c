#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>

int configUART1()
{
    struct termios cUART1;
    int UART1 = open("/dev/ttyO0", O_RDWR);

    if(tcgetattr(UART1,&cUART1))
        printf("Erro tcgetattr");
    cfmakeraw(&cUART1);
    cfsetspeed(&cUART1,B115200); 
    cUART1.c_cflag &= ~CSTOPB;

    cUART1.c_cc[VMIN] = 1;
    cUART1.c_cc[VTIME] = 1;
    if (tcsetattr(UART1, TCSANOW, &cUART1))
        printf("Erro tcsetattr");
        
    return UART1;
}

int main()
{

    int UART1 = configUART1(); // call the UART configuration function
    char dis[2], out[100], string[100];

    printf("Que dispositivo eu sou?");
    scanf("%c", &dis[0]);
    dis[1] = 0;
    string[0] = 0;
    strcat(string, "Ola! Essa e uma mensagem do dispositivo ");
    strcat(string, dis);

    // testa UART
    write(UART1, string, strlen(string));
    sleep(1);
    read(UART1, out, 100);
    printf("Mensagem lida pelo dispositivo %s: %s\n", dis, out);
    close(UART1);
    return 0;
}