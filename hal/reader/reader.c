/*
 * reader.c:
 *      implements the reception protocol running on a RaspberryPi ModelB2 for the Interrogator data
 *      Jonathan Casas, Camilo Rodriguez, jonathan.casas11ch@gmail.com
 *      Compile as gcc -o reader reader.c -lwiringPi
 */
#include "reader.h" 


int main (void){

  printf ("Raspberry Interrogator Reader\n") ;
  //low level setup
  if (wiringPiSetup () == -1)
      return 1 ;

  //setup ports
  setup_ports();

  //open storage file
  FILE *fp;
  fp = fopen("/home/pi/jonathan/InterrogatorRaspi/hal/reader/data/data_test.txt", "w");
  //dclare variables
  int val;		//store read value
  int PointCounter = 0;	//store data size counter
  

//enter infinite loop
  for (;;)
  {
   
    //wait incoming data signal
    while(!digitalRead(ACKPIN));
    //when incoming data is detected, read ports
    digitalWrite(END, 0);
    val = read_ports();
    //printf("counter from main %d\n ", PointCounter);
    save_data(fp, val, &PointCounter);
    digitalWrite(END, 1);
    
  }
//end infinite loop


  fclose(fp); //close file
  return 0 ;
}



//function to setup physical ports on the RaspberryPi Model B2
void setup_ports(void){
 
 //set data pins with pull-down configuration
  int bit;
  printf("Ports setup\n");
  pinMode(BIT1, INPUT);
  pullUpDnControl(BIT1, PUD_DOWN);
  bit = digitalRead(BIT1);
  printf("pin 1 set %d\n", bit);

  pinMode(BIT2, INPUT);
  pullUpDnControl(BIT2, PUD_DOWN);
  bit = digitalRead(BIT2);
  printf("pin 2 set %d\n", bit);

  pinMode(BIT3, INPUT);
  pullUpDnControl(BIT3, PUD_DOWN);
  bit = digitalRead(BIT3);
  printf("pin 3 set %d\n", bit);

  pinMode(BIT4, INPUT);
  pullUpDnControl(BIT4, PUD_DOWN);
  bit = digitalRead(BIT4);
  printf("pin 4 set %d\n", bit);

  pinMode(BIT5, INPUT);
  pullUpDnControl(BIT5, PUD_DOWN);
  bit = digitalRead(BIT5);
  printf("pin 1 set %d\n", bit);

  pinMode(BIT6, INPUT);
  pullUpDnControl(BIT6, PUD_DOWN);
  bit = digitalRead(BIT6);
  printf("pin 6 set %d\n", bit);

  pinMode(BIT7, INPUT);
  pullUpDnControl(BIT7, PUD_DOWN);
  bit = digitalRead(BIT7);
  printf("pin 7 set %d\n", bit);

  pinMode(BIT8, INPUT);
  pullUpDnControl(BIT8, PUD_DOWN);
  bit = digitalRead(BIT8);
  printf("pin 8 set %d\n", bit);

  pinMode(BIT9, INPUT);
  pullUpDnControl(BIT9, PUD_DOWN);
  bit = digitalRead(BIT9);
  printf("pin 9 set %d\n", bit);

  pinMode(BIT10, INPUT);
  pullUpDnControl(BIT10, PUD_DOWN);
  bit = digitalRead(BIT10);
  printf("pin 10 set %d\n", bit);

  pinMode(BIT11, INPUT);
  pullUpDnControl(BIT11, PUD_DOWN);
  bit = digitalRead(BIT11);
  printf("pin 11 set %d\n", bit);

  pinMode(BIT12, INPUT);
  pullUpDnControl(BIT12, PUD_DOWN);
  bit = digitalRead(BIT12);
  printf("pin 12 set %d\n", bit);

  pinMode(BIT13, INPUT);
  pullUpDnControl(BIT13, PUD_DOWN);
  bit = digitalRead(BIT13);
  printf("pin 13 set %d\n", bit);

  pinMode(BIT14, INPUT);
  pullUpDnControl(BIT14, PUD_DOWN);
  bit = digitalRead(BIT14);
  printf("pin 14 set %d\n", bit);

  pinMode(BIT15, INPUT);
  pullUpDnControl(BIT15, PUD_DOWN);
  bit = digitalRead(BIT15);
  printf("pin 15 set %d\n", bit);

  pinMode(BIT16, INPUT);
  pullUpDnControl(BIT16, PUD_DOWN);
  bit = digitalRead(BIT16);
  printf("pin 16 set %d\n", bit);

  //set ack pin to start the port reading pull-down config
  pinMode(ACKPIN, INPUT);
  pullUpDnControl(ACKPIN, PUD_DOWN);
  //set finsh read pin to indicate when the acquisition was finished
  pinMode(END, OUTPUT);
  int val = read_ports();
  printf("initial values: %d\n", val);

}

//function to read gpio ports
int read_ports(void){

  //initialies the variable
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

  return val;

}

//save acquired data
void save_data(FILE *fp, int val, int *counter){

 if (*counter < RAMP){
  //increases data counter
  ++*counter;
  //write data in txt file
  fprintf(fp, "%d, ", val);
 }
 else{
  //new line
  *counter  = 0;
  //write data  and end of line in txt file
  fprintf(fp, "%d\n", val);
 }

}


