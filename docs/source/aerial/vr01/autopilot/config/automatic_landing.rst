Automatic Landing
=================

.. Após a conexão do Lidar ao sistema via PWM, alguns parâmetros do piloto automático devem ser alterados para que ele reconheça o sensor. Esses parâmetros podem ser facilmente alterados através do QGroundControl. São eles: 

After the connection of LIDAR to the system via PWM, some parameters of the autopilot must be changed so that it recognizes the sensor. These parameters can be easily changed using QGroundControl. It's them:

.. mostrar como chegar a esta pagina
..
	* RNG_FND = 5, indica que a conexão ocorre via PWM.
	* RNDFND_MAX_CM = 4000, representa a distância máxima em que o sensor é confiável.
	* RNDFND_STOP_PIN = 55, indica o pino conectado ao sinal de ativação do Lidar. Permite que o dispositivo reinicie o sensor caso ele para de fornecer dados.
	* Os parâmetros RNDFND_SCALING e RNDFND_OFFSET devem ser ajustados de forma a se calibrar o sensor (costumam ser aproximadamente 0 e 1, respectivamente).

* RNG_FND = 5, indicates that the connection occurs via PWM.

* RNDFND_MAX_CM = 4000, represents the maximum distance the sensor is reliable.

* RNDFND_STOP_PIN = 55, indicates the pin connected to the Lidar activation signal. Allows the device to reset the sensor if it stops providing data.

* The parameters RNDFND_SCALING and RNDFND_OFFSET must be adjusted in order to calibrate the sensor (they are usually approximately 0 and 1, respectively).

.. adicionar imagem configurando

.. O sensor pode ser testado pelo QGroundControl, onde as leituras podem ser observadas no campo **Sonar Range**. Após a configuração do sensor, o piloto automático será capaz de pousar a aeronave de forma muito mais rápida e precisa. O pouso ocorre pelo envio do comando **Land** ao controlador, mas para que ele ocorra corretamente deve-se definir a posição da pista de pouso e deve-se ajustar os parâmetros de pouso, como, por exemplo, a velocidade com que o avião deve pousar. 
.. A documentação detalhada sobre pousos automáticos pode ser encontrada em `Automatic Landing`_.

The sensor can be tested by QGroundControl, where readings can be observed in **Sonar Range** tab. After setting up the sensor, the autopilot will be able to land the aircraft much more quickly and accurately. The landing takes place by sending the command **Land** to the controller, but for it to occur correctly, the landing strip position must be defined and the landing parameters must be adjusted, such as the speed at which the airplane must land .

Detailed documentation on automatic landings can be found at `Automatic Landing`_.

.. _Automatic Landing: . http://ardupilot.org/plane/docs/automatic-landing.html.
