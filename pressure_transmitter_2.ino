// Constants
const int sensorPin = A0;           // Analog input pin for the sensor
const float minVoltage = 0.6;       // Minimum sensor voltage (4 mA)
const float maxVoltage = 3.0;       // Maximum sensor voltage (20 mA)
const float minPressure = 0.0;      // Pressure at 4 mA in psi
const float maxPressure = 1500.0;   // Pressure at 20 mA in psi
const int adcResolution = 1023;     // ADC resolution (10-bit for standard Arduino)



void setup() {
  Serial.begin(9600);
}

void loop() {
  int sensorValue = analogRead(sensorPin); // Read the analog input
  //Serial.println(sensorValue);

  float voltage = (sensorValue / float(adcResolution)) * 5.0; // Convert ADC value to voltage

  // Map voltage to pressure (0 - 1500 psi)
  float pressure = mapVoltageToPressure(voltage);

  // Output the results
  Serial.print("Voltage: ");
  Serial.print(voltage);
  Serial.print(" V, Pressure: ");
  Serial.print(pressure);
  Serial.println(" psi");

  delay(1000); // Delay for readability
}

// Function to map voltage to pressure
float mapVoltageToPressure(float voltage) {
  // Scale voltage range (0.6V - 3.0V) to pressure range (0 psi - 1500 psi)
  float pressure =  ((voltage - minVoltage) / (maxVoltage - minVoltage)) * (maxPressure - minPressure) + minPressure;
  return pressure;
}
