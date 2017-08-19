/* Sensores CNY70 */

void init_cny70(int cny_1, int cny_2) {
  pinMode(cny_1, INPUT);
  pinMode(cny_2, INPUT);
}

/* Revisar estado de sensores CNY70 */

int check_cny70(int cny_1, int cny_2) {
  int state = 0;
  if ((digitalRead(cny_1) == 0) | (digitalRead(cny_2) == 0)) {
    state = 1;
  }
  return state;
}

byte check_hcsr04(int* distancia) {
  byte palabra = 0;
  distancia[0] = sonar_1.convert_cm(sonar_1.ping_median(3)); // para evitar ruido. (un poco)
  distancia[1] = sonar_2.convert_cm(sonar_2.ping_median(3)); // para evitar ruido. (un poco)
  distancia[2] = sonar_3.convert_cm(sonar_3.ping_median(3)); // para evitar ruido. (un poco)

  if (distancia[0] > 0) {
    palabra = palabra + 1;
  }
  else if (distancia[1] > 0) {
    palabra = palabra + 2;
  }
  else if (distancia[2] > 0) {
    palabra = palabra + 4;
  }
  
  return palabra;
}
