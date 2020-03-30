volatile int NbTopsFan; 
int Calc;
int suma;
int rele = 4;
int parametro;
int valvula  = 3;
int hallsensor = 2; 
void rpm () 
{
NbTopsFan++; 
}
void setup() //
{ 
pinMode(hallsensor, INPUT);
pinMode(rele, OUTPUT);
pinMode(valvula, OUTPUT); 
Serial.begin(9600); 
attachInterrupt(0, rpm, RISING); 
}
void loop ()
{
  digitalWrite(rele, HIGH);
NbTopsFan = 0;

sei(); 
delay (10); 
cli(); 
Calc = (NbTopsFan * 5.5);

suma= suma+Calc;
if (suma <= 6){
  digitalWrite(valvula, LOW);


   
}else{
  digitalWrite(valvula, HIGH );
  suma=0;
}
Serial.print (suma, DEC); 
Serial.print (" L/min \r\n"); 

}
