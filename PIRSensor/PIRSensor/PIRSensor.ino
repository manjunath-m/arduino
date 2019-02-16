/*********
  Rui Santos
  Complete project details at https://randomnerdtutorials.com  
  https://randomnerdtutorials.com/esp32-pir-motion-sensor-interrupts-timers/
  https://www.instructables.com/id/Make-a-Pocket-Size-Theremin-With-ESP32/
*********/

#define timeSeconds 5

// Set GPIOs for LED and PIR Motion Sensor
const int led = 26;
const int motionSensor = 27;
int buzzerPin = 12;

// Timer: Auxiliary variables
unsigned long now = millis();
unsigned long lastTrigger = 0;
boolean startTimer = false;

int photoValue;
long buzzerFreq; // The frequency to buzz the buzzer
long buzzMAX = 2500; // Maximum frequency for the buzzer
long photoMAX = 1023; // Maximum value for the photoresistor


// Checks if motion was detected, sets LED HIGH and starts a timer
void IRAM_ATTR detectsMovement() {
  Serial.println("MOTION DETECTED!!!");
  digitalWrite(led, HIGH);
//  digitalWrite(buzzerPin,HIGH);
//   buzz(buzzerPin, buzzerFreq, 10);  
  startTimer = true;
  lastTrigger = millis();
   
   //buzz
   //photValue = analogRead(photopin); // Values 0-1023
  photoValue = 500;
  buzzerFreq = (photoValue * buzzMAX) / photoMAX;
  buzz(buzzerPin, buzzerFreq, 10);  
}

void buzz(int targetPin, long frequency, long length) {
   long delayValue = 1000000/frequency/2;
   delayValue = 10000;
   long numCycles = frequency * length/ 1000;
   numCycles = 10;
   for (long i=0; i < numCycles; i++){
        
      digitalWrite(targetPin,HIGH);
      delayMicroseconds(delayValue);
      digitalWrite(targetPin,LOW);
      delayMicroseconds(delayValue);
   }
}

void setup() {
  // Serial port for debugging purposes
  Serial.begin(115200);
  
  // PIR Motion Sensor mode INPUT_PULLUP
  pinMode(motionSensor, INPUT_PULLUP);
  // Set motionSensor pin as interrupt, assign interrupt function and set RISING mode
  attachInterrupt(digitalPinToInterrupt(motionSensor), detectsMovement, RISING);

  // Set LED to LOW
  pinMode(led, OUTPUT);
  digitalWrite(led, LOW);

  //Buzzer
  pinMode(buzzerPin, OUTPUT);

  //TEMP
//  digitalWrite(buzzerPin,HIGH);
//  delay(2000);
//  digitalWrite(buzzerPin,LOW);
}

void loop() {
  // Current time
  now = millis();
  // Turn off the LED after the number of seconds defined in the timeSeconds variable
  if(startTimer && (now - lastTrigger > (timeSeconds*1000))) {
    Serial.println("Motion stopped...");
    digitalWrite(led, LOW);
    digitalWrite(buzzerPin,LOW);
    startTimer = false;
  }
}
