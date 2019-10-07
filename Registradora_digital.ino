const int Trigger = PA6;   //Pin digital PA6 para el Trigger del sensor
const int Echo = PA5;   //Pin digital PA% para el Echo del sensor
long t; //timepo que demora en llegar el eco
long d; //distancia en centimetros
const int zum=PA4; //Zumbador
const int Led = PC13; //Led pc13
int cont=0;
int pasaje=5200;
int precio_total;

//Pasaje bus intermunicipal

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

 

  
  
  if(d<8){
   
    
      cont++;
      sonar();
      delay(3000);

  }

  precio_total=cont*pasaje;
  
  if(leer == 'm'){
    Serial.print("El total es de: $");
    Serial.print(precio_total);
    Serial.println();
    Serial.print("El total de personas fue: ");
    Serial.print(cont);
    Serial.println();
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
