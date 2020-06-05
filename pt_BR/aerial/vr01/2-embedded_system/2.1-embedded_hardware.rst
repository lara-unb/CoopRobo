Computador Embarcado 
====================

Overo WaterStorm
----------------

Após considerar as aplicações mais específicas a serem realizadas, o computador embarcado escolhido foi o Overo WaterStorm Computer-On-Module (COM), esse sistema embarcado apresenta um processador DM3730 com arquitetura ARM Cortex-A8 e clock de base do processador de até 1 GHz. Além disso, esse computador está acoplado a uma placa de expansão Tobi que acrescenta ao computador embarcado conexões do tipo display DVI, Ethernet, USB Host, USB OTG, USB console, áudio Stereo e um segmento com 40 pin-headers que podem ser utilizados para a mais diversas funções, como modulação PWM, GPIO, alimentação, conversão analógico digital e comunicação serial.

.. figure:: /img/Aerial/System_Gumstix.png
   :align: center

   Sistema Gumstix com computador Overo WaterSTORM, placa de expansão Tobi e câmera Caspa VL

Acoplou-se também ao sistema uma câmera Caspa VL, capaz de capturar imagens coloridas com dimensão de 752 x 480 pixels em uma frequência de 60 imagens por segundo. Esses três componentes são produzidos pela empresa Gumstix, fabricante de hardware especializada em computadores pequenos do tipo computador-em-módulo (COM - Computer-On-Module), muito utilizados para sistemas embarcados.

Apesar do tamanho pequeno, a combinação da Overo COM com a placa de extensão TOBI possui o mesmo desempenho do que um computador Linux completo de tamanho normal, maior do que outros sistemas desse tipo encontrados no mercado, como, por exemplo, o computador Raspberry Pi.

Especificações
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
   As especificações completas do computador, da placa de extensão e da câmera estão disponíveis nas fichas técnicas abaixo.

   * :download:`Datasheet - Overo Waterstorm COM <docs/GUM3703WB-1729092.pdf>`
   * :download:`Manual - Overo Waterstorm COM <docs/manual_overo.pdf>`
   * :download:`Datasheet - Placa de extensão TOBI <docs/PKG30002.pdf>`
   * :download:`Datasheet - Câmera Caspa VL <docs/PKG30009C.pdf>` 


Referências
-----------

   	* PITA, H. C. Desenvolvimento de sistema de comunicação multiplataforma para veículos aéreos de asa fixa. Faculdade de Tecnologia, Universidade de Brasília, 2018.
      
	* `Overo® WaterSTORM COM - Gumstix Store`_ 

.. _Overo® WaterSTORM COM - Gumstix Store: https://store.gumstix.com/overo-waterstorm-com.html