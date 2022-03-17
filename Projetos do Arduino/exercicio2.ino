unsigned int a ;
unsigned int b ;
bool erro;

void setup() {
 Serial.begin(9600);
 erro = false;
}

void loop() {
unsigned int w;
a = operador();

b = operador();

if((a >= 0 && a <=9)&&(b>=0 && b <=9)){
  w = soma(a , b );
    Serial.print(a);
    Serial.print(" + ");
    Serial.print(b);
    Serial.print(" = ");
    Serial.println(w);
    Serial.println();
  }

else{
   Serial.println("Erro: Digite de novo!");
  }

}


unsigned int soma(int x , int y){
unsigned int c;
c = x+y;
return c;

}

unsigned int convert(int valor){
  
  switch(valor){
     case 48:
        return 0;
        break;
     case 49:
        return 1;
        break;
     case 50:
        return 2;
        break;
     case 51:
        return 3;
        break;
     case 52:
        return 4;
        break;
     case 53:
        return 5;
        break;
     case 54:
        return 6;
        break;
     case 55:
        return 7;
        break;
     case 56:
        return 8;
        break;
     case 57:
        return 9;
        break;
     default:
        return 'a';
        break;
  }
  }

unsigned int operador(){
  unsigned int e;
  while(!Serial.available()){
   }
  
  e = Serial.read();
 // e = convert(e);
 e = e - 48;

  return e;
  }
  
