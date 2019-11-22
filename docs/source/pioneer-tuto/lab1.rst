Mobile Robotics Lab: Assignment 1
================================= 

Objetivos
---------

Aprender a criar um pacote no ROS.


Introdução
----------

Todo o software produzido no ROS é organizado em pacotes. Um pacote pode conter nós do ROS, bibliotecas independentes, datasets, arquivos de configuração ou qualquer material que possa constituir um módulo. Para que um pacote seja visto pelo ROS ele deve ter no mínimo os seguintes requisitos:

* Deve conter um arquivo chamado package.xml com código catkin;
* Deve conter um arquivo CMakeLists.txt;
* Cada pacote deve ter seu próprio diretório;

O arquivo package.xml reúne todas as informações de autor, nome do pacote, versão do código e dependências. Já o CMakeLists.txt reúne as regras de compilação do pacote.


Procedimentos
-------------

* No terminal, configure o ros com o comando:
    * $ bash.sh
* No novo terminal aberto, entre na pasta catkin_ws. Esse será o ambiente de trabalho a ser usado neste curso:
    * $ cd catkin_ws
* Entre na pasta src. Para o ROS essa é pasta onde fica o código fonte dos pacotes:
    * $ cd src
* Use o script catkin_create_pkg para criar um novo pacote. Esse pacote será chamado de ‘beginner_tutorials’ e terá como dependências os pacotes std_msgs, roscpp e rospy:
    * $ catkin_create_pkg beginner_tutorials std_msgs rospy roscpp
* Este comando irá criar uma pasta chamada de beginner_tutorials que conterá um package.xml e um CMakeLists.txt parcialmente preenchidos com as dependências indicadas. 
    * Abra o CMakeLists.txt em um editor de texto e procure onde as dependências são chamadas.
    * Abra o package.xml em um editor de texto e procure onde as informações de autor, versão e dependências são informadas.
* Para compilar o workspace volte para catkin_ws:
    * $ cd ~/catkin_ws
* Atualize as variáveis de ambiente do ROS:
    * $ cd catkin_ws
    * $ . devel/ros_custom.sh
* Compile o workspace:
    * $ catkin_make

Referências
-----------
Esse tutorial foi baseado no tutorial Creating a ROS Package do ROS:

http://wiki.ros.org/ROS/Tutorials/CreatingPackage

