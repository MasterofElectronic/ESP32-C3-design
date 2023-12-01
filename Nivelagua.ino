#include <BluetoothSerial.h>

BluetoothSerial SerialBT;

void setup() {
  Serial.begin(115200);
  SerialBT.begin("ESP32_BT");  // Puedes cambiar "ESP32_BT" por el nombre deseado para tu dispositivo Bluetooth
  pinMode(A0, INPUT);
}

void loop() {
  int sensorValue = analogRead(A0);

  // Enviar datos por Bluetooth
  SerialBT.print("Nivel:");
  SerialBT.println(sensorValue);

  delay(1000);  // Ajusta el intervalo según sea necesario
}