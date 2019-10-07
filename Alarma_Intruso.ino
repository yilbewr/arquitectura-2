const int Trigger = PA6;   //Pin digital PA6 para el Trigger del sensor
const int Echo = PA5;   //Pin digital PA% para el Echo del sensor
long t; //timepo que demora en llegar el eco
long d; //distancia en centimetros
const int zum=PA4; //Zumbador
const int Led = PC13; //Led pc13
int enc=1;

//Alarma intrusos

void setup() {

  Serial.begin(9600);//iniciailzamos la comunicación
  pinMode(Trigger, OUTPUT); //pin como salida
  pinMode(Echo, INPUT);  //pin como entrada
  digitalWrite(Trigger, LOW);//Inicializamos el pin con 0
  pinMode(zum, OUTPUT);
  pinMode (Led, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

  distancia();
  
  
  
char leer = Serial.read();

  if(d<4){

    enc=1;

  
    
    while(leer!='a'&& enc==1){

      Serial.print("¡¡INTRUSO!!");
      Serial.println();
      
      encenderLed();
      sonar();

      char leer = Serial.read();
      
      if(leer=='a'){

        enc=0;
        
        Serial.println();
        Serial.print("Apagado");
        Serial.println();
        
      }
      
    }
    
    
   } 
        
}


  
  
  




void distancia(){

  digitalWrite(Trigger, HIGH);
  delayMicroseconds(10);          //Enviamos un pulso de 10us
  digitalWrite(Trigger, LOW);
  
  t = pulseIn(Echo, HIGH); //obtenemos el ancho del pulso
  d = t/59;             //escalamos el tiempo a una distancia en cm
  
  /*Serial.print("Distancia: ");
  Serial.print(d);      //Enviamos serialmente el valor de la distancia
  Serial.print("cm");
  Serial.println();
  delay(100);          //Hacemos una pausa de 100ms
*/
}

void sonar()
{
  
  digitalWrite(zum, HIGH);
  delay(50);
  digitalWrite(zum, LOW);
  delay(50);
  
}

void encenderLed()
{

  digitalWrite(Led,HIGH);
  delay(50);
  digitalWrite(Led,LOW);
  delay(50);
  
  
}
