AirSpeed Calibration
=====================

The airspeed calibration needs to read a stable baseline with 0 airspeed in order to determine an offset. Cup your hands over the pitot to block any wind (if calibrating the sensor indoors this is not needed) and then blow into the tube using your mouth (to signal completion of the calibration).

Calibration Steps
~~~~~~~~~~~~~~~~~

  1. Open the app QGroundControl and connect the vehicle by the wire to the computer's usb.
  2. Select the **Gear** icon (Vehicle Setup) in the top toolbar and then **Sensors** in the sidebar.
  3. Click the **AirSpeed** sensor button.
  4. Shield the sensor from the wind (i.e. cup it with your hand). Take care not to block any of its holes.
  5. Click **OK** to start the calibration.
  6. Blow on the tip of the pitot tube to indicate that the calibration is complete.
  7. Wait two to three seconds before removing the cover, remembering that the calibration will be completed in a few seconds.
     
.. tip:: 
  Blowing into the tube is also a basic check that the dynamic and static ports are installed correctly. If they are swapped then the sensor will read a large negative differential pressure when you blow into the tube, and the calibration will abort with an error.

More Information
----------------
 
* `QGroundControl user guide > AirSpeed`_.

.. _QGroundControl user guide > AirSpeed: https://docs.qgroundcontrol.com/en/SetupView/sensors_px4.html#airspeed


