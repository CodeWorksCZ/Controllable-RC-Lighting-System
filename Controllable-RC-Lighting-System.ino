//Solid LED
const int GREEN_AND_RED_LED = 2;
//Flashing LED
const int RED_LED = 3;
const int WHITE_LED = 4;
//LANDING LIGHT
const int WHITE_LANDING_LED = 1;

//PWM
const unsigned  int PWM_FLASH_VALUE = 2000;
const unsigned  int PWM_LED_VALUE = 2500;

unsigned int signalPulse;

//PWM INPUT
const int PWM_IN = 0;

void setup() {

  pinMode(WHITE_LED, OUTPUT);
  pinMode(GREEN_AND_RED_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);
  pinMode(WHITE_LANDING_LED, OUTPUT);

  pinMode(PWM_IN, INPUT);

  //Default LED state
  digitalWrite(GREEN_AND_RED_LED, HIGH);
  digitalWrite(RED_LED, LOW);
  digitalWrite(WHITE_LED, LOW);
  digitalWrite(WHITE_LANDING_LED, LOW);


}

// the loop function runs over and over again forever
void loop() {

  signalPulse = pulseIn(PWM_IN, HIGH);

  if (signalPulse > PWM_FLASH_VALUE) {
    blinkBeaconRed();
    delay(300);
    blinkBeaconWhite();
  }

  if (signalPulse > PWM_LED_VALUE) {
    digitalWrite(WHITE_LANDING_LED, HIGH);
  } else {
    digitalWrite(WHITE_LANDING_LED, LOW);

  }

  delay(1000);
}

void blinkBeaconRed() {
  digitalWrite(RED_LED, HIGH);
  delay(10);
  digitalWrite(RED_LED, LOW);
}

void blinkBeaconWhite() {
  digitalWrite(WHITE_LED, HIGH);
  delay(10);
  digitalWrite(WHITE_LED, LOW);
  delay(10);
  digitalWrite(WHITE_LED, HIGH);
  delay(10);
  digitalWrite(WHITE_LED, LOW);

}

void switchBeaconOff() {
  digitalWrite(WHITE_LED, LOW);
  digitalWrite(RED_LED, LOW);

}

void switchLandingLightsOn() {
  digitalWrite(WHITE_LANDING_LED, HIGH);

}

void switchLandingLightsOff() {
  digitalWrite(WHITE_LANDING_LED, LOW);

}
