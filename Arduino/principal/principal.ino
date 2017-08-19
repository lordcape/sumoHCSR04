#include <NewPing.h>

#define TRIGGER_PIN_1  12
#define ECHO_PIN_1     11
#define TRIGGER_PIN_2  10
#define ECHO_PIN_2     9
#define TRIGGER_PIN_3  8
#define ECHO_PIN_3     7
#define MAX_DISTANCE   25

#define CNY_1          A0
#define CNY_2          A1

#define INA_M1         2
#define INA_M2         3
#define PWM_M1         4
#define PWM_M2         5
#define EN_M           6

#define LED1           13

NewPing sonar_1(TRIGGER_PIN_1, ECHO_PIN_1, MAX_DISTANCE);
NewPing sonar_2(TRIGGER_PIN_2, ECHO_PIN_2, MAX_DISTANCE);
NewPing sonar_3(TRIGGER_PIN_3, ECHO_PIN_3, MAX_DISTANCE);

int cny70_state = 0;
int dist[3] = {0, 0, 0};
byte hcsr04_state = 0;

void setup() {
  Serial.begin(115200);
  init_cny70(CNY_1, CNY_2);
  init_motores(INA_M1, INA_M2, EN_M);
  init_leds(LED1);
}

void loop() {

  cny70_state = check_cny70(CNY_1, CNY_2);
  //cny70_state = 1; // DEBUG PURPOSE ONLY !!! para forzar la entrada!!
  
  if (cny70_state == 0) {
    mover_motores(INA_M1, INA_M2, EN_M, PWM_M1, PWM_M2, -200, -200); delay(200);  // reversa
  }
  else {
    hcsr04_state = check_hcsr04(dist);

    switch (hcsr04_state) {
      case 0b00000001 :
        mover_motores(INA_M1, INA_M2, EN_M, PWM_M1, PWM_M2, 100, -100); delay(20); // giro antihorario (visto desde arriba)
        break;
      case 0b00000010 :
        mover_motores(INA_M1, INA_M2, EN_M, PWM_M1, PWM_M2, 200, 200); delay(20); // embestida adelante
        break;
      case 0b00000100 :
        mover_motores(INA_M1, INA_M2, EN_M, PWM_M1, PWM_M2, -100, 100); delay(20); // giro horario (visto desde arriba)
        break;
      default :
        mover_motores(INA_M1, INA_M2, EN_M, PWM_M1, PWM_M2, 100, 200); delay(20); // paseo circular tranqui
        break;
    }

  }





  /*
    check_hcsr04(dist);

    if (dist[0] > 0 | dist[1] > 0 | dist[2] > 0)
    {
      encender_leds(LED1, 1);
    } else
    {
      encender_leds(LED1, 0);
    }

    Serial.print("Flag Sensor 1:  ");
    Serial.println(flag_sensor_1);
    Serial.print("Flag Sensor 2:  ");
    Serial.println(flag_sensor_2);
    Serial.println("-------------------");*/
}



