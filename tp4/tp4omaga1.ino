
const int tempSensorPin = A0;
const int lightSensorPin = A1;


const int ledRPin = 9;
const int ledGPin = 10;
const int ledBPin = 11;

void setup() {
  
  pinMode(ledRPin, OUTPUT);
  pinMode(ledGPin, OUTPUT);
  pinMode(ledBPin, OUTPUT);

  
  Serial.begin(9600);
}

void loop() {
  
  float temperature = leerTemperatura();

 
  int lightLevel = leerLuz();

 
  Serial.print("El nivel de luz actual es: ");
  Serial.println(lightLevel);
  Serial.print("y la temperatura actual es: ");
  Serial.print(temperature);
  Serial.println("°C");

  
  if (lightLevel < 100) {
    if (temperature > 90) {
      encenderLED(255, 0, 0);  
    } else if (temperature < 18) {
      encenderLED(0, 0, 255); 
    } else {
      encenderLED(0, 255, 0);  
    }
  } else {
    apagarLED();
  }

  delay(1000); 
}

float leerTemperatura() {
 
  int sensorValue = analogRead(tempSensorPin);

  
  float voltage = sensorValue * (5.0 / 1023.0);
  float temperature = (voltage - 0.5) * 100.0;

  return temperature;
}

int leerLuz() {
 
  int sensorValue = analogRead(lightSensorPin);

  return sensorValue;
}

void encenderLED(int red, int green, int blue) {
  
  analogWrite(ledRPin, red);
  analogWrite(ledGPin, green);
  analogWrite(ledBPin, blue);
}

void apagarLED() {

  analogWrite(ledRPin, 0);
  analogWrite(ledGPin, 0);
  analogWrite(ledBPin, 0);
}
