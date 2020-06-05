Operational System
===================

.. Um computador digital com determinada complexidade que exige o gerenciamento dos recursos do sistema e tais funções primárias necessitam de um sistema operacional. O núcleo ou kernel é a parte mais importante e de nível mais baixo de um sistema operacional, ele tem a função de definir qual programa recebe atenção do processador, gerenciar memória, criar um sistema de arquivos, gerenciar o sistema de comunicação, etc.

A digital computer with a certain complexity that requires the management of system resources and such primary functions require an operating system. The kernel is the most important and lowest level part of an operating system, it has the function of defining which program receives attention from the processor, managing memory, creating a file system, managing the communication system, etc.

.. O primeiro passo para a utilização desse computador, é a criação e configuração de uma imagem de sistema operacional que atende aos requisitos do projeto. São eles: compatibilidade com o computador utilizado, *Overo WaterStorm COM*, e suporte para aplicações em tempo real.

The first step in using this computer is to create and configure an operating system image that meets the requirements of the project. They are: compatibility with the computer used, *Overo WaterStorm COM*, and support for real-time applications.

.. Um Sistema Operacional de Tempo Real ou RTOS (*Real Time Operating Systems*) é um sistema operacional destinado à execução de múltiplas tarefas com tempo de resposta a um evento (externo ou interno) pré-definido. Existem duas abordagens para a execução de aplicações de tempo real em Linux, uso de ferramentas que implementam um kernel duplo ou o uso de RTL (Real-time Linux). 

An Real Time Operating Systems (**RTOS**) is an operating system destined to the execution of multiple tasks with response time to a pre-defined event (external or internal). There are two approaches to running real-time applications on Linux, using tools that implement a dual kernel or using RTL (Real-time Linux).

RT-Mag
~~~~~~

.. Inicialmente, foi decidido a utilização da ferramenta RT-MaG como sistema operacional do sistema embarcado. 

Initially, it was decided to use the RT-MaG tool as an operating system for the embedded system.

.. O projeto RT-MaG (*Real-Time - Marseille Grenoble Project*) é um projeto desenvolvido pelo Gipsa-Lab (Grenoble, França) e o Institute of Mouvement Sciences (ISM, Marseille, França). O objetivo deste projeto é fornecer ferramentas eficientes para a prototipagem rápida de robôs para pesquisa e aplicações acadêmicas. O RT-MaG fornece uma caixa de ferramentas para Matlab e Simulink para programar sistemas Linux-COM. Com a ferramenta, pode-se facilmente gerar um aplicativo autônomo em tempo real a partir de um modelo Simulink para um robô usando um sistema Linux.

The RT-MaG project (*Real-Time - Marseille Grenoble Project*) is a project developed by Gipsa-Lab (Grenoble, France) and the Institute of Mouvement Sciences (ISM, Marseille, France). The aim of this project is to provide efficient tools for rapid prototyping of robots for research and academic applications. RT-MaG provides a toolbox for Matlab and Simulink to program Linux-COM systems. With the tool, you can easily generate a standalone application in real time from a Simulink model for a robot using a Linux system.

.. figure:: /img/Aerial/FlyingRobot_small.jpg
   :align: right
   :width: 280 px
   :figwidth: 300 px
   :alt: RT X4-MaG, primeiro robô desenvolvido utilizando o sistema RT-Mag

   RT X4-MaG, first robot developed using the RT-Mag system

.. Essas ferramentas consistem em um conjunto de blocos simulink que fornecem acesso direto às entradas e saídas do computador. Os modelos Simulink são convertidos automaticamente em aplicações em tempo real. O uso dessas ferramentas é totalmente gratuito. Além disso, atualmente, o Gumstix Overo COM é totalmente compatível com o sistema RT-MaG.

These tools consist of a set of simulink blocks that provide direct access to the computer's inputs and outputs. Simulink models are automatically converted into real-time applications. The use of these tools is completely free. In addition, Gumstix Overo COM is currently fully compatible with the RT-MaG system.

.. Entretanto, a ferramenta RT-MaG toma para si muitas das operações necessárias para a operação do nosso sistema, o que impossibilita utiliza-lo da maneira que ele foi idealizado, em consequência disto a demasiada simplificação da etapa poderia prejudicar aplicações futuras. Com essa ferramenta seria inviável utilizar o protocolo de comunicação *MAVLink* do piloto automático para comunicação entre os dispositivos ou aeronaves, por exemplo.

However, the RT-MaG tool takes on many of the operations necessary for the operation of our system, which makes it impossible to use it in the way it was designed, as a result, too much simplification of the stage could harm future applications. With this tool, it would be impracticable to use the autopilot *MAVLink* communication protocol for communication between devices or aircraft, for example.

.. Destaca-se ainda a documentação desatualizada, que dificultou a instalação dos componentes da ferramenta como a toolbox do Matlab, que nunca chegou a funcionar, e o sistema operacional do computador embarcado. A complexidade na utilização do sistema aumentava a cada etapa enquanto mesmo as etapas iniciais mais simples ainda não funcionavam adequadamente.

Also noteworthy is the outdated documentation, which made it difficult to install the tool's components, such as the Matlab toolbox, which never worked, and the operating system of the embedded computer. The complexity in using the system increased with each step while even the simplest initial steps still did not work properly.

.. Note::
   More details of the RT-MaG project can be found at `Projet RT-MaG`_.

.. _Projet RT-MaG: http://www.gipsa-lab.fr/projet/RT-MaG/#

Linux
~~~~~

.. figure:: /img/Aerial/linux.png
   :align: right
   :width: 160 px
   :alt: Tux, a mascote do Linux

   Tux, the mascot of Linux

.. O Linux é um sistema operacional popularmente utilizado em sistemas embarcados. Além de fornecer suporte para mais arquiteturas computacionais que qualquer outro sistema, ele ainda é leve e possui código aberto, minimizando os custos de implementação. Dos diferentes sistemas operacionais suportados pelas placas Gumstix Overo, destacam-se os sistemas baseados em Linux. Sendo o **Ubuntu** e o **Yocto Project** os principais, além de serem recomendados pelo próprio fabricante.

Linux is an operating system popularly used in embedded systems. In addition to providing support for more computational architectures than any other system, it is still lightweight and open source, minimizing implementation costs. Of the different operating systems supported by Gumstix Overo cards, Linux-based systems stand out. Being **Ubuntu** and **Yocto Project** the main ones, besides being recommended by the manufacturer itself.


Projeto Yocto
-------------

.. figure:: /img/Aerial/yocto.png
   :align: left
   :width: 200 px
   :figwidth: 220 px

   

.. O projeto Yocto é um projeto de colaboração open source da `Linux Foundation`_, cujo objetivo é produzir e fornecer metadados, ferramentas e processos para ajudar seus usuários a criar distribuições baseadas em Linux para *softwares* embarcados, independentemente da arquitetura do sistema. 

The Yocto project is an open source collaboration project from the `Linux Foundation`_, whose goal is to produce and provide metadata, tools and processes to help its users create Linux-based distributions for embedded software, regardless of the system architecture.

.. _Linux Foundation: https://www.linuxfoundation.org/

.. Um elemento a ser destacado dentre os componentes do Projeto Yocto é o sistema de compilação baseado na arquitetura `OpenEmbedded`_, que permite que os desenvolvedores criem suas próprias distribuições Linux especificas para seu ambiente, de acordo com suas próprias necessidades.  Essas configurações do Project Yocto fornecidas pelos fornecedores de hardware geralmente incluem configurações do kernel, módulos do kernel, firmware do kernel e pacotes do sistema básico. 

One element to be highlighted among the components of the Yocto Project is the build system based on the `OpenEmbedded`_ architecture, which allows developers to create their own Linux distributions specific to their environment, according to their own needs. These Project Yocto configurations provided by hardware vendors generally include kernel configurations, kernel modules, kernel firmware and base system packages.

.. Outra ferramenta importante do Yocto Project é o sistema de compilação por referência Poky. Ele contém a ferramenta BitBake, que permite a compilação cruzada independentemente da plataforma. Além disso, o BitBake gerencia todos os arquivos de configuração e dados, e tenta reduzir o tempo de compilação usando todos os recursos de processamento disponíveis.

Another important tool of the Yocto Project is the Poky reference build system. It contains the BitBake tool, which allows cross-compilation regardless of the platform. In addition, BitBake manages all configuration files and data, and tries to reduce compilation time using all available processing resources.

.. Infelizmente, com a ampla versatilidade do Projeto Yocto, a complexidade do processo de criação de uma distribuição personalizada também está aumentando.

Unfortunately, with the wide versatility of the Yocto Project, the complexity of the process of creating a customized distribution is also increasing.

.. _OpenEmbedded: https://www.openembedded.org/wiki/Main_Page

.. Note::
   More details of the Yocto project can be found at `yoctoproject.org`_.

.. _yoctoproject.org: https://www.yoctoproject.org/

Ubuntu
------

.. figure:: /img/Aerial/ubuntu.jpg
   :align: left
   :width: 200 px
   :figwidth: 220 px

.. Ubuntu é um sistema operacional de código aberto, desenvolvido a partir do núcleo Linux, baseado no Debian. O Ubuntu é desenvolvido pela `Canonical`_ e pela comunidade em um modelo de governança meritocrática. A Canonical fornece atualizações gratuitas de segurança e suporte para cada versão do Ubuntu. Todas as versões são disponibilizadas sem custo algum.

Ubuntu is an open source operating system, developed from the Linux kernel, based on Debian. Ubuntu is developed by `Canonical`_ and the community in a model of meritocratic governance. Canonical provides free security updates and support for each version of Ubuntu. All versions are available at no cost.

.. _Canonical: https://canonical.com/

.. A vantagem de se utilizar o sistema Ubuntu é que esse é um sistema operacional a partir do núcleo Linux muito difundido que já contém diversos softwares que podem ser úteis para algumas aplicações futuras, ele contém, por exemplo, um compilador o que facilita a criação e execução de códigos simples para testes rápidos. 

The advantage of using the Ubuntu system is that it is an operating system from the very popular Linux core that already contains several software that may be useful for some future applications, it contains, for example, a compiler which facilitates the creation and execution of simple codes for rapid tests.

.. A desvantagem de se utilizar este sistema operacional é que podem ser executadas muitas tarefas paralelas desnecessárias que diminuem a especificidade e o desempenho do computador embarcado. 

The disadvantage of using this operating system is that many unnecessary parallel tasks can be performed that decrease the specificity and performance of the embedded computer.

.. Note::
   More details about Ubuntu can be found at `ubuntu.com`_.

.. _ubuntu.com: https://ubuntu.com/

Chosen System
~~~~~~~~~~~~~

.. Chegamos a instalar o RT-Mag no sistema embarcado, entretanto, devido a complicações posteriores à instalação do sistema operacional, optou-se por não mais utilizar essa ferramenta. 

We even installed the RT-Mag on the embedded system, however, due to complications after the installation of the operating system, it was decided not to use this tool anymore.

.. Decidiu-se então utilizar o núcleo oferecido pelo Projeto Yocto por ser específico para o modelo de computador embarcado. Optando pela instalaçao do sistema Ubuntu 15.04 em um dos computadores com o intuito de analisar as diferenças entre os dois sistemas operacionais e realizar testes. 

It was then decided to use the core offered by the Yocto Project as it is specific to the embedded computer model. Choosing to install the Ubuntu 15.04 system on one of the computers in order to analyze the differences between the two operating systems and perform tests.

.. Entretanto, o sistema Ubuntu, apesar de ser uma versão estável e adaptada para o sistema em questão, apresentou erros não solucionados no processo de instalação, impossibilitando a instalação do sistema em um cartão SD.

However, the Ubuntu system, despite being a stable version and adapted to the system in question, presented unresolved errors in the installation process, making it impossible to install the system on an SD card.
 

.. Não foi possivel instalar o sistema Ubuntu
.. Decidiu-se então utilizar o núcleo oferecido pelo Projeto Yocto por ser específico para o modelo de computador embarcado. Todavia, realizamos a instalação do Ubuntu em um dos computadores embarcados com o intuito de analisar as diferenças entre às duas principais opções de sistemas operacionais. O sistema Ubuntu instalado foi o Ubuntu 15.04 por ser uma versão estável e adaptada para o sistema em questão.

References
----------

	* PITA, H. C. Desenvolvimento de sistema de comunicação multiplataforma para veículos aéreos de asa fixa. Faculdade de Tecnologia, Universidade de Brasília, 2018.

	* ROCHA, E. M. C. Desenvolvimento de um sistema com veículos aéreos não-tripulados autônomos. Faculdade de Tecnologia, Universidade de Brasília, 2017.

	* Phanuel Hieber. Yocto Project on the Gumstix Overo Board. Technische Universität München. 

	* `RT-MaG Project`_ - gipsa-lab.fr

	* `Yocto Project`_ - yoctoproject.org

.. _RT-MaG Project: http://www.gipsa-lab.fr/projet/RT-MaG/
.. _Yocto Project: https://www.yoctoproject.org/

.. https://www.gumstix.com/images/1241515-1.pdf
