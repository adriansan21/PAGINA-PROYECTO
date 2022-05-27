// Incluímos la librería para poder controlar el servo
#include <Servo.h>
 
// Declaramos la variable para controlar el servo
Servo servoMotor;

// Variables de los motores

// Motores de la izquierda
const int MOTOR_DELANTE_IZQUIERDA = 10;  // Pin digital 10 que hace que las ruedas de la izquierda avancen hacia delante
const int MOTOR_DETRAS_IZQUIERDA = 11;  // Pin digital 11 que hace que las ruedas de la izquierda avancen hacia atrás

// Motores de la derecha
const int MOTOR_DELANTE_DERECHA = 12;  // Pin digital 12 que hace que las ruedas de la derecha avancen hacia delante
const int MOTOR_DETRAS_DERECHA = 13;  // Pin digital 13 que hace que las ruedas de la derecha avancen hacia atrás


// Variables del sensor ultrasónico (HC-SR04)
const int PIN_TRIGGER = 7;
const int PIN_ECHO = 6;
const int CENTIMETROS = 50; // Son los centímetros a los que queremos que gire el coche
long TIEMPO;  // Variable que guarda el tiempo
float DISTANCIA;  // Variable que guarda la distancia
float DISTANCIA_DERECHA;  // Variable que guarda la distancia a la derecha
float DISTANCIA_IZQUIERDA;  // Variable que guarda la distancia a la izquierda

// Declaramos el pin al que está conectado el servo
const int PIN_SERVO = 3;


void setup()
{
// Se declaran los motores como OUTPUT
  pinMode (MOTOR_DELANTE_IZQUIERDA, OUTPUT);
  pinMode (MOTOR_DETRAS_IZQUIERDA, OUTPUT);
  pinMode (MOTOR_DELANTE_DERECHA, OUTPUT);
  pinMode (MOTOR_DETRAS_DERECHA, OUTPUT);

// Se declara como OUTPUT el TRIGGER y como INPUT el ECHO.
  pinMode(PIN_TRIGGER,OUTPUT);
  pinMode(PIN_ECHO,INPUT);
  Serial.begin(9600); // Se inicia el puerto de comunicaciones
  servoMotor.attach(PIN_SERVO);

}



// Código que se repite en bucle
void loop()
{
  SENSOR_ULTRASONICO();
  // Si la distancia es mayor que los centímetros avanzará
  if(DISTANCIA>CENTIMETROS)
  {
    ROBOT_DELANTE();
  }
  else
  {
  // Si los centímetros son mayores que la distancia el coche se parará y girará hacia la derecha o hacia la izquierda
    ROBOT_QUIETO();
    delay(500);
    ROBOT_ATRAS();
    delay(250);
    ROBOT_QUIETO();
    delay(500);

     GIRAR_SERVO();
    

    if (DISTANCIA_DERECHA > DISTANCIA_IZQUIERDA) {
      ROBOT_DERECHA ();
    } else {
      ROBOT_IZQUIERDA();
    }
    delay(500);

  }
}

void GIRAR_SERVO() {

// Desplazamos a la posición 0º
servoMotor.write(0);
// Esperamos 1 segundo
delay(1000);

// Desplazamos a la posición 90º
servoMotor.write(90);
// Esperamos 1 segundo
delay(1000);

CALCULAR_DISTANCIA_IZQUIERDA();

// Desplazamos a la posición 180º
servoMotor.write(180);
// Esperamos 1 segundo
delay(1000);

CALCULAR_DISTANCIA_DERECHA();

// Desplazamos a la posición 0º
servoMotor.write(90);

delay(500);
  
}


void SENSOR_ULTRASONICO()
{
  // En esta parte del código lo que vamos a hacer es calcular la distancia gracias al sensor ultrasónico.
  // Lo que hará será enviar un sonido y calcular el tiempo que tarda en volver.
  // Gracias a la fórmula de abajo podrá calcular la distancia en centímetros.
    digitalWrite(PIN_TRIGGER,LOW);
    delayMicroseconds(10);

    digitalWrite(PIN_TRIGGER, HIGH);
    delayMicroseconds(10);
    TIEMPO=pulseIn(PIN_ECHO, HIGH);
    DISTANCIA= int(0.017*TIEMPO);
    Serial.println("El valor de la distancia es ");
    Serial.println(DISTANCIA);
    delay(200);
}

void CALCULAR_DISTANCIA_DERECHA()
{
  // En esta parte del código lo que vamos a hacer es calcular la distancia a la derecha cuando el servo gire a la derecha gracias al sensor ultrasónico.
  // Lo que hará será enviar un sonido y calcular el tiempo que tarda en volver.
  // Gracias a la fórmula de abajo podrá calcular la distancia en centímetros.
    digitalWrite(PIN_TRIGGER,LOW);
    delayMicroseconds(10);

    digitalWrite(PIN_TRIGGER, HIGH);
    delayMicroseconds(10);
    TIEMPO=pulseIn(PIN_ECHO, HIGH);
    DISTANCIA_DERECHA= int(0.017*TIEMPO);
    Serial.println("El valor de la distancia a la derecha es ");
    Serial.println(DISTANCIA_DERECHA);
    delay(200);
}

void CALCULAR_DISTANCIA_IZQUIERDA()
{
  // En esta parte del código lo que vamos a hacer es calcular la distancia a la izquierda cuando el servo gire a la izquierda gracias al sensor ultrasónico.
  // Lo que hará será enviar un sonido y calcular el tiempo que tarda en volver.
  // Gracias a la fórmula de abajo podrá calcular la distancia en centímetros.
    digitalWrite(PIN_TRIGGER,LOW);
    delayMicroseconds(10);

    digitalWrite(PIN_TRIGGER, HIGH);
    delayMicroseconds(10);
    TIEMPO=pulseIn(PIN_ECHO, HIGH);
    DISTANCIA_IZQUIERDA= int(0.017*TIEMPO);
    Serial.println("El valor de la distancia a la izquierda es ");
    Serial.println(DISTANCIA_IZQUIERDA);
    delay(200);
}


// Función que hace que se activen los pines de los motores hacia delante y el coche avance hacia delante.



void ROBOT_DELANTE()
{
  // Motores del lado izquierdo.
  // El pin de delante está en HIGH mientras que el de detrás está en LOW, por lo que las dos ruedas de la izquierda girarán hacia delante.
  digitalWrite (MOTOR_DELANTE_IZQUIERDA, HIGH);
  digitalWrite (MOTOR_DETRAS_IZQUIERDA, LOW);
  // Motores del lado derecho.
  // El pin de delante está en HIGH mientras que el de detrás está en LOW, por lo que las dos ruedas de la derecha girarán hacia delante.
  digitalWrite (MOTOR_DELANTE_DERECHA, HIGH);
  digitalWrite (MOTOR_DETRAS_DERECHA, LOW);
}



// Esta función lo que hará es que se activen los pines del coche hacia detrás y el coche avance hacia atrás. 
void ROBOT_ATRAS()
{
  // Motores del lado izquierdo.
  // El pin de detrás está en HIGH mientras que el de delante está en LOW, por lo que las dos ruedas de la izquierda girarán hacia atrás.
  digitalWrite (MOTOR_DELANTE_IZQUIERDA, LOW);
  digitalWrite (MOTOR_DETRAS_IZQUIERDA, HIGH);
  // Motores del lado derecho.
  // El pin de detrás está en HIGH mientras que el de delante está en LOW, por lo que las dos ruedas de la derecha girarán hacia atrás.
  digitalWrite (MOTOR_DELANTE_DERECHA, LOW);
  digitalWrite (MOTOR_DETRAS_DERECHA, HIGH);
}



// Esta función lo que hará es hacer que únicamente giren las ruedas de la izquierda hacia delante para que así se produzca un giro hacia la derecha.
void ROBOT_DERECHA()
{
  // Motores del lado izquierdo.
  // El pin de las ruedas de la izquierda hacia delante está en HIGH, por lo que las ruedas girarán hacia delante y provocarán un giro hacia la derecha.
  digitalWrite (MOTOR_DELANTE_IZQUIERDA, HIGH);
  digitalWrite (MOTOR_DETRAS_IZQUIERDA, LOW);
  // Motores del lado derecho.
  // Los dos pines están en LOW, por lo que ninguna de las ruedas se quedarán quietas. 
  digitalWrite (MOTOR_DELANTE_DERECHA, LOW);
  digitalWrite (MOTOR_DETRAS_DERECHA, LOW);
}



// Esta función lo que hará es hacer que únicamente giren las ruedas de la derecha hacia delante para que así se produzca un giro hacia la izquierda.
void ROBOT_IZQUIERDA ()
{
  // Motores del lado izquierdo.
  // Los dos pines están en LOW, por lo que ninguna de las ruedas se quedarán quietas. 
  digitalWrite (MOTOR_DELANTE_IZQUIERDA, LOW);
  digitalWrite (MOTOR_DETRAS_IZQUIERDA, LOW);
  // Motores del lado derecho.
  // El pin de las ruedas de la derecha hacia delante está en HIGH, por lo que las ruedas girarán hacia delante y provocarán un giro hacia la izquierda.
  digitalWrite (MOTOR_DELANTE_DERECHA, HIGH);
  digitalWrite (MOTOR_DETRAS_DERECHA, LOW);
}



// Esta función lo que hará es hacer que todas las ruedas se queden quietas poniendo todos los pines en LOW.
void ROBOT_QUIETO()
{
  // Motores del lado izquierdo.
  // Se paran los motores del lado izquierdo.
  digitalWrite (MOTOR_DELANTE_IZQUIERDA, LOW);
  digitalWrite (MOTOR_DETRAS_IZQUIERDA, LOW);
  // Motores del lado derecho.
  // Se paran los motores del lado derecho.
  digitalWrite (MOTOR_DELANTE_DERECHA, LOW);
  digitalWrite (MOTOR_DETRAS_DERECHA, LOW);
}
