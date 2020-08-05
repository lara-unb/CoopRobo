#include <termios.h> //POSIX terminal control definitions
#include <sys/types.h> 
#include <sys/stat.h>
#include <fcntl.h> // File control definitions
#include <stdio.h> // Standard input/output definitions
#include <errno.h> // Error number definitions
#include <unistd.h> // UNIX standard function definitions
#include <stdlib.h> // C standard library
#include <string.h> // String function definitions

int open_port(void){
    int UART1;
    UART1 = open("/dev/ttyO0", O_RDWR);

    if (UART1 == -1){
        fprintf(stderr, "open_port: Unable to open /dev/ttyO0 %s \n",strerror(errno));
        exit(EXIT_FAILURE);
    }
    return UART1;
}

int main(void){
    int UART1 = 0;
    struct termios cUART1;
    int rc; //Return value

    UART1 = open_port(); //Open tty device for read and write

    //Get de current options for the port
    if((rc = tcgetattr(UART1, &cUART1)) < 0){
        fprintf(stderr, "Failed to get attr: %d, %s\n", UART1, strerror(errno));
        exit(EXIT_FAILURE);
    }    

    //Set the baud rates to 115200
    cfsetispeed(&cUART1, B115200);

    //Set the baud rates to 115200
    cfsetospeed(&cUART1, B115200);

    cfmakeraw(&cUART1);
    cUART1.c_cflag &= ~CSTOPB; //1 stop bit
    cUART1.c_cflag &= ~PARENB; //No parity
    cUART1.c_cflag &= ~CSIZE; 
    cUART1.c_cflag |= CS8; // 8 bits
    cUART1.c_cc[VMIN] = 1;
    cUART1.c_cc[VTIME] = 1;

    //Set the new attributes
    if((rc = tcsetattr(UART1, TCSANOW, &cUART1)) < 0){
        fprintf(stderr, "Failed to set attr: %d, %s\n", UART1,strerror(errno));
        exit(EXIT_FAILURE);
    }
    
    close(UART1);
    return EXIT_SUCCESS;
}