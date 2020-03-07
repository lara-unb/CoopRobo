Mobile Robotics Lab 3
=====================

Objetivos
---------

O objetivo desse exercício é programar a movimentação de um robô diferencial usando os comando no terminal aprendidos no laboratório passado. Este exercício usará uma versão simulada do robô Pioneer.

Procedimentos
-------------

Na pasta src do seu workspace (catkin_ws/src/) baixe o pacote fcr2018
    * $ git clone https://github.com/Gastd/fcr2018

Atualize as variáveis de ambiente do ROS
    * $ cd ~/catkin_ws
    * $ source devel/ros_custom.sh

Abra a simulação do pioneer
    * $ roslaunch fcr2017 pioneer3at.gazebo.launch

Use o ‘rostopic list’ para descobrir quais mensagens o pioneer publica e quais ele recebe. Use o ‘rostopic echo’ para olhá-las.

Descubra qual tópico o robô usa para publicar as informações do laser

Descubra qual tópico o robô usa para publicar as informações da odometria

Descubra qual tópico é usado para enviar velocidades para o robô

Use o ‘rostopic pub’ para publicar velocidades. Escolha números que façam o robô andar em uma linha reta

Faça o robô andar em um círculo

Faça o robô andar em um retângulo

Referências
-----------
