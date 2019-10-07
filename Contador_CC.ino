const int Trigger = PA6;   //Pin digital PA6 para el Trigger del sensor
const int Echo = PA5;   //Pin digital PA% para el Echo del sensor
long t; //timepo que demora en llegar el eco
long d; //distancia en centimetros
const int zum=PA4; //Zumbador
const int Led = PA7; //Led 
int cont=0;


//Contador personas CC

void setup() {

  Serial.begin(9600);//iniciailzamos la comunicación
  pinMode(Trigger, OUTPUT); //pin como salida
  pinMode(Echo, INPUT);  //pin como entrada
  digitalWrite(Trigger, LOW);//Inicializamos el pin con 0
  pinMode(zum, OUTPUT);
  pinMode (Led, OUTPUT);
  digitalWrite (Led, LOW);

  
  

}

void loop() {
  // put your main code here, to run repeatedly:


digitalWrite(Led,LOW);
  distancia();
  
char leer = Serial.read();

  
   digitalWrite(Led,LOW);

  if(leer == 'm'){
    Serial.print("Personas: ");
    Serial.print(cont);
    Serial.println();
  } 
  
  if(d<8){
   

      cont++;
      encenderLed();
      sonar();
      delay(2000);
     
  }else{

    digitalWrite(Led,LOW);
    
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
  delay(100);
  digitalWrite(zum, LOW);
  delay(100);
  
}

void encenderLed()
{

  digitalWrite(Led,HIGH);
  delay(100);
 
  digitalWrite(Led,LOW);
  delay(100);
  
  
}
