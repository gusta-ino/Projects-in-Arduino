#define abre 2 //acionar o motor para abrir 
#define fecha 3 //acionar o motor para fechar
#define trava 4 //travar ou destravar a tranca
#define finalabre 12 //fim de curso da abertura
#define finalfecha 11//fim de curso do fechamento

#include <SoftwareSerial.h>// inclui a bibliotea para a comunicação bluetooth
SoftwareSerial btSerial(5, 6); // RX, TX

//a variavel verificacao serve para  verificar a condição atual ou seja o processo que está em andamento e com isso permitir que seja 
//executada somente uma unica função por vez
byte verificacao = 0;
byte verif_abre = 0;
byte verif_fecha = 0;

static bool liga = HIGH; // variaveis estaticas para facilitar os comandos seguintes
static bool desliga = LOW; // variaveis estaticas para facilitar os comandos seguintes

void setup() 
{
    pinMode(abre, OUTPUT);
    pinMode(fecha, OUTPUT);
    pinMode(trava, OUTPUT);
    pinMode(finalabre ,INPUT_PULLUP);
    pinMode(finalfecha,INPUT_PULLUP);
    
    //inicialmente todos os dispositivos ficam desligados, ou seja, em LOW
  
    digitalWrite(abre,LOW);
    digitalWrite(fecha,LOW);
    digitalWrite(trava,LOW);
    
    btSerial.begin(9600);
}

void loop() 
{
    bluetooth();
    travas();
  
}

void bluetooth()
{
    static String btComando;//variavel que guarda as informações que vêm do app via bluetooth


    while (btSerial.available()) 
          {
          char comandoChega = btSerial.read();
          btComando += char( comandoChega );
            if (comandoChega == ';') 
            {
//A@b#r$i*r&; é uma rash usada para que o portão não seja controlado por qualquer app
               if (btComando == "A@b#r$i*r&;") 
               {
                if(verificacao == 2)
                {
                return;
                }
                if(verificacao != 2 )
                {
                digitalWrite(abre, liga);
                digitalWrite(trava, liga);
                delay(500);
                digitalWrite(trava, desliga);
                verificacao = 1;
                verif_abre = 1;
                }
               }
//e f$e+C=h!a%r#; é uma rash usada para que o portão não seja controlado por qualquer app
               if (btComando == "f$e+C=h!a%r#;") 
               {
               if(verificacao == 1)
               {
               return; 
               }
               if(verificacao != 1 )
               { 
               digitalWrite(fecha, liga);
               digitalWrite(trava, liga);
               }
               verificacao = 2;
               verif_fecha = 1;
               }
//A função parar finaliza por imediato todos os processos que estão em execução.               
               if(btComando == "parar;")
               {
                if(verificacao == 1)
                {
                 digitalWrite(abre, desliga);
                 digitalWrite(fecha, desliga);
                 digitalWrite(trava, desliga);
                 verificacao = 0;
                }
                  if(verificacao == 2)
                {
                 digitalWrite(abre, desliga);
                 digitalWrite(fecha, desliga);
                 digitalWrite(trava, desliga);
                 verificacao = 0;
                }
               }
               btComando = ""; 
        }
    } 
}
// função responsável pelo fim de curso do motor, irão receber um sinal para processar o fim de curso do motor, e assim  fazendo
//o desligamento ou o acionamento da trava
void travas()
{
    if(verif_abre == 1)
    {
      if(digitalRead(finalabre) == LOW)
      {
         digitalWrite(abre, desliga);
         verificacao = 0;
         verif_abre = 0;
      }
    }
    if(verif_fecha == 1)
    {
            if(digitalRead(finalfecha) == LOW)
            {
            digitalWrite(fecha, desliga);            
            delay(1000);
            digitalWrite(trava, desliga);
            verificacao = 0;
            verif_fecha = 0;
            }   
    }
}
