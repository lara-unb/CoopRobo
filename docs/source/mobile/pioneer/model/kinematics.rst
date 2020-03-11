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


.. paragrafo sobre robos com rodas

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
Where the :math:`X_I` and :math:`Y_I` defines the global reference frame, also known as the inertial frame, and :math:`X_R` and :math:`Y_R` defines the local reference frame or the robot frame.
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

Wheels and its constraints
~~~~~~~~~~~~~~~~~~~~~~~~~~

"Wheeled Mobile Robots (WMR) constitute a class of mechanical systems characterized by kinematics constraints that are not integrable and cannot, therefore, be eliminated from the model equations" [2]_.
If we want to study and describe a robot motion, we also must specify which are the hypotheses and constraints of the wheels.
There are three essential hypotheses about the kinematics model of the wheeled robot during the motion; they are:

- Each wheel remain perpendicular about its plane;
- There is only one contact point between plane and wheel;
- There is only rolling without slipping;

And two constraints:

- About rolling: the motion component along the wheel plane is equal to the rotation velocity of the wheel;
- About slipping: the motion component along the orthogonal direction is equal to zero;

Some authors may call these constraints as "the pure rolling and rotation condition".


Differential Drive Model
~~~~~~~~~~~~~~~~~~~~~~~~

Now we delve into modeling of a differential drive kinematic.
Dudek et al. say that the differential drive consists of two wheels mounted in the same axis with separated motors [3]_.
Each wheel contributes to the robot motion, so to fully describe the robot motion, we must compute each contribution.

.. figure:: /img/pioneer/wheel_vel.png
   :align: right
   :width: 400 px
   :figwidth: 420 px
   :alt: The global reference frame and the robot local reference frame.

   Wheel velocities and the robot frame.

The image shows the robot, the wheel velocities, and the local frame.
:math:`\dot{\phi}_1` and :math:`\dot{\phi}_2` is the spin speed of the left wheel and right wheel.
:math:`r` is the wheel radius, while the distance between the two wheels is :math:`l`.
While :math:`v_1` is the left wheel velocity along the ground and :math:`v_2` the right wheel velocity.
As the wheels contribute independently to the robot motion, we can analyze each contribution separately.

.. math::
   \begin{array}{c}
      v_i   = \frac{\dot{\phi}_i r}{2} \\
   \omega_i = (-1^i)\frac{\dot{\phi}_i r}{2 l} \\
      \text{where } i = \{1, 2\}
   \end{array}

Point :math:`P` is halfway between the two wheels, so each wheel contributes with half of the linear speed of the robot in the direction of :math:`X_R`.
Each wheel also adds a new component to the angular speed of the robot.
:math:`v_1` moves the robot counter-clockwise around point :math:`P` while :math:`v_2` moves it clockwise.
That is why they differ in their sign.
And, using the equation which relates the angular speed of disk with its linear speed, we have the above equations.

Using the superposition theorem, we have the equations for the linear velocity in the direction of :math:`X_R` and the angular velocity in the direction of :math:`Z_R`:

.. math::
   \begin{array}{c}
   v      & = &   v_1 + v_2 \\
   \omega & = & -\omega_1 + \omega_2
   \end{array}

In the local frame, we have the following kinematic equation:

.. math::
  \dot{\xi_R} & = & 
  \left[ \begin{array}{c} \frac{r}{2} &  \frac{r}{2} \\ 
                                0       &        0 \\ 
                        -\frac{r}{2 l}  & \frac{r}{2 l}  \end{array} \right] \left[ \begin{array}{c} \dot{\phi}_1 \\ \dot{\phi}_2 \end{array} \right]

.. note::
  In the robot frame, there is no velocity in the direction of :math:`Y_R`. Because we assumed the pure rolling and rotation condition. And yet he can reach any point in the global frame.

Forward Kinematics
------------------

The forward kinematics problem tries to solve the problem when we have the control inputs, and we must know where the robot goes in the global frame.
As we have seen, to solve this question, we should know five parameters of the robot — two parameters about the robot geometry, :math:`l` and :math:`r`, the current robot orientation, :math:`\theta`, and, at least, the two inputs, :math:`\dot{\phi}_1` and :math:`\dot{\phi}_2`.

.. math::
   \dot{\xi_I} = \left[ \begin{array}{c} \dot{x} \\ \dot{y} \\ \dot{\theta} \end{array} \right] = f(l, r, \theta, \dot{\phi_1}, \dot{\phi_2})

:math:`f` is the function that solves the forward kinematics problem.
To map between the parameter vector, :math:`\{l, r, \theta, \phi_1, \phi_2\}`, and the state of the robot in the inertial frame.
We should use the matrix, which links the spin speed and the derivative of the robot state in the local frame.
Then, we can transform the robot velocities in the local frame to the global frame utilizing the inverse of the rotation matrix.

.. math::
   \begin{array}{c}
   R(\theta)^{-1} = \left[ \begin{array}{c} cos \theta &-sin \theta & 0 \\
                                            sin \theta & cos \theta & 0 \\
                                                 0     &      0     & 1 \end{array} \right], &
  \dot{\xi_I} = R(\theta)^{-1} \dot{\xi_R}, &
  \dot{\xi_R} =
  \left[ \begin{array}{c} \frac{r}{2} &  \frac{r}{2} \\ 
                                0       &        0 \\ 
                        -\frac{r}{2 l}  & \frac{r}{2 l}  \end{array} \right] \left[ \begin{array}{c} \dot{\phi}_1 \\ \dot{\phi}_2 \end{array} \right]
  \end{array}


.. math::
  \dot{\xi_I} & = & R(\theta)^{-1}
  \left[ \begin{array}{c} \frac{r}{2} &  \frac{r}{2} \\ 
                                0       &        0 \\ 
                        -\frac{r}{2 l}  & \frac{r}{2 l}  \end{array} \right]
  \left[ \begin{array}{c} \dot{\phi}_1 \\ \dot{\phi}_2 \end{array} \right]

Then,

.. math::
  f(l, r, \theta, \dot{\phi_1}, \dot{\phi_2}) & = & 
  \left[ \begin{array}{c} cos \theta &-sin \theta & 0 \\
                          sin \theta & cos \theta & 0 \\
                               0     &      0     & 1 \end{array} \right]
  \left[ \begin{array}{c} \frac{r}{2} &  \frac{r}{2} \\ 
                                0       &        0 \\ 
                        -\frac{r}{2 l}  & \frac{r}{2 l}  \end{array} \right] 
  \left[ \begin{array}{c} \dot{\phi}_1 \\ \dot{\phi}_2 \end{array} \right]

.. math::
  f(l, r, \theta, \dot{\phi_1}, \dot{\phi_2}) & = & 
  \left[ \begin{array}{c} \frac{r cos \theta}{2} &  \frac{r cos \theta}{2} \\ 
                          \frac{r sin \theta}{2} &  \frac{r sin \theta}{2} \\ 
                         -\frac{r}{2 l}          &  \frac{r}{2 l}    \end{array} \right]
  \left[ \begin{array}{c} \dot{\phi}_1 \\ \dot{\phi}_2 \end{array} \right]

Or

.. math::
  \dot{\xi_I} & = &
  \left[ \begin{array}{c} \frac{r cos \theta}{2} &  \frac{r cos \theta}{2} \\ 
                          \frac{r sin \theta}{2} &  \frac{r sin \theta}{2} \\ 
                         -\frac{r}{2 l}          &  \frac{r}{2 l}    \end{array} \right]
  \left[ \begin{array}{c} \dot{\phi}_1 \\ \dot{\phi}_2 \end{array} \right]

.. note::
  The matrix which maps spin speed to the robot velocities is commonly known as **Jacobian Matrix**.

Well, we know the relationship between spin speeds and robot velocities, but what about the robot pose in the global frame?

.. math::
  \xi_I = \int_{0}^{t}
  \left[ \begin{array}{c} \frac{r cos \theta}{2} &  \frac{r cos \theta}{2} \\ 
                          \frac{r sin \theta}{2} &  \frac{r sin \theta}{2} \\ 
                         -\frac{r}{2 l}          &  \frac{r}{2 l}    \end{array} \right]
  \left[ \begin{array}{c} \dot{\phi}_1 \\ \dot{\phi}_2 \end{array} \right]
  dt

Or

.. math::
  \begin{cases}
  x(t) = \frac{r}{2} \int_{0}^{t} (\dot{\phi_1}(t) + \dot{\phi_2}(t)) cos (\theta(t)) dt \\
  y(t) = \frac{r}{2} \int_{0}^{t} (\dot{\phi_1}(t) + \dot{\phi_2}(t)) sin (\theta(t)) dt \\
  \theta(t) = \frac{r}{2 l} \int_{0}^{t} (\dot{\phi_2}(t) - \dot{\phi_1}(t)) dt
  \end{cases}

Inverse Kinematics
------------------

The inverse kinematics problem is the opposite of the forward problem.
The problem aims to solve the following question: "What are the controls needed to reach the desired pose?".

.. math::
   \left[ \begin{array}{c} \dot{\phi_1} \\ \dot{\phi_2}\end{array} \right] = g(\dot{\xi_I})

The function :math:`g` is the mathematical inverse of the function :math:`f`.

.. math::
   g = f^{-1} = 
   \left[ \begin{array}{c} \frac{r cos \theta}{2} &  \frac{r cos \theta}{2} \\ 
                          \frac{r sin \theta}{2} &  \frac{r sin \theta}{2} \\ 
                         -\frac{r}{2 l}          &  \frac{r}{2 l}    \end{array} \right]^{-1}

As we can see, the matrix which represents the function :math:`f` is not be invertible.
This is the main problem of any inverse kinematics, while the forward kinematics can be modeled, the inverse kinematics it is often not analitically solvable.
However, we can try to solve the problem, limiting the possibles solution like :math:`\dot{\phi}_1 = \dot{\phi}_2` or :math:`\dot{\phi}_1 = -\dot{\phi}_2`.

.. figure:: /img/pioneer/diff_drive.png
   :alt: A differential-drive robot in its global reference frame.

   A differential-drive robot in its global reference frame. Figure from [1]_.

Kinematic Model
~~~~~~~~~~~~~~~

The kinematics of a differential-drive mobile robot described in the inertial frame :math:`\{ X_I , Y_I , θ \}` is given by

.. math::
  \left[ \begin{array}{c} \dot{x} \\ \dot{y} \\ \dot{\theta} \end{array} \right] & = & 
  \left[ \begin{array}{c} v \cos \theta \\ v \sin \theta \\ \omega \end{array} \right] & = & 
  \left[ \begin{array}{c} \cos \theta & 0 \\ \sin \theta & 0 \\ 0 & 1 \end{array} \right] \left[ \begin{array}{c} v \\ \omega \end{array} \right]

Where :math:`x`, :math:`y` and :math:`\theta` are the coordinates of the robot in the global frame and :math:`u = (v, \omega)` is the control vector.



.. note::
  A differential drive robot has a major problem which is...
  Feng et al. [4]_ develops in 1993 a motion controller which...


.. References

.. [1] Roland Siegwart and Illah R. Nourbakhsh. 2004. Introduction to Autonomous Mobile Robots. Bradford Company, USA.
.. [2] G. Campion, G. Bastin and B. Dandrea-Novel, "`Structural properties and classification of kinematic and dynamic models of wheeled mobile robots`_," in IEEE Transactions on Robotics and Automation, vol. 12, no. 1, pp. 47-62, Feb. 1996.
.. [3] Gregory Dudek and Michael Jenkin. 2010. Computational Principles of Mobile Robotics (2nd. ed.). Cambridge University Press, USA.
.. [4] L. Feng, Y. Koren and J. Borenstein, "`Cross-coupling motion controller for mobile robots`_," in IEEE Control Systems Magazine, vol. 13, no. 6, pp. 35-43, Dec. 1993.

.. _Omron Adept MobileRobots: http://www.mobilerobots.com/Mobile_Robots.aspx
.. _Structural properties and classification of kinematic and dynamic models of wheeled mobile robots: https://ieeexplore.ieee.org/document/481750
.. _Cross-coupling motion controller for mobile robots: https://ieeexplore.ieee.org/document/248002/

