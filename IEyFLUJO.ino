// IE                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          
const int inhalacion =  13;
const int Pinbombaout = 12;
int t1          = 0;
int valorPotenciometro = 0; 
const int pinSensor = 0;

// comparador de flujo
volatile int NbTopsFan; 
int Calc;
int suma;
int valorPotenciometro1;
int t;
int valvula  = 3;
int hallsensor = 2; 
const int potenciometro = 1;
void rpm ()
{
NbTopsFan++; 
}





void setup() {
  pinMode(inhalacion, OUTPUT);
  pinMode(Pinbombaout, OUTPUT);
  pinMode(pinSensor, INPUT);
  Serial.begin(9600);    



  pinMode(hallsensor, INPUT);
  pinMode(valvula, OUTPUT); 
  Serial.begin(9600); 
  attachInterrupt(0, rpm, RISING); 
  pinMode(potenciometro, INPUT);
}

void loop() {
   
  NbTopsFan = 0;
  suma = 0;
  valorPotenciometro = analogRead(pinSensor);
  t1= map(valorPotenciometro, 0, 1023, 1500, 3000  );

  
  digitalWrite(inhalacion, LOW);   // turn the LED on (HIGH is the voltage level) 
  
  for(int i = 0; i <=70; i ++ ){
       sei(); 
       delay (10); 
       cli(); 
       Calc = (NbTopsFan * 5.5);
       valorPotenciometro1 = analogRead(potenciometro);
       t= map(valorPotenciometro1, 0, 1023, 8, 15 );
       suma= suma+Calc;
       if (suma <= t )
            {
            digitalWrite(inhalacion, LOW);

            }
         else{
            digitalWrite(valvula, HIGH ); 
            suma=0;
              }
  }

  digitalWrite(inhalacion, HIGH);    // turn the LED off by making the voltage LOW
  delay(200+t1);
}
