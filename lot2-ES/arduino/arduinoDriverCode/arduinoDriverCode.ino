const int LED1 = 13;
const int LED2 = 12;
const int buttonPin1 = 2;
const int buttonPin2 = 4;

int buttonState1 = 0;
int buttonState2 = 0;
char data;

void setup() {
  Serial.begin(9600);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(buttonPin1, INPUT);
  pinMode(buttonPin2, INPUT);
}

void loop() { 
  buttonState1 = digitalRead(buttonPin1);
  buttonState2 = digitalRead(buttonPin2);
  
//  if (buttonState1 == LOW) {
//    digitalWrite(LED2, HIGH);
//    Serial.print(1, BIN);
//  } else {
//    digitalWrite(LED2, LOW);
//    Serial.print(0, BIN); 
//  }
  if (Serial.available() > 0) {

    
    data = (char)Serial.read();
    delay(5);
   
    switch(data) {
      case 49:
        digitalWrite(LED1, HIGH);
        break;
      case 50:
        digitalWrite(LED2, HIGH);
        break;
      case 48:
        digitalWrite(LED2, LOW);
        digitalWrite(LED1, LOW);
        break;
    }
  }
}
