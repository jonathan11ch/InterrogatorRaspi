/*
 * blink.c:
 *      blinks the first LED
 *      Gordon Henderson, projects@drogon.net
 */

#include <stdio.h>
#include <wiringPi.h>
//bit ports definition
#define BIT1	0
#define BIT2    1
#define BIT3	2
#define BIT4	3
#define BIT5	4
#define BIT6	5
#define BIT7	6
#define BIT8	7
#define BIT9	8
#define BIT10	9
#define BIT11	10
#define BIT12	11
#define BIT13	12
#define BIT14	13
#define BIT15	14
#define BIT16	15



int main (void)
{
  printf ("Raspberry Pi blink\n") ;
  int a = 0;
  if (wiringPiSetup () == -1)
    return 1 ;

  pinMode (BIT1, INPUT) ;         // aka BCM_GPIO pin 17

  for (;;)
  {
    if(a){
	printf ("in high\n") ;    
	a = digitalRead(BIT1) ;       // On
    	delay (500) ;               // mS
    //digitalWrite (0, 0) ;       // Off
    //delay (500) ;
	}
  }
  return 0 ;
}

