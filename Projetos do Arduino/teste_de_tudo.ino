#include <DS3231.h>
DS3231  rtc(SDA, SCL);
int condi = 1;
void setup() {
Serial.begin(9600);

rtc.begin();

// As seguintes linhas podem ser descomentadas para definir a data e hora
//rtc.setTime(14, 11, 0);     //Defina a hora para está config. 00:00:00 (formato de 24 horas)
}

void loop() {

   if(condi == 1)
      {
      tempoclock();
      }
  
}

int tempoclock()
{    
    // timerclock = 1000;
     Serial.print("Hora:"); 
     Serial.println(rtc.getTimeStr()); 
     Serial.println("");

}
