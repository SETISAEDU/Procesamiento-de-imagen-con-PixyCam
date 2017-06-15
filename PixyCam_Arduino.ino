// Comunicacion de la PixyCam con microcontrolador
   
#include <SPI.h>  
#include <Pixy.h>

//int pixelsWidth;   //read by the camera
//int pixelsHeight; //read by the camera
int Pos_X;         //Lectura por la camara 
int Pos_Y;         //Lectura por la camara
int pixelsWidth;
int pixelsHeight;
const int LED1 = 2; //Para generar la matriz de LED
const int LED2 = 3;
const int LED3 = 4;
const int LED4 = 5;
const int LED5 = 6;
const int LED6 = 7;
const int LED7 = 8;
const int LED8 = 9;
const int LED9 = 10; 


Pixy pixy;         // Objeto principal de la libreria Pixy

void setup()
{
  pinMode (LED1,OUTPUT);
  pinMode (LED2,OUTPUT);
  pinMode (LED3,OUTPUT);
  pinMode (LED4,OUTPUT);
  pinMode (LED5,OUTPUT);
  pinMode (LED6,OUTPUT);
  pinMode (LED7,OUTPUT);
  pinMode (LED8,OUTPUT);
  pinMode (LED9,OUTPUT);
  Serial.begin(9600);
  Serial.print("Starting...\n");

  pixy.init();      // Inicializa la libreria Pixy
}

void loop()
{ 
  static int i = 0;
  int j;
  uint16_t blocks;
  char buf[32]; 
  
  
  blocks = pixy.getBlocks();      Grabar la lectura del bloque
  
  // If there are detect blocks, print them!
  if (blocks) //Si se ha detectado un bloque se imprimira en pantalla.
  {
    i++;
    
    
    if (i%50==0) //Realiza la impresion cada 50 cuadros para que no genere conflictos la placa Arduino
    {
      sprintf(buf, "Detected %d:\n", blocks);
      Serial.print(buf);
      for (j=0; j<blocks; j++)
      {
        Pos_X = pixy.blocks[j].x;            //Obtiene la posicion en X del objeto
        Pos_Y = pixy.blocks[j].y;            //Obtiene la posicion en Y del objeto
        pixelsWidth = pixy.blocks[j].width;  //Obtiene la anchura del objeto
        pixelsHeight = pixy.blocks[j].height;//Obtiene la altura del objeto
//      Serial.print("Width: ");
//      Serial.print(pixelsWidth);
//      Serial.print(" Height: ");
//      Serial.println(pixelsHeight);
        Serial.print("Post_X: ");          
        Serial.print(Pos_X);                    //Imprime el valor de la posicion X en el monitor
        Serial.print(" Post_Y: ");              //Imprime el valor de la posicion Y en el monitor
        Serial.println(Pos_Y);
      

        
      }
      
      
    }
      if (  (240 <= Pos_X && Pos_X <= 320) && ( 0 <= Pos_Y && Pos_Y <= 50) ) //Definimos el rango de visualizacion para la seccion 1
    {
        digitalWrite(LED1,HIGH);
        digitalWrite(LED2,LOW);
        digitalWrite(LED3,LOW);
        digitalWrite(LED4,LOW);
        digitalWrite(LED5,LOW);
        digitalWrite(LED6,LOW);
        digitalWrite(LED7,LOW);
        digitalWrite(LED8,LOW);
        digitalWrite(LED9,LOW);
        delay(1);
    }
    
     if (  (80 < Pos_X && Pos_X < 240) && ( 0 <= Pos_Y && Pos_Y <= 50 )) //Definimos el rango de visualizacion para la seccion 2
    {
        digitalWrite(LED1,LOW);
        digitalWrite(LED2,HIGH);
        digitalWrite(LED3,LOW);
        digitalWrite(LED4,LOW);
        digitalWrite(LED5,LOW);
        digitalWrite(LED6,LOW);
        digitalWrite(LED7,LOW);
        digitalWrite(LED8,LOW);
        digitalWrite(LED9,LOW);
        delay(1);
    }

     if ( ( 0 <= Pos_X && Pos_X <= 80) && ( 0 <= Pos_Y && Pos_Y <= 50 )) //Definimos el rango de visualizacion para la seccion 3
    {
        digitalWrite(LED1,LOW);
        digitalWrite(LED2,LOW);
        digitalWrite(LED3,HIGH);
        digitalWrite(LED4,LOW);
        digitalWrite(LED5,LOW);
        digitalWrite(LED6,LOW);
        digitalWrite(LED7,LOW);
        digitalWrite(LED8,LOW);
        digitalWrite(LED9,LOW);
        delay(1);
    }
     
     if (  (240 <= Pos_X && Pos_X <= 320) && ( 50 < Pos_Y && Pos_Y < 150) ) //Definimos el rango de visualizacion para la seccion 4
    {
        digitalWrite(LED1,LOW);
        digitalWrite(LED2,LOW);
        digitalWrite(LED3,LOW);
        digitalWrite(LED4,HIGH);
        digitalWrite(LED5,LOW);
        digitalWrite(LED6,LOW);
        digitalWrite(LED7,LOW);
        digitalWrite(LED8,LOW);
        digitalWrite(LED9,LOW);
        delay(1);
    }
    
     if (  (80 < Pos_X && Pos_X < 240) && ( 50 < Pos_Y && Pos_Y < 150) ) //Definimos el rango de visualizacion para la seccion 5
    {
        digitalWrite(LED1,LOW);
        digitalWrite(LED2,LOW);
        digitalWrite(LED3,LOW);
        digitalWrite(LED4,LOW);
        digitalWrite(LED5,HIGH);
        digitalWrite(LED6,LOW);
        digitalWrite(LED7,LOW);
        digitalWrite(LED8,LOW);
        digitalWrite(LED9,LOW);
        delay(1);
    }
    
      if (  (0 <= Pos_X && Pos_X <= 80) && ( 50 <= Pos_Y && Pos_Y <= 150) ) //Definimos el rango de visualizacion para la seccion 6
    {
        digitalWrite(LED1,LOW);
        digitalWrite(LED2,LOW);
        digitalWrite(LED3,LOW);
        digitalWrite(LED4,LOW);
        digitalWrite(LED5,LOW);
        digitalWrite(LED6,HIGH);
        digitalWrite(LED7,LOW);
        digitalWrite(LED8,LOW);
        digitalWrite(LED9,LOW);
        delay(1);
    }

    if (  (240 <= Pos_X && Pos_X <= 320) && ( 150 <= Pos_Y && Pos_Y <= 200) ) //Definimos el rango de visualizacion para la seccion 7
    {
        digitalWrite(LED1,LOW);
        digitalWrite(LED2,LOW);
        digitalWrite(LED3,LOW);
        digitalWrite(LED4,LOW);
        digitalWrite(LED5,LOW);
        digitalWrite(LED6,LOW);
        digitalWrite(LED7,HIGH);
        digitalWrite(LED8,LOW);
        digitalWrite(LED9,LOW);
        delay(1);
    }
    
    if (  (80 < Pos_X && Pos_X < 240) && ( 150 <= Pos_Y && Pos_Y <= 200) ) //Definimos el rango de visualizacion para la seccion 8
    {
        digitalWrite(LED1,LOW);
        digitalWrite(LED2,LOW);
        digitalWrite(LED3,LOW);
        digitalWrite(LED4,LOW);
        digitalWrite(LED5,LOW);
        digitalWrite(LED6,LOW);
        digitalWrite(LED7,LOW);
        digitalWrite(LED8,HIGH);
        digitalWrite(LED9,LOW);
        delay(1);
    }
    
    if (  (0 <= Pos_X && Pos_X <= 80) && ( 150 <= Pos_Y && Pos_Y <= 200) ) //Definimos el rango de visualizacion para la seccion 9
    {
        digitalWrite(LED1,LOW);
        digitalWrite(LED2,LOW);
        digitalWrite(LED3,LOW);
        digitalWrite(LED4,LOW);
        digitalWrite(LED5,LOW);
        digitalWrite(LED6,LOW);
        digitalWrite(LED7,LOW);
        digitalWrite(LED8,LOW);
        digitalWrite(LED9,HIGH);
        delay(1);
    }
  }
  else {                         //Si no esta en niguna de las secciones definidas, se apagan todos los LED's
    digitalWrite(LED1,LOW);
    digitalWrite(LED2,LOW);
    digitalWrite(LED3,LOW);
    digitalWrite(LED4,LOW);
    digitalWrite(LED5,LOW);
    digitalWrite(LED6,LOW);
    digitalWrite(LED7,LOW);
    digitalWrite(LED8,LOW);
    digitalWrite(LED9,LOW);
    delay(1);
    }
  
}
