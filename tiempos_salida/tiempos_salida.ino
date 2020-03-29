
const int boton3x1 = 2;
const int boton2x1 = 3;
const int salida =  10;

int estadoboton3x1 = 0;
int estadoboton2x1 = 0;
int redirecciona1 = 0;
int redirecciona2 = 0;

void setup() {

  pinMode(salida, OUTPUT);
 
  pinMode(boton3x1, INPUT);
  pinMode(boton2x1, INPUT);
}

void loop() {
  
  estadoboton3x1 = digitalRead(boton3x1);
 
  if (estadoboton3x1 == HIGH) {
        redirecciona1 == HIGH;
                
        while(redirecciona1==HIGH){
          
                               }
             digitalWrite(salida,HIGH); 
             delay(1000);
             digitalWrite(salida,LOW);
             delay(3000);
          
             estadoboton2x1 = digitalRead(boton2x1);
             if (estadoboton2x1 == HIGH) {
             redirecciona1 == LOW;
             redirecciona2 == HIGH; 
                                   }
     
                         }
 estadoboton2x1 = digitalRead(boton2x1);
  
 if (estadoboton2x1 == HIGH) {
        redirecciona2 == HIGH;
                
        while(redirecciona2==HIGH){
          
                               }
             digitalWrite(salida,HIGH); 
             delay(1000);
             digitalWrite(salida,LOW);
             delay(2000);
          
             estadoboton3x1 = digitalRead(boton3x1);
             if (estadoboton3x1 == HIGH) {
             redirecciona2 == LOW;
             redirecciona1 == HIGH; 
                                   }
     
                         }                        

}                         
