#include <LiquidCrystal.h>
#include <DS3231.h>

#define selecionar 6
#define enter 7
#define mudaposition 8
#define mais_um 9
#define menos_um 10

LiquidCrystal lcd(12,11,5,4,3,2);

DS3231  rtc(SDA, SCL);

void setup()
{
  Serial.begin(9600);
  
  lcd.begin(16,2);
  
  rtc.begin();

 pinMode(selecionar, INPUT_PULLUP);
  pinMode(enter,  INPUT_PULLUP);
   pinMode(mudaposition,  INPUT_PULLUP);
    pinMode(mais_um,  INPUT_PULLUP);
     pinMode(menos_um,  INPUT_PULLUP);
     
  
  // The following lines can be uncommented to set the date and time
  //rtc.setDOW(WEDNESDAY);     // Set Day-of-Week to SUNDAY
  //rtc.setTime(02, 33, 30);     // Set the time to 12:00:00 (24hr format)
  //rtc.setDate(06, 02, 2022);   // Set the date to January 1st, 2014
}

void loop()
{
  // Send Day-of-Week
  Serial.print(rtc.getDOWStr());
  Serial.print(" ");
  
  // Send date
  Serial.print(rtc.getDateStr());
  //Serial.print(" -- ");
  lcd.setCursor(0,0);
  lcd.print(rtc.getDateStr());
  
  // Send time
  Serial.println(rtc.getTimeStr());
  lcd.setCursor(0,1);
  lcd.println(rtc.getTimeStr());

  lcd.setCursor(8,1);
  lcd.print("  ");
  lcd.print(rtc.getTemp());
  lcd.setCursor(14,1);
   lcd.print("C");
  delay (1000);
  lcd.clear();

    if(digitalRead(selecionar) == 0)
  {
    bool verifica = true;
    while(verifica == true)
    {  
       if(digitalRead(mais_um) == 0)
       {
        int alarme_hora = 0;
        int alarme = 0;
        
        alarme_hora = 
        
        lcd.print(alarme_hora);
        delay(1000);
        //lcd.clear();
        //verifica = false;
        }   
    } 
   }
}
