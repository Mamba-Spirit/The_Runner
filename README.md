# The_Runner
The_Runner is an Arduino-based game project developed during my first year. Inspired by the Chrome Dinosaur game, this project involves a character that runs and jumps over obstacles, with the game accelerating as it progresses.

## Features
* Character Control: The character can jump to avoid obstacles.
* Obstacles: Cacti appear as obstacles that the character must avoid.
* Increasing Difficulty: The game speed increases over time, making it more challenging.

## Components Used
* Arduino
* LiquidCrystal Display (LCD)
* LEDs (Green and Orange)

## Libraries
The following libraries are used in this project:

* ISEN.h
* LabIsen-2009.h
* ISL12026.h
* MCP23X08.h
* LiquidCrystal.h

## Setup
1. **Connect the LCD**: Ensure the LCD is correctly wired to the Arduino.
2. **LEDs Setup**: Connect the Green LED to pin 2 and the Orange LED to pin 9.
3. **Upload the Code**: Use the Arduino IDE to upload the provided `.ino` file to your Arduino board.

## Code Explanation
The main components of the code include:

* **Character Design**: Custom characters for the running and jumping dinosaur are created.
* **Game Loop**: The main loop handles the game start, character movement, obstacle generation, and speed increase.

## Custom Characters :
```
byte dino[8] = {
      B00000,
      B00000,
      B00011,
      B00011,
      B10110,
      B11110,
      B11110,
      B01010,
};

byte dinojp[8] = {
      B00000,
      B00000,
      B00011,
      B00011,
      B10110,
      B11110,
      B11111,
      B01000,
};

byte cactus[8] = {
      B00100,
      B00101,
      B10101,
      B10101,
      B10101,
      B01111,
      B00100,
      B00100
};

```
## Setup Function :
```
void setup() {
  pinMode(LED_ORANGE, OUTPUT);
  pinMode(LED_VERTE, INPUT);
  lcd.createChar(2, dino);
  lcd.createChar(1, cactus);
  lcd.createChar(3, dinojp);
  lcd.begin(16, 2);
  debut = 0;
}

```
## Main Loop :
```
void loop() {
  if (debut == 0) {
    start();
    debut = 1;
  }
  lcd.setCursor(0, 1);
  lcd.write(2);
  Saut();
  Cactus();
  delay();
}
```
## Key Functions
* **Saut()**: Makes the character jump to avoid obstacles.
* **Game_Over()**: Called when the player loses the game.
* **start()**: Initializes and starts the game.
* **compteur_points()**: Counts the points as the player progresses.

## Usage
* Start the Game: Once the Arduino is powered, the game will start automatically.
* Jump: Use the designated button to make the character jump and avoid obstacles.
* Score: The score increases as you survive longer, with the speed increasing to add difficulty.

