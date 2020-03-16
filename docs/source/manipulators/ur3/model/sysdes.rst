.. figure:: /img/ur3/sys_des/capa_sysdes.jpg
    :width: 400px
    :height: 300px
    :scale: 100 %
    :alt: Power button
    :align: center



System Description
==================


Overview
~~~~~~~~

The UR3 is a table-top collaborative robot. With its 3 kg payload it is very capable and its small footprint makes it suitable for limited workspace situations. With its infinite turn on the end joint, several activities can be perfomed with grippers attached at robot tool connector.

Some of its applications:

- Laboratory work
- Assembly tasks
- Polishing
- Soldering
- Gluing
- Screwing
- Painting
- Pick and place
- Operating hand tools
- Fume hood tasks


Description
~~~~~~~~~~~
.. list-table:: UR3 Description
   :widths: 50 50
   :header-rows: 0

   * - Weight
     - 11.2 kg
   * - Payload
     - 3 kg
   * - Reach
     - 500 mm
   * - Footprint
     - Ø 128 mm 
   * - Degrees of freedom
     - 6 rotating joints
   * - Joint ranges
     - +/- 360°, infinite rotation on end joint
   * - Speed wrist joints
     - 360 degrees/sec 
   * - Other joints
     - 180 degrees/sec.
   * - Noise
     - Comparatively noiseless
   * - IP classification
     - IP64

Communication
~~~~~~~~~~~~~

.. image:: /img/ur3/sys_des/UR3-ControlBox-PC.png
      :width: 400px
      :height: 400px
      :scale: 100 %
      :align: center

There are two main communication gateway in this system. 

Foremost, there is a TCP/IP communication port between a LinuxPC and the UR3 Control Box. Basically, it is possible to send ROS commands directly from from Linux Terminal or specialized simulation softwares.

Next, there is a serial communication port between the Control Box and the UR3 Robot. It is responsible for send all the position and velocity commands to the robot.

Some of its specification:

- TCP/IP 100 Mbit: IEEE 802.3u, 100BASE-TX
- Ethernet socket & Modbus TCP


Control Box
~~~~~~~~~~~

.. image:: /img/ur3/sys_des/controlbox.png
      :width: 300px
      :height: 300px
      :scale: 100 %
      :align: center

Linux PC
~~~~~~~~
