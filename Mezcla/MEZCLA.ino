
const int Pinbombain =  13;
const int Pinbombaout = 12;
int t          = 0;
int valorPotenciometro = 0;  // variable para guardar el valor leido del sensor
  const int pinSensor = 0;
// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(Pinbombain, OUTPUT);
  pinMode(Pinbombaout, OUTPUT);
   pinMode(pinSensor, INPUT);
   Serial.begin(9600);    
}

// the loop function runs over and over again forever
void loop() {
  valorPotenciometro = analogRead(pinSensor);
  t= map(valorPotenciometro, 0, 1023, 600, 1000  );
  digitalWrite(Pinbombain, HIGH);   // turn the LED on (HIGH is the voltage level)
  
  delay(t);                       // wait for a second
  digitalWrite(Pinbombain, LOW);    // turn the LED off by making the voltage LOW
  delay(1000-t);
                    // wait for a second

                   Serial.print("Valor del Potenciometro = ");
                   Serial.print(valorPotenciometro);   
                   Serial.print("    t = ");  

                   Serial.println(t);   
 
                   delay(100);
                    
  
}
