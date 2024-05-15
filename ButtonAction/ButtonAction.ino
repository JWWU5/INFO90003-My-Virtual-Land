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
  if (lastBlackThree == LOW && curBlackThree == HIGH) { 
    Serial.println("black_3");
  }
  if (lastBlackFour == LOW && curBlackFour == HIGH) { 
    Serial.println("black_4");
  }
  if (lastBlackFive == LOW && curBlackFive == HIGH) { 
    Serial.println("black_5");
  }

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


  delay(50);

}
