#ifndef READER_H
#define READER_H

#include <stdio.h>
#include <wiringPi.h>


//bit ports definition
//Input data 
#define BIT1	0	// bit 1 set in GPIO 0 (wiringPi lib) and x RPi pins  
#define BIT2    1	// bit 2 set in GPIO 1 (wiringPi lib) and x RPi pins
#define BIT3	2	// bit 3 set in GPIO 2 (wiringPi lib) and x RPi pins
#define BIT4	3	// bit 4 set in GPIO 3 (wiringPi lib) and x RPi pins
#define BIT5	4	// bit 5 set in GPIO 4 (wiringPi lib) and x RPi pins
#define BIT6	5	// bit 6 set in GPIO 5 (wiringPi lib) and x RPi pins
#define BIT7	6	// bit 7 set in GPIO 6 (wiringPi lib) and x RPi pins
#define BIT8	7	// bit 8 set in GPIO 7 (wiringPi lib) and x RPi pins
#define BIT9	28	// bit 9 set in GPIO 28 (wiringPi lib) and x RPi pins
#define BIT10	29	// bit 10 set in GPIO 29 (wiringPi lib) and x RPi pins
#define BIT11	10	// bit 11 set in GPIO 10 (wiringPi lib) and x RPi pins
#define BIT12	11	// bit 12 set in GPIO 11 (wiringPi lib) and x RPi pins
#define BIT13	12	// bit 13 set in GPIO 12 (wiringPi lib) and x RPi pins
#define BIT14	13	// bit 14 set in GPIO 13 (wiringPi lib) and x RPi pins
#define BIT15	14	// bit 15 set in GPIO 14 (wiringPi lib) and x RPi pins
#define BIT16	15	// bit 16 set in GPIO 15 (wiringPi lib) and x RPi pins

//control bits defined in the protocol
#define ACKPIN  16	// readable pin to start data acquisition
#define END     27	// write bit to indicate end of acquisition
#define RAMP    4096	// data length size for each ramp of the interrogator

//function prototypes

//setup all ports required for data transmision defined in the protocol
void setup_ports(void);

//read data ports 
int read_ports(void);

//save data (val) and increases counter to control the linelength in the file
void save_data(FILE *fp, int val, int *counter);



#endif
