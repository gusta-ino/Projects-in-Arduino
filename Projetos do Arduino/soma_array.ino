char tempo1[8] = {'1' , '9' , ':' , '4' , '9' , ':' , '5' , '6'};//definição da primeira hora a ser somada
char tempo2[8] = {'2' , '3' , ':' , '3' , '6' , ':' , '1' , '8'};//definição da segunda hora a ser somada
char tempo_final[8] = {'0' , '0' , ':' , '0' , '0' , ':' , '0' , '0'};//resultado da soma
//43:26:14

byte hora_final[3];//ARRAY para os resultados
byte s1;
byte s2;
byte m1;
byte m2;
byte h1;
byte h2;

void setup() {
Serial.begin(9600);
}

void loop() 
{
 somar_tempo();// chama a função que está fazendo a soma das horas, minutos e segundos
 
 Serial.print(h2);//caracter n° 2 das horas
 Serial.print(h1);//caracter n° 1 das horas
 Serial.print(':');
 Serial.print(m2);//caracter n° 2 dos minutos
 Serial.print(m1);//caracter n° 1 dos minutos
 Serial.print(':');
 Serial.print(s2);//caracter n° 2 dos segundos
 Serial.print(s1);//caracter n° 1 dos segundos
 while(true){}
}

void somar_tempo()
{
//////////////////////////////////////////////////////////////SEGUNDOS//////////////////////////////////////////////////////////////////////////////

hora_final[2] = (tempo1[6] - 48)* 10 + (tempo1[7] - 48) + (tempo2[6] - 48)* 10 + (tempo2[7] - 48); // faz a soma dos segundos

              if(hora_final[2] >60) //verifica se é maior que um minuto(maior que 60s)
                      {
                       hora_final[2] = hora_final[2] - 60 % hora_final[2]; // subtrai 60 e atribui somente o caracter da direita a variavel
                       hora_final[1] = hora_final[1] + 1; // soma 1 na proxima varivel, que no caso é minutos
                       
                       tempo_final[7] = hora_final[2] % 10;//separa os caracteres, no caso do % pega o caracter que vem depois da virgula
                             s1 = tempo_final[7]; // faz a conversão de int pra string
                       tempo_final[6] = hora_final[2] / 10;// separa os caracteres, no caso da / pega o caracter que vem antes da virgula
                             s2 = tempo_final[6]; // faz a conversão de int pra string
                      }
//Se a condição não for maior que 60 vai executar parte do processo do if, só que do lado de fora

                      tempo_final[7] = hora_final[2] % 10;//separa os caracteres, no caso do % pega o caracter que vem depois da virgula
                            s1 = tempo_final[7];// faz a conversão de int pra string
                      tempo_final[6] = hora_final[2] / 10;// separa os caracteres, no caso da / pega o caracter que vem antes da virgula
                            s2 = tempo_final[6];// faz a conversão de int pra string

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////MINUTOS////////////////////////////////////////////////////////////////////////////////

hora_final[1] = (tempo1[3] - 48)* 10 + (tempo1[4] - 48) + (tempo2[3] - 48)* 10 + (tempo2[4] - 48)+ hora_final[1];

              if(hora_final[1] >60)//verifica se é maior que um minuto(maior que 60s)
              {
               hora_final[1] = hora_final[1] - 60 % hora_final[1];// subtrai 60 e atribui somente o caracter da direita a variavel
               hora_final[0] = hora_final[0] + 1;// soma 1 na proxima varivel, que no caso é horas

               tempo_final[4] = hora_final[1] % 10;//separa os caracteres, no caso do % pega o caracter que vem depois da virgula
               m1 = tempo_final[4];// faz a conversão de int pra string
               tempo_final[3] = hora_final[1] / 10;// separa os caracteres, no caso da / pega o caracter que vem antes da virgula
               m2 = tempo_final[3];// faz a conversão de int pra string
                              
              }
              tempo_final[4] = hora_final[1] % 10;//separa os caracteres, no caso do % pega o caracter que vem depois da virgula
                    m1 = tempo_final[4];// faz a conversão de int pra string
              tempo_final[3] = hora_final[1] / 10;// separa os caracteres, no caso da / pega o caracter que vem antes da virgula
                    m2 = tempo_final[3];// faz a conversão de int pra string
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////HORA///////////////////////////////////////////////////////////////////////////////
hora_final[0] = (tempo1[0] - 48)* 10 + (tempo1[1] - 48) + (tempo2[0] - 48)* 10 + (tempo2[1] - 48)+ hora_final[0];

              if(hora_final[0] >60)//verifica se é maior que um minuto(maior que 60s)
              {
               hora_final[0] = hora_final[0] - 60 % hora_final[0];// subtrai 60 e atribui somente o caracter da direita a variavel

               tempo_final[1] = hora_final[0] % 10;//separa os caracteres, no caso do % pega o caracter que vem depois da virgula
                     h1 = tempo_final[1];// faz a conversão de int pra string
               tempo_final[0] = hora_final[0] / 10;// separa os caracteres, no caso da / pega o caracter que vem antes da virgula
                     h2 = tempo_final[0];// faz a conversão de int pra string
              }
               tempo_final[1] = hora_final[0] % 10;//separa os caracteres, no caso do % pega o caracter que vem depois da virgula
                     h1 = tempo_final[1];// faz a conversão de int pra string
               tempo_final[0] = hora_final[0] / 10;// separa os caracteres, no caso da / pega o caracter que vem antes da virgula
                     h2 = tempo_final[0];// faz a conversão de int pra string
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
}
