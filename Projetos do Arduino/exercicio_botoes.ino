/*===============================================================================================================================*/
#include <TimerOne.h>//Biblioteca do timer
#define botao1 13//Pino de entrada do botão
#define botao2 12//Pino de entrada do botão
/*===============================================================================================================================*/

int conta_click1 = 1;//Armazena a quantidade de vezes que o botão foi clicado
int conta_click2 = 1;//Armazena a quantidade de vezes que o botão foi clicado

int tempo;//Variavel pra substituir o delay, e não travar o programa
int conta1;//variavel para ser utilizada na condição do botão estar desapertado e mandar a mensagem somente uma vez
int conta2;//variavel para ser utilizada na condição do botão estar desapertado e mandar a mensagem somente uma vez

bool condicao1 = false;//1ª condição para fazer a verificação do "delay" na função do timer
bool condicao2 = true;//2ª condição para fazer a verificação do "delay" na função do timer
bool condicao3 = false;//3ª condição para fazer a verificação do "delay" na função do timer
bool condicao4 = true;//4ª condição para fazer a verificação do "delay" na função do timer

/*===============================================================================================================================*/

void setup() 
{
Serial.begin(9600);
pinMode(botao1 , INPUT_PULLUP);// define o estado do pino 
pinMode(botao2 , INPUT_PULLUP);// define o estado do pino 

Timer1.initialize(10000); // inicializar timer com período de 10 mseg
Timer1.attachInterrupt(timer); // anexar função a ser executada a cada período

tempo = 30;
}

/*===============================================================================================================================*/

void loop() 
{ 
  recebe_botao();//chama a função dos botões

}

/*===============================================================================================================================*/


void recebe_botao()
{   
/*=================================================PRIMEIRO BOTÃO================================================================*/  
     if(digitalRead(botao1) == LOW)// verifica enquanto o botão estiver acionado
     {
        if(condicao1 == true)//verifica se a condição é verdadeira
        {
              Serial.print("Tecla 1 apertada pela ");
              Serial.print(conta_click1);
              Serial.println("ª vez");
              conta_click1++;//soma 1 na variavel
              condicao1 = false;//muda o estado da variavel para falso
              conta1 = 0;// a variavel volta para 0 assim mostrando que a tecla foi desacionada
        }
     }
     if(digitalRead(botao1) == HIGH)// verifica enquanto o botão estiver desacionado
     {
        if(conta1 == 0)//verifica se conta é igula a 0, assim exibindo a mensagem somente uma vez
        {
              if(condicao2 == false)//verifica se a condição é falsa
              {
               Serial.println("Tecla 1 desapertada");  
               condicao2 = true;
               conta1++;//torna a variavel maior que 0 para a exibição ser feita somente uma unica vez, e não repetidamente
              }
           }
     }
/*===============================================================================================================================*/

/*=================================================SEGUNDO BOTÃO================================================================*/  

          if(digitalRead(botao2) == LOW)// verifica enquanto o botão estiver acionado
             {
                if(condicao3 == true)//verifica se a condição é verdadeira
                {
                      Serial.print("Tecla 2 apertada pela ");
                      Serial.print(conta_click2);
                      Serial.println("ª vez");
                      conta_click2++;//soma 1 na variavel
                      condicao3 = false;//muda o estado da variavel para falso
                      conta2 = 0;// a variavel volta para 0 assim mostrando que a tecla foi desacionada
                }
             }
     if(digitalRead(botao2) == HIGH)// verifica enquanto o botão estiver desacionado
                 {
                    if(conta2 == 0)//verifica se conta é igula a 0, assim exibindo a mensagem somente uma vez
                    {
                          if(condicao4 == false)//verifica se a condição é falsa
                          {
                           Serial.println("Tecla 2 desapertada");  
                           condicao4 = true;
                           conta2++;//torna a variavel maior que 0 para a exibição ser feita somente uma unica vez, e não repetidamente
                          }
                    }
                  }  
}

/*===============================================================================================================================*/


/*======================================================FUNÇÃO DO TIMER==========================================================*/

void timer()//Função do timer para fazer o "delay"
{
 tempo--;//Decrementa a variavel

 if(tempo == 0)//verifica se a variavel é igual a 0
 {
  tempo = 30;//reseta o tempo para o valor inicial
  condicao1 = true;
  condicao2 = false;
  condicao3 = true;
  condicao4 = false;
 }
 else
 {
  return;
  }
  
}

/*===============================================================================================================================*/
