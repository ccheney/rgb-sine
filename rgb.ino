/* PWM Pin Slot Placements */
int const RED_PIN = 3;
int const BLUE_PIN = 5;
int const GREEN_PIN = 6;

/* Controls the speed of our sine's oscillation */
float const FREQUENCY = .001;

/* Sets the center of amplitude for our sine to oscillate from */
float const CENTER = (255 / 2);

/* Controls the amplitude of our values (range 0-255) */
float const AMPLITUDE = (255 / 2);

/* 0deg out of phase, default sine wave */
int const RED_PHASE = 0;

/* 120deg out of phase of our default sine wave */
float const GREEN_PHASE = (2 * PI / 3);

/* 240deg out of phase of our default sine wave */
float const BLUE_PHASE = (4 * PI / 3);

/* Number of colors to generate in a sine wave */
int const COLOR_COUNT = 32000;

void setup() {
    Serial.begin(9600);
}

void loop() {
    int redValue = 0;
    int greenValue = 0;
    int blueValue = 0;
    
    int i = 0;
    int length = COLOR_COUNT;
    for (; i < length; i++) {
        redValue = sin(FREQUENCY * i + RED_PHASE) * AMPLITUDE + CENTER;
        greenValue = sin(FREQUENCY * i + GREEN_PHASE) * AMPLITUDE + CENTER;
        blueValue = sin(FREQUENCY * i + BLUE_PHASE) * AMPLITUDE + CENTER;
        analogWrite(RED_PIN, redValue);
        analogWrite(GREEN_PIN, greenValue);
        analogWrite(BLUE_PIN, blueValue);

        Serial.print(round(redValue));
        Serial.print(", ");
        Serial.print(round(greenValue));
        Serial.print(", ");
        Serial.print(round(blueValue));
        Serial.println("");
    }
}

