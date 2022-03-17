#include <LiquidCrystal.h>

LiquidCrystal lcd(12,11,5,4,3,2);

void setup() {
lcd.begin(16,2);
lcd.print("bah meu");

//lcd.setCursor(0,1);//0,0 são respectivamente coluna e linha

//lcd.clear();
lcd.setCursor(0,1);

}

void loop() {
 

}
