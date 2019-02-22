int out = 1;
int son;
int led_rouge = 3;
int ambiant = 512; //à mesurer
int var = 30;

void setup() {
  Serial.begin(9600);
  pinMode(led_rouge,OUTPUT);
  /*digitalWrite(led_rouge,HIGH);
  delay(200); //élimination du pic de tension au moment du téléversement sur l'arduino
  for (int i=0; i<32000; i++) {
    //int max stockable ~32500 > utilisation de float
    ambiant = ambiant + analogRead(out);
    //Serial.println(analogRead(out));
  }
  ambiant = ambiant / 32000;
  Serial.println("Niveau d'ambiance : " + String(ambiant));*/
  digitalWrite(led_rouge,LOW);
}

void loop() {
  son = analogRead(out);
  Serial.println(son);
  /*if ((son > ambiant+var) || (son < ambiant-var)) {
    //Serial.println("Clap !");
    digitalWrite(led_rouge,HIGH);
    delay(40);
    digitalWrite(led_rouge,LOW);
  }
  delay(15);*/
}
