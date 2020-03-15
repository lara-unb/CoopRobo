Lab 1: First Contact
====================

objective
---------

The new user contacts the ur3 platform and performs a first experiment.


Introduction
------------

This lab teaches how to run a code to make a simple move on the ur3 robot using ROS.

Procedures to setup the ur3 robot
---------------------------------

First, let's turn on the UR3 robot by pressing the POWER button shown in figure 1.

.. figure:: /img/ur3/lab1/power.jpeg
    :width: 100px
    :height: 100px
    :scale: 100 %
    :alt: Power button
    :align: center

    Figure 1: Power button

After pressing the power button, the screen like the figure below will appear.

.. figure:: /img/ur3/lab1/tela_carregando.jpeg
    :width: 500px
    :height: 300px
    :scale: 100 %
    :alt: loading
    :align: center

    Figure 2: Loading screen

After loading the robot system, the screen as the figure below will appear.

.. figure:: /img/ur3/lab1/go_initialize.jpeg
    :width: 500px
    :height: 300px
    :scale: 100 %
    :alt: go initialize
    :align: center

    Figure 3: Apresentation screen

Now, turn on the control box by clicking **Go to the initialization screen**, which is in the center of figure 3.

now, we have a screen like figure 4.

.. figure:: /img/ur3/lab1/ini_robot.jpeg
    :width: 500px
    :height: 300px
    :scale: 100 %
    :alt: init robot
    :align: center

    Figure 4: screen to turn on the robotic arm.

The turn on the robot, press the **ON** button. The screen that will appear will be like as in figure 5.

.. figure:: /img/ur3/lab1/start.jpeg
    :width: 500px
    :height: 300px
    :scale: 100 %
    :alt: start
    :align: center

    Figure 5: start screen.

The robot is now on. To unlock the joints, press the **START** button.
The robot will make an unlocking sound, which is expected, and will enter the normal operating mode that can be seen in figure 6.

.. figure:: /img/ur3/lab1/ok.jpeg
    :width: 500px
    :height: 300px
    :scale: 100 %
    :alt: ok
    :align: center

    Figure 6.

Depois disso, aperte **OK** que fica localizado no canto inferior direito da tela (figura 6).
Now, a new screen will appear (figure 7) with some options for robot functionality. Let's click on **Program Robot**.

.. figure:: /img/ur3/lab1/pr.jpeg
    :width: 500px
    :height: 300px
    :scale: 100 %
    :alt: pr
    :align: center

    Figure 7.

Depois de apertar **Program Robot** aparecerá uma tela semelhante a figura 8. Aperte **Move**.

Ready. We have completed our robot setup and the final screen is similar to Figure 9.

.. figure:: /img/ur3/lab1/move.jpeg
    :width: 500px
    :height: 300px
    :scale: 100 %
    :alt: move
    :align: center

    Figure 8.

.. figure:: /img/ur3/lab1/home.jpeg
    :width: 500px
    :height: 300px
    :scale: 100 %
    :alt: home
    :align: center

    Figure 9.

Procedures to setup the Linux PC
--------------------------------

Now let's turn on the computer that controls the robot.
To do this, connect the LARA computer designated for the UR3 robot.
The computer name is **ur3** and password **ur3**.

One more thing, the communication will be done using the TCP/IP protocol using cable,
so check if the network cable of the Lara-robots router is connected to the ur3 computer.

After making the instructions described in the paragraph above,
we will download the files that contain the codes for our experiment.
To do this, open the application called **Terminator** on the ubuntu 18.04 taskbar,
which is exactly like figure 10.

.. figure:: /img/ur3/lab1/terminator.png
    :width: 300px
    :height: 300px
    :scale: 30 %
    :alt: terminator
    :align: center

    Figure 10: Terminator

After opening **Terminator**, we will use the command **git clone** to download the file.
Then, type in the Terminator the command (If the file already exists, skip this step):

    * $ git clone https://github.com/lara-unb/UR3\_interface.git 

The next step is to compile the code to "run" on the ur3 computer.
To compile the code we will enter the directory,
using Terminator, where the executable folders are.

With the command shown below you can enter the interface code workspace.

    * $ cd UR3_interface/catkin_ur3  

To compile the code use the command:

    * $ catkin_make

You will receive a message like the one in figure 11 below.

.. figure:: /img/ur3/lab1/comp.png
    :width: 800px
    :height: 400px
    :scale: 100 %
    :alt: compile
    :align: center

    Figure 11.

The computer setup is ready. In the next step we will learn how to start the ROS (Robot Operating System).

ROS initialization
------------------

The demo_1 interface and executables are ready (done in the previous step),
now let's start ROS. For that, we will open more sections in Terminator.

Open 4 (four) sections as shown in figure 12 below.

To split the Terminator you can use Ctrl + shift + O to split horizontally or Ctrl + shift + E to split vertically.
Remembering that the new sections have to be in the same workspace.

.. figure:: /img/ur3/lab1/ter_4.png
    :width: 800px
    :height: 400px
    :scale: 100 %
    :alt: Terminatopor 4 section
    :align: center

    Figure 12.

Para iniciar o ROS use o comando:

    * $ roscore

When ROS is ready, you will receive a message in one of the sections as shown in figure 13 shown below.

.. figure:: /img/ur3/lab1/roscore.png
    :width: 800px
    :height: 400px
    :scale: 100 %
    :alt: roscore
    :align: center

    Figure 13.

NOTE: Don't touch the section that ROS is running.

Running Demo_1
--------------

To run **demo_1**, we will first run the **interface** (Use another section of Terminator).
For this, we will configure setup of the ROS package with the following command:

    * $ source devel/setup.bash 

Do this for all sections of the Terminator except for the one running ROS.

Now let's "run" the interface application.
To do this, type the command shown below and press ENTER on one of the Terminator sections.

    * $ rosrun ur3 interface

If everything is working as expected,
the message we will get in return for this command is shown below in figure 14.

.. figure:: /img/ur3/lab1/inter.png
    :width: 800px
    :height: 400px
    :scale: 100 %
    :alt: inter
    :align: center

    Figure 14.
 
When you have confirmation that the robot is ready (UR3 is ready) we can run demo_1.

Now, in another section of Terminator, we will "run" the demo-1 application.
To do this, type the command shown below and press ENTER.

    * $ rosrun ur3 demo_1

At this point, the robot should start making a repetitive movement and after a few seconds it will stop.
After that movement for the robot will have executed demo_1.

View topics
-----------

Topics are data structures in which the variables of the robot joints are published.
In this robot, there are two topics, but for this experiment,
we will focus on just one that will be the topic **arm**.

In order to observe the data present in the topic **arm**,
we will type, in another section of **Terminator** the following command:

    * $ rostopic echo /arm

Figure 15, shown below, shows the result of this command with its respective variables.

.. figure:: /img/ur3/lab1/topic.png
    :width: 800px
    :height: 200px
    :scale: 100 %
    :alt: topic
    :align: center

    Figure 15.

You can "kill" this command by typing ctrl + C.

rqt_plot: Graphical data visualization interface
------------------------------------------------

To have a visualization of the joint data in a graphical interface,
we will use the application rqt_plot.
This application allows the user to observe that of a variable over time.

Given that explanation, let's use the tool.
To do this, type the command shown below.

    * $ rqt_plot

Figure 16, shown below, shows the application rqt_plot with
one of the variables (joint speed 0 (zero)) being shown over time.

.. figure:: /img/ur3/lab1/rqt.png
    :width: 800px
    :height: 400px
    :scale: 100 %
    :alt: rqt_plot
    :align: center

    Figure 16.

To see a particular variable, type/arm/variable[joint number] in Topic below MatPlot.

Saving the experiment to a file
-------------------------------

To save the data, just type the following command:

    * $ rosbag record /arm

With this command you will write the data for all topics in a bag file.

Turning off Robot and Computer
------------------------------

To turn the robot off, press the **POWER** button, figure 1, and then click **Power Off**.

To shut down the computer, close all **Terminator** tabs and shut down Ubuntu normally.



