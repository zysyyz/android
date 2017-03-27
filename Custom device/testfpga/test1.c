#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/ioctl.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>

#define GETVAL		10
#define GETSTART	20
#define GETSTOP		30
#define GETINTVAL	40
#define GETINTCOUNT	50
#define SETSTART	60
#define SETSTOP		70
#define SETINTVAL	80
#define CLRINTCOUNT	90
#define WAITFORINT	100
 
int main(int argc,char *argv[])
{
    int x=6,v;
    int fd=open("/dev/myfpga",O_RDWR);
    int cmd=atoi(argv[1]);
    switch(cmd)
    {
	case 1: // get value
		v=ioctl(fd,10,0);
		printf("val=%d\n",v);
		break;
	case 2: // set start
		ioctl(fd,60,atoi(argv[2]));
		break;
	case 3: // set end
		ioctl(fd,70,atoi(argv[2]));
		break;
	case 4: // set int
		ioctl(fd,80,atoi(argv[2]));
		break;
        case 5:
		while(x--)
    		{
        		ioctl(fd,100,0);
		        printf("Interrupt handler\n");
    		}
		break;
    }
    return 0;
}






