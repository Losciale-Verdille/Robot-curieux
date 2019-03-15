// Vérification du fonctionnement des moteurs

//-- MOTEUR A --
int ENA=9; //Connecté à Arduino pin 9(sortie PWM)
int IN1=4; //Connecté à Arduino pin 4 // en arrière
int IN2=5; //Connecté à Arduino pin 5 //en avant
//-- MOTEUR B --
int ENB=10; //Connecté à Arduino pin 10(Sortie PWM)
int IN3=6; //Connecté à Arduino pin 6 // en avant
int IN4=7; //Connecté à Arduino pin 7 // en arrière

void setup() {
  pinMode(ENA,OUTPUT);
  pinMode(ENB,OUTPUT);
  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  pinMode(IN3,OUTPUT);
  pinMode(IN4,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  //on fait avancer les moteurs à pleine puissance
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,HIGH);
  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,LOW);
  analogWrite(ENA,255);
  analogWrite(ENB,255);
}
