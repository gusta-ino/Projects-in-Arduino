#include <TimerOne.h>

#define ledplaca 13

int tempo;

void setup() {
pinMode(ledplaca , OUTPUT);

digitalWrite(ledplaca, HIGH);

Timer1.initialize(10000); // inicializar timer com período de 10 mseg
Timer1.attachInterrupt(TrataTimer); // anexar função a ser executada a cada período

tempo = 50;

}

void loop() {

delay(2000);
digitalWrite(ledplaca, LOW);

}

void TrataTimer() {

tempo--;

if(tempo)

     return; 

else 
    {
     tempo = 50;
     digitalWrite(ledplaca, HIGH);   
    }
  
}
