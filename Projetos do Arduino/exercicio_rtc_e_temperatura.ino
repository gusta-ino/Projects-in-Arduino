
#include <LiquidCrystal.h>

LiquidCrystal lcd(12,11,5,4,3,2);

#include <DS3231.h>

DS3231  rtc(SDA, SCL);

unsigned long pausa1 = 0;
unsigned long pausa2 = 0;

void setup()
{
  Serial.begin(9600);
  rtc.begin();

  lcd.begin(16,2);
  // As seguintes linhas podem ser descomentadas para definir a data e hora
     //rtc.setTime(20, 24, 0);     //Defina a hora para está config. 00:00:00 (formato de 24 horas)
     //rtc.setDate(4, 6, 2021);   //Definir a dia,mes e ano
}

void loop()
{ 
   if((millis() - pausa1) == 1000)
      {     
            // Mostra a data
            Serial.print(rtc.getDateStr());
            lcd.setCursor(0,0);
            lcd.print(rtc.getDateStr());
            lcd.print(" - ");
            Serial.print(" - ");
          
            // Mostra a hora
            Serial.println(rtc.getTimeStr()); 
            lcd.print(rtc.getTimeStr()); 
            
          
           pausa1 = millis();
                
      }
        lcd.clear();
      if((millis() - pausa2) == 10000)
                {
                  Serial.print("");
                  Serial.print("Temperatura: ");
                  Serial.print(rtc.getTemp());
                  Serial.println(" C°");
                  lcd.print("");
                  //lcd.print("Temperatura: ");
                  lcd.print(rtc.getTemp());
                  lcd.println(" C°");
                  
                  pausa2 = millis();
                  lcd.clear(); 
                }
               
           
}
