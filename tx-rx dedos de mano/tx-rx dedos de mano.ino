//variables 
char option = ' ';          //variable para lectura 
int t=0;                    //variable para tiempo
int k1=0;                    //variable para tiempo contador
int k2=0;                    //variable para tiempo

const int Azul = 10;        // variable salida digital LED AZUL
const int Verde = 11;       // variable salida digital LED VERDE
const int Rojo = 12;        // variable salida digital LED ROJO
const int Amarillo = 13;    // variable salida digital LED AMARILLO


void setup() {
  Serial.begin(9600);                       //Habilita comunicacion serial
  Serial.println("CLEARDATA");              //etiqueta de encabezado opcional
  Serial.println("LABEL,Sensorx,muestra");  // etiqueta opcional
  

  pinMode(Azul , OUTPUT);                   //declara como salida             
  pinMode(Verde , OUTPUT);                  //declara como salida
  pinMode(Rojo , OUTPUT);                   //declara como salida
  pinMode(Amarillo , OUTPUT);               //declara como salida

}

void loop() {
// variables lectura de puerto analogico
 int indice=analogRead(A0);
 int Medio=analogRead(A1);
 int Anular=analogRead(A2);
 int Menique=analogRead(A3);

// normalización
 float ind = indice*(5/1024.0);
 float med = Medio*(5/1024.0);
 float anu = Anular*(5/1024.0);
 float men = Menique*(5/1024.0);
// transmisión de dato por lectura de los puertos analógicos
 Serial.print("DATA,");
 Serial.print(ind);
 Serial.print(",");
 Serial.print(med);
 Serial.print(",");
 Serial.print(anu);
 Serial.print(",");
 Serial.println(men);
 
 // recibo de datos enviados por la x terminal
if(Serial.available()>0){
  //leemos la opcion enviada
    option = Serial.read();
    if(option == 'a'){
      digitalWrite(Azul, HIGH);
      //Serial.println("a");
     // Serial.print(",");
      k1=1;
    }
    if(option == 'b'){
      digitalWrite(Verde, HIGH);
      //Serial.println("b");
      k1=1;
    } 
    if(option == 'c'){
      digitalWrite(Rojo, HIGH);
      //Serial.println("c");
      k1=1;
    }
    if(option == 'd'){
      digitalWrite(Amarillo, HIGH);
      //Serial.println("d");
      k1=1;
    }

  }
// condición cuando se recibe una orden 
  if(k1==1){
    k2=1;       // permite almaceran una constante 
    }
    else{
    t=0;
    }

// sentencia de tiempo
    if(k2==1)
    {
      //enviamos los datos de tiempo cada 200ms cuando se asigna el dedo a ser presionado 
    t++;
     Serial.print(",");
     Serial.println(t);
    }

//condición para pagar leds y variable de tiempo encerado 
        if(ind >1){
      digitalWrite(Azul, LOW);
      t=0;
      k1=0;
      k2=0;
    }
         if(med >1){
      digitalWrite(Verde, LOW);
       t=0;
       k1=0;
       k2=0;
    }
         if(anu >1){
      digitalWrite(Rojo, LOW);
       t=0;
       k1=0;
       k2=0;
    }
         if(men >1){
      digitalWrite(Amarillo, LOW);
       t=0;
       k1=0;
       k2=0;
    }
delay(100);
}