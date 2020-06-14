/**
 * http://codigoelectronica.com/blog/arduino-blink
 * 
 * Autor: Oscar Fernandez Alzate, twitter: @OscarDevOps
 * Código Electrónica @codelectronica
 */
int led = 13;

void setup() {
  pinMode(led, OUTPUT);
}

void loop() {
  digitalWrite(led, HIGH);
  delay(1000);
  digitalWrite(led, LOW);
  delay(1000);
}
