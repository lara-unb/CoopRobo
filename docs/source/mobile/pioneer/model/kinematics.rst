Kinematics
==========

.. paragrafo sobre cinematica

Kinematics, in classical mechanics, study the description of the motion of points, bodies (objects), and groups of bodies without considering the forces that cause them to move. 
In mobile robotics, kinematics helps us to understand and quantify the constraints about the robot design, which implies restrictions in its movement.
Also, we can draw the paths and trajectories that the robot can do.
Here, the text focus on wheeled robots, which can only move in 2D space.

.. paragrafo sobre robos drive

.. figure:: /img/pioneer/p3-dx.jpg
   :align: left
   :width: 320 px

   Pioneer P3-DX

.. figure:: /img/pioneer/p3-at.jpg
   :align: right
   :width: 320 px

   Pioneer P3-AT


The P3-DX is a two-wheel-drive and P3-AT is a four-wheel-drive.
The `Omron Adept MobileRobots`_ considers in its manual the P3-DX as a differential drive robot and the P3-AT as a skid/slip drive robot.
For our sake, both are modeled as differential drive vehicles because the exact center of rotation in a skid/slip drive is unpredictable [1]_.
The differential drive consists of two wheels mounted in the same axis with separated motors [2]_.


.. paragrafo sobre robos com rodas

"Wheeled Mobile Robots (WMR) constitute a class of mechanical systems characterized by kinematics constraints that are not integrable and cannot, therefore, be eliminated from the model equations" [3]_.
In order to represent the motion of a mobile robot, we must define the reference frames and determine their position.
There are two essential frames to a robot if we consider the robot as a rigid body.
They are the global reference frame, that is world fixed, and the local reference frame, which is robot fixed.

.. figure:: /img/pioneer/robot_frames.png
   :align: left
   :width: 300 px
   :figwidth: 320 px
   :alt: The global reference frame and the robot local reference frame.

   The global reference frame and the robot local reference frame. Figure from [1]_.

The figure shows a robot and its reference frames.
Where the :math:`X_I` and :math:`Y_I` defines the global reference frame, and :math:`X_R` and :math:`Y_R` defines the local reference frame.
The coordinates :math:`x` and :math:`y` represent the robot's position in the global reference frame, point P, whereas :math:`\theta` is the angular difference among the global and the local reference frames.
Thus, we represent the robot's pose as the vector with these three components.

.. math::
   \xi_I = \left[ \begin{array}{c} x \\ y \\ \theta \end{array} \right]


We can now utilize this definition to describe elements represented in the local frame in the global frame and vice-versa.
For example, we can map the motion calculated in the global frame to motion in the robot's local frame.
Or, we can map obstacles sensed by the robot in terms of the global reference frame.

.. math::
   R(\theta) = \left[ \begin{array}{c} cos \theta & sin \theta & 0 \\
                                      -sin \theta & cos \theta & 0 \\
                                            0     &      0     & 1 \end{array} \right]

The *orthogonal rotation matrix* does the map between these frames as a function of the robot's current pose.


.. math::
  \dot{\xi_R} = R(\theta) \dot{\xi_I}

Forward Kinematics
~~~~~~~~~~~~~~~~~~

.. math::
   \dot{\xi_I} = \left[ \begin{array}{c} \dot{x} \\ \dot{y} \\ \dot{\theta} \end{array} \right] = f(l, r, \theta, \dot{\phi_1}, \dot{\phi_2})


Inverse Kinematics
~~~~~~~~~~~~~~~~~~


.. math::
   \left[ \begin{array}{c} \dot{\phi_1} \\ \dot{\phi_2}\end{array} \right] = g(\dot{\xi_I})



.. figure:: /img/diff_drive.png
   :alt: A differential-drive robot in its global reference frame.

   A differential-drive robot in its global reference frame. Figure from [1]_.

.. math::
  \left[ \begin{array}{c} \dot{x} \\ \dot{y} \\ \dot{\theta} \end{array} \right] & = & 
  \left[ \begin{array}{c} v \cos \theta \\ v \sin \theta \\ \omega \end{array} \right] & = & 
  \left[ \begin{array}{c} \cos \theta & 0 \\ \sin \theta & 0 \\ 0 & 1 \end{array} \right] \left[ \begin{array}{c} v & \omega \end{array} \right]

Where :math:`x`, :math:`y` and :math:`\theta` are the coordinates of the robot in the global frame and :math:`u = (v, \omega)` is the control vector.



.. note::
  A differential drive robot has a major problem which is...
  Feng et al. [4]_ develops in 1993 a motion controller which...


.. References

.. [1] Roland Siegwart and Illah R. Nourbakhsh. 2004. Introduction to Autonomous Mobile Robots. Bradford Company, USA.
.. [2] Gregory Dudek and Michael Jenkin. 2010. Computational Principles of Mobile Robotics (2nd. ed.). Cambridge University Press, USA.
.. [3] G. Campion, G. Bastin and B. Dandrea-Novel, "`Structural properties and classification of kinematic and dynamic models of wheeled mobile robots`_," in IEEE Transactions on Robotics and Automation, vol. 12, no. 1, pp. 47-62, Feb. 1996.
.. [4] L. Feng, Y. Koren and J. Borenstein, "`Cross-coupling motion controller for mobile robots`_," in IEEE Control Systems Magazine, vol. 13, no. 6, pp. 35-43, Dec. 1993.

.. _Omron Adept MobileRobots: http://www.mobilerobots.com/Mobile_Robots.aspx
.. _Structural properties and classification of kinematic and dynamic models of wheeled mobile robots: https://ieeexplore.ieee.org/document/481750
.. _Cross-coupling motion controller for mobile robots: https://ieeexplore.ieee.org/document/248002/

