/**
 * Arduino display 7 segmentos
 * Creado por: Oscar Fernandez @OscarDevOps
 * Publicado por: codigoelectronica.com <codigoelectronica@gmail.com>
 * 
 * Este código permite visualizar los números de 0 al 9 en el display de 
 * cátodo común
 */

//Declaramos los pines qde conexión del display
const int pins[7] = { 2, 3, 4, 5, 6, 7, 8 }; 

//Declaramos los numeros para el ánodo común
const byte numbersDisplayAnode[10] = {0b0111111,     //0
                          0b0000110,          //1
                          0b1011011,          //2
                          0b1001111,          //3
                          0b1100110,          //4
                          0b1101101,          //5
                          0b1111101,          //6
                          0b0000111,          //7
                          0b1111111,          //8
                          0b1101111};         //9

void setup() {
  //Ponemos los pines como salida
  for(int i = 0; i < 7; i++) {
    pinMode(pins[i], OUTPUT);  
  }

  //Iniciamos el display en 0
  lightSegments(0);
}

void loop() {
  for(int i = 0; i < 10; i++) {
    lightSegments(i);
    delay(1000);
  }
}

/**
 * Esta función permite encender el segmento con el número 
 * pasado como argumento
 * 
 * int number Número del 0 al 9
 */
void lightSegments(int number) {
  byte numberBit = numbersDisplayAnode[number];
  for (int i = 0; i < 7; i++)  {
    int bit = bitRead(numberBit, i);
    digitalWrite(pins[i], bit);
  }
}
