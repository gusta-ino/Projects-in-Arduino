#include <LiquidCrystal.h>
#include <TimerOne.h>

#define selecionar 6
#define enter 7
#define mudaposition 8
#define mais_um 9
#define menos_um 10

int tempo;
int segundo = 0;
int minuto = 0;
int hora = 0;
int despertador = 0;
int settimer = 0;

bool contador = false;
LiquidCrystal lcd(12,11,5,4,3,2);

void setup() {
  Serial.begin(9600);
  
  lcd.begin(16,2);

  pinMode(selecionar, INPUT_PULLUP);
  pinMode(enter,  INPUT_PULLUP);
   pinMode(mudaposition,  INPUT_PULLUP);
    pinMode(mais_um,  INPUT_PULLUP);
     pinMode(menos_um,  INPUT_PULLUP);

Timer1.initialize(1000); // inicializar timer com período de 10 mseg
Timer1.attachInterrupt(TrataTimer); // anexar função a ser executada a cada período

tempo = 1000;

}

void loop() {
  if(contador == true){
  contador = false;
  segundo++;
despertador = hora + despertador;
  
  if(segundo == 60)
  {
    segundo = 0 ;
    minuto++;
    }
    
   if(minuto == 60)
   {
    minuto = 0;
    hora++;
    }

    if(digitalRead(selecionar) == 0)
  {
    bool verifica = true;
    while(verifica == true)
    {  
       if(digitalRead(mais_um) == 0)
       {
        settimer++;
        
        delay(400);
        if(settimer == 24)
        {
          settimer = 0;
          Serial.println(settimer);
          }
        else
        {
        Serial.println(settimer); 
        }
        
        }
     hora = settimer;
     
    if(digitalRead(enter) == 0)
    {
       verifica = false;
       settimer = 0;
      }
    }
   }

    
if(segundo < 10)
    { 
      if(minuto < 10)
      {    
        if(hora < 10)
        {
        Serial.print('0');
        Serial.print(hora);
        Serial.print(':');
        Serial.print('0');
        Serial.print(minuto);
        Serial.print(':');
        Serial.print('0');
        Serial.println(segundo);
        }
        else
        {
        Serial.print(hora);
        Serial.print(':');
        Serial.print('0');
        Serial.print(minuto);
        Serial.print(':');
        Serial.print('0');
        Serial.println(segundo); 
        }
      }
      else
      {
      if(hora < 10)
        {
      Serial.print('0');
      Serial.print(hora);
      Serial.print(':');
      Serial.print(minuto);
      Serial.print(':');
      Serial.print('0');
      Serial.println(segundo); 
      }
      else
      {
      Serial.print(hora);
      Serial.print(':');
      Serial.print(minuto);
      Serial.print(':');
      Serial.print('0');
      Serial.println(segundo);
      }
      }
      }
     
else{
      if(minuto < 10)
      {
      
      if(hora < 10)
        {
        Serial.print('0');
        Serial.print(hora);
        Serial.print(':');
        Serial.print('0');
        Serial.print(minuto);
        Serial.print(':');
        Serial.println(segundo);
        }
        else
        {
        Serial.print(hora);
        Serial.print(':');
        Serial.print('0');
        Serial.print(minuto);
        Serial.print(':');
        Serial.println(segundo); 
         }
      }
 
  

}
  }
}

void TrataTimer() {
tempo--;

if(tempo)
     return; 
else 
    {
     contador = true;
     tempo = 1000;
    }


}
