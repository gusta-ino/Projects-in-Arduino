int a ;
int b ;
bool erro;

void setup() {
 Serial.begin(9600);
 erro = false;
}

void loop() {
int w;
while(true){
 
if(erro == true){
  erro = false;
  Serial.println("Erro: Digite de novo!");
  }
 
while(!Serial.available()){
   }
    
a = Serial.read();

a = convert(a);
  if( a == 'a'){
         erro = true;
         return ;
        }

while(!Serial.available()){
   }
   
b = Serial.read();

b = convert(b);
        if( b == 'a'){
         erro = true;
         return ;  
        }

        if(erro == true){
          erro = true;
          return;
          }

w = soma(a , b );
    Serial.print(a);
    Serial.print(" + ");
    Serial.print(b);
    Serial.print(" = ");
    Serial.println(w);
    Serial.println();
}
}

int soma(int x , int y){
int c;
c = x+y;
return c;

}

int convert(int valor){
  
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

  
