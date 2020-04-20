Embedded System
=====================

.. Note::
   **TEST with excerpts from tg pita and moura**



O computador embarcado será adicionado à aeronave de modo a comunicar-se com a Pixhawk e um modem que transmitirá informações de outros computadores embarcados que estarão em situações semelhantes em outras aeronaves. O microprocessador deverá processar as informações obtidas através do modem e repassar instruções ao piloto automático Pixhawk. Neste capítulo será explicitado os primeiros passos e procedimentos que tiveram de ser realizados para operar o microprocessador.

Computadores embarcados são processadores digitais acoplados a diversos periféricos com o objetivo de tratar uma atividade pré determinada. A pré determinação da sua atividade permite que os computadores embarcados possuam menor tamanho, peso, preço e capacidade de processamento do que computadores comuns que desempenham funções similares. 

Contudo existem desvantagens para sua aplicação causadas pelo mesmo motivo que os tornam atrativos. Por serem bem específicos geralmente estes dispositivos não podem ter sua função inicial alterada sem mudar boa parte de seu software ou estrutura do hardware, em alguns casos estes dispositivos chegam a não apresentar interface com o usuário. 

Overo WaterStorm
~~~~~~~~~~~~~~~~~

Em nosso caso mais especificamente o computador embarcado escolhido foi o Overo WaterStorm Computer-On-Module(COM), esse sistema embarcado apresenta um processador DM3730 com arquitetura ARM Cortex-A8 e clock de base do processador de até 1 GHz. Além disso, esse computador está acoplado a uma placa de expansão Tobi que acrescenta ao computador embarcado conexões do tipo display DVI, Ethernet, USB Host, USB OTG, USB console, áudio Stereo e um segmento com 40 pin-headers que podem ser utilizados para a mais diversas funções, como modulação PWM, GPIO, alimentação, conversão analógico digital e comunicação serial. 

Acoplou-se também ao sistema uma câmera Caspa VL, capaz de capturar imagens coloridas com dimensão de 752 x 480 pixels em uma frequência de 60 imagens por segundo. Esses três componentes, que podem ser vistos na figura 2.8, são produzidos pela empresa Gumstix, fabricante de hardware especializada em computadores pequenos do tipo computador-em-módulo (COM - computer-on-module), muito utilizados para
sistemas embarcados.

Apesar do tamanho pequeno, a combinação da Overo COM com a placa de extensão TOBI possui o mesmo desempenho do que um computador Linux completo de tamanho normal, maior do que outros sistemas desse tipo encontrados no mercado, como, por exemplo, o computador Raspberry Pi.

Especificações 
----------------
