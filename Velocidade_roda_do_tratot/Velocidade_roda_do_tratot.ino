const byte interruptPin = 2;
volatile byte state = LOW;
float velAngular, tempo, deltaTempo, velLinear, tempoAnterior = 0, pi = 3.141592;
const float ;

void setup() {
  Serial.begin(9600);
  pinMode(interruptPin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(interruptPin), Velocidade, RISING);
}

void loop() {
  tempo = millis();//INICIA O MILLIS
}

void Velocidade() {
  state = !state;

  if (tempoAnterior != 0) {
    deltaTempo = tempo - tempoAnterior;
    tempoAnterior = tempo;
    velAngular = pi / (4 * (deltaTempo / 1000)); //∆θ/∆T --> 2π/∆T
    velLinear = velAngular * raio * 3.6;
  } else {
    tempoAnterior = tempo;
  }
  Serial.print(velLinear);
  Serial.println(" Km/h");
}
