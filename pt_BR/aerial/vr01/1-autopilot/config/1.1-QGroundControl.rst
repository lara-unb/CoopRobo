QGroundControl
==============

O QGroundControl é uma das principais Estações de Controle em Solo (ECS) disponíveis atualmente a trabalhar com pilotos automáticos compatíveis com MAVLink, incluindo o PX4 e ArduPilot.

.. QGroundControl is one of the main Ground Control Station (GCS) currently available to work with autopilots compatible with MAVLink, including PX4 and ArduPilot.

Para aplicar neste projeto, escolheu-se o QGroundControl como ECS por fornece uso fácil e direto para iniciantes, além de oferecer, a usuários experientes, suporte a recursos avançados no controle completo de voo e configurações do veículo com PX4.

.. To implement this project, QGroundControl was chosen as GCS because it provides easy and direct use for beginners, in addition to offering experienced users support for advanced features in complete flight control and vehicle configurations with PX4.

Além disso, QGroundControl é uma das ECSs mais estáveis em relação as outras, possui uma interface simples e eficiente e está disponível em diversos sistemas operacionais, como Windows, Mac OS X, Linux, Android e o iOS.

.. Moreover, QGroundControl is one of the most stable ECSs in relation to the others, has a simple and efficient interface and is available in several operating systems, such as Windows, Mac OS X, Linux, Android and iOS.

Requisitos do Sistema
~~~~~~~~~~~~~~~~~~~~~

O QGroundControl pode ser executado normalmente na maioria dos computadores modernos. Um computador com um i5 e pelo menos 8 GB de RAM terá bom desempenho em todos os aplicativos do programa. Para uma melhor experiência, é aconselhável ter o sistema operacional em sua última versão estável.

.. QGroundControl can run normally on most modern computers. A computer with an i5 and at least 8 GB of RAM will perform well for all applications in the program. For a better experience, it is advisable to have the operating system in its latest stable version.

Instalação
~~~~~~~~~~

-  **Windows**
     
   -  Instalação do QGroundControl nas versões de 64 bits do Windows Vista ou posterior: 

      
      1. Efetue o download do instalador do `QGroundControl.exe <https://s3-us-west-2.amazonaws.com/qgroundcontrol/latest/QGroundControl-installer.exe>`_
      2. Clique duas vezes no executável para inicializar o instalador.

 
-  **Mac OS X**

   -  Instalação do QGroundControl no Mac OS 10.10 ou posterior:

      1. Efetue o download do `QGroundControl.dmg <https://s3-us-west-2.amazonaws.com/qgroundcontrol/latest/QGroundControl.dmg>`_
      2. Clique duas vezes no arquivo .dmg para instalar 
      3. Mova o aplicativo $ QGroundControl para a pasta *Application*


-  **Ubuntu**

.. Ubuntu has a **serial modem manager** that interferes with applications involving robotics that use a serial (or USB serial) port. Before installing **QGroundControl**, is necessary to remove such **serial modem manager** and grant its user the permissions to access the serial port. You also need to install GStreamer to enable video streaming.

O Ubuntu possui um gerenciador de modem serial (*serial modem manager*) que interfere nas aplicações envolvendo robótica que utilizam uma porta serial (ou serial USB). Antes da instalação do *QGroundControl* é necessário remover tal gerenciador de modens e conceder ao seu usuário as permissões para acessar a porta serial. Também é preciso instalar o GStreamer para possibilitar o streaming de video.

   - Antes de instalar o QGroundControl pela primeira vez:

    1. Digite no prompt de comando:
      
       ::
         
           sudo usermod -a -G dialout $USER
           sudo apt-get remove modemmanager -y
           sudo apt install gstreamer1.0-plugins-bad gstreamer1.0-libav -y

    2. Execute logout e login novamente para ativar a alteração nas permissões de usuario.

   -  Instalação do QGroundControl no Ubuntu Linux 16.04 LTS ou posterior:

    1. Efetue o download do `QGroundControl.AppImage <https://s3-us-west-2.amazonaws.com/qgroundcontrol/latest/QGroundControl.AppImage>`_
    2. Instale e execute os comandos do terminal:

       ::
         
           cd Downloads
           chmod +x ./QGroundControl.AppImage
           ./QGroundControl.AppImage

.. Tip::
   A última linha de comando não é necessário se o usuário for ao gerenciador de arquivos, procurar o arquivo QGroundControl baixado e clicar duas vezes nele.

.. The last command line is not necessary if the user goes to the file manager, search for the downloaded QGroundControl file and double-click it.

-  **Android**
    
   - O QGroundControl está disponível no Google Play Store em `QGroundControl - play.google.com <https://play.google.com/store/apps/details?id=org.mavlink.qgroundcontrol>`_ .

 

-  **IOS**

   -  O QGroundControl está disponível na App Store.


