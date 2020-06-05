Sistema Operacional
===================

Um computador digital com determinada complexidade que exige o gerenciamento dos recursos do sistema e tais funções primárias necessitam de um sistema operacional. O núcleo ou kernel é a parte mais importante e de nível mais baixo de um sistema operacional, ele tem a função de definir qual programa recebe atenção do processador, gerenciar memória, criar um sistema de arquivos, gerenciar o sistema de comunicação etc.

O primeiro passo para a utilização desse computador, é a criação e configuração de uma imagem de sistema operacional que atende aos requisitos do projeto. São eles: compatibilidade com o computador utilizado, *Overo WaterStorm COM*, e suporte para aplicações em tempo real.

Um Sistema Operacional de Tempo Real ou RTOS (*Real Time Operating Systems*) é um sistema operacional destinado à execução de múltiplas tarefas com tempo de resposta a um evento (externo ou interno) pré-definido. Existem duas abordagens para a execução de aplicações de tempo real em Linux, uso de ferramentas que implementam um kernel duplo ou o uso de RTL (Real-time Linux). 

RT-Mag
~~~~~~

Inicialmente, foi decidido a utilização da ferramenta RT-MaG como sistema operacional do sistema embarcado. 

O projeto RT-MaG (*Real-Time - Marseille Grenoble Project*) é um projeto desenvolvido pelo Gipsa-Lab (Grenoble, França) e o Institute of Mouvement Sciences (ISM, Marseille, França). O objetivo deste projeto é fornecer ferramentas eficientes para a prototipagem rápida de robôs para pesquisa e aplicações acadêmicas. O RT-MaG fornece uma caixa de ferramentas para Matlab e Simulink para programar sistemas Linux-COM. Com a ferramenta, pode-se facilmente gerar um aplicativo autônomo em tempo real a partir de um modelo Simulink para um robô usando um sistema Linux.

.. figure:: /img/Aerial/FlyingRobot_small.jpg
   :align: right
   :width: 280 px
   :figwidth: 300 px
   :alt: RT X4-MaG, primeiro robô desenvolvido utilizando o sistema RT-Mag

   RT X4-MaG, primeiro robô desenvolvido utilizando o sistema RT-Mag

Essas ferramentas consistem em um conjunto de blocos simulink que fornecem acesso direto às entradas e saídas do computador. Os modelos Simulink são convertidos automaticamente em aplicações em tempo real. O uso dessas ferramentas é totalmente gratuito. Além disso, atualmente, o Gumstix Overo COM é totalmente compatível com o sistema RT-MaG.

Entretanto, a ferramenta RT-MaG toma para si muitas das operações necessárias para a operação do nosso sistema, o que impossibilita utiliza-lo da maneira que ele foi idealizado, em consequência disto a demasiada simplificação da etapa poderia prejudicar aplicações futuras. Com essa ferramenta seria inviável utilizar o protocolo de comunicação *MAVLink* do piloto automático para comunicação entre os dispositivos ou aeronaves, por exemplo.

Destaca-se ainda a documentação desatualizada, que dificultou a instalação dos componentes da ferramenta como a toolbox do Matlab, que nunca chegou a funcionar, e o sistema operacional do computador embarcado. A complexidade na utilização do sistema aumentava a cada etapa enquanto mesmo as etapas iniciais mais simples ainda não funcionavam adequadamente.

.. Note::
   Mais detalhes do projeto RT-MaG podem ser encontrados em `Projet RT-MaG`_.

.. _Projet RT-MaG: http://www.gipsa-lab.fr/projet/RT-MaG/#

Linux
~~~~~

.. figure:: /img/Aerial/linux.png
   :align: right
   :width: 160 px
   :alt: Tux, a mascote do Linux

   Tux, a mascote do Linux

O Linux é um sistema operacional popularmente utilizado em sistemas embarcados. Além de fornecer suporte para mais arquiteturas computacionais que qualquer outro sistema, ele ainda é leve e possui código aberto, minimizando os custos de implementação. Dos diferentes sistemas operacionais suportados pelas placas Gumstix Overo, destacam-se os sistemas baseados em Linux. Sendo o **Ubuntu** e o **Yocto Project** os principais, além de serem recomendados pelo próprio fabricante.

Projeto Yocto
-------------

.. figure:: /img/Aerial/yocto.png
   :align: left
   :width: 200 px
   :figwidth: 220 px

   

O projeto Yocto é um projeto de colaboração open source da `Linux Foundation`_, cujo objetivo é produzir e fornecer metadados, ferramentas e processos para ajudar seus usuários a criar distribuições baseadas em Linux para *softwares* embarcados, independentemente da arquitetura do sistema. 

.. _Linux Foundation: https://www.linuxfoundation.org/

Um elemento a ser destacado dentre os componentes do Projeto Yocto é o sistema de compilação baseado na arquitetura `OpenEmbedded`_, que permite que os desenvolvedores criem suas próprias distribuições Linux especificas para seu ambiente, de acordo com suas próprias necessidades.  Essas configurações do Project Yocto fornecidas pelos fornecedores de hardware geralmente incluem configurações do kernel, módulos do kernel, firmware do kernel e pacotes do sistema básico. 

Outra ferramenta importante do Yocto Project é o sistema de compilação por referência Poky. Ele contém a ferramenta BitBake, que permite a compilação cruzada independentemente da plataforma. Além disso, o BitBake gerencia todos os arquivos de configuração e dados, e tenta reduzir o tempo de compilação usando todos os recursos de processamento disponíveis.

Infelizmente, com a ampla versatilidade do Projeto Yocto, a complexidade do processo de criação de uma distribuição personalizada também está aumentando.

.. _OpenEmbedded: https://www.openembedded.org/wiki/Main_Page

.. Note::
   Mais detalhes do projeto Yocto podem ser encontrados em `yoctoproject.org`_.

.. _yoctoproject.org: https://www.yoctoproject.org/

Ubuntu
------

.. figure:: /img/Aerial/ubuntu.jpg
   :align: left
   :width: 200 px
   :figwidth: 220 px

Ubuntu é um sistema operacional de código aberto, desenvolvido a partir do núcleo Linux, baseado no Debian. O Ubuntu é desenvolvido pela `Canonical`_ e pela comunidade em um modelo de governança meritocrática. A Canonical fornece atualizações gratuitas de segurança e suporte para cada versão do Ubuntu. Todas as versões são disponibilizadas sem custo algum.

.. _Canonical: https://canonical.com/

A vantagem de se utilizar o sistema Ubuntu é que esse é um sistema operacional a partir do núcleo Linux muito difundido que já contém diversos softwares que podem ser úteis para algumas aplicações futuras, ele contém, por exemplo, um compilador o que facilita a criação e execução de códigos simples para testes rápidos. 

A desvantagem de se utilizar este sistema operacional é que podem ser executadas muitas tarefas paralelas desnecessárias que diminuem a especificidade e o desempenho do computador embarcado. 

.. Note::
   Mais detalhes a respeito do Ubuntu podem ser encontrados em `ubuntu.com`_.

.. _ubuntu.com: https://ubuntu.com/

Sistema Escolhido
~~~~~~~~~~~~~~~~~

Chegamos a instalar o RT-Mag no sistema embarcado, entretanto, devido a complicações posteriores à instalação do sistema operacional, optou-se por não mais utilizar essa ferramenta. 

Decidiu-se então utilizar o núcleo oferecido pelo Projeto Yocto por ser específico para o modelo de computador embarcado. Optando pela instalação do sistema Ubuntu 15.04 em um dos computadores com o intuito de analisar as diferenças entre os dois sistemas operacionais e realizar testes. 

Entretanto, o sistema Ubuntu, apesar de ser uma versão estável e adaptada para o sistema em questão, apresentou erros não solucionados no processo de instalação, impossibilitando a instalação do sistema em um cartão SD. 

.. Não foi possível instalar o sistema Ubuntu
.. Decidiu-se então utilizar o núcleo oferecido pelo Projeto Yocto por ser específico para o modelo de computador embarcado. Todavia, realizamos a instalação do Ubuntu em um dos computadores embarcados com o intuito de analisar as diferenças entre às duas principais opções de sistemas operacionais. O sistema Ubuntu instalado foi o Ubuntu 15.04 por ser uma versão estável e adaptada para o sistema em questão.


Referencias
-----------

	* PITA, H. C. Desenvolvimento de sistema de comunicação multiplataforma para veículos aéreos de asa fixa. Faculdade de Tecnologia, Universidade de Brasília, 2018.

	* ROCHA, E. M. C. Desenvolvimento de um sistema com veículos aéreos não-tripulados autônomos. Faculdade de Tecnologia, Universidade de Brasília, 2017.

	* Phanuel Hieber. Yocto Project on the Gumstix Overo Board. Technische Universität München. 

	* `RT-MaG Project`_ - gipsa-lab.fr

	* `Yocto Project`_ - yoctoproject.org

.. _RT-MaG Project: http://www.gipsa-lab.fr/projet/RT-MaG/
.. _Yocto Project: https://www.yoctoproject.org/

.. https://www.gumstix.com/images/1241515-1.pdf
