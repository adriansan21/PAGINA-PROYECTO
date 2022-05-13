int lectura=0;
void setup () {
Serial.begin(9600);
pinMode (lectura,INPUT);
}

void loop() {
   lectura=digitalRead(8);
   Serial.println(lectura);
   delay(200);
 }
