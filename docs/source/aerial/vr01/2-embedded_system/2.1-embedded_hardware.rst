Embedded Computer 
=================

Overo WaterStorm
----------------

.. Após considerar as aplicações mais específicas a serem realizadas, o computador embarcado escolhido foi o Overo WaterStorm Computer-On-Module (COM), esse sistema embarcado apresenta um processador DM3730 com arquitetura ARM Cortex-A8 e clock de base do processador de até 1 GHz. Além disso, esse computador está acoplado a uma placa de expansão Tobi que acrescenta ao computador embarcado conexões do tipo display DVI, Ethernet, USB Host, USB OTG, USB console, áudio Stereo e um segmento com 40 pin-headers que podem ser utilizados para a mais diversas funções, como modulação PWM, GPIO, alimentação, conversão analógico digital e comunicação serial.

After considering the most specific applications to be performed, the embedded computer chosen was the Overo WaterStorm Computer-On-Module (COM), this embedded system features a DM3730 processor with ARM Cortex-A8 architecture and a processor base clock of up to 1 GHz. In addition, this computer is attached to a Tobi expansion card that adds DVI display, Ethernet, USB Host, USB OTG, USB console, stereo console and a segment with 40 pin-headers that can be used to the embedded computer. for the most diverse functions, such as PWM modulation, GPIO, power, analog digital conversion and serial communication.

.. figure:: /img/Aerial/System_Gumstix.png
   :align: center

   Gumstix system with Overo WaterSTORM computer, Tobi expansion card and Caspa VL camera

.. Acoplou-se também ao sistema uma câmera Caspa VL, capaz de capturar imagens coloridas com dimensão de 752 x 480 pixels em uma frequência de 60 imagens por segundo. Esses três componentes são produzidos pela empresa Gumstix, fabricante de hardware especializada em computadores pequenos do tipo computador-em-módulo (COM - computer-on-module), muito utilizados para sistemas embarcados.

A Caspa VL camera, capable of capturing color images with dimensions of 752 x 480 pixels at a frequency of 60 images per second, was also attached to the system. These three components are produced by the company Gumstix, a manufacturer of hardware specialized in small computers of the type computer-in-module (COM - Computer-On-Module), widely used for embedded systems.

.. Apesar do tamanho pequeno, a combinação da Overo COM com a placa de extensão TOBI possui o mesmo desempenho do que um computador Linux completo de tamanho normal, maior do que outros sistemas desse tipo encontrados no mercado, como, por exemplo, o computador Raspberry Pi.

Despite its small size, the combination of Overo COM with the TOBI extension card has the same performance as a full-size Linux computer, larger than other systems of this type found on the market, such as the Raspberry Pi computer.

Specifications
--------------

-  **Camera**
   -   Camera Connector: 27-Pin (OMAP ISP)
-  **Mechanical**
   -   Length: 58 mm
   -   Width: 17 mm
-  **Memory**
   -   Flash Memory (NAND): 512
-  **Processor**
   -   Graphics Acceleration: PowerVR SGX530 with OpenGL
   -   Digital Signal Processor: C64x+
   -   Processor: Texas Instruments OMAP3730
   -   Processor Architecture: ARM Cortex-A8
   -   Processor Base Clock: 800 MHz
   -   Processor Max Clock: 1 GHz
-  **Power**
   -   Power Management: Texas Instruments TPS65950
-  **Storage**
   -   Storage Expansion via microSD Card Slot


.. Note:: 
   The complete specifications for the computer, extension card and camera are available in the datasheets below.
   
   * :download:`Datasheet - Overo Waterstorm COM <docs/GUM3703WB-1729092.pdf>`
   * :download:`Manual - Overo Waterstorm COM <docs/manual_overo.pdf>`
   * :download:`Datasheet - Placa de extensão TOBI <docs/PKG30002.pdf>`
   * :download:`Datasheet - Câmera Caspa VL <docs/PKG30009C.pdf>`  


References
----------

   	* PITA, H. C. Desenvolvimento de sistema de comunicação multiplataforma para veículos aéreos de asa fixa. Faculdade de Tecnologia, Universidade de Brasília, 2018.
      
	* `Overo® WaterSTORM COM - Gumstix Store`_ 

.. _Overo® WaterSTORM COM - Gumstix Store: https://store.gumstix.com/overo-waterstorm-com.html