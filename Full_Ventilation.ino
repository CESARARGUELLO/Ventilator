#include <pt.h>
  //define pin 12 to manage expiration pump 
#define E_VALVE_PIN 12
  //define pin 13 to manage inspiration pump
#define I_VALVE_PIN 13
  //define pin 0 to set IE relationship
#define IE_INPUT_PIN 0
  //define pin 1 to set the breathing frequency
#define BF_INPUT_PIN 1
  //defines the minimun breathing frequency
#define bfMin 12
  //defines the maximun breathing frequency
#define bfMax  25
  //defines the minimun IE value (1:1), set to 10 to be set the precision to 0.1   
#define ieMin 10
  //defines the maximun i:E value (1:4)
#define ieMax 40
  //defines the breathing hold time (in miliseconds)
#define bHTime 20

static struct pt ptIE;

static int protothreadIEBreathing(struct pt *pt )
{
  static unsigned long lastTimeBreath = 0;
  static int bf_input = 0;  //holds the reading from the potentiometer
  static int bf = 0;        //holds the maps from the sensor to the maxs and mins values
  static int ie_input = 0;  //holds the reading from the potentiometer
  static int ie = 0;        //holds the maps from the sensor to the maxs and mins values  
  
  static int bTime = 0;     //holds the calculated breating time 
  static int ieValue = 0;   //holds the I:E relationship
  static int iTime = 0;   //holds the inspiration time by breathing cycle
  static int eTime = 0;   //holds the expiration time by breathing cycle

  PT_BEGIN(pt);
  while(1) {
    bf_input = analogRead(BF_INPUT_PIN);                    //Read the input value
    bf = map(bf_input, 0 , 1023, bfMin, bfMax);             //Maps the readed values to bfMax and bfMin
    ie_input = analogRead(IE_INPUT_PIN);                    //Read the input value
    ie = map(ie_input, 0 , 1023, ieMin, ieMax);             //Maps the readed values to ieMax and ieMin
    bTime = 60000/bf;                                       //Calculate the time for a single breathing cycle (in miliseconds)
    iTime = (10*(bTime - bHTime))/(10 - ie);                //Calculate the inspiration time based on frequency, ie relation and hold time
    eTime = (ie*(bTime - bHTime))/(ie + 10);                //Calculate the expiration time based on frequency, ie relation and hold time
    digitalWrite(I_VALVE_PIN, HIGH);                        //Open inspiration valve
    lastTimeBreath = millis();                              //Capture the actual time
    PT_WAIT_UNTIL(pt, millis() - lastTimeBreath > iTime);   //Keeps the inspiration valve opens during the calculated inspiration time
    digitalWrite(I_VALVE_PIN, LOW);                         //Close the inspiration Valve
    lastTimeBreath = millis();                              //Capture the actual time
    PT_WAIT_UNTIL(pt, millis() - lastTimeBreath > bHTime);  //Keeps both valves closed during the defined hold time 
    digitalWrite(E_VALVE_PIN, HIGH);                        //Open the expiration valve
    lastTimeBreath = millis();                              //Capture the actual time
    PT_WAIT_UNTIL(pt, millis() - lastTimeBreath > eTime);   //Keeps the expiration valve opens during the calculated inspiration time
    digitalWrite(E_VALVE_PIN, LOW);                         //Close the expiration valve
  }
  PT_END(pt);
}

void setup() {
  // put your setup code here, to run once:
  // set E_VALVE_PIN as output
  pinMode(E_VALVE_PIN, OUTPUT);     //Sets E_VALVE_PIN as output
  pinMode(I_VALVE_PIN, OUTPUT);     //Sets I_VALVE_PIN as output
  pinMode(IE_INPUT_PIN, INPUT);     //Sets IE_INPUT_PIN as input
  pinMode(BF_INPUT_PIN, INPUT);     //Sets BF_INPUT_PIN as input
  PT_INIT(&ptIE);                   //Initializes phIE protothead
}

void loop() {
  // put your main code here, to run repeatedly:
  //Launch ptIE protothread
  protothreadIEBreathing(&ptIE);
}
