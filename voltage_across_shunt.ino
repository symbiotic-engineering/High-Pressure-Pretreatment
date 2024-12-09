const int sensorPin = A2;  // Analog pin connected to the resistor
const float resistorValue = 220.0;  // Resistor value in ohms
const float adcResolution = 5.0 / 1024.0;  // Resolution per ADC step (assuming 5V reference and 10-bit ADC)

void setup() {
  Serial.begin(9600);  // Start the serial communication
}

void loop() {
  int adcValue = analogRead(sensorPin);  // Read the ADC value
  float voltage = adcValue * adcResolution;  // Convert ADC value to voltage
  
  // Print the voltage
  Serial.print("Voltage across 220-ohm resistor: ");
  Serial.print(voltage, 3);  // Print voltage with 3 decimal places
  Serial.println(" V");

  delay(1000);  // Wait a second before next reading
}
