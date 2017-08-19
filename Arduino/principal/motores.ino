#define INA_M1 2
#define INA_M2 3
#define PWM_M1 4
#define PWM_M2 5
#define EN_M 6

/* Inicializo motores */

void init_motores(int ina_m1, int ina_m2, int en) {
  pinMode(ina_m1, OUTPUT);
  pinMode(ina_m2, OUTPUT);
  pinMode(en, OUTPUT);
  apagar_motores(en);
}

/* Apagar motores */

void apagar_motores(int en) {
  digitalWrite(en, 0);
}

/* Mover motores */

void mover_motores(int ina_m1, int ina_m2, int en, int pwm_m1, int pwm_m2, int pwm1, int pwm2) {

  digitalWrite(en, 1); // enable motors
  int speed_m1 = 0;
  int speed_m2 = 0;

  if (pwm1 > 0) {
    digitalWrite(ina_m1, 0);
    speed_m1 = pwm1;
  }
  else if (pwm1 < 0) {
    digitalWrite(ina_m1, 1);
    speed_m1 = 255 + pwm1;
  }
  else {
    digitalWrite(en, 0);
  }
  analogWrite(pwm_m1, speed_m1);

  if (pwm2 > 0) {
    digitalWrite(ina_m2, 0);
    speed_m2 = pwm2;
  }
  else if (pwm2 < 0) {
    digitalWrite(ina_m2, 1);
    speed_m2 = 255 + pwm2;
  }
  else {
    digitalWrite(en, 0);
  }
  analogWrite(pwm_m2, speed_m2);

}


