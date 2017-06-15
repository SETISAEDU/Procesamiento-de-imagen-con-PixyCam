# Procesamiento-de-imagen-con-PixyCam

A continuación realizaremos un proyecto enfocado a la visión artificial por medio de procesamiento de imagen en tiempo real utilizando la PixyCam. Realizaremos el reconocimiento de un determinado objeto y con un ARDUINO Mega se procesara la información enviada desde la PixyCam para activar un arreglo  LED´s que indicaran en qué posición se encuentra el objeto.

## ¿Qué es PixyMon?

un software que es capaz de controlar y almacenar los datos de la cámara Pixy para que una vez que la cámara se apague, el ordenador vuelva a volcar los datos y los objetos y colores aprendidos no se pierdan. Además Pixy se puede conectar no sólo a un ordenador sino también a placas como Arduino o Raspberry Pi 2 que pueden funcionar como una placa auxiliar y dar autonomía a la cámara Pixy. 

## Protocolo de comunicación PixyCam

La pixycam puede exportar sus datos mediante varias interfaces de comunicación según el usuario elija a su conveniencia. Es compatible con SPI, I2C, UART, y mediante pines analógicos y digitales. Pixy Es compatible con la comunicación USB 2.0 a través de su conector mini-USB. El protocolo de comunicación puede configurarse mediante las opciones de parámetros en el software PixyMon.

### Pines de conexión según el protoco de comunicación.

`SPI` : Es el puerto de salida por defecto, utiliza 3 cables (pines 1,3 y 4 del conector I/O)

`I2C` : Este es un puerto que utiliza dos líneas, bidireccionales (pines 5 y 9 del conector I/O)

`UART`: Este es el puerto serial (pines 1 y 4 del conector I/O). Pixy recibe datos a través del pin 1 (entrada) y los trasmite a través del pin 4 (salida).

`Salidas digitales y analógicos` : Detecta valores de voltaje entre un valor de 0 a 3.3 V, al igual que valores digitales, detecta como uno lógico los 3.3 V.

En la siguiente figura se representa la distribución de pines de la PixyCam:

## Representanción del reconocimiento del objeto con los indicadores LED

El programa que se cargara al ARDUINO Mega se llama: `PixyCam_Arduino` el cual consiste en procesar las señales adquiridas por la PixCam utilizando la comunicación SPI, para activar un arreglo de LED que indicara la posición donde se encuentra el objeto que la PixyCam está detectando.

El arreglo de los indicadores LED´s forman una matriz de 3x3 que representan las secciones en las que hemos dividido el rango de visualización de la cámara, como se muestra en la siguiente figura:




