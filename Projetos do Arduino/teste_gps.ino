#include <LiquidCrystal.h>

#include <TimerOne.h>

LiquidCrystal lcd(2, 4, 9, 10, 11, 12);

char leitura_GPS;
char dados_GPS[100];
char ddmmaaaa[10];
byte horaf[2];
char hhmm[5];
char temperatura[6];
char umidade[3];
char temp_e_umi[9];
 

int i = 0;

bool timeout;
bool verifica_segundo;
bool verifica_temperatura;


int tempo;
int segundo;
int mostra_temp;

int hora;

void setup()
{
  timeout = false;
  verifica_segundo = false;
  verifica_temperatura = false;
  
  Serial.begin(9600);
  lcd.begin(16, 2);

  Timer1.initialize(10000); // inicializar timer com período de 10 mseg
  Timer1.attachInterrupt(timer); // anexar função a ser executada a cada período

  tempo = 500;

  segundo = 100;

  mostra_temp = 1000;

}

void loop()
{

  if (timeout)
      {
        //lcd.print("ERRO");
        timeout = false;
      }
  if (verifica_segundo == true)
     {
     GPS();
     tela();
     }
  
}

/////////////////Acerta o fuso horario///////////////////

int acertafuso()
{
  hora = (dados_GPS[7] - 48) * 10 + ((dados_GPS[8]) - 48) - 3;
  
  if (hora < 0 )
  {
    hora = 24 + hora;
    }
    horaf[0] = hora % 10;
    horaf[1] = hora / 10;
  
}

/////////////////////////////////////////////////////////

/////////////////////////Função do Timer////////////////////////////

void timer()
{
  tempo--;

  if (tempo != 0)
      {}
  else
      {
        tempo = 500;
        timeout = true;
      }

  segundo--;

  if (segundo != 0 )
    {}
  else
      {
        segundo = 100;
        verifica_segundo = true;
      }
  if(mostra_temp != 0)
    return;

  else
      {      
      mostra_temp = 1000;
      verifica_temperatura = true;
      }
}
///////////////////////////////////////////////////////////////////////////////

//////////////////////////////Função do GPS////////////////////////////////////

void GPS()
{
  if (Serial.available())
  {
 
    leitura_GPS = Serial.read();
    dados_GPS[i++] = leitura_GPS;
//Faz a leitura da data e separa nas variaveis 
    if (leitura_GPS == 0x0a)
    {
      i = 0;
      if (dados_GPS[0] == '$')
        if (dados_GPS[1] == 'G')
          if (dados_GPS[2] == 'P')
            if (dados_GPS[3] == 'R')
              if (dados_GPS[4] == 'M')
                if (dados_GPS[5] == 'C')
                {
                 ddmmaaaa[0] = dados_GPS[53];
                  ddmmaaaa[1] = dados_GPS[54];
                  ddmmaaaa[2] = '/';
                  ddmmaaaa[3] = dados_GPS[55];
                  ddmmaaaa[4] = dados_GPS[56];
                  ddmmaaaa[5] = '/';
                  ddmmaaaa[6] = '2';
                  ddmmaaaa[7] = '0';
                  ddmmaaaa[8] = dados_GPS[57];
                  ddmmaaaa[9] = dados_GPS[58];
                  dados_GPS[i] = 0;
                  tempo = 300;
                  segundo = 100;
                }

////////////////////////////////////////////////////////////////////////////////////

//Faz a leitura da hora e guarda nas variaveis

      if (dados_GPS[0] == '$')
        if (dados_GPS[1] == 'G')
          if (dados_GPS[2] == 'P')
            if (dados_GPS[3] == 'G')
              if (dados_GPS[4] == 'G')
                if (dados_GPS[5] == 'A')
                    { 
                      acertafuso(); 
                      hhmm[2] = ':';
                      hhmm[3] = dados_GPS[9];
                      hhmm[4] = dados_GPS[10];
                    }
    }
///////////////////////////////////////////////////////////////////////////////
  }
}
///////////////////////////////////////////////////////////////////////////////
void DHT11()
{ 
  temp_e_umi[0] = 'T';
  temp_e_umi[1] = 'T';
  temp_e_umi[2] = ',';
  temp_e_umi[3] = 't';
  temp_e_umi[4] = 11110111;// Pelo que eu testei 1111 0111 é correspondente ao caracter °
  temp_e_umi[5] = 'C';
  temp_e_umi[6] = 'U';
  temp_e_umi[7] = 'u';
  temp_e_umi[8] = '%';
  
  //Temperatura e umidade
  temperatura[0] = temp_e_umi[0];
  temperatura[1] = temp_e_umi[1];
  temperatura[2] = temp_e_umi[2];
  temperatura[3] = temp_e_umi[3];
  temperatura[4] = temp_e_umi[4];
  temperatura[5] = temp_e_umi[5];
  umidade[0] = temp_e_umi[6];
  umidade[1] = temp_e_umi[7];
  umidade[2] = temp_e_umi[8];
}
/////////////////////////////////////////////////////////////////////////////////////

//////////////Mostra as informações no LCD/////////////////////

void tela()
{
//chama as funções para poder obter as informções
   DHT11();

////////////////////////////////////////////////

//Exibe o dia, mes e ano formatado em dd/mm/aaaa
if(verifica_segundo = true)
{ 
   GPS();
   lcd.setCursor(0, 0);
   lcd.print(ddmmaaaa[0]);
   lcd.print(ddmmaaaa[1]);
   lcd.print(ddmmaaaa[2]);
   lcd.print(ddmmaaaa[3]);
   lcd.print(ddmmaaaa[4]);
   lcd.print(ddmmaaaa[5]);
   lcd.print(ddmmaaaa[6]);
   lcd.print(ddmmaaaa[7]);
   lcd.print(ddmmaaaa[8]);
   lcd.print(ddmmaaaa[9]);
/////////////////////////////////////////////////

//Exibe hora e minuto da seguinte formatação hh:mm

   lcd.setCursor(11, 0);
   lcd.print(horaf[0]);
   lcd.print(horaf[1]);
   lcd.print(hhmm[2]);
   lcd.print(hhmm[3]);
   lcd.print(hhmm[4]);
}
///////////////////////////////////////////////////

//Exibe na segunda linha a temperatura(TT,t°C) e umidade(Uu%) 
   lcd.setCursor(0, 1);
   lcd.print(temperatura[0]);
   lcd.print(temperatura[1]);
   lcd.print(temperatura[2]);
   lcd.print(temperatura[3]);
   lcd.print(temperatura[4]);
   lcd.print(temperatura[5]);
   lcd.setCursor(8, 1);
   lcd.print(umidade[0]);
   lcd.print(umidade[1]);
   lcd.print(umidade[2]);
///////////////////////////////////////////////////////////////
}
