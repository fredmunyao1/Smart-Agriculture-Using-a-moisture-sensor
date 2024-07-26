const int moistureSensorPin = 7;  // Digital pin connected to the soil moisture sensor
const int relayPin = 8;           // Digital pin connected to the relay module
int moistureState = 0;            // Variable to store the moisture sensor state

void setup() {
  pinMode(moistureSensorPin, INPUT);  // Set the moisture sensor pin as an input
  pinMode(relayPin, OUTPUT);          // Set the relay pin as an output
  Serial.begin(9600);                 // Initialize serial communication
}

void loop() {
  moistureState = digitalRead(moistureSensorPin);  // Read the moisture sensor state
  Serial.print("Moisture State: ");
  Serial.println(moistureState);  // Print the moisture state to the Serial Monitor

  if (moistureState == LOW) {     // If the soil is dry (sensor output is LOW)
    digitalWrite(relayPin, LOW);  // Turn on the relay (activate the water pump)
    Serial.println("Watering the plants...");
  } else {                        // If the soil is wet (sensor output is HIGH)
    digitalWrite(relayPin, HIGH); // Turn off the relay (deactivate the water pump)
    Serial.println("Soil is moist enough.");
  }

  delay(2000); // Wait for 2 seconds before the next reading
}
