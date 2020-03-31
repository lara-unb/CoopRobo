Orientação do piloto automático
================================

Por padrão, o controlador de voo e a bússola externa, se houver, devem ser colocados no chassi da aeronave orientados de modo que a seta aponte para a frente do veículo. Se a placa ou a bússola externa estiver em qualquer outra orientação, será necessario ajustar a orientação no firmware.

Cálculo de orientação
~~~~~~~~~~~~~~~~~~~~~~

As compensações dos angulos de rotação `YAW, PITCH e / ou ROLL`_ são calculados em relação a orientação vertical apontando para a frente (rotação no sentido horário em torno dos eixos Z, Y e X, respectivamente). Esse diagrama é chamado de *body frame* (diagrama de corpo) e a orientação padrão é dada por ``ROTATION_NOME``.

.. _YAW, PITCH e / ou ROLL: https://www.youtube.com/watch?v=pQ24NtnaLl8
.. image:: /img/Aerial/fc_orientation_1.png
    :align: center

Por exemplo, a imagem abaixo apresenta rotações de aeronaves em torno do eixo z (YAW), correspondendo, respectivamente, a: ``ROTATION_NONE``, ``ROTATION_YAW_90``, ``ROTATION_YAW_180``, ``ROTATION_YAW_270``.

.. image:: /img/Aerial/yaw_rotation.png
    :align: center

Definindo a orientação
~~~~~~~~~~~~~~~~~~~~~~~

Para definir as orientações no firmware: 

.. Note::
   Antes de definir a orientação, o QGroundControl deve ser iniciado, conectado ao veiculo e o firmware já deve ter sido instalado na placa controladora de voo.

1. Selecione o ícone de **engrenagem** (Configuração do veículo) na barra de ferramentas superior e, em seguida, **Sensors** na barra lateral.

.. adicionar imagem

2. Selecione o botão **Set Orientations**.

.. adicionar imagem

3. Selecione a orientação do piloto automatico, conforme calculado.

.. adicionar imagem 

4. Selecione a **External Compass Orientation** (Orientação da bússola externa) da mesma maneira (esta opção será exibida apenas se o seu veículo tiver uma bússola externa).


5. Pressione **OK**.


Mais informações
----------------

* `Advanced Orientation Tuning`_.
.. _Advanced Orientation Tuning: https://docs.px4.io/v1.9.0/en/advanced_config/advanced_flight_controller_orientation_leveling.html
* `PX4 user guide > Sensor Orientation`_.
.. _PX4 user guide > Sensor Orientation: https://docs.px4.io/v1.9.0/en/config/flight_controller_orientation.html  
* `QGroundControl user guide > Sensors`_.
.. _QGroundControl user guide > Sensors: https://docs.qgroundcontrol.com/en/SetupView/sensors_px4.html#flight_controller_orientation


