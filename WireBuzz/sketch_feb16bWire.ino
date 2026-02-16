
const int touchPin = 2;
const int buzzerPin = 8;
const int ledPin = 9;

int score = 0;

// 7-segment pins (a,b,c,d,e,f,g)
int segPins[7] = {3,4,5,6,7,10,11};

// Digit patterns (0-9) for common cathode
byte digits[10][7] = {
  {1,1,1,1,1,1,0}, //0
  {0,1,1,0,0,0,0}, //1
  {1,1,0,1,1,0,1}, //2
  {1,1,1,1,0,0,1}, //3
  {0,1,1,0,0,1,1}, //4
  {1,0,1,1,0,1,1}, //5
  {1,0,1,1,1,1,1}, //6
  {1,1,1,0,0,0,0}, //7
  {1,1,1,1,1,1,1}, //8
  {1,1,1,1,0,1,1}  //9
};

void setup() {
  pinMode(touchPin, INPUT_PULLUP);
  pinMode(buzzerPin, OUTPUT);
  pinMode(ledPin, OUTPUT);

  for(int i=0;i<7;i++){
    pinMode(segPins[i], OUTPUT);
  }

  displayDigit(0);
}

void loop() {

  if(digitalRead(touchPin) == LOW){
    score++;
    if(score > 9) score = 9;

    displayDigit(score);

    digitalWrite(ledPin, HIGH);
    tone(buzzerPin, 800);
    delay(200);
    noTone(buzzerPin);
    digitalWrite(ledPin, LOW);

    delay(300);
  }

  // If no mistakes for 10 seconds → winner
  static unsigned long startTime = millis();
  if(millis() - startTime > 10000){
    playWinnerMelody();
    startTime = millis();
  }
}

void displayDigit(int num){
  for(int i=0;i<7;i++){
    digitalWrite(segPins[i], digits[num][i]);
  }
}

void playWinnerMelody(){
  int melody[] = {523,659,784,1046}; // C E G C
  for(int i=0;i<4;i++){
    tone(buzzerPin, melody[i]);
    delay(300);
  }
  noTone(buzzerPin);
}

