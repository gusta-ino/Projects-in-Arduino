#include <TimerOne.h>

#define led  2
#define contador 10

bool estado = HIGH; 

Timer1.initialize(10000);
Timer1.attachInterrupt(conta tempo);

void setup() {
 pinMode(led , OUTPUT);
 digitalWrite(led , estado);
}

void loop() {
  

}

void contatempo(){
  
  
}
