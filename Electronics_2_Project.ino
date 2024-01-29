int redPin = 3;      // red LED connected to digital pin 3
int yellowPin = 5;   // yellow LED connected to digital pin 5
int greenPin = 6;    // green LED connected to digital pin 6

void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(yellowPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  Serial.begin(9600);  // initialize serial communication at 9600 bits per second
}

void loop() {
  int binaryVals[8] = {0}; // initialize an array to store the binary values for each pin
  for (int i = 0; i < 8; i++) {
    int analogVal = analogRead(i); // read the analog voltage value at the current pin
    if (analogVal > 4*1023/5) { // if the voltage is above 4V (80% of 5V), set the binary value to 1
      binaryVals[i] = 1;
    } else { // if the voltage is below 4V, set the binary value to 0
      binaryVals[i] = 0;
    }
  }
  int decimalVal = 0; // initialize a variable to store the decimal value
  for (int i = 0; i < 8; i++) {
    decimalVal += binaryVals[i] * pow(2, i); // calculate the decimal value by adding the binary values of each pin
  }
  float voltageVal = decimalVal * (5.0 / 255.0);
  
  Serial.print("Decimal Value: ");
  Serial.print(decimalVal); // print the decimal value to the serial monitor
  Serial.print("      Voltage: ");
  Serial.println(voltageVal, 2);

  if (voltageVal > 3.0) {
    digitalWrite(redPin, HIGH);    // turn on red LED at full brightness
    digitalWrite(yellowPin, LOW);   // turn off yellow LED
    digitalWrite(greenPin, LOW);    // turn off green LED
  } else if (voltageVal > 1.0) {
    digitalWrite(redPin, LOW);      // turn off red LED
    digitalWrite(yellowPin, HIGH); // turn on yellow LED at full brightness
    digitalWrite(greenPin, LOW);    // turn off green LED
  } else {
    digitalWrite(redPin, LOW);      // turn off red LED
    digitalWrite(yellowPin, LOW);   // turn off yellow LED
    digitalWrite(greenPin, HIGH);  // turn on green LED at full brightness
  }

  delay(400); // wait for 100 milliseconds before reading the analog voltage values again
}
