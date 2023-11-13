#include <Arduino.h>
#include <Wire.h>
#include "Adafruit_NeoPixel.h"

//---------------------------- Neo Pixeles ---------------------------------------------------------------------------------------------------------------
#define NeoPin 23
#define NunPixel 16

Adafruit_NeoPixel pixels(NunPixel, NeoPin, NEO_RBG);

String message;
bool S = false;
#define LM75_ADDRESS 0x48
float temperatura; 
bool cicloInicio = false;

//-------------------------------------------------------------------------------------------------------------------------------------------------
//Variables de comunicación Uart con Tiva C
int DatoSensor;
String BanderaTiva;

void MedirSensor (void);
void NeoMed0 (void);
void NeoMed1 (void);
void NeoMed2 (void);
void NeoMed3 (void);
void NeoGua (void);
void NeoIni (void);

void setup() {
 Wire.begin();
 Serial.begin(115200);
 Serial2.begin(115200);

pixels.begin();
pixels.clear();
pixels.setBrightness(25);

pixels.setPixelColor(0, pixels.Color(100,100,150));
pixels.show();

NeoIni();

}

void loop() {
pixels.setBrightness(25);

Wire.beginTransmission(LM75_ADDRESS);
Wire.write(0x00);
Wire.endTransmission();     // Finalizar comunicació

if (Serial2.available()) {
		BanderaTiva = Serial2.readString();

		if (BanderaTiva == "on") {
    
		Serial.println("Medición requerida!");
    MedirSensor();
		delay(200);
		}
	 if (BanderaTiva == "S") {
    
		Serial.println("La medición ha sido guardada");
    NeoGua();
		delay(200);
		}

	}
}

void MedirSensor (void){

Wire.requestFrom(LM75_ADDRESS, 1);    // Solicitar 1 byte del esclavo #23
byte len = Wire.read();
Wire.requestFrom(LM75_ADDRESS, (int)len);  // Solicitar 'len' byte del esclavo #23

while (Wire.available()) { // hay datos disponibles?
    int c = Wire.read();    // recibir byte como un caracter
    temperatura = c;
  }
  if (temperatura < 40.0) {
    Serial.print("Temperatura: ");
    Serial.print(temperatura);
    Serial.println(" °C");
    Serial2.print(temperatura); 
    Serial.print("Medición enviada: ");
    Serial.println(temperatura); 

      if (temperatura>= 36.5 && temperatura<= 37) {
       NeoMed2();
       //amarilla
       }
      if (temperatura< 36.5) {
       NeoMed1();
       //azul
       }
      if (temperatura>= 37 && temperatura<= 38) {
       NeoMed3();
       //verde
       }
      if (temperatura>38) {
      NeoMed0();
      //rojo
       }
  }
  delay(1000);
}
//-------------------------------------------Mediciones------------------------------------------------------------------------------------------
void NeoMed0 (void){
pixels.setPixelColor(0, pixels.Color((0),(0),(255)));
pixels.show();
pixels.setPixelColor(1, pixels.Color((0),(0),(255)));
pixels.show();
pixels.setPixelColor(2, pixels.Color((0),(0),(255)));
pixels.show();
pixels.setPixelColor(3, pixels.Color((0),(0),(255)));
pixels.show();
pixels.setPixelColor(4, pixels.Color((0),(0),(255)));
pixels.show();
pixels.setPixelColor(5, pixels.Color((0),(0),(255)));
pixels.show();
pixels.setPixelColor(6, pixels.Color((0),(0),(255)));
pixels.show();
pixels.setPixelColor(7, pixels.Color((0),(0),(255)));
pixels.show();
pixels.setPixelColor(8, pixels.Color((0),(0),(255)));
pixels.show();
pixels.setPixelColor(9, pixels.Color((0),(0),(255)));
pixels.show();
pixels.setPixelColor(10, pixels.Color((0),(0),(255)));
pixels.show();
pixels.setPixelColor(11, pixels.Color((0),(0),(255)));
pixels.show();
pixels.setPixelColor(12, pixels.Color((0),(0),(255)));
pixels.show();
pixels.setPixelColor(13, pixels.Color((0),(0),(255)));
pixels.show();
pixels.setPixelColor(14, pixels.Color((0),(0),(255)));
pixels.show();
pixels.setPixelColor(15, pixels.Color((0),(0),(255)));
pixels.show();

delay(600);

pixels.setPixelColor(0, pixels.Color((0),(0),(0)));
pixels.show();
pixels.setPixelColor(1, pixels.Color((0),(0),(0)));
pixels.show();
pixels.setPixelColor(2, pixels.Color((0),(0),(0)));
pixels.show();
pixels.setPixelColor(3, pixels.Color((0),(0),(0)));
pixels.show();
pixels.setPixelColor(4, pixels.Color((0),(0),(0)));
pixels.show();
pixels.setPixelColor(5, pixels.Color((0),(0),(0)));
pixels.show();
pixels.setPixelColor(6, pixels.Color((0),(0),(0)));
pixels.show();
pixels.setPixelColor(7, pixels.Color((0),(0),(0)));
pixels.show();
pixels.setPixelColor(8, pixels.Color((0),(0),(0)));
pixels.show();
pixels.setPixelColor(9, pixels.Color((0),(0),(0)));
pixels.show();
pixels.setPixelColor(10, pixels.Color((0),(0),(0)));
pixels.show();
pixels.setPixelColor(11, pixels.Color((0),(0),(0)));
pixels.show();
pixels.setPixelColor(12, pixels.Color((0),(0),(0)));
pixels.show();
pixels.setPixelColor(13, pixels.Color((0),(0),(0)));
pixels.show();
pixels.setPixelColor(14, pixels.Color((0),(0),(0)));
pixels.show();
pixels.setPixelColor(15, pixels.Color((0),(0),(0)));
pixels.show();
}

void NeoMed1 (void){
pixels.setPixelColor(0, pixels.Color((0),(250),(0)));
pixels.show();
pixels.setPixelColor(1, pixels.Color((0),(250),(0)));
pixels.show();
pixels.setPixelColor(2, pixels.Color((0),(250),(0)));
pixels.show();
pixels.setPixelColor(3, pixels.Color((0),(250),(0)));
pixels.show();
pixels.setPixelColor(4, pixels.Color((0),(250),(0)));
pixels.show();
pixels.setPixelColor(5, pixels.Color((0),(250),(0)));
pixels.show();
pixels.setPixelColor(6, pixels.Color((0),(250),(0)));
pixels.show();
pixels.setPixelColor(7, pixels.Color((0),(250),(0)));
pixels.show();
pixels.setPixelColor(8, pixels.Color((0),(250),(0)));
pixels.show();
pixels.setPixelColor(9, pixels.Color((0),(250),(0)));
pixels.show();
pixels.setPixelColor(10, pixels.Color((0),(250),(0)));
pixels.show();
pixels.setPixelColor(11, pixels.Color((0),(250),(0)));
pixels.show();
pixels.setPixelColor(12, pixels.Color((0),(250),(0)));
pixels.show();
pixels.setPixelColor(13, pixels.Color((0),(250),(0)));
pixels.show();
pixels.setPixelColor(14, pixels.Color((0),(250),(0)));
pixels.show();
pixels.setPixelColor(15, pixels.Color((0),(250),(0)));
pixels.show();

delay(600);

pixels.setPixelColor(0, pixels.Color((0),(0),(0)));
pixels.show();
pixels.setPixelColor(1, pixels.Color((0),(0),(0)));
pixels.show();
pixels.setPixelColor(2, pixels.Color((0),(0),(0)));
pixels.show();
pixels.setPixelColor(3, pixels.Color((0),(0),(0)));
pixels.show();
pixels.setPixelColor(4, pixels.Color((0),(0),(0)));
pixels.show();
pixels.setPixelColor(5, pixels.Color((0),(0),(0)));
pixels.show();
pixels.setPixelColor(6, pixels.Color((0),(0),(0)));
pixels.show();
pixels.setPixelColor(7, pixels.Color((0),(0),(0)));
pixels.show();
pixels.setPixelColor(8, pixels.Color((0),(0),(0)));
pixels.show();
pixels.setPixelColor(9, pixels.Color((0),(0),(0)));
pixels.show();
pixels.setPixelColor(10, pixels.Color((0),(0),(0)));
pixels.show();
pixels.setPixelColor(11, pixels.Color((0),(0),(0)));
pixels.show();
pixels.setPixelColor(12, pixels.Color((0),(0),(0)));
pixels.show();
pixels.setPixelColor(13, pixels.Color((0),(0),(0)));
pixels.show();
pixels.setPixelColor(14, pixels.Color((0),(0),(0)));
pixels.show();
pixels.setPixelColor(15, pixels.Color((0),(0),(0)));
pixels.show();
}

void NeoMed2 (void){
pixels.setPixelColor(0, pixels.Color((200),(0),(255)));
pixels.show();
pixels.setPixelColor(1, pixels.Color((200),(0),(255)));
pixels.show();
pixels.setPixelColor(2, pixels.Color((200),(0),(255)));
pixels.show();
pixels.setPixelColor(3, pixels.Color((200),(0),(255)));
pixels.show();
pixels.setPixelColor(4, pixels.Color((200),(0),(255)));
pixels.show();
pixels.setPixelColor(5, pixels.Color((200),(0),(255)));
pixels.show();
pixels.setPixelColor(6, pixels.Color((200),(0),(255)));
pixels.show();
pixels.setPixelColor(7, pixels.Color((200),(0),(255)));
pixels.show();
pixels.setPixelColor(8, pixels.Color((200),(0),(255)));
pixels.show();
pixels.setPixelColor(9, pixels.Color((200),(0),(255)));
pixels.show();
pixels.setPixelColor(10, pixels.Color((200),(0),(255)));
pixels.show();
pixels.setPixelColor(11, pixels.Color((200),(0),(255)));
pixels.show();
pixels.setPixelColor(12, pixels.Color((200),(0),(255)));
pixels.show();
pixels.setPixelColor(13, pixels.Color((200),(0),(255)));
pixels.show();
pixels.setPixelColor(14, pixels.Color((200),(0),(255)));
pixels.show();
pixels.setPixelColor(15, pixels.Color((200),(0),(255)));
pixels.show();

delay(600);

pixels.setPixelColor(0, pixels.Color((0),(0),(0)));
pixels.show();
pixels.setPixelColor(1, pixels.Color((0),(0),(0)));
pixels.show();
pixels.setPixelColor(2, pixels.Color((0),(0),(0)));
pixels.show();
pixels.setPixelColor(3, pixels.Color((0),(0),(0)));
pixels.show();
pixels.setPixelColor(4, pixels.Color((0),(0),(0)));
pixels.show();
pixels.setPixelColor(5, pixels.Color((0),(0),(0)));
pixels.show();
pixels.setPixelColor(6, pixels.Color((0),(0),(0)));
pixels.show();
pixels.setPixelColor(7, pixels.Color((0),(0),(0)));
pixels.show();
pixels.setPixelColor(8, pixels.Color((0),(0),(0)));
pixels.show();
pixels.setPixelColor(9, pixels.Color((0),(0),(0)));
pixels.show();
pixels.setPixelColor(10, pixels.Color((0),(0),(0)));
pixels.show();
pixels.setPixelColor(11, pixels.Color((0),(0),(0)));
pixels.show();
pixels.setPixelColor(12, pixels.Color((0),(0),(0)));
pixels.show();
pixels.setPixelColor(13, pixels.Color((0),(0),(0)));
pixels.show();
pixels.setPixelColor(14, pixels.Color((0),(0),(0)));
pixels.show();
pixels.setPixelColor(15, pixels.Color((0),(0),(0)));
pixels.show();
}

void NeoMed3 (void){
pixels.setPixelColor(0, pixels.Color((220),(0),(0)));
pixels.show();
pixels.setPixelColor(1, pixels.Color((220),(0),(0)));
pixels.show();
pixels.setPixelColor(2, pixels.Color((220),(0),(0)));
pixels.show();
pixels.setPixelColor(3, pixels.Color((220),(0),(0)));
pixels.show();
pixels.setPixelColor(4, pixels.Color((220),(0),(0)));
pixels.show();
pixels.setPixelColor(5, pixels.Color((220),(0),(0)));
pixels.show();
pixels.setPixelColor(6, pixels.Color((220),(0),(0)));
pixels.show();
pixels.setPixelColor(7, pixels.Color((220),(0),(0)));
pixels.show();
pixels.setPixelColor(8, pixels.Color((220),(0),(0)));
pixels.show();
pixels.setPixelColor(9, pixels.Color((220),(0),(0)));
pixels.show();
pixels.setPixelColor(10, pixels.Color((220),(0),(0)));
pixels.show();
pixels.setPixelColor(11, pixels.Color((220),(0),(0)));
pixels.show();
pixels.setPixelColor(12, pixels.Color((220),(0),(0)));
pixels.show();
pixels.setPixelColor(13, pixels.Color((220),(0),(0)));
pixels.show();
pixels.setPixelColor(14, pixels.Color((220),(0),(0)));
pixels.show();
pixels.setPixelColor(15, pixels.Color((220),(0),(0)));
pixels.show();

delay(600);

pixels.setPixelColor(0, pixels.Color((0),(0),(0)));
pixels.show();
pixels.setPixelColor(1, pixels.Color((0),(0),(0)));
pixels.show();
pixels.setPixelColor(2, pixels.Color((0),(0),(0)));
pixels.show();
pixels.setPixelColor(3, pixels.Color((0),(0),(0)));
pixels.show();
pixels.setPixelColor(4, pixels.Color((0),(0),(0)));
pixels.show();
pixels.setPixelColor(5, pixels.Color((0),(0),(0)));
pixels.show();
pixels.setPixelColor(6, pixels.Color((0),(0),(0)));
pixels.show();
pixels.setPixelColor(7, pixels.Color((0),(0),(0)));
pixels.show();
pixels.setPixelColor(8, pixels.Color((0),(0),(0)));
pixels.show();
pixels.setPixelColor(9, pixels.Color((0),(0),(0)));
pixels.show();
pixels.setPixelColor(10, pixels.Color((0),(0),(0)));
pixels.show();
pixels.setPixelColor(11, pixels.Color((0),(0),(0)));
pixels.show();
pixels.setPixelColor(12, pixels.Color((0),(0),(0)));
pixels.show();
pixels.setPixelColor(13, pixels.Color((0),(0),(0)));
pixels.show();
pixels.setPixelColor(14, pixels.Color((0),(0),(0)));
pixels.show();
pixels.setPixelColor(15, pixels.Color((0),(0),(0)));
pixels.show();
}

//--------------------------------------------------------------------------------------------------------------------------------------------------------
void NeoGua (void){
pixels.setPixelColor(1, pixels.Color((200),(100),(255)));
delay(250);
pixels.show();
pixels.setPixelColor(3, pixels.Color((200),(100),(255)));
delay(250);
pixels.show();
pixels.setPixelColor(5, pixels.Color((200),(100),(255)));
delay(250);
pixels.show();
pixels.setPixelColor(7, pixels.Color((200),(100),(255)));
delay(250);
pixels.show();
pixels.setPixelColor(9, pixels.Color((200),(100),(255)));
delay(250);
pixels.show();
pixels.setPixelColor(11, pixels.Color((200),(100),(255)));
delay(250);
pixels.show();
pixels.setPixelColor(13, pixels.Color((200),(100),(255)));
delay(250);
pixels.show();
pixels.setPixelColor(15, pixels.Color((200),(100),(255)));
delay(250);
pixels.show();
delay(600);

pixels.setPixelColor(1, pixels.Color((0),(0),(0)));
delay(250);
pixels.show();
pixels.setPixelColor(3, pixels.Color((0),(0),(0)));
delay(250);
pixels.show();
pixels.setPixelColor(5, pixels.Color((0),(0),(0)));
delay(250);
pixels.show();
pixels.setPixelColor(7, pixels.Color((0),(0),(0)));
delay(250);
pixels.show();
pixels.setPixelColor(9, pixels.Color((0),(0),(0)));
delay(250);
pixels.show();
pixels.setPixelColor(11, pixels.Color((0),(0),(0)));
delay(250);
pixels.show();
pixels.setPixelColor(13, pixels.Color((0),(0),(0)));
delay(250);
pixels.show();
pixels.setPixelColor(15, pixels.Color((0),(0),(0)));
delay(250);
pixels.show();
}

void NeoIni (void){
pixels.setPixelColor(0, pixels.Color((200),(250),(100)));
delay(150);
pixels.show();
pixels.setPixelColor(1, pixels.Color((200),(250),(100)));
delay(150);
pixels.show();
pixels.setPixelColor(2, pixels.Color((200),(250),(100)));
delay(150);
pixels.show();
pixels.setPixelColor(3, pixels.Color((200),(100),(100)));
delay(150);
pixels.show();
pixels.setPixelColor(4, pixels.Color((200),(250),(100)));
delay(150);
pixels.show();
pixels.setPixelColor(5, pixels.Color((200),(100),(100)));
delay(150);
pixels.show();
pixels.setPixelColor(6, pixels.Color((200),(250),(100)));
delay(150);
pixels.show();
pixels.setPixelColor(7, pixels.Color((200),(100),(100)));
delay(150);
pixels.show();
pixels.setPixelColor(8, pixels.Color((200),(250),(100)));
delay(150);
pixels.show();
pixels.setPixelColor(9, pixels.Color((200),(100),(100)));
delay(150);
pixels.show();
pixels.setPixelColor(10, pixels.Color((200),(250),(100)));
delay(150);
pixels.show();
pixels.setPixelColor(11, pixels.Color((200),(100),(100)));
delay(150);
pixels.show();
pixels.setPixelColor(12, pixels.Color((200),(250),(100)));
delay(150);
pixels.show();
pixels.setPixelColor(13, pixels.Color((200),(100),(100)));
delay(150);
pixels.show();
pixels.setPixelColor(14, pixels.Color((200),(250),(100)));
delay(150);
pixels.show();
pixels.setPixelColor(15, pixels.Color((200),(100),(100)));
delay(150);
pixels.show();
delay(600);

pixels.setPixelColor(0, pixels.Color((0),(0),(0)));
delay(250);
pixels.show();
pixels.setPixelColor(1, pixels.Color((0),(0),(0)));
delay(250);
pixels.show();
pixels.setPixelColor(2, pixels.Color((0),(0),(0)));
delay(250);
pixels.show();
pixels.setPixelColor(3, pixels.Color((0),(0),(0)));
delay(250);
pixels.show();
pixels.setPixelColor(4, pixels.Color((0),(0),(0)));
delay(250);
pixels.show();
pixels.setPixelColor(5, pixels.Color((0),(0),(0)));
delay(250);
pixels.show();
pixels.setPixelColor(6, pixels.Color((0),(0),(0)));
delay(250);
pixels.show();
pixels.setPixelColor(7, pixels.Color((0),(0),(0)));
delay(250);
pixels.show();
pixels.setPixelColor(8, pixels.Color((0),(0),(0)));
delay(250);
pixels.show();
pixels.setPixelColor(9, pixels.Color((0),(0),(0)));
delay(250);
pixels.show();
pixels.setPixelColor(10, pixels.Color((0),(0),(0)));
delay(250);
pixels.show();
pixels.setPixelColor(11, pixels.Color((0),(0),(0)));
delay(250);
pixels.show();
pixels.setPixelColor(12, pixels.Color((0),(0),(0)));
delay(250);
pixels.show();
pixels.setPixelColor(13, pixels.Color((0),(0),(0)));
delay(250);
pixels.show();
pixels.setPixelColor(14, pixels.Color((0),(0),(0)));
delay(250);
pixels.show();
pixels.setPixelColor(15, pixels.Color((0),(0),(0)));
delay(250);
pixels.show();
}