/*
Program: Dice Game
Name: Agustin Espinoza
Professor: Dr. Keaton 
Course: SIE370
Date: 2/13/23
*/

// Declare variables
int greenRandNumber;
int blueRandNumber;
char inputCode;

void setup() {
  // Begin serial on 9600 baud
  Serial.begin(9600);
  randomSeed(analogRead(13));
  // Prompt user to begin game
  Serial.println("\nWelcome to the dice game. \nPress Y if you would like to play a round of dice or N if you do not.");
}

void playGame() {
  // Generate random numbers for green and blue player
  greenRandNumber = random(1, 6);
  blueRandNumber = random(1, 6);

  // Print score if green player wins
  if (greenRandNumber > blueRandNumber) {
    Serial.print("\n\nGreen Wins!");
    Serial.print("\n\nGreen Player rolled ");
    Serial.print(greenRandNumber);
    Serial.print("\nBlue Player rolled ");
    Serial.print(blueRandNumber);
    pinMode(13, OUTPUT);
    digitalWrite(13, HIGH);
    delay(1000);
  }

  // Print score if blue player wins
  if (greenRandNumber < blueRandNumber) {
    Serial.print("\n\nBlue Wins!");
    Serial.print("\n\nBlue Player rolled ");
    Serial.print(blueRandNumber);
    Serial.print("\nGreen Player rolled ");
    Serial.print(greenRandNumber);
    pinMode(7, OUTPUT);
    digitalWrite(7, HIGH);
    delay(1000);
  }

  // Print score if tie
  if (greenRandNumber == blueRandNumber) {
    Serial.print("\n\nTie! Both rolls were ");
    Serial.print(greenRandNumber);
    pinMode(11, OUTPUT);
    digitalWrite(11, HIGH);
    delay(1000);
  }

  delay(50);
}

void loop() {
  // Check if serial input is available
  if (Serial.available()) {
    // Store serial input in inputCode variable ('Y' or 'N')
    inputCode = Serial.read();
    // Turn off all three LEDs
    digitalWrite(13, LOW);
    digitalWrite(7, LOW);
    digitalWrite(11, LOW);

    switch (inputCode) {
      // If user types 'N'
      case 'N':
        Serial.print("\n\nOk. Maybe Later.");
        Serial.print("\nPress Y if you would like to play a round of dice or N if you do not.");
        break;
      // If user types 'Y'
      case 'Y':
        playGame();
        Serial.print("\n\nPress Y if you would like to play a round of dice or N if you do not.");
        break;
      // If user types anything other than 'Y' or 'N'
      default:
        Serial.println("\n\nError: Press Y if you would like to play a round of dice or N if you do not.");
        break;
    }
  }
}
