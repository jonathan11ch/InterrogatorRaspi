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
#define ACKPIN  16
#define END     27

void setup_ports(void);

void read_ports(FILE *fp);


int main (void)
{
  printf ("Raspberry Interrogator Reader\n") ;

 
  if (wiringPiSetup () == -1)
      return 1 ;


   //setup ports
  setup_ports();

  //open storage file
  FILE *fp;
  fp = fopen("/home/pi/jonathan/InterrogatorRaspi/hal/reader/data/data_test.txt", "w");
  
  //enter infinite loop
  for (;;)
  {
    //wait incoming data signal
    while(!digitalRead(ACKPIN));
    read_ports(fp);
    
    //a = digitalRead(BIT1);
    //if(a){
    //printf ("in high\n") ;	//a = digitalRead(BIT1) ;       // On
    //delay (500) ;}               // mS
    //digitalWrite (0, 0) ;       // Off
    //delay (500) ;
  }
  return 0 ;
}

void setup_ports(void){
  //set data pins
  printf("sss");
  pinMode(BIT1, INPUT);
  pullUpDnControl(BIT1, PUD_DOWN);
  printf("pin 1 set");
  pinMode(BIT2, INPUT);
  pullUpDnControl(BIT2, PUD_DOWN);
   printf("pin 2 set");
  pinMode(BIT3, INPUT);
  pullUpDnControl(BIT3, PUD_DOWN);
   printf("pin 3 set");
  pinMode(BIT4, INPUT);
  pullUpDnControl(BIT4, PUD_DOWN);
   printf("pin 4 set");
  pinMode(BIT5, INPUT);
  pullUpDnControl(BIT5, PUD_DOWN);
   printf("pin 5 set");
  pinMode(BIT6, INPUT);
  pullUpDnControl(BIT6, PUD_DOWN);
   printf("pin 6 set");
  pinMode(BIT7, INPUT);
  pullUpDnControl(BIT7, PUD_DOWN);
   printf("pin 7 set");
  pinMode(BIT8, INPUT);
  pullUpDnControl(BIT8, PUD_DOWN);
   printf("pin 8 set");
  pinMode(BIT9, INPUT);
  pullUpDnControl(BIT9, PUD_DOWN);
   printf("pin 9 set");
   pinMode(BIT10, INPUT);
   pullUpDnControl(BIT10, PUD_DOWN);
   printf("pin 10 set");
  pinMode(BIT11, INPUT);
  pullUpDnControl(BIT11, PUD_DOWN);
   printf("pin 11 set");
  pinMode(BIT12, INPUT);
  pullUpDnControl(BIT12, PUD_DOWN);
   printf("pin 12 set");
  pinMode(BIT13, INPUT);
  pullUpDnControl(BIT13, PUD_DOWN);
   printf("pin 13 set");
  pinMode(BIT14, INPUT);
  pullUpDnControl(BIT14, PUD_DOWN);
   printf("pin 14 set");
  pinMode(BIT15, INPUT);
  pullUpDnControl(BIT15, PUD_DOWN);
   printf("pin 15 set");
  pinMode(BIT16, INPUT);
  pullUpDnControl(BIT16, PUD_DOWN);
   printf("pin 16 set");
  //set ack pin
  pinMode(ACKPIN, INPUT);
  pullUpDnControl(ACKPIN, PUD_DOWN);
  //set finsh read pin
  pinMode(END, OUTPUT);

}


void read_ports(FILE *fp){
  digitalWrite(END, 0);
  int val= 0;
  val = (val + digitalRead(BIT1));
  val = val + (digitalRead(BIT2) << 1);
  val = val + (digitalRead(BIT3) << 2);
  val = val + (digitalRead(BIT4) << 3);
  val = val + (digitalRead(BIT5) << 4);
  val = val + (digitalRead(BIT6) << 5);
  val = val + (digitalRead(BIT7) << 6);
  val = val + (digitalRead(BIT8) << 7);
  val = val + (digitalRead(BIT9) << 8);
  val = val + (digitalRead(BIT10) << 9);
  val = val + (digitalRead(BIT11) << 10);
  val = val + (digitalRead(BIT12) << 11);
  val = val + (digitalRead(BIT13) << 12);
  val = val + (digitalRead(BIT14) << 13);
  val = val + (digitalRead(BIT15) << 14);
  val = val + (digitalRead(BIT16) << 15);
  //write data
  fprintf(fp, "%d/n",val );
  digitalWrite(END, 1);
 // printf("val %d\n", val);
}



