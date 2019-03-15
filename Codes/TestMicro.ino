// Vérification micro
// Lecture sur traceur série

int out = 1; //numéro du micro

void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.println(analogRead(out););
}
