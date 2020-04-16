Connections
==========

.. A imagem abaixo apresenta as conexões dos sensores e demais itens inclusos no Pixhawk. Cada parte será analisada com mais detalhes nas seções a seguir.

The image below shows the connections of the sensors and other items included in the Pixhawk. Each part will be analyzed in more detail in the following sections.

.. Adicionar imagem das conexões do pixhawk (não esquecer do airspeed)


Buzzer and Safety Switch
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. A campainha fornece sinais sonoros que indicam a situação do VANT. Enquanto o interruptor atua na segurança da aeronave, bloqueando e desbloqueando os motores.

The buzzer provides audible signals that indicate the situation of the UAV. While the switch operates in the safety of the aircraft, locking and unlocking the engines.

.. Note::
   The safety switch is activated by default and when activated, it does not allow flight, blocking the engines. To disable safe mode, press and hold the switch for 1 second. You can activate safe mode again by pressing the switch.

.. Para conectar a campainha e o interruptor de segurança (itens obrigatórios), basta liga-lós ao Pixhawk como mostrado abaixo.

To connect the buzzer and the safety switch (required items), simply connect them to the Pixhawk as shown below.

.. image:: /img/Aerial/px1_buzzer_and_safety_switch.jpg
    :align: center

Slitter I2C
~~~~~~~~~~~~

.. O *slitter* I2C expande a quantidade de portas I2C permitindo a conexão de até quatro periféricos ao Piwhawk. Utilize um cabo de 4 fios para conectar o *slitter* I2C e para alimentar uma bússola externa, um display LED, um sensor de velocidade do ar digital e/ou qualquer outro periférico compatível ao veículo.

The I2C slitter expands the number of I2C ports allowing the connection of up to four peripherals to the Piwhawk. Use a 4-wire cable to connect the I2C slitter and to power an external compass, an LED display, a digital air speed sensor and/or any other peripheral compatible to the vehicle.

Airspeed Sensor
~~~~~~~~~~~~~~~~~~~

Em edição...

.. verificar no laboratorio 

GPS + Compass 
~~~~~~~~~~~~~~

.. O GPS, outro dispositivo obrigatório, deve ser conectado à porta GPS (6 pinos) usando o cabo de 6 fios fornecidos no kit. A conexão da bússola é opcional, porém recomendamos fortemente sua utilização. Para conecta-lá, ligue um cabo de 4 fios a uma porta I2C do *slitter* I2C, como mostrado abaixo.

The GPS, another indispensable device, must be connected to the GPS port (6-pin) using the 6-wire cable provided in the kit.  The compass connection is optional, but strongly recommend its use. To connect it, connect a 4-wire cable to an I2C port on the I2C slitter, as shown below.

.. adicionar imagem do GPS/bussola

.. Note::
   The GPS/Compass should be mounted on the aircraft's chassis as far away from other electronic components as possible, with the indicator arrow facing forward and as aligned as possible with the Pixhawk.

Radio Control (RC)
~~~~~~~~~~~~~~~~~~

.. O sistema de rádio controle (RC) é necessário caso deseje controlar manualmente seu veículo, dado que o Pixhawk não requer um sistema de rádio para modos de voo autônomo.

The radio control (RC) system is necessary if you want to manually control your vehicle, as the Pixhawk does not require a radio system for autonomous flight modes.

.. Para conectar o sistema de rádio controle, será necessário selecionar um transmissor/receptor compatível e depois vinculá-lo para que eles se comuniquem. 

To connect the radio control system, is necessary need to select a compatible transmitter/receiver and then link it up so that they can communicate.

.. Tip::
   Read the instructions that came with your transmitter/receiver.

.. As instruções a seguir mostram como conectar os diferentes tipos de receptores ao Pixhawk:

The following instructions show how to connect the different types of receivers to the Pixhawk:

* Spektrum and DSM receivers connect to the SPKT/DSM input.

.. image:: /img/Aerial/pixhawk_3dr_receiver_spektrum.jpg

* PPM-SUM and S.BUS receivers connect to ground, power and RC signal pins, as shown. 

.. image:: /img/Aerial/pixhawk_3dr_receiver_ppm_sbus.jpg

* The PPM and PWM receivers that have an individual wire for each channel must connect to the RC port via a PPM encoder (PPM-Sum receivers use a single signal wire for all channels).

For more information on selecting a radio system, receiver compatibility, and connecting your transmitter and receiver pair, see: `Remote control transmitters and receivers`_.

.. _Remote control transmitters and receivers: https://docs.px4.io/v1.9.0/en/getting_started/rc_transmitter_receiver.html

Telemetry 
~~~~~~~~~~~

.. Os modens de telemetria podem ser usados ​​para comunicar e controlar um veículo em voo a partir de uma estação terrestre (por exemplo, você pode direcionar o VANT para uma posição específica ou carregar uma nova missão). Um modem deve ser conectado ao seu veículo, como mostrado abaixo. O outro modem deverá ser conectado ao computador da estação terrestre ou dispositivo móvel (geralmente por uma porta USB).

Telemetry modems can be used to communicate and control a vehicle in flight from an ground station (for example, you can direct the UAV to a specific position or load a new mission). A modem must be connected to your vehicle, as shown below. Another modem must be connected to the ground station computer or mobile device (usually via a USB port).

.. image:: /img/Aerial/pixhawk_3dr_telemetry_radio.jpg

Power Module
~~~~~~~~~~~~~~~~~~

.. O módulo de energia (*Power module* - PM) fornece energia ao controlador de voo da bateria e também envia informações sobre a corrente analógica e a tensão fornecida pelo módulo (incluindo a energia do controlador de voo e dos motores, etc.).

The **Power module** (PM) supplies power to the battery flight controller and also sends information about the analog current and voltage supplied by the module (including power to the flight controller and motors, etc.).

.. A saída do modulo de energia (PM) deve ser conectada à porta **POWER** do Pixhawk usando um cabo de 6 fios, como apresentado na imagem. A entrada do modulo deverá ser conectada a uma bateria de LiPo, enquanto a saída principal será responsável por fornecer energia aos ESCs e motores da aeronave (possivelmente através de uma placa de distribuição de energia, a depender da aeronave).

The output of the power module (PM) must be connected to the Pixhawk ** POWER ** port using a 6-wire cable, as shown in the image. The input module must be connected to a battery Po, while the main output will be responsible for supplying power to the ESCs and the aircraft engine (possibly through a power distribution board, depending on the aircraft).

.. image:: /img/Aerial/pixhawk_3dr_power_module.jpg

Distance Sensor
~~~~~~~~~~~~~~~~~~~~

.. O Pixhawk suporta vários sensores de distância diferentes, incluindo os Lidars (que usam lasers ou raios infravermelhos para medições de distância) e Sonars (que utilizam som ultrassônico), e também incluem os buscadores de alcance LED Maxbotix Sonar e Pulsed Light. Dessa forma, a instalação varia de dispositivo para dispositivo. Mais informações a respeito da configuração dos sensores pode ser visualizada em `Rangefinders`_.

Pixhawk supports several different distance sensors, including Lidars (which use lasers or infrared rays for distance measurements) and Sonars (which use ultrasonic waves), and also include the Maxbotix Sonar and Pulsed Light LED range finders. Therefore, the installation varies from device to device. More information about the sensor configuration can be seen in `Rangefinders`_.

.. _Rangefinders: https://ardupilot.org/copter/docs/common-rangefinder-landingpage.html#rangefinders-landing-page

.. figure:: /img/Aerial/RangeFinder_LandingPageImage_4.jpg
   :align: center

   Example of some compatible distance sensors

.. explicar pq escolheu o lidar

.. Para implementar o projeto, escolheu-se o sensor Lidar para habilitar a função de pouso automático devido sua maior precisão em relação aos demais. O sensor lidar pode ser conectado ao Pixhawk de duas formas, através do protocolo I2C na porta I2C (ou I2C *slitter*) ou por *pulse-width-modulation* (PWM) na trilha PWM. 

To implement the project, the Lidar sensor was chosen to enable the automatic landing function due to its greater accuracy compared to the others. Lidar sensor can be connected to the Pixhawk in two ways, via the I2C protocol on the I2C port (or I2C slitter) or by pulse-width-modulation (PWM) on the PWM track.

.. De acordo com a documentação do Pixhawk, o lidar utilizado apresenta problemas de interferência com outros dispositivos quando conectado na porta I2C. Assim, escolheu-se a conexão por PWM. Um diagrama de conexão pode ser vista na tabela abaixo e o esquema de montagem pode ser visto na figura a seguir, onde o valor do resistor pode variar entre 200Ω e 1kΩ [1]_.

According to the Pixhawk documentation, the Lidar used presents interference problems with other devices when connected to the I2C port. Thus, the PWM connection was chosen. A connection diagram can be seen in the table below and the assembly diagram can be seen in the following figure, where the value of the resistor can vary between 200Ω and 1kΩ [1] _.

.. table:: Connection diagram between Lidar and Pixhawk

	===================    ======================================
	 Sinal LIDAR-Lite              Sinal Pixhawk            
	===================    ======================================
		J1                      CH6 Out - V+            
		J2              CH6 Out - Signal (sinal interno 55) 
		J3              CH5 Out - Signal (sinal interno 54) 
		J4                                             
		J5                                             
		J6                    Ch6 Out - Ground         
	===================    ======================================

.. figure:: /img/Aerial/pixhawk_lidar_connection.png
    :align: center
    
.. Mais detalhes sobre a conexão podem ser encontrados em `LIDAR-Lite Rangefinder`_.

More details about the connection can be found in `LIDAR-Lite Rangefinder`_.

.. _LIDAR-Lite Rangefinder: https://ardupilot.org/copter/docs/common-rangefinder-lidarlite.html?highlight=lidar#lidar-lite-rangefinder


More information
-----------------

* `Pixhawk Wiring Quick Start - PX4 User Guide`_
.. _Pixhawk Wiring Quick Start - PX4 User Guide: https://docs.px4.io/v1.9.0/en/assembly/quick_start_pixhawk.html

* `Basic Assembly - PX4 User Guide`_
.. _Basic Assembly - PX4 User Guide: https://docs.px4.io/v1.9.0/en/assembly/

* `Pixhawk Series - PX4 User Guide`_
.. _Pixhawk Series - PX4 User Guide: https://docs.px4.io/v1.9.0/en/flight_controller/pixhawk_series.html

* `Peripheral Hardware - Ardupilot Docs`_
.. _Peripheral Hardware - Ardupilot Docs: https://ardupilot.org/copter/docs/common-optional-hardware.html

.. References

.. [1] Eduardo Moura Cirilo Rocha. 2017. Desenvolvimento de um sistema com veículos aéreos não-tripulados autônomos, Universidade de Brasília, Brasil





