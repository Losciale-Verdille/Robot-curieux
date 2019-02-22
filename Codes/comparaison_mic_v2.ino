int var = 100;
int micro,dir;
int nb_Mesures, n_1, n_2, n_3, n_4;

// Micro & AOP 1
int gap1;
int m1 = 1;
int amp1 = 503;

// Micro & AOP 2
int gap2;
int m2 = 2;
int amp2 = 505;

//Micro & AOP 3
int gap3;
int m3 = 3;
int amp3 = 510;

//Micro & AOP 4
int gap4;
int m4 = 4;
int amp4 = 508;

void setup() {
  Serial.begin(9600);
}

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


void loop() {
  nb_Mesures = 0;
  n_1 = 0;
  n_2 = 0;
  n_3 = 0;
  n_4 = 0;
  Serial.println("OK");
  while (nb_Mesures<100) {
    gap1 = abs(amp1-analogRead(m1));
    gap2 = abs(amp2-analogRead(m2));
    gap3 = abs(amp3-analogRead(m3));
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
      nb_Mesures++;;
    }
  }
  dir = Compare(gap1,gap2,gap3,gap4);
  Serial.println(dir);
  delay(50);
}
