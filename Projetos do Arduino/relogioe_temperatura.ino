/*
  DS3231: Real-Time Clock. Simple example
  Read more: www.jarzebski.pl/arduino/komponenty/zegar-czasu-rzeczywistego-rtc-ds3231.html
  GIT: https://github.com/jarzebski/Arduino-DS3231
  Web: http://www.jarzebski.pl
  (c) 2014 by Korneliusz Jarzebski
*/

#include <Wire.h>
#include <DS3231.h>
DS3231 clock;
RTCDateTime dt;

void setup()
{
  Serial.begin(9600);

  // Inicializa o relogio 
  Serial.println("Inicializção do relogio");;
  clock.begin();

  // Definir o tempo de compilação do esboço
  clock.setDateTime(__DATE__, __TIME__);
}

void loop()
{
  dt = clock.getDateTime();

  Serial.print("Data e hora: ");
  Serial.print(dt.day);   Serial.print("/");
  Serial.print(dt.month);  Serial.print("/");
  Serial.print(dt.year);    Serial.print(" ");
  Serial.print(dt.hour);   Serial.print(":");
  Serial.print(dt.minute); Serial.print(":");
  Serial.print(dt.second); Serial.println("");

  if(dt.second == 0)
    {
        clock.forceConversion();
        Serial.print("Temperatura: ");
        Serial.print(clock.readTemperature());
        Serial.print("° ");
        Serial.println(" ");
    }
  

  delay(1000);
}
