unsigned int a ;
unsigned int b ;
unsigned int c ;
unsigned int d ;
bool erro;

void setup() {
 Serial.begin(9600);
 erro = false;
}

void loop() {
a = operador();
a = a - 48;

b = operador();

c = operador();
c = c - 48;

if(a >= 0 && a <=9)
{
    if(c>=0 && c <=9)
    {
        switch(b){
        case '+':
        d = a+c;
        Serial.print(a);
        Serial.print(" + ");
        Serial.print(c);
        Serial.print(" = ");
        Serial.println(d);
        Serial.println();
        break;
        case '-':
        d = a-c;
        Serial.print(a);
        Serial.print(" - ");
        Serial.print(c);
        Serial.print(" = ");
        Serial.println(d);
        Serial.println();
        break;
        case '*':
        d = a*c;
        Serial.print(a);
        Serial.print(" * ");
        Serial.print(c);
        Serial.print(" = ");
        Serial.println(d);
        Serial.println();
        break;
        case '/':
        d = a/c;
        Serial.print(a);
        Serial.print(" / ");
        Serial.print(c);
        Serial.print(" = ");
        Serial.println(d);
        Serial.println();
        break;
        
        default:
        Serial.println("Erro!!! Somente simbolos operacionais...");
        return ; 
  }
}
else{
    Serial.println("Erro!!! Somente números são válidos");
    return ; 
    } 
 }

else{
    Serial.println("Erro!!! Somente números são válidos");
    return;
    } 
  }
  



unsigned int operador(){
  unsigned int e;
  while(!Serial.available()){
   }
  
  e = Serial.read();
  

  return e;
  }
  
