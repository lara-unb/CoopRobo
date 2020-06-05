Radio Setup
===========

The Radio Setup option that is present in QGroundControl is used to configure the mapping of your remote control unit's main attitude control sticks (rotation, pitch, yaw, throttle) fot the channels and to calibrate the minimum, maximum, trim and reverse settings for all other controls / RC channels.

Binding the Receiver
~~~~~~~~~~~~~~~~~~~~

Before calibrating the radio system, the receiver and transmitter must be connected. The connection process of a transmitter and receiver pair is hardware specific.

* `QGroundControl user guide > Spektrum receiver`_.

.. _QGroundControl user guide > Spektrum receiver: http://docs.px4.io/v1.9.0/en/config/radio.html#spektrum_bind

* `FrSky receiver`_ (Youtube)

.. _FrSky receiver : https://www.youtube.com/watch?v=1IYg5mQdLVI


Calibration Steps
~~~~~~~~~~~~~~~~~

In the calibration process it will be indicated that the handles are moved in a specific pattern that is shown in the transmitter diagram in the upper right corner of the screen.

 1. Turn on your RC transmitter.
 2. Open the app QGroundControl and connect the vehicle by the wire to the computer's usb.
 3. Select the **Gear** icon (Vehicle Setup) in the top toolbar and then **Radio** in the sidebar.
 4. Press **OK** to start the calibration.
 5. Set the transmitter mode radio button that matches your transmitter (this ensures that QGroundControl displays the correct stick positions for you to follow during calibration).
 6. Move the sticks to the positions indicated in the text (and on the transmitter image). Press Next when the sticks are in position. Repeat for all positions.
 7. When prompted, move all other switches and dials through their full range (you will be able to observe them moving on the Channel Monitor).
 8. Press **Next** to save the settings.

More Information
----------------

* `Radio Setup Video`_ (Youtube)

.. _Radio Setup Video : https://www.youtube.com/watch?v=91VGmdSlbo4&feature=youtu.be&t=4m30s
     





