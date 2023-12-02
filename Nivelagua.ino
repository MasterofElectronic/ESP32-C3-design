#include <BluetoothSerial.h>

BluetoothSerial SerialBT;
#if !defined(CONFIG_BT_ENABLE) || !defined(CONFIG_BLUEDROID_ENABLE)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

void setup() {
  Serial.begin(115200);
  SerialBT.begin("ESP32_BT");  
  pinMode(A0, INPUT);
}

void loop() {
  int sensorValue = analogRead(A0);

  // Enviar datos por Bluetooth
  
  SerialBT.println(sensorValue);
  SerialBT.print(";");

  delay(1000);  // Ajusta el intervalo según sea necesario
}
