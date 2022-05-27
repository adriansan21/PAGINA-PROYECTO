const int MOTOR_DETRAS_DERECHA = 13;  // Pin digital 13 para controlar sentido giro motor izquierdo
const int MOTOR_DELANTE_DERECHA = 12;  // Pin digital 12 para controlar sentido giro motor izquierdo

// Definición de variables y constantes relacionadas con el motor derecho
const int MOTOR_DETRAS_IZQUIERDA = 11;  // Pin digital 11 para controlar sentido giro motor izquierdo
const int MOTOR_DELANTE_IZQUIERDA = 10;  // Pin digital 10 para controlar sentido giro motor izquierdo

// Este programa usará el sensor de ultrasonidos HCSR04
// para medir la distancia a la que se encuentran
// diferentes obstáculos en centímetros y mostrarlo por el puerto serie.
const int PIN_TRIGGER = 7;
const int PIN_ECHO = 6;
const int CENTIMETROS = 50;
long TIEMPO;  // Almacena el tiempo de respuesta del sensor de entrada
float DISTANCIA;  // Almacena la distancia en cm a la que se encuentra el objeto

// Función que se ejecuta una sola vez al cargar el programa
void setup()
{
  // Se declaran todos los pines como salidas
  pinMode (MOTOR_DETRAS_DERECHA, OUTPUT);
  pinMode (MOTOR_DELANTE_DERECHA, OUTPUT);
  pinMode (MOTOR_DETRAS_IZQUIERDA, OUTPUT);
  pinMode (MOTOR_DELANTE_IZQUIERDA, OUTPUT);

  pinMode(PIN_TRIGGER,OUTPUT); // El emisor emite por lo que es configurado como salida
  pinMode(PIN_ECHO,INPUT);   // El receptor recibe por lo que es configurado como entrada
  Serial.begin(9600); // Inicia el puerto de comunicaciones en serie
}
// Función que se repite de manera periódica
void loop()
{
  SENSOR_ULTRASONICO();
  // Si el valor de la distancia es menor que 5 cm se para y sigue recto en caso contrario
  if(DISTANCIA>CENTIMETROS)
  {

    ROBOT_DELANTE();
  }
  else
  {
    ROBOT_DERECHA ();
  }
}
/*
 Función SENSOR_ULTRASONICO: para medir la longitud del pulso entrante.
 Mide el tiempo que transcurrido entre el envío del pulso ultrasónico
 y cuando el sensor recibe el rebote,
 es decir: desde que el pin echo empieza a recibir el rebote, HIGH,
 hasta que deja de hacerlo, LOW, la longitud del pulso entrante.
*/
void SENSOR_ULTRASONICO()
{
    // Se inicializa el sensor de infrasonidos
    digitalWrite(PIN_TRIGGER,LOW);  // Para estabilizar
    delayMicroseconds(10);

    // Comenzamos las mediciones
    // Se envía una señal activando la salida trigger durante 10 microsegundos
    digitalWrite(PIN_TRIGGER, HIGH);  // envío del pulso ultrasónico
    delayMicroseconds(10);
    TIEMPO=pulseIn(PIN_ECHO, HIGH);
    DISTANCIA= int(0.017*TIEMPO); // Fórmula para calcular la distancia en cm
    Serial.println("El valor de la distancia es ");
    Serial.println(DISTANCIA);
    delay(200);
}
/*
  Función ROBOT_DELANTE: esta función hará que ambos motores se activen a máxima potencia
  por lo que el robot avanzará hacia delante
*/
void ROBOT_DELANTE()
{
  // Motor izquierdo
  // Al mantener un pin HIGH y el otro LOW el motor gira en un sentido
  digitalWrite (MOTOR_DETRAS_DERECHA, HIGH);
  digitalWrite (MOTOR_DELANTE_DERECHA, LOW);
  // Motor derecho
  // Al mantener un pin HIGH y el otro LOW el motor gira en un sentido
  digitalWrite (MOTOR_DETRAS_IZQUIERDA, HIGH);
  digitalWrite (MOTOR_DELANTE_IZQUIERDA, LOW);
}
/*
  Función ROBOT_ATRAS: esta función hará que ambos motores se activen a máxima potencia
  en sentido contrario al anterior por lo que el robot avanzará hacia atrás
*/
void ROBOT_ATRAS()
{
  // Motor izquierdo
  // Al mantener un pin LOW y el otro HIGH el motor gira en sentido contrario al anterior
  digitalWrite (MOTOR_DETRAS_DERECHA, LOW);
  digitalWrite (MOTOR_DELANTE_DERECHA, HIGH);
  // Motor derecho
  // Al mantener un pin LOW y el otro HIGH el motor gira en sentido contrario al anterior
  digitalWrite (MOTOR_DETRAS_IZQUIERDA, LOW);
  digitalWrite (MOTOR_DELANTE_IZQUIERDA, HIGH);
}
/*
  Función ROBOT_DERECHA: esta función acccionará el motor izquierdo y parará el derecho
  por lo que el coche girará hacia la derecha (sentido horario)
*/
void ROBOT_DERECHA()
{
  //  Motor izquierdo
  // Se activa el motor izquierdo
  digitalWrite (MOTOR_DETRAS_DERECHA, HIGH);
  digitalWrite (MOTOR_DELANTE_DERECHA, LOW);
  // Motor derecho
  // Se para el motor derecho
  digitalWrite (MOTOR_DETRAS_IZQUIERDA, LOW);
  digitalWrite (MOTOR_DELANTE_IZQUIERDA, LOW);
}
/*
  Función ROBOT_IZQUIERDA: esta función acccionará el motor derecho y parará el izquierdo
  por lo que el coche girará hacia la izquierda (sentido antihorario)
*/
void ROBOT_IZQUIERDA ()
{
   //  Motor izquierdo
  // Se para el motor izquierdo
  digitalWrite (MOTOR_DETRAS_DERECHA, LOW);
  digitalWrite (MOTOR_DELANTE_DERECHA, LOW);
  // Motor derecho
  // Se activa el motor derecho
  digitalWrite (MOTOR_DETRAS_IZQUIERDA, HIGH);
  digitalWrite (MOTOR_DELANTE_IZQUIERDA, LOW);
}
/*
  Función ROBOT_QUIETO: esta función parará ambos motores
  por lo que el robot se parará.
*/
void ROBOT_QUIETO()
{
  // Motor izquierdo
  // Se para el motor izquierdo
  digitalWrite (MOTOR_DETRAS_DERECHA, LOW);
  digitalWrite (MOTOR_DELANTE_DERECHA, LOW);
  // Motor derecho
  // Se para el motor derecho
  digitalWrite (MOTOR_DETRAS_IZQUIERDA, LOW);
  digitalWrite (MOTOR_DELANTE_IZQUIERDA, LOW);
}
