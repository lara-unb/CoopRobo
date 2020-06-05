Montando o Pixhawk
==================

.. substituir as imagens por imagens do lab

Orientação do Piloto Automático
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Por padrão, o controlador de voo e a bússola externa devem ser colocados na estrutura da aeronave orientados de modo que a seta aponte para a frente do veículo. Se a placa ou a bússola externa estiverem em qualquer outra orientação, será necessário corrigir a orientação no firmware.

.. By default, the flight controller and the external compass should be placed on the aircraft frame oriented so that the arrow points towards the front of the vehicle. If the card or external compass are in any other direction, you need to correct the orientation in firmware.

Cálculo da Orientação
----------------------

As compensações dos ângulos de rotação `YAW, PITCH e / ou ROLL`_ são calculados em relação à orientação vertical apontando para a frente (rotação no sentido horário em torno dos eixos Z, Y e X, respectivamente). Esse diagrama é chamado de *body frame* (diagrama de corpo) e a orientação padrão é dada por ``ROTATION_NOME``.

.. The compensations for the rotation angles `YAW, PITCH and / or ROLL`_ are calculated in relation to the vertical orientation pointing forward (clockwise rotation around the Z, Y and X axes, respectively). This diagram is called body frame and the default orientation is given by `` ROTATION_NOME``.

.. _YAW, PITCH e / ou ROLL: https://www.youtube.com/watch?v=pQ24NtnaLl8
.. image:: /img/Aerial/fc_orientation_1.png
    :align: center

Por exemplo, a imagem abaixo apresenta rotações de aeronaves em torno do eixo z (YAW), correspondendo, respectivamente, a: ``ROTATION_NONE``, ``ROTATION_YAW_90``, ``ROTATION_YAW_180``, ``ROTATION_YAW_270``.

.. For example, the image below shows aircraft rotations around the z axis (YAW), corresponding, respectively, to: ``ROTATION_NONE``, ``ROTATION_YAW_90``, ``ROTATION_YAW_180``, ``ROTATION_YAW_270``.

.. image:: /img/Aerial/yaw_rotation.png
    :align: center

Definindo a Orientação
-----------------------

Para definir as orientações no firmware: 

.. Note::
   Antes de definir a orientação, o QGroundControl deve ser iniciado, conectado ao veículo e o firmware já deve ter sido instalado na placa controladora de voo.

1. Selecione o ícone de **engrenagem** (Configuração do veículo) na barra de ferramentas superior e, em seguida, **Sensors** na barra lateral.

.. adicionar imagem

2. Selecione o botão **Set Orientations**.

.. adicionar imagem

3. Selecione a orientação do piloto automático, conforme calculado.

.. adicionar imagem 

4. Selecione a **External Compass Orientation** (Orientação da bússola externa) da mesma maneira (esta opção será exibida apenas se o seu veículo tiver uma bússola externa).

5. Pressione **OK**.

.. adicionar imagem da seta

.. Tip::
   A documentação completa sobre como ajustar a orientação do piloto automático está disponível em `Orientação do piloto automático`_.

.. _Orientação do piloto automático: https://docs.px4.io/v1.9.0/en/config/flight_controller_orientation.html

Isolamento de Vibrações
~~~~~~~~~~~~~~~~~~~~~~~

As placas Pixhawk possuem acelerômetros e giroscópios embutidos, sendo sensíveis a vibrações. Elevados níveis de vibração podem causar uma série de problemas, incluindo redução do desempenho de voo, voos mais curtos e maior desgaste do veículo. Em casos extremos, a vibração pode levar a falhas dos sensores, resultando em falhas de estimativa ou até mesmo a interrupção do voo.

.. Pixhawk boards have built-in accelerometers and gyroscopes, being sensitive to vibrations. High levels of vibration can cause a number of problems, including reduced flight performance, shorter flights and increased vehicle wear. In extreme cases, vibration can lead to sensor failures, resulting in estimation errors or even flight interruption.

Por essa razão, o Pixhawk vem com *espumas de amortecimento de vibrações*. 

.. For this reason, the Pixhawk comes with *vibration damping foams*.

.. adicionar imagem 

O Pixhawk deve ser montado na aeronave utilizando as espumas antivibratórias incluídas no kit. Ele deve ser posicionado o mais próximo possível do centro de gravidade do veículo.

.. The Pixhawk must be mounted on the aircraft using the anti-vibration foams included in the kit. It should be positioned as close as possible to the vehicle's center of gravity.

.. Tip::
   Para determinar se os níveis de vibração estão muito altos e utilizar algumas técnicas para melhorar as características de vibração, recomenda-se o tópico `PX4 user guide > Vibration Isolation`_.

.. To determine whether the vibration levels are too high and use some techniques to improve the vibration characteristics, recommended to the topic `PX4 user guide> Vibration Isolation`_.

.. _PX4 user guide > Vibration Isolation: https://docs.px4.io/v1.9.0/en/assembly/vibration_isolation.html#vibration-isolation

Mais Informações
----------------

* `Advanced Orientation Tuning`_.

* `PX4 user guide > Sensor Orientation`_.

* `QGroundControl user guide > Sensors`_.

* `PX4 user guide > Vibration Isolation`_.

.. _Advanced Orientation Tuning: https://docs.px4.io/v1.9.0/en/advanced_config/advanced_flight_controller_orientation_leveling.html
.. _PX4 user guide > Sensor Orientation: https://docs.px4.io/v1.9.0/en/config/flight_controller_orientation.html  
.. _QGroundControl user guide > Sensors: https://docs.qgroundcontrol.com/en/SetupView/sensors_px4.html#flight_controller_orientation
.. _PX4 user guide > Vibration Isolation: https://docs.px4.io/v1.9.0/en/assembly/vibration_isolation.html#vibration-isolation
