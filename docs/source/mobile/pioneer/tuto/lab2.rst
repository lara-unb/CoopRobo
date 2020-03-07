Mobile Robotics Lab 2
=====================

Objetivos
---------

Aprender sobre mensagens e tópicos do ROS.


Procedimentos
-------------

Abra o terminal e inicie o nó central do ROS:
    * $ roscore

Em outro terminal inicie o turtlesim:
    * $ rosrun turtlesim turtlesim_node

O ROS usa um sistema de comunicação distribuída em que os executáveis, chamados de nós, usam tópicos para a troca de mensagens. Um nó pode publicar e/ou se inscrever em um tópico. Para ver os tópicos ativos, abra um novo terminal e use o comando:
    * $ rostopic list

Este comando irá listar todos os tópicos ativos. Para ver o nós ativos use:
    * $ rosnode list

Para ver as informações de um nó, use rosnode info /nome_do_no:
    * $ rosnode info /turtlesim

Este comando irá mostrar os tópicos que são publicados e ouvidos pelo nó turtlesim. Para mover a tartaruga do turtlesim deve-se publicar no tópico /turtle1/cmd_vel. Cada tópico no ROS tem um único tipo de mensagem. Para saber qual o tipo da mensagem publicada no tópico /turtle1/cmd_vel use o comando:
    * $ rostopic info /turtle1/cmd_vel

Este comando mostrará o tipo de mensagem, os ‘publishers’ e os ‘subscribers’ deste tópico. O tipo ‘geometry_msgs/Twist’ representa uma velocidade como uma velocidade angular e uma velocidade linear. Para ver a estrutura dessa mensagem visite http://docs.ros.org/api/geometry_msgs/html/msg/Twist.html ou use o comando:
    * $ rosmsg show geometry_msgs/Twist
    * Obs.: Todas as unidades no ROS estão no Sistema Internacional de Unidades (SI), portanto a velocidade se dá em m/s;

Para publicar uma mensagem no tópico /turtle1/cmd_vel, use o comando:
    * $ rostopic pub /turtle1/cmd_vel geometry_msgs/Twist "{linear:[0.0, 0.0, 0.0], angular:[0.0, 0.0, 0.0]}"
    * Obs.: a tecla TAB pode ser usada para completar os comandos;

O primeiro argumento da mensagem representa a velocidade linear e suas componentes x, y e z. Já o segundo argumento representa a velocidade angular e suas componentes. Como a tartaruga está sendo simulada em um ambiente 2D apenas as velocidades linear em x e angular em z farão a tartaruga se mover. Para isso use, por exemplo:
    * $ rostopic pub /turtle1/cmd_vel geometry_msgs/Twist "{linear:[1.0, 0.0, 0.0], angular:[0.0, 0.0, 0.0]}"

Para enviar uma mensagem em loop, deve-se adicionar o argumento ‘-r <frequência_do_loop>’. Para enviar o mesmo comando acima em um loop de 10 Hz, por exemplo, use:
    * $ rostopic pub /turtle1/cmd_vel geometry_msgs/Twist "{linear:[0.0, 0.0, 0.0], angular:[0.0, 0.0, 1.0]}" -r 10

Para ver o que está sendo publicado em um nó pode se usar ‘rostopic echo’:
    * $ rostopic echo /turtle1/cmd_vel
    * $ rostopic echo /turtle1/pose

Usando os comando acima faça a tartaruga desenhar uma linha.
Usando os comando acima faça a tartaruga desenhar um quadrado.
Usando os comando acima faça a tartaruga desenhar um círculo.

Referências
-----------

Para mais informações sobre tópicos, mensagens e nós visite:

* http://wiki.ros.org/ROS/Tutorials/UnderstandingNodes
* http://wiki.ros.org/ROS/Tutorials/UnderstandingTopics
* Referência sobre geometry_msgs: http://wiki.ros.org/geometry_msgs
* Referência sobre o turtlesim: http://wiki.ros.org/turtlesim

