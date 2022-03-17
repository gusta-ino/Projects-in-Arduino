/*3.  Função para MULTIPLICAR e DIVIDIR dois operadores. Retorna o valor da multiplicação e da divisão.
Resultado1 = a * b
Resultado2 = a / b
*/
  int a = 10;
  int b = 2;
  int c;
  int d;

void setup()
{
  Serial.begin(9600);

}

void loop()
{ 

opera(a ,b);

Serial.print(c);
Serial.println("");
Serial.println(d);
while(true){}
 }

void opera(int m1 , int m2)
{ 
  
 c = m1*m2;
 d = m1/m2;

} 
