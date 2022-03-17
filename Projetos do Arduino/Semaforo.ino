#define abre 2 //acionar o motor para abrir 
#define fecha 3 //acionar o motor para fechar
#define trava 4 //travar ou destravar a tranca
#define finalabre 12
#define finalfecha 11
#include <SoftwareSerial.h>// inclui a bibliotea para a comunicação bluetooth
SoftwareSerial btSerial(5, 6); // RX, TX

bool a = true;
bool f = true;

void setup() {
  pinMode(abre, OUTPUT);
  pinMode(fecha, OUTPUT);
  pinMode(trava, OUTPUT);
  pinMode(finalabre ,INPUT_PULLUP);
  pinMode(finalfecha,INPUT_PULLUP);

  digitalWrite(abre,LOW);
  digitalWrite(fecha,LOW);
  digitalWrite(trava,LOW);
  
  btSerial.begin(9600);
  Serial.begin(9600);
}

void loop() {
static String btComando;
static bool liga = HIGH; // variaveis estaticas para facilitar os comandos seguintes
static bool desliga = LOW; // variaveis estaticas para facilitar os comandos seguintes

while (btSerial.available()) {
      char comandoChega = btSerial.read();
      btComando += char( comandoChega );
        if (comandoChega == ';') 
        {
/*=======A@b#r$i*r&; e f$e+C=h!a%r#; são codigos para que o portão não seja controlado por qualquer app=======*/
            if (btComando == "A@b#r$i*r&;") 
               {
                while(a == true){
                digitalWrite(trava, liga);
                delay(1000);
                digitalWrite(abre, liga);
                delay(1000);
                digitalWrite(trava, desliga);   
                }        
               }

               else if (btComando == "f$e+C=h!a%r#;")
               {
               
               digitalWrite(fecha, HIGH);
               digitalWrite(trava, HIGH);
               }
               btComando = ""; 
        }
    }
//resposavel pelo final de curso do motor, irão receber um sinal para processar 
//o fim de curso do motor, e assim  fazendo o desligamento
if(digitalRead(finalabre) == LOW){
            digitalWrite(abre, desliga);
            a = false;
            }
if(digitalRead(finalfecha) == LOW){
           digitalWrite(fecha, desliga);            
           delay(1000);
           digitalWrite(trava, desliga);

        }   
 
  }
  
