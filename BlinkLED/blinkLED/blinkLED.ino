/*https://www.instructables.com/id/Blinking-an-LED-With-ESP32/ */
const int ledPin = 26;
const int greenLedPin = 32;

void setup() {
  // setup pin 5 as a digital output pin
  pinMode (ledPin, OUTPUT);
  pinMode (greenLedPin, OUTPUT);
}

void loop() {
  digitalWrite (ledPin, HIGH);  // turn on the LED
  delay(50);  
  digitalWrite (greenLedPin, HIGH);  // turn on the LED
  delay(50); 
  digitalWrite (ledPin, LOW); // turn off the LED
  delay(50); 
  digitalWrite (greenLedPin, LOW);  // turn on the LED
  delay(50);  // wait for half a second or 500 milliseconds
}
