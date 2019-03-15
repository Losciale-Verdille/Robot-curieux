// Vérification du fonctionnement du module Bluetooth
// Permet d'executer les commandes AT

#include<SoftwareSerial.h>

#define RX 3
#define TX 2
char Data;
SoftwareSerial BlueT(RX,TX);

void setup() {
  //initialisation de la discussion
  BlueT.begin(9600);
  Serial.begin(9600);
  Serial.println("Bonjour - Pret pour les commandes AT");

}

void loop() {
  // si il y a des informations que le BlueTooth veut transmettre
  while (BlueT.available()) {
  Serial.print(char(BlueT.read())); }
  // si il y a des informations que l'utilisateur veut transmettre
  while (Serial.available()) {
  BlueT.write(char(Serial.read())); }
}
