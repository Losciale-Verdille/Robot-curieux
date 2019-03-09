#include <SoftwareSerial.h>
//-- MOTEUR A --
int ENA=9; //Connecté à Arduino pin 9(sortie PWM)
int IN1=4; //Connecté à Arduino pin 4 // en arrière
int IN2=5; //Connecté à Arduino pin 5 //en avant
//-- MOTEUR B --
int ENB=10; //Connecté à Arduino pin 10(Sortie PWM)
int IN3=6; //Connecté à Arduino pin 6 // en avant
int IN4=7; //Connecté à Arduino pin 7 // en arrière

int RX=2;// connexion BT
int TX=3;
SoftwareSerial BlueT(RX,TX);

char Data;//caractère envoyé

boolean modeauto=true;//le robot se conduit seul?

//micro
int var = 90; //MINIMUM 50!!!
int micro,dir;
int nb_Mesures, n_1, n_2, n_3, n_4;

// Micro & AOP 1
int gap1;
int m1 = 1;
int amp1 = 501;

// Micro & AOP 2
int gap2;
int m2 = 2;
int amp2 = 510;

//Micro & AOP 3
int gap3;
int m3 = 3;
int amp3 = 507;

//Micro & AOP 4
int gap4;
int m4 = 4;
int amp4 = 505;

void setup() {
pinMode(ENA,OUTPUT); // Configurer
pinMode(ENB,OUTPUT); // les broches
pinMode(IN1,OUTPUT); // comme sortie
pinMode(IN2,OUTPUT);
pinMode(IN3,OUTPUT);
pinMode(IN4,OUTPUT);

BlueT.begin(9600);
Serial.begin(9600);
}

void loop() {
  if(modeauto){//mode auto activé ?
    if(BlueT.available()){//on lit le caractère
      Data=BlueT.read();
      if(Data=='c'){//avant
      modeauto=false;
      }
    }
    delay(100);
    switch(deplacementauto()){
      case 1:
       Serial.println("d");
       stopper();
        droite();
        break;
      case 2:
       Serial.println("g");
       stopper();
        gauche();
        break;
      case 4:
       Serial.println("a");
       stopper();
        avant();
        break;
      case 3:
       Serial.println("v");
       //stopper();
        //bas();
        break;
      default:
       Serial.println("defa");
        break;
    }
  }else{
    manoeuvre();
  }
}

void droite(){
  analogWrite(ENB,0);
  analogWrite(ENA,255);
}
  
void gauche(){
  analogWrite(ENB,255);
  analogWrite(ENA,0);
}

void avant(){
  digitalWrite(IN2,HIGH);
  digitalWrite(IN1,LOW);      
  digitalWrite(IN4,HIGH);
  digitalWrite(IN3,LOW);
  analogWrite(ENB,255);
  analogWrite(ENA,160);
}

void bas(){
  digitalWrite(IN2,LOW);
  digitalWrite(IN1,HIGH);      
  digitalWrite(IN4,LOW);
  digitalWrite(IN3,HIGH);
  analogWrite(ENB,255);
  analogWrite(ENA,255);
  }

void manoeuvre(){
  if(BlueT.available()){
    Data=BlueT.read();
    if(Data=='C'){//on met le mode automatique
      modeauto=true;
    }

    if(Data=='1'){//avant
      avant();
    }
    if(Data=='2'){//droite
      droite();
    }
    if(Data=='3'){//bas
      bas();
    }
    if(Data=='4'){//gauche
      gauche();
    }
    if(Data=='0'){//stopper
      stopper();
    }
  }
}

//Cette fonction compare entre les 4micros dans quel direction est le bruit et renvoie le numero du micro où la detection est la plus forte
int Compare(int in1, int in2, int in3, int in4) {
  int mic = 1;
  int vmax = in1;
  if (in2>vmax) {
    mic = 2;
    vmax = in2;
  }
  if (in3>vmax) {
    mic = 3;
    vmax = in3;
  }
  if (in4>vmax) {
    mic = 4;
    vmax = in4;
  }
  return mic;
}
void stopper(){
  analogWrite(ENA,0);
  analogWrite(ENB,0);
}


//fonction qui permet au robot de se déplacer automatiquement en fonction du bruit
int deplacementauto(){
  nb_Mesures = 0;
  n_1 = 0;
  n_2 = 0;
  n_3 = 0;
  n_4 = 0;
  while (nb_Mesures<30) {
    gap1 = abs(amp1-analogRead(m1));
    gap2 = abs(amp2-analogRead(m2));
    gap3 = 3*abs(amp3-analogRead(m3));
    gap4 = abs(amp4-analogRead(m4));
    if ((gap1 >= var) || (gap2 >= var) || (gap3 >= var) || (gap4 >= var)){
      micro = Compare(gap1,gap2,gap3,gap4);
      if (micro == 1){
        n_1++;
        }
      if (micro == 2){
        n_2++;
        }
      if (micro == 3){
        n_3++;
        }
      if (micro == 4){
        n_4++;
        }
      nb_Mesures++;
    }
  }
  dir = Compare(n_1,n_2,n_3,n_4);
  return dir;
}
