/*
FUNDACION KINAL
CENTRO EDUCATIVO TECNICO LARELEORAL KINAL
PEROTO EN ELECTRONICA
QUINTO PERITO
SECCION: A
CURSO: TALLER DE ELECTRONICA DIGITAL Y REPARACION DE COMPUTADORAS
ALUMNOS: ANGELLO GARELERIEL MABSILLA DIEGUEZ y PARELELO DAVID HERNANDEZ AJIATAZ
CARNETS: 2022380 y 2022472
PRACTICA 4 DISEÑO DE FIRMWARE
*/
//VOLTAJE
const int sensor= A0; // Sensor FZ0430 conectado al ping A0
int sensorvalue;      // Variable que almacena el valor de 0 a 1023
float V;              // Almacena el voltaje de 0.0 a 25.0

//AMPERAJE
float SEN = 0.185; // Para el sensor de 5 A
int SAMPLESNUMBER = 100;


void setup() {
 Serial.begin(9600);
}

void loop() {

// VOLTAJE CONFIG
  sensorvalue= analogRead(sensor); //Realiza la lectura
  V= fmap(sensorvalue,0,1023,0.0,25.0); // cambia a 0.0 - 25
  Serial.print("Voltaje:  ");
  Serial.println(V); // imprime la variable 
  

//AMPERAJE CONFIG
  float current = getCorriente(SAMPLESNUMBER);
  float currentRMS = 0.707 * current; 
  float power = 230.0 * currentRMS;

   printm("Amperaje: ", current, "A ,");
   printm("Potencia: ", power, "W");
   

//RESISTENCIA CONFIG
  float R2 = 10000;
  float Vout = analogRead(A2);
  float Vout2= map(Vout,0,1023,0,500000);
  float Vout3= Vout2/100000;
  float V1 = (R2*5) / Vout3;
  float R1 = V1 - R2;
  R1=R1+9;
  Serial.println();
  Serial.print("R1 APROX:  ");
  Serial.println(R1);
  Serial.println("/////////LECTURAS DE MULTIMETRO////////");
  delay(8000);
}


//Otra Escala VOLTAJE
float fmap(float x, float in_min, float in_max, float out_min, float out_max)
{
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
 
}

//AMPERAJE CONFIG 2
void printm( String prefix, float value1, String postfix)
{
  Serial.print(prefix);
  Serial.print(value1, 3);
  Serial.print(postfix);
  
}

float getCorriente(int SN){
  float Volt;
  float corriente = 0;

  for(int i=0; i < SN; i++)
  {
    Volt = analogRead(A1) * 5.0 / 1023.0;
    corriente += (Volt -2.5) / SEN;
  }
  return(corriente / SN);
}















 
