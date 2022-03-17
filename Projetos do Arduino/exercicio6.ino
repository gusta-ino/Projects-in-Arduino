

void setup() 
{
 Serial.begin(9600);

}

void loop() 
{
int a = 5;
int b = 6;
int c = 4;
int d;

d = somasub(a , b , c);

Serial.print(d);
while(true){}
}

int somasub(int x , int y , int z)
{
  int r; 
 r = x + y - z;
 return r ;
}
