Firmware
========

A instalação do *firmware* no hardware do controlador de voo pode ser efetuada de duas formas, pelo uso de um programa de Estação de Controle Terrestre (ECT) ou diretamente pelo uso de ferramentas de desenvolvedor sem o uso de um programa auxiliar [1]_. 

.. The installation of the firmware on the flight controller hardware can be done in two ways, by using an Ground Control Station (GCS) program or directly by using developer tools without using an auxiliary program. 

.. Tip::
   Antes de iniciar esta seção, recomenda-se o download e instalação do QGroundControl em seu computador. 

.. Adicionar links de download, instalação e documentação oficial.


.. Note::
   A documentação oficial do QGroundControl está disponível em `QGroundControl`_.

.. The official QGroundControl documentation is available at `QGroundControl`_.

.. _QGroundControl: https://docs.qgroundcontrol.com/en/

Instalação
~~~~~~~~~~

Recomenda-se a instalação da versão mais recente do PX4, a fim de obter as correções de bug e as melhores e mais recentes funções.

.. We recommend using the latest version of PX4 in order to benefit from bug fixes and get the best and latest features.

.. Note::
    Antes de instalar o firmware, todas as conexões USB do veículo devem ser desconectadas e o veículo não deve ser alimentado por uma bateria. 

.. Before installing the firmware, all USB connections of the vehicle must be disconnected and the vehicle must not be powered by a battery.


1. Selecione o icone da engrenagem (**Vehicle Setup**) na barra de ferramentas superior e, em seguida, selecione **Firmware** na barra lateral.

.. Select the *Gear* icon (**Vehicle Setup**) on the top toolbar, then select **Firmware** on the sidebar.

.. Adicionar imagem

2. Conecte o Pixhawk diretamente ao seu computador via USB (não conecte através de um hub USB).

.. Connect the flight controller directly to your computer via USB (do not connect through a USB hub).


3. Selecione a opção **PX4 Flight Stack X.x.x Release** para instalar a versão mais recente do PX4 em seu controlador de voo (detectado automaticamente).

.. Select the PX4 Flight Stack X.x.x Release option to install the latest stable version of PX4 for your hardware (autodetected).


.. Adicionar imagem


4. Clique em **OK** para iniciar a instalação. 

.. 4. Click ** OK ** to start the installation.

.. Adicionar imagem


O firmware seguirá com várias etapas de atualização (download do novo firmware, exclusão da versão antiga, etc.). O progresso geral é exibido em uma barra de progresso. 

.. The firmware will then proceed a several number of upgraee steps (download the new firmware, erasing old firmware version, etc.). The overall progress is displayed in a progress bar.

Assim que a instalação acabar e o firmware estiver instalado, o controlador será reiniciado e reconectado.

.. Once the firmware has completed loading, the device will reboot and reconnect.
 
Mais Informações
----------------

* `PX4 user guide > Firmware`_.

* `QGroundControl user guide > Firmware`_.

* `PX4 Setup Video`_ (Youtube)

.. _PX4 user guide > Firmware: https://docs.px4.io/v1.9.0/en/config/firmware.html
.. _QGroundControl user guide > Firmware: https://docs.qgroundcontrol.com/en/SetupView/Firmware.html
.. _PX4 Setup Video: https://www.youtube.com/watch?v=91VGmdSlbo4&feature=youtu.be

.. References

.. [1] Eduardo Moura Cirilo Rocha. 2017. Desenvolvimento de um sistema com veículos aéreos não-tripulados autônomos, Universidade de Brasília, Brasil.


