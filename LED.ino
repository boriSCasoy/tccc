//bibliotecas
#include <MD_Parola.h>
#include <MD_MAX72xx.h>
#include <SPI.h>

//configuração do hardware
#define HARDWARE_TYPE MD_MAX72XX::FC16_HW 
#define MAX_DEVICES 4

//pinagem
#define CLK_PIN   13
#define DATA_PIN  11
#define CS_PIN    10

//construtor
MD_Parola P = MD_Parola(HARDWARE_TYPE, DATA_PIN, CLK_PIN, CS_PIN, MAX_DEVICES);


int a = 0;

/////////////////////////////////////////////////////////////

void setup(void)
{
  P.begin();
  Serial.begin(9600);
  P.print("Hello!");
}

/////////////////////////////////////////////////////////////

void loop(void)
{
  P.setIntensity(a);
  a ++;
  if(a > 40)
    a = 0;
  Serial.println(a);
  delay(1000);
}

/////////////////////////////////////////////////////////////



// setSpeed(int) - tempo da pausa entre os frames, de 0 a 100
// P.setIntensity(a);
// Serial.println(a);