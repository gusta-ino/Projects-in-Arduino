#include <LiquidCrystal.h>

LiquidCrystal lcd(12,11,5,4,3,2);

#define selecionar 6
#define enter 7
#define mudaposition 8
#define mais_um 9
#define menos_um 10

char dados[100];

int i = 0;

bool timeout;

int tempo;

int hora;

void setup() 
{
 timeout = false;
 Serial.begin(9600);
 lcd.begin(16,2);

 pinMode(selecionar, INPUT_PULLUP);
  pinMode(enter,  INPUT_PULLUP);
   pinMode(mudaposition,  INPUT_PULLUP);
    pinMode(mais_um,  INPUT_PULLUP);
     pinMode(menos_um,  INPUT_PULLUP);
     
Timer1.initialize(10000); // inicializar timer com período de 10 mseg
Timer1.attachInterrupt(timer); // anexar função a ser executada a cada período

tempo = 300;

}

void loop()
{
byte ler;
  if(timeout)
    {
      Serial.println("Dados não recebidos");
      timeout = false;
    }
  if(Serial.available())
  { 

     ler = Serial.read();
     Serial.print(ler);
     dados[i++] = ler;
         if(ler == 0x0a)
            {
            i = 0;
             if(dados[0] == '$')
               if(dados[1] == 'G')
                  if(dados[2] == 'P')
                     if(dados[3] == 'G')
                        if(dados[4] == 'G')
                           if(dados[5] == 'A')
                           {
                           acertafuso();
                           Serial.print(hora);
                           Serial.print(':');
                           Serial.print(dados[9]);
                           Serial.print(dados[10]);
                           Serial.print(':');
                           Serial.print(dados[11]);
                
                           Serial.println(dados[12]);
                           Serial.println();
                            lcd.setCursor(0,0);
                            lcd.print('D');
                            lcd.print('D');
                            lcd.print('/');
                            lcd.print('M');
                            lcd.print('M');
                            lcd.print('/');
                            lcd.print('A');
                            lcd.print('A');
                            lcd.print('A');
                            lcd.print('A');
                            lcd.setCursor(0,1);
                            lcd.print(hora);
                            lcd.print(':');
                            lcd.print(dados[9]);
                            lcd.print(dados[10]);
                            lcd.print(':');
                            lcd.print(dados[11]);
                            lcd.print(dados[12]);
                            dados[i] = 0;
                            tempo = 300;
                           }
              }
  }
  if(digitalRead(selecionar) == HIGH)
  {
    bool verifica = true;
    while(verifica == true)
    {
       lcd.print(hora);
       lcd.print(':');
       lcd.print(dados[9]);
       lcd.print(dados[10]);
       lcd.print(':');
       lcd.print(dados[11]);
       lcd.print(dados[12]);
       lcd.clear();
       
       if(digitalRead(mais_um) == HIGH)
       {
        int alarme_hora = 0;
        alarme_hora == hora;
        alarme_hora++;
        lcd.print(alarme_hora);
        lcd.print(':');
        lcd.print(dados[9]);
        lcd.print(dados[10]);
        lcd.print(':');
        lcd.print(dados[11]);
        lcd.print(dados[12]);
        }
      
    } 
   
   }
}

int acertafuso()
{     
      hora = (dados[7] - 48)*10 + ((dados[8]) - 48) - 3;
      
      if(hora < 0 )
      hora = 24 + hora; 
}    

void timer()
{
 tempo--;
 
 if(tempo != 0)
    return;
  
 else
    {
     tempo = 300;
     timeout = true;
     }
   
}
