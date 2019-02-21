#include<Servo.h> //Omar Alberto Bañol Gomez,Frey Camilo Mahecha Velasco
#define pinservo 9
#define PINSERVO 13
Servo motorderecho;
Servo motorizquierdo;
int estado = '0';
void setup() {
  motorderecho.attach(pinservo);
  motorizquierdo.attach(PINSERVO);
  motorderecho.write(90);  //Motor en stop
motorizquierdo.write(90); //Motor en stop
  Serial.begin(9600);
}

void loop() {
   if (Serial.available() > 0) {    // lee el bluetooth y almacena en estado
    estado = Serial.read();
    Serial.println(estado);
  }
    
  if(estado == 'S'){
    motorderecho.write(90);    //Motor en stop
    motorizquierdo.write(90);   //Motor en stop
    
  }
  else{
  if (estado == 'w') //ADELANTE
  {
    motorderecho.write(0);
    motorizquierdo.write(180);
    
  }
  if (estado == 's') //ATRAS
  {
    motorderecho.write(180);
    motorizquierdo.write(0);
  }
  if (estado == 'd') //DERECHA
  {
    motorderecho.write(180);
    motorizquierdo.write(180);
 
  }
  if (estado == 'a') //izquierda
  {
  motorderecho.write(0);
    motorizquierdo.write(0);
 
  }
   if(estado== '1')
   {
motorderecho.write(90);
motorizquierdo.write(90);
   }



  }
 

}
