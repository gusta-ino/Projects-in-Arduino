unsigned int a ;
unsigned int b ;
bool erro;

void setup() {
 Serial.begin(9600);
 erro = false;
}

void loop() {
a = operador();
if((a == 0)||(a ==2)||(a == 4)||(a == 6)||(a == 8)){
  Serial.print(a);
  Serial.println(" é par!");
  }
  
else{
     if((a == 1)||(a ==3)||(a == 5)||(a == 7)||(a == 9)){
          Serial.print(a);
          Serial.println(" é impar!");
          }
            else{
                Serial.println("ERRO...Digite novamente...");
                } 
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
  
