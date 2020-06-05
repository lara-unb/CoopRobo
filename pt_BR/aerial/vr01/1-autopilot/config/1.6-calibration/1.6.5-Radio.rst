Calibração do Radio
===================

.. The Radio Setup option that is present in QGroundControl is used to configure the mapping of your remote control unit's main attitude control sticks (rotation, pitch, yaw, throttle) fot the channels and to calibrate the minimum, maximum, trim and reverse settings for all other controls / RC channels.

A opção Radio Setup, presente no QGroundControl, é usada para configurar o mapeamento dos principais bastões de controle de atitude da unidade de controle remoto (rotation, pitch, yaw, throttle) para os canais e calibrar as configurações mínimas, máximas, de compensação e reversão para todos os outros controles / canais RC.

Conexão Radio-Receptor-Transmissor
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. Before calibrating the radio system, the receiver and transmitter must be connected. The connection process of a transmitter and receiver pair is hardware specific.


Antes de calibrar o sistema de rádio, o receptor e o transmissor devem estar conectados. O processo de conexão de um transmissor e receptor é específico do hardware.

* `QGroundControl user guide > Spektrum receiver`_.

.. _QGroundControl user guide > Spektrum receiver: http://docs.px4.io/v1.9.0/en/config/radio.html#spektrum_bind

* `FrSky receiver`_ (Youtube)

.. _FrSky receiver : https://www.youtube.com/watch?v=1IYg5mQdLVI


Etapas de Calibração
~~~~~~~~~~~~~~~~~~~~

.. In the calibration process it will be indicated that the handles are moved in a specific pattern that is shown in the transmitter diagram in the upper right corner of the screen.

No processo de calibração, será indicado que os bastões são movidos em um padrão específico que é mostrado no diagrama do transmissor no canto superior direito da tela.

 1. Ligue o transmissor RC.
 2. Abra o aplicativo QGroundControl e conecte o veículo pelo fio ao usb do computador.
 3. Selecione o ícone **Engrenagem** (Configuração do veículo) na barra de ferramentas superior e, em seguida, **Rádio** na barra lateral.
 4. Pressione **OK** para iniciar a calibração.
 5. Defina o botão de opção do modo de transmissor que corresponde ao seu transmissor (isso garante que o QGroundControl exiba as posições corretas dos bastões para você seguir durante a calibração).
 6. Mova os bastões para as posições indicadas no texto (e na imagem do transmissor). Pressione **Next** quando os bastões estiverem na posição. Repita para todas as posições.
 7. Quando solicitado, mova todos os outros  por toda as possibilidades de posições (você poderá observá-los se movendo no Monitor de canal).
 8. Pressione **Avançar** para salvar as configurações.

Mais Informações
----------------

* `Radio Setup Video`_ (Youtube)

.. _Radio Setup Video : https://www.youtube.com/watch?v=91VGmdSlbo4&feature=youtu.be&t=4m30s
     





