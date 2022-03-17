#include <TimerOne.h>

#define ledplaca 13
#define led 2

int tempo;
int timerled;

bool alternar ; 

void setup() {
  Serial.begin(9600);
pinMode(ledplaca , OUTPUT);
pinMode(led , OUTPUT);
digitalWrite(ledplaca, HIGH);

Timer1.initialize(10000); // inicializar timer com período de 10 mseg
Timer1.attachInterrupt(TrataTimer); // anexar função a ser executada a cada período

tempo = 1000;

}

void loop() {
  digitalWrite(led, HIGH);
  
  timerled = 100;
  
  while(timerled != 0)
    {
    Serial.println(timerled); 
    }        
  digitalWrite(led, LOW);
  timerled = 300;
  while(timerled != 0)
    {
    Serial.println(timerled); 
    }  

  Serial.println("loop"); 
}

void TrataTimer() {
tempo--;

if(timerled)
{
   timerled--;
}

if(tempo)
     return; 
else 
    {  
     tempo = 1000;
     alternar = !alternar;
     digitalWrite(ledplaca,  alternar);
    }


}
