Probabilistic Kinematics
========================

In the previous section, we try to model the movement of a mobile robot mathematically.
As we have seen, we made assumptions to get a simple model capable of describing the movement without loss of generality.
Nevertheless, if the assumptions are incorrect, we have to put in the trash all our work?
Or, we can make adjustments to continue to describe the actions with the same simplicity of the previous model?

Well, the purpose of this section is to delve into the assumptions.
Try to predict when they are incorrect.
Furthermore, study a way that could deal with this kind of problem.


In the previous sections, we build a mathematical model looking at a mobile robot modeled with just two wheels.
However, as we have seen, our robots have more than two wheels.
The P3-DX has three wheels, two motored, and a castor wheel.
The P3-AT has four wheels and two motors, one for each side.
None of them fits in our model.
The castor wheel adds a new problem in the differential drive model.
Moreover, the four wheels violate the pure rolling and rotation condition.

The castor wheel problem
~~~~~~~~~~~~~~~~~~~~~~~~

The castor wheel, unlike fixed wheels, is an off-centered orientable wheel that is orientable to the robot frame.

.. figure:: /img/pioneer/castor-wheel.jpg
   :align: right
   :width: 200 px
   :figwidth: 220 px
   :alt: Castor wheel.

   Castor wheel.

The castor wheel does not add any additional constraints to the robot motion, because the robot motion will steer the wheel to a new orientation.
However, in a castor wheel, the steering action itself moves the robot chassis because of the offset between the ground contact point and the vertical axis of rotation.

The steering action adds uncertainty to the robot motion.
As we can not predict the additional action, we can not guarantee that the control action will drive the robot to the desired pose.

.. figure:: /img/pioneer/castor_prob.gif
   :alt: Castor wheel producing a unpredictable movement.

   Castor wheel producing a unpredictable movement.

The above image shows the simulation of rotation in place of the P3-DX.
The castor wheel begins not aligned to the rotation.
Then the robot starts to move; this movement steers the castor wheel.
Although, the castor wheel pushes the robot away from its original position when steering.
We can try to parameterize the steering action, adding a new translation and expand the previous model to add the new change, as we see in [1]_.
Nonetheless, here we try to generalize this problem as a violation of the motion hypothesis since the robot will not move as the equations tell anymore.


The assumption violation
~~~~~~~~~~~~~~~~~~~~~~~~

Velocity Motion Model
~~~~~~~~~~~~~~~~~~~~~


Odometry Motion Model
~~~~~~~~~~~~~~~~~~~~~


.. [1] Roland Siegwart and Illah R. Nourbakhsh. 2004. Introduction to Autonomous Mobile Robots. Bradford Company, USA.
