Firmware
=========

.. A instalação do *firmware* no hardware do controlador de voo pode ser efetuada de duas formas, pelo uso de um programa de Estação de Controle Terrestre (ECT) ou diretamente pelo uso de ferramentas de desenvolvedor sem o uso de um programa auxiliar. Uma ECT é uma aplicação de *software* que roda em um computador terrestre e se comunica com o veículo pelo uso de telemetria sem fio [1]_. 

The installation of the firmware on the flight controller hardware can be done in two ways, by using an Ground Control Station (GCS) program or directly by using developer tools without using an auxiliary program. An GCS is a software application that runs on a ground computer and communicates with the vehicle through the use of wireless telemetry [1]_.

.. As principais ECT's disponíveis são Mission Planner, APM Planner 2, MAVProxy, QGroundControl e UgCS. Para aplicar neste projeto, escolheu-se o QGroundControl por fornecer uso facil e direto para iniciantes, boa documentação, programa mais estável em relação aos demais e ainda oferecer recursos avançados para usuários experientes.

The main GCS's available are Mission Planner, APM Planner 2, MAVProxy, QGroundControl and UgCS. To implement this project, QGroundControl was chosen because it provides easy and direct use for beginners, good documentation, a more stable program in relation to the others and also offers advanced features for experienced users.


.. Tip::
   Before starting this section, it is recommended to download and install QGroundControl on your computer.

.. Antes de iniciar esta seção, recomenda-se o download e instalação do QGroundControl em seu computador. 

.. Adicionar links de download, instalação e documentação oficial.


.. Note::
   The official QGroundControl documentation is available at `QGroundControl`_.

.. A documentação oficial do QGroundControl está disponível em `QGroundControl`_.

.. _QGroundControl: https://docs.qgroundcontrol.com/en/

Stable installation
~~~~~~~~~~~~~~~~~~~~

.. Recomenda-se a instalação da versão mais recente do PX4, a fim de obter as correções de bug e as melhores e mais recentes funções.

We recommend using the latest version of PX4 in order to benefit from bug fixes and get the best and latest features.

.. Note::
   Before installing the firmware, all USB connections of the vehicle must be disconnected and the vehicle must not be powered by a battery.

.. Antes de instalar o firmware, todas as conexões USB do veículo devem ser desconectadas e o veículo não deve ser alimentado por uma bateria. 


.. 1. Selecione o icone da engrenagem (**Vehicle Setup**) na barra de ferramentas superior e, em seguida, selecione **Firmware** na barra lateral.

1. Select the *Gear* icon (**Vehicle Setup**) on the top toolbar, then select **Firmware** on the sidebar.

.. Adicionar imagem

.. 2. Conecte o Pixhawk diretamente ao seu computador via USB (não conecte através de um hub USB).

2. Connect the flight controller directly to your computer via USB (do not connect through a USB hub).


.. 3. Selecione a opção **PX4 Flight Stack X.x.x Release** para instalar a versão mais recente do PX4 em seu controlador de voo (detectado automaticamente).

3. Select the PX4 Flight Stack X.x.x Release option to install the latest stable version of PX4 for your hardware (autodetected).

.. Adicionar imagem

.. 4. Clique em **OK** para iniciar a instalação. 

4. Click **OK** to start the installation.

.. Adicionar imagem


.. O firmware seguirá com várias etapas de atualização (download do novo firmware, exclusão da versão antiga, etc.). O progresso geral é exibido em uma barra de progresso. 

The firmware will then proceed a several number of upgraee steps (download the new firmware, erasing old firmware version, etc.). The overall progress is displayed in a progress bar.

.. Assim que a instalação acabar e o firmware estiver instalado, o controlador será reiniciado e reconectado.

Once the firmware has completed loading, the device will reboot and reconnect.
 
More information
------------------

* `PX4 user guide > Firmware`_.

* `QGroundControl user guide > Firmware`_.

* `PX4 Setup Video`_ (Youtube)

.. _PX4 user guide > Firmware: https://docs.px4.io/v1.9.0/en/config/firmware.html
.. _QGroundControl user guide > Firmware: https://docs.qgroundcontrol.com/en/SetupView/Firmware.html
.. _PX4 Setup Video: https://www.youtube.com/watch?v=91VGmdSlbo4&feature=youtu.be

.. References

.. [1] Eduardo Moura Cirilo Rocha. 2017. Desenvolvimento de um sistema com veículos aéreos não-tripulados autônomos, Universidade de Brasília, Brasil.


