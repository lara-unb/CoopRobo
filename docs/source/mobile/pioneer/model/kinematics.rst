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
  :width: 300 px
  :figwidth: 320 px
  :alt: The global reference frame and the robot local reference frame.

  The global reference frame and the robot local reference frame.



.. math::
   \xi_I = \left[ \begin{array}{c} x \\ y \\ \theta \end{array} \right]

.. figure:: /img/diff_drive.png
  :alt: A differential-drive robot in its global reference frame.

  A differential-drive robot in its global reference frame. Figure removed from [1]_.


.. .. figure:: /img/gif2.gif
..   :alt: A differential-drive robot in its global reference frame.

Forward Kinematics
~~~~~~~~~~~~~~~~~~



Inverse Kinematics
~~~~~~~~~~~~~~~~~~


.. [1] Roland Siegwart and Illah R. Nourbakhsh. 2004. Introduction to Autonomous Mobile Robots. Bradford Company, USA.
.. [2] Gregory Dudek and Michael Jenkin. 2010. Computational Principles of Mobile Robotics (2nd. ed.). Cambridge University Press, USA.
.. [3] G. Campion, G. Bastin, B. D'Andréa-Bovel. "`Structural Properties and Classification of Kynematic and Dynamic Models of Wheeled Mobile Robots`_", IEEE Trans. on Robotics and Automation, V. 12, N. 1, 1996, pp. 47-62.

.. _Omron Adept MobileRobots: http://www.mobilerobots.com/Mobile_Robots.aspx
.. _Structural Properties and Classification of Kynematic and Dynamic Models of Wheeled Mobile Robots: http://www2.ene.unb.br/gaborges/disciplinas/pcr/artigos/1996_campion_ieeetra.pdf
