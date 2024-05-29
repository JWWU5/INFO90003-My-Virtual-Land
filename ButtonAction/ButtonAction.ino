int whiteOne = 13;
int whiteTwo = 12;
int whiteThree = 27;
int whiteFour = 33;
int whiteFive = 15;
int whiteSix = 32;
int whiteSeven = 14;

int blackOne = 26;
int blackTwo = 25;
int blackThree = 34;
int blackFour = 39;
int blackFive = 36;

int resetBtn = 8;
int hugeRedBtn = 37;
int volumnChange = 4;
int fan = 7;

// store button's last condition
bool lastWhiteOne = LOW;
bool lastWhiteTwo = LOW;
bool lastWhiteThree = LOW;
bool lastWhiteFour = LOW;
bool lastWhiteFive = LOW;
bool lastWhiteSix = LOW;
bool lastWhiteSeven = LOW;

bool lastBlackOne = LOW;
bool lastBlackTwo = LOW;
bool lastBlackThree = LOW;
bool lastBlackFour = LOW;
bool lastBlackFive = LOW;

bool lastResetBtn = LOW;
bool lastHugeRedBtn = LOW;

bool isFanOn = false;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(whiteOne, INPUT);
  pinMode(whiteTwo, INPUT);
  pinMode(whiteThree, INPUT);
  pinMode(whiteFour, INPUT);
  pinMode(whiteFive, INPUT);
  pinMode(whiteSix, INPUT);
  pinMode(whiteSeven, INPUT);
  
  pinMode(blackOne, INPUT);
  pinMode(blackTwo, INPUT);
  pinMode(blackThree, INPUT);
  pinMode(blackFour, INPUT);
  pinMode(blackFive, INPUT);

  pinMode(resetBtn, INPUT);
  pinMode(hugeRedBtn, INPUT); // change from day to night

  pinMode(fan, OUTPUT);
}

void loop() {
  bool curWhiteOne = digitalRead(whiteOne);
  bool curWhiteTwo = digitalRead(whiteTwo);
  bool curWhiteThree = digitalRead(whiteThree);
  bool curWhiteFour = digitalRead(whiteFour);
  bool curWhiteFive = digitalRead(whiteFive);
  bool curWhiteSix = digitalRead(whiteSix);
  bool curWhiteSeven = digitalRead(whiteSeven);

  bool curBlackOne = digitalRead(blackOne);
  bool curBlackTwo = digitalRead(blackTwo);
  bool curBlackThree = digitalRead(blackThree);
  bool curBlackFour = digitalRead(blackFour);
  bool curBlackFive = digitalRead(blackFive);

  bool curResetBtn = digitalRead(resetBtn);
  bool curHugeRedBtn = digitalRead(hugeRedBtn);

  if (lastWhiteOne == LOW && curWhiteOne == HIGH) { 
    Serial.println("white_1");
  }
  if (lastWhiteTwo == LOW && curWhiteTwo == HIGH) { 
    Serial.println("white_2");
  }
  if (lastWhiteThree == LOW && curWhiteThree == HIGH) { 
    Serial.println("white_3");
  }
  if (lastWhiteFour == LOW && curWhiteFour == HIGH) { 
    Serial.println("white_4");
  }
  if (lastWhiteFive == LOW && curWhiteFive == HIGH) { 
    Serial.println("white_5");
  }
  if (lastWhiteSix == LOW && curWhiteSix == HIGH) { 
    Serial.println("white_6");
  }
  if (lastWhiteSeven == LOW && curWhiteSeven == HIGH) { 
    Serial.println("white_7");
  }

  if (lastBlackOne == LOW && curBlackOne == HIGH) { 
    Serial.println("black_1");
  }
  if (lastBlackTwo == LOW && curBlackTwo == HIGH) { 
    Serial.println("black_2");
  }
  // black three control the raining mode
  if (lastBlackThree == LOW && curBlackThree == HIGH) { 
    Serial.println("black_3");
    if (isFanOn) {
      Serial.println("fan on");
      analogWrite(fan, 0); // trun off the fan
      isFanOn = false;
    } else {
      Serial.println("fan off");
      analogWrite(fan, 255); // trun on the fan
      isFanOn = true;
    }
    
  } 
  if (lastBlackFour == LOW && curBlackFour == HIGH) { 
    Serial.println("black_4");
  }
  if (lastBlackFive == LOW && curBlackFive == HIGH) { 
    Serial.println("black_5");
  }

  if (lastResetBtn == LOW && curResetBtn == HIGH) {
    Serial.println("reset");
  }
  if (lastHugeRedBtn == LOW && curHugeRedBtn == HIGH) {
    Serial.println("day_change");
  }

  int inputValue = analogRead(volumnChange);
  //Serial.println(inputValue);

  lastWhiteOne = curWhiteOne;
  lastWhiteTwo = curWhiteTwo;
  lastWhiteThree = curWhiteThree;
  lastWhiteFour = curWhiteFour;
  lastWhiteFive = curWhiteFive;
  lastWhiteSix = curWhiteSix;
  lastWhiteSeven = curWhiteSeven;

  lastBlackOne = curBlackOne;
  lastBlackTwo = curBlackTwo;
  lastBlackThree = curBlackThree;
  lastBlackFour = curBlackFour;
  lastBlackFive = curBlackFive;

  lastResetBtn = curResetBtn;
  lastHugeRedBtn = curHugeRedBtn;


  delay(50);



}

