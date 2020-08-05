#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>

int main()
{

    int arq = open("/sys/class/gpio/export", O_WRONLY); // Opens the file for writing only
    write(arq, "10", 2); // write "10" on the archive
    close(arq); // closes the file

    arq = open("/sys/class/gpio/gpio10/direction", O_WRONLY);
    write(arq, "out", 3);
    close(arq);

    arq = open("/sys/class/gpio/gpio10/value", O_RDWR); // Opens the file for reading and writing
    
    for (int i = 0; i < 1000; i++) // repeats the command i times
    {
        write(arq, "1", 1); // write "1"
        printf("Saida = 1\n");
        usleep (1000000);
        write(arq, "0", 1); // write "0"
        printf("Saida = 0\n");
        usleep (1000000) ;
        
        printf("i = %d \n", i);       
        
    }
    close(arq);

    return 0;
}