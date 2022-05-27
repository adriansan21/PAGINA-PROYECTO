int motorizquierdadelante = 11;
int motorderechadelante = 13;

void setup() {
  pinMode(motorizquierdadelante, OUTPUT);
  pinMode(motorderechadelante, OUTPUT);

  Serial.begin(9600);

}

void loop() {
    digitalWrite (motorizquierdadelante, 100);
    digitalWrite (motorderechadelante, 100);
}
