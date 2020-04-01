
const int Pinbombain =  13;
const int Pinbombaout = 12;
const int pinSensor = 0;
int t = 0;
int valorPotenciometro = 0;  // variable para guardar el valor leido del sensor

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(Pinbombain, OUTPUT);
  pinMode(Pinbombaout, OUTPUT);
  pinMode(pinSensor, INPUT);
  Serial.begin(9600);    
}

// the loop function runs forever
void loop() {
  valorPotenciometro = analogRead(pinSensor);
  t = map(valorPotenciometro, 0, 1023, 1500, 3000  );
  digitalWrite(Pinbombain, HIGH);   // turn the LED on (HIGH is the voltage level) 
  delay(1000);                       // wait for a second
  digitalWrite(Pinbombain, LOW);    // turn the LED off by making the voltage LOW
  delay(200+t);
  
  Serial.print("Valor del Potenciometro = ");
  Serial.print(valorPotenciometro);   
  Serial.print("    t = ");  
  Serial.println(t);   
  delay(100);
  
}
