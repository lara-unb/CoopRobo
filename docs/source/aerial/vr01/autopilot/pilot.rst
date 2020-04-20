Autopilot
=================

.. Colocar a logo do PX4 aqui

.. https://ardupilot.org/copter/docs/introduction.html#
.. https://docs.px4.io/master/en/getting_started/

.. Note::
   This topic consists of a summary of the information available on the page `Getting Started - PX4`_. 
.. _Getting Started - PX4: https://docs.px4.io/v1.9.0/en/getting_started/px4_basic_concepts.html

Introduction
~~~~~~~~~~~~

.. O PX4 é um piloto automático profissional de código aberto, desenvolvido tanto pelo meio industrial quanto pela classe acadêmica e apoiado pela comunidade mundial ativa. O PX4 pode ser executado em várias placas controladoras de voo. Merecendo destaque os controladores de voo de *hardware* aberto da série `PixHawk`_, executando o PX4 no `NuttX OS`_ [1]_.

PX4 is the professional open source autopilot, developed by both world-class developers from industry and academia, and supported by the active world wide community. The PX4 can run on multiple flight controll boards. Deserving highlight flight open hardware controllers of the `PixHawk`_ series, running PX4 on `NuttX OS`_ [1]_.  

.. Dadas as opções de placas controladoras de voo disponíveis no mercado, escolheu-se o Pixhawk1 como piloto automático por seu melhor custo beneficio para o projeto.

Given the options available on the market, Pixhawk 1 was chosen as an autopilot for its best cost benefit for the project.


.. _Pixhawk: https://pixhawk.org
.. _NuttX OS: https://nuttx.apache.org/

.. Adicionar imagem do pixhawk do lado

.. O Pixhawk atua em diversos tipos de veículos, desde drones de corrida e carga a veículos terrestres e submersíveis. Neste artigo, focaremos na aplicação em aeronaves, onde o Pixhawk atua como um controlador de voo de uso geral, responsável pela aquisição, condicionamento e processamento de sinais provenientes dos sensores da aeronave e pelo controle dos atuadores da aeronave. 

The Pixhawk operate in several types of vehicle, from racing drones and cargo to land and submersible vehicles. In this article we will focus on aircraft application, where the Pixhawk operate as a general use flight controller, responsible for the acquisition, conditioning and processing of signals from the aircraft's sensors and for controlling the aircraft's actuators.


.. Ele oferece um ambiente de desenvolvimento compatível com sistemas Unix e Linux, facilitando o desenvolvimento de aplicações de software. O sistema Pixhawk possui capacidade de *multithreading*, ou seja, pode executar várias tarefas simultaneamente sem que uma interfira na outra através do compartilhamento de recursos do processo. Além disso, ele possui funções de piloto automático integrado com logs detalhados de missões e comportamento de voo [2]_.

Pixhawk offers a development environment compatible with Unix and Linux systems, favoring the development of software applications. The Pixhawk system has `multithreading`_ capabilities, that is, it can perform several tasks simultaneously without interfering with the other through the sharing of process resources. Moreover, it has integrated autopilot functions with detailed logs missions and flight behavior [2]_.

.. _multithreading: https://en.wikipedia.org/wiki/Multithreading_(computer_architecture)

.. Dado as opções disponíveis no mercado, escolheu-se o Pixhawk1 como piloto automático por seu melhor custo beneficio para o projeto.

Given the options available on the market, Pixhawk 1 was chosen as an autopilot for its best cost benefit for the project.

Basic Concepts
~~~~~~~~~~~~~~~

.. Adicionar https://docs.px4.io/v1.9.0/en/getting_started/

.. Este tópico apresenta alguns conceitos básicos a respeito de veículos aéreos não tripulados e o uso da plataforma PX4. 

This topic introduces some basics concepts about unmanned aerial vehicles (UAV) and the use of PX4 platform.


Unmanned Aerial Vehicle (UAV or drone)
----------------------------------------

.. Um VANT é todo e qualquer tipo de aeronave que pode ser controlada nos 3 eixos de liberdade e não necessita de pilotos embarcados para ser guiado, podendo ser controlado remotamente ou autonomamente.

A UAV is any types of aircraft that can be controlled on the 3 axes of freedom and do not need a pilot on board to be guided, being able to be controlled remotely or autonomously.

.. O “cérebro” de um drone é chamado de piloto automático, um instrumento responsavel por controlar a trajetória de voo da aeronave. Referindo-se a VANTs, o piloto automático consiste em um *software* de controle de voo sendo executado em um *hardware* especifico para a mesma função.

The "brain" of a drone is called autopilot, an instrument responsible for controlling the aircraft's flight path. Referring to UAVs, the autopilot consists of flight control software running on specific hardware for the same function.

Ground Control Station (GCS)
-----------------------------

.. Uma **Estação de Controle em Solo** (ECS), do inglês *Ground Control Station* (GCS), é uma plataforma de controle, normalmente uma aplicação de *software* sendo executada em um computador em solo, que se comunica com os VANTs por telemetria sem fio e provê aos operadores humanos o controle das aeronaves.

A Ground Control Station (GCS) is a control platform, usually a software application running on a computer on the ground, which communicates with UAVs for wireless telemetry and provides human operators control of the aircraft.

.. A estação em solo entrega ao controlador diversos dados em tempo real sobre o desempenho e posição dos VANTs e pode até servir como um "cockpit virtual", fornecendo muitos dos mesmos instrumentos que um piloto teria caso estivesse pilotando um avião. Contudo, um *software* de Controle em solo é normalmente utilizado para o planejamento, envio das missões de voo e definição de parâmetros de voo.

The ground station delivers to the controller several data in real time on the performance and position of UAVs and can even serve as a "virtual cockpit", providing many of the same instruments that a pilot would have if he were flying an airplane. However, Ground Control  software is normally used for planning, uploading flight missions and defining flight parameters.

.. Existem mais de dez estações de controle em solo diferentes. Na área de controle de VANTs, os principais controladores são Mission Planner, APM Planner 2, MAVProxy, QGroundControl e UgCS. Para Tablet/Smartphone, há Tower (DroidPlanner 3), MAVPilot, AndroPilot e SidePilot. [4]_

There are more than ten different ground control stations. In the area of UAV control, the main controllers are Mission Planner, APM Planner 2, MAVProxy, QGroundControl e UgCS. For Tablet / Smartphone, there is Tower (DroidPlanner 3), MAVPilot, AndroPilot e SidePilot. [4]_

.. https://ardupilot.org/copter/docs/common-choosing-a-ground-station.html#overview

Dronecode Platform
-------------------

.. O PX4 faz parte da `Dronecode Plataform`_, uma plataforma completa para desenvolvimento de drones, sob uma licença de código aberto a comunidade. Incluindo, entre outras, os controladores `PX4`_, a estação de controle terrestre `QGroundControl`_, o `Dronecode SDK`_ e o `Dronecode Camera Manager`_. [4]_

PX4 is part of the `Dronecode Plataform`_, a complete platform for drone development, under an open source license the community. It includes, among other things, the `PX4`_ flight stack, `QGroundControl`_ ground control station, the `Dronecode SDK`_ and the `Dronecode Camera Manager`_. [3]_


.. _Dronecode Plataform: https://www.dronecode.org/
.. _PX4: https://px4.io/
.. _QGroundControl: http://qgroundcontrol.com/
.. _Dronecode SDK: https://www.dronecode.org/sdk/
.. _Dronecode Camera Manager: https://camera-manager.dronecode.org/en/


Sensors
~~~~~~~~

.. Os sistemas baseados em PX4 utilizam diversos sensores para determinar o estado do veículo (sendo estes essenciais para a estabilização e para possibilitar o controle autônomo). Os estados do veículo incluem: posição, direção, velocidade, velocidade do ar, orientação (atitude), taxas de rotação em diferentes direções, nível da bateria, etc.

The PX4 based system uses several sensors to determine vehicle state (these being essential for stabilization and to enable autonomous control). The vehicle states include: position, heading, speed, airspeed, orientation (attitude), rates of rotation in different directions, battery level, etc.

.. O sistema requer minimamente um giroscópio, acelerômetro, magnetômetro (bússola), barômetro e um sensor de velocidade do ar para o caso de asas fixas (caso do projeto). É necessário ainda um GPS ou outro sistema de posicionamento para ativar todos os modos automáticos e alguns modos assistidos. 

The system minimally requires a gyroscope, accelerometer, magnetometer (compass), barometer and an airspeed sensor for the case of fixed wing (project case). A GPS or other positioning system is also required to activate all automatic modes and some assisted modes.

.. Os controladores da série Pixhawk já vem com um conjunto mínimo de sensores incorporados. Sensores adicionais/externos podem ser conectados ao controlador.

Pixhawk series flight controllers come with a minimum set of sensors incorporated. Additional/external sensors can be connected to the controller.

GPS & Compass
-------------

.. O PX4 suporta vários receptores e bússolas (magnetômetros) do Sistema de Navegação Global por Satélite (Global Navigation Satellite System - GNSS). Além de suportar os `Receptores GPS Real-time Kinematic`_ (RTK), otimizando os sistemas de GPS a uma precisão em nível de centímetros. 

The PX4 supports several receivers and compasses (magnetometers) of the Global Navigation Satellite System (GNSS). It also supports Real Time Kinematic (RTK) GPS Receivers, optimizing GPS systems to centimeter level accuracy.

..
   .. Note:: 
   Os controladores da série Pixhawk incluem uma bússola *interna*, porém recomendamos o uso de um módulo externo de bússola + GPS (*compass/GPS*), sendo este montado o mais longe possível dos cabos de alimentação dos motores para reduzir a interferência eletromagnética.

.. Note:: 
   Pixhawk series controllers include an *internal* compass, but we recommend using an external Compass + GPS module, which is mounted as far as possible from power supply lines to reduce electromagnetic interference.

.. O PX4 suporta a conecção de até 4 magnetômetros internos ou externos, embora apenas um seja realmente utilizado para orientação. O sistema escolhe de forma automática a melhor bússola disponível com base em sua prioridade (bússolas externas têm maior prioridade). Se a bússola principal vier a falhar durante o voo, o sistema seleciona a aproxima maior prioridade. Caso a falha ocorra antes do voo, o carregamento plano de voo será negado.

The PX4 supports the connection of up to 4 internal or external magnetometers, although only one will actually be used as a heading source. The system automatically chooses the best available compass based on their internal priority (external magnetometers have a higher priority). If the primary compass fails in-flight, it will failover to the next one. If it fails before flight, arming will be denied.

.. Mais informações e a lista de GPS/bússola suportados pode ser encontradas em `GPS/Compass`_.

More information and the list of supported GPS/Compass can be found at `GPS/Compass`_.

.. adicionar imagem do gps

.. _Receptores GPS Real-time Kinematic: https://docs.px4.io/v1.9.0/en/gps_compass/rtk_gps.html
.. _GPS/Compass: https://docs.px4.io/v1.9.0/en/gps_compass/


Airspeed
---------
..
   .. Tip::
   Os sensores de velocidade do ar são altamente recomendados para o funcionamento seguro de um VANT asa fixa ou VTOL (*Vertical Take-Off and Landing* - Decolagem e Aterragem Vertical).

.. Tip::
   Airspeed sensors are highly recommended for the safe operation of a fixed wing UAV or VTOL (Vertical Take-Off and Landing).


.. O voo de um VANT asa fixa depende da velocidade do ar, já que é este que garante sua sustentação em voo e não a velocidade em relação ao solo. O piloto automático não possui outros meios para detectar estol (perda de sustentação da aeronave em voo), por este motivo os sensores de velocidade do ar são muito importantes.

The flight of a fixed wing UAV depends on the airspeed, since this guarantees its support in flight and not  the speed in relation to the ground. The autopilot has no other means to detect stall (loss of lift of the aircraft), for this reason air speed sensors are highly recommended.

.. Mais informações e a lista de sensores de velocidade do ar suportados pode ser encontradas em `Airspeed sensors`_.

More information and the list of supported Airspeed sensors can be found at `Airspeed sensors`_.

.. _Airspeed sensors: https://docs.px4.io/v1.9.0/en/sensor/airspeed.html
.. adicionar imagem do sensor


Distance (telemeter)
-----------------------

.. Os sensores de distância fornecem medição de distância em tempo real. Podendo ser óptico, quando baseado em um mecanismo de focalização, ou ultrassônico (ecotelêmetro ou telêmetro acústico), quando utiliza reflexões sonoras. Eles são utilizados para melhorar a precisão do pouso, prevenir colisões, acompanhar o terreno, aviso de limites de altura, etc.

Distance sensors provide real-time distance measurement. It can be optical, when based on a focusing mechanism, or ultrasonic (ecotelemeter or acoustic rangefinder), when using sound reflections. They are used for improved landing behaviour, terrain following, collision prevention, warning of regulatory height limits, etc.

.. O PX4 suporta uma grande variedade de sensores de distância, usando tecnologias diferentes e oferecendo suporte a diferentes recursos. Mais informações e a lista de sensores de distância suportados pode ser encontrada em `Distance sensors`_.

The PX4 supports a wide variety of distance sensors, using different technologies and supporting different features. More information and the list of supported distance sensors can be found at More information and the list of supported distance sensors can be found at `Distance sensors`_.

.. _Distance sensors: https://docs.px4.io/v1.9.0/en/sensor/rangefinders.html
.. adicionar imagem do sensor


Optica Flow
-------------

.. O PX4Flow é uma câmera inteligente de fluxo óptico com um sensor de sonar embutido que pode rastrear movimentos. O PX4 combina os dados do sensor com as informações de outras fontes de posição (GPS, por exemplo) para fixar uma posição de forma mais precisa. Este sensor pode ser utilizado em ambientes fechados, quando não há sinal de GPS disponível.

PX4Flow is an optical flow smart camera that can track motion, and has as integrated sonar sensor. PX4 blends the sensor output with information from other position sources (e.g. GPS) to provide a more accurate position lock. This sensor can be used indoors, when no GPS signal is available.

.. A maior parte de suas aplicações é direcionada a aeronaves de asas rotativas.

Most of its applications are directed to rotary-wing aircraft.

Pixhawk Specifications
~~~~~~~~~~~~~~~~~~~~~~~~~~~

-  **Processor**

   -  32-bit ARM Cortex M4 core with FPU
   -  168 Mhz/256 KB RAM/2 MB Flash
   -  32-bit failsafe co-processor

-  **Sensors**

   -  MPU6000 as main accel and gyro
   -  ST Micro 16-bit gyroscope
   -  ST Micro 14-bit accelerometer/compass (magnetometer)
   -  MEAS barometer

-  **Power**

   -  Ideal diode controller with automatic failover
   -  Servo rail high-power (7 V) and high-current ready
   -  All peripheral outputs over-current protected, all inputs ESD
      protected

-  **Interface**

   -  5x UART serial ports, 1 high-power capable, 2 with HW flow
      control
   -  Spektrum DSM/DSM2/DSM-X Satellite input
   -  Futaba S.BUS input (output not yet implemented)
   -  PPM sum signal
   -  RSSI (PWM or voltage) input
   -  I2C, SPI, 2x CAN, USB
   -  3.3V and 6.6V ADC inputs

-  **Dimensions**

   -  Weight 38 g (1.3 oz)
   -  Width 50 mm (2.0”)
   -  Height 15.5 mm (.6”)
   -  Length 81.5 mm (3.2”)
   
-  **Included items**

   -  1 x SanDisk Ultra micro SD Card (8GB)
   -  1 x MRC0225- Cable [3-Pins DF-13] to Switch+LED
   -  1 x MRC0224- Cable [2-Pins DF-13] to Buzzer
   -  1 x I2C Splitter
   -  2 x MRC0213- Cable [6-Pins JST-GH] to [6-Pins DF-13], (Telemetry Radio, Power module and Extra)
   -  1 x MRC0216- Cable [6-Pins DF-13] to [6-Pins DF-13], (For legacy products)
   -  4 x Damping Foams
   -  3 x Decals "APM Rover", "APM Copter" and "APM Plane"

More information
-----------------
* `Dronecode Platform, Basic Concepts, PX4 Autopilot User Guide`_. docs.px4.io

.. _Dronecode Platform, Basic Concepts, PX4 Autopilot User Guide: https://docs.px4.io/v1.9.0/en/getting_started/px4_basic_concepts.html#dronecode

 .. References

.. [1] `PX4 Autopilot User Guide`_. docs.px4.io

.. [2] Para mais informações a respeito de `Multithreading (arquitetura computacional)`_.

.. [3] Eduardo Moura Cirilo Rocha. 2017. Desenvolvimento de um sistema com veículos aéreos não-tripulados autônomos, Universidade de Brasília, Brasil.

.. [4] `Choosing a Ground Station - Conter documentation`_. ardupilot.org 

.. _PX4 Autopilot User Guide: https://docs.px4.io/v1.9.0/en/
.. _Multithreading (arquitetura computacional): https://pt.wikipedia.org/wiki/Multitarefa
.. _Choosing a Ground Station - Conter documentation: https://ardupilot.org/copter/docs/common-choosing-a-ground-station.html#choosing-a-ground-station

