  /* 
  TECHMAKE DEMOS - LCDs (Liquid Crystal Displays)
  
  * Descripcion del DEMO:
    * Ejemplos de animacion, texto y caracteres especiales con una pantalla LCD + Arduino.
  
  * Material Utilizado:
    * (1) Pantalla LCD: http://www.techmake.com/productos/lcds.html
    * (1) Potenciometro: http://www.techmake.com/productos/components/potenciometros.html
    * (20) Cables Jumper Wire M/M de 20cm: http://www.techmake.com/00043.html
    * (1) Arduino Uno R3: http://www.techmake.com/00001.html
  
  * Conexiones:
  
     * LCD
        * 1 = GND
        * 2 = 5V
        * 3 = Pin central del potenciometro (para ajustar el contraste)
        * 4 = Arduino Pin Digital 12
        * 5 = GND
        * 6 = Arduino Pin Digital 11
        * 11 = Arduino Pin Digital 5
        * 12 = Arduino Pin Digital 4
        * 13 = Arduino Pin Digital 3
        * 14 = Arduino Pin Digital 2
        * 15 = 5V
        * 16 = GND
    
Este codigo fue creado por TechMake Electronics,
con mucha ayuda de la comunidad Arduino, SparkFun y Jeremy Blum.
Este codigo es completamente gratuito para cualquier uso.
Visita http://www.techmake.com para mas DEMOS y tutoriales.
Visita http://www.arduino.cc para aprender mas sobre el Arduino.
Visita http://www.sparkfun.com para conocer todo de SparkFun.

Creado el 08/May/2015 por David S. Gonzalez P.
*/

// Cargar la libreria LiquidCrystal
// esta nos habilitara los comandos de interfaz para el LCD: 

#include <LiquidCrystal.h>

// Inicializa la libreria con los pines que nosotros utilizamos.
// (Nota: puedes utilizar diferentes pines si es necesario.)
// Ve a http://arduino.cc/en/Reference/LiquidCrystal
// para mas informacion. 

LiquidCrystal lcd(12,11,5,4,3,2);

// Creamos los arreglos de byte en binario

byte c1[8] = {B10000,B10000,B10000,B10000,B10000,B10000,B10000};
byte c2[8] = {B11000,B11000,B11000,B11000,B11000,B11000,B11000};
byte c3[8] = {B11100,B11100,B11100,B11100,B11100,B11100,B11100};
byte c4[8] = {B11110,B11110,B11110,B11110,B11110,B11110,B11110};
byte c5[8] = {B11111,B11111,B11111,B11111,B11111,B11111,B11111};
byte cruz[8] = {B00000,B00100,B01110,B00100,B00100,B00100,B00000};

int modo = 0; // para que cambie la animacion
int t = 150; // tiempo personalizado

void setup() 
{
  Serial.begin(9600);
  
  // La libreria LiquidCrystal puede utilizarse con diferentes tamanos de LCDs.
  // Nosotros utilizamos uno que es de 2 lineas de 16 caracteres,
  // asi que le informaremos de eso a la libreria:
  
  lcd.begin(16,2);
  
  // Los datos enviados al display se quedaran ahi hasta que se sobreescribe 
  // o es cortada la alimentacion. Este puede ser un problema cuando cargues 
  // un nuevo sketch al Arduino pero los antiguos datos permanecen en el display.
  // Limpiemos el LCD utilizando el comando clear() de la libreria LiquidCrystal:
  
  lcd.clear();
  
  // Se despliega el primer mensaje
  // En las pantallas LCD existe un cursor igual que en la computadora
  // solo que por default, este es invisible. Puedes hacerlo visible
  // con otros compandos de la libreria si asi lo deseas.
  // Cuando se energiza el display, el cursor invisible comienza en
  // el primer renglon y primer columna.
  
  lcd.print("techmake.com");
  
  // Caracteres personalizados (nombre, arreglo de byte)
  
  lcd.createChar(0, c1);
  lcd.createChar(1, c2);
  lcd.createChar(2, c3);
  lcd.createChar(3, c4);
  lcd.createChar(4, c5);
  lcd.createChar(5, cruz);
}

void loop() 
{  
  switch (modo)
  {
    case 0:  // Barra de progreso por pixeles
      lcd.setCursor(0,1);
      lcd.print("                ");
      
      // Barra de progreso
      for (int i = 0; i<16; i++)
      {
        for (int j = 0; j<5; j++)
        {
          lcd.setCursor(i,1);
          lcd.write(j);
          delay(25);
        }
      }
      modo++;
      break;
      
    case 1:  // Hola techmakers!
      lcd.setCursor(0,1);
      lcd.print("                ");
      
      lcd.setCursor(0,1);     
      lcd.print("H               ");
      delay(t);
      lcd.setCursor(0,1);
      lcd.print("Ho              ");
      delay(t);
      lcd.setCursor(0,1);
      lcd.print("Hol             ");
      delay(t);
      lcd.setCursor(0,1);
      lcd.print("Hola            ");
      delay(t);
      lcd.setCursor(0,1);
      lcd.print("Hola            ");
      delay(t);
      lcd.setCursor(0,1);
      lcd.print("Hola t          ");
      delay(t);
      lcd.setCursor(0,1);
      lcd.print("Hola te         ");
      delay(t);
      lcd.setCursor(0,1);
      lcd.print("Hola tec        ");
      delay(t);
      lcd.setCursor(0,1);
      lcd.print("Hola tech       ");
      delay(t);
      lcd.setCursor(0,1);
      lcd.print("Hola techm      ");
      delay(t);
      lcd.setCursor(0,1);
      lcd.print("Hola techma     ");
      delay(t);
      lcd.setCursor(0,1);
      lcd.print("Hola techmak    ");
      delay(t);
      lcd.setCursor(0,1);
      lcd.print("Hola techmake   ");
      delay(t);
      lcd.setCursor(0,1);
      lcd.print("Hola techmaker  ");
      delay(t);
      lcd.setCursor(0,1);
      lcd.print("Hola techmakers ");
      delay(t);
      lcd.setCursor(0,1);
      lcd.print("Hola techmakers!");
      delay(1000);
      modo++;
      break;    
      
    case 2:  // Cruz parpadeando
      lcd.setCursor(0,1);
      lcd.print("                ");
      
      for (int repite = 0; repite < 4; repite++)
      {
        for (int i = 0; i<16; i++)
        {
          lcd.setCursor(i,1);
          lcd.write(5);
        }
        delay(500);
        lcd.setCursor(0,1);
        lcd.print("                ");
        delay(500);
      }
      modo=0;
      break;  
  }  
}
