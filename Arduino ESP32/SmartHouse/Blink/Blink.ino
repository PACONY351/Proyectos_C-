int leds[] = {D2,D3,D4,D5,D6};
int BUTT = D1;
int cont = 0;
bool prevState = HIGH;

void setup(){
  
  for(int i = 0; i < 5; i++){
    pinMode(leds[i], OUTPUT);
    digitalWrite(leds[i], LOW);
  }
  
  pinMode(BUTT, INPUT_PULLUP);  // Activa resistencia pull-up interna
}

void loop(){
  bool currentState = digitalRead(BUTT);

  // Detecta solo cuando se presiona (borde descendente)
  if (prevState == HIGH && currentState == LOW) {
    cont++;
    delay(200); // Pequeño anti-rebote

    switch (cont) {
      case 1:
        gusano();
        break;
      case 2:
        interCal();
        break;
      case 3:
        interCalIn();
        break;
      case 4:
        gusano2();
        break;
      case 5:
        sirenas();
        break;
      case 6:
        // Apagar todos y reiniciar
        for (int i = 0; i < 5; i++) {
          digitalWrite(leds[i], LOW);
        }
        cont = 0;
        break;
    }
  }

  prevState = currentState;
}

void gusano(){
  for(int i = 0; i < 5; i++){
    delay(1000);
    digitalWrite(leds[i], HIGH);
  }
  for(int i = 0; i < 5; i++){
    delay(1000);
    digitalWrite(leds[i], LOW);
  }
}

void interCal(){
  for(int i = 0; i < 5 ; i++){
    if(i % 2 == 0){
      digitalWrite(leds[i], HIGH);
      delay(1000);
      digitalWrite(leds[i], LOW);
    }
  }
}

void interCalIn(){
  for(int i = 0; i < 5 ; i++){
    if(i % 3 == 0){
      digitalWrite(leds[i], HIGH);
      delay(1000);
      digitalWrite(leds[i], LOW);
    }
  }
}

void gusano2(){
  for(int i = 0; i<2; i++){
    for(int j = 0; j < 5; j++){
      delay(500);
      digitalWrite(leds[j], HIGH);
    }
    for(int k = 0; k < 5; k++){
      delay(500);
      digitalWrite(leds[k], LOW);
    }
  }
}

void sirenas(){
  for(int i = 0; i < 10; i++){
    for(int j = 0; j < 5 ; j++){
      if(j % 2 == 0){
        digitalWrite(leds[j], HIGH);
        delay(500);
        digitalWrite(leds[j], LOW);
      }
    }
    for(int k = 0; k < 5 ; k++){
      if(k % 3 == 0){
        digitalWrite(leds[k], HIGH);
        delay(500);
        digitalWrite(leds[k], LOW);
      }
    }
  }
}
