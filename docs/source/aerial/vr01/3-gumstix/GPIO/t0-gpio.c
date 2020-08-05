// controla o pino 18 da placa Tobi

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>

int main()
{
    int opcao;
    int arq;
    
    arq = open("/sys/class/gpio/export", O_WRONLY);
    write(arq, "10", 2);
    close(arq);

    arq = open("/sys/class/gpio/gpio10/direction", O_WRONLY);
    write(arq, "out", 3);
    close(arq);

    arq = open("/sys/class/gpio/gpio10/value", O_RDWR);
    system("clear");

    while(opcao !=2 )
    {
        printf("0->bit 0       1->bit 1       2->SAIR\n");
        scanf("%i", &opcao);

        switch (opcao)
        {
        case 0:
        {
            write(arq, "0", 1);
            printf("Saida = 0 \n");
            break;
        }

        case 1:
        {
            write(arq, "1", 1);
            printf("Saida = 1 \n");
            break;
        }

        case 2:
            break;

        default:
            printf("Valor invalido!\n");
            break;
        }
    }

    close(arq);
    return 0;
}