Sistema Operacional 
====================
.. Note::
   **TESTE**

Um computador digital com determinada complexidade que exige o gerenciamento dos recursos do sistema e tais funções primárias necessitam de um sistema operacional. O núcleo ou kernel é a parte mais importante e de nível mais baixo de um sistema operacional, ele tem a função de definir qual programa recebe atenção do processador, gerenciar memória, criar um sistema de arquivos, gerenciar o sistema de comunicação, etc.

O primeiro passo para a utilização desse computador, é a criação e configuração de uma imagem de sistema operacional que atende aos requisitos do projeto. São eles: compatibilidade com o computador utilizado, *Overo WaterStorm COM*, e suporte para aplicações em tempo real.

Um Sistema Operacional de Tempo Real ou RTOS (*Real Time Operating Systems*) é um sistema operacional destinado à execução de múltiplas tarefas com tempo de resposta a um evento (externo ou interno) pré-definido. Existem duas abordagens para a execução de aplicações de tempo real em Linux, uso de ferramentas que implementam um kernel duplo ou o uso de RTL (Real-time Linux). 

RT-Mag
~~~~~~~

Inicialmente foi decidido em trabalhos anteriores a utilização da ferramenta RT-MaG como sistema operacional do sistema embarcado. 

O projeto RT-MaG (*Real-Time - Marseille Grenoble Project*) é um projeto desenvolvido pelo Gipsa-Lab (Grenoble, França) e o Institute of Mouvement Sciences (ISM, Marseille, França). O objetivo deste projeto é fornecer ferramentas eficientes para a prototipagem rápida de robôs para pesquisa e aplicações acadêmicas. O RT-MaG fornece uma caixa de ferramentas para Matlab e Simulink para programar sistemas Linux-COM. Com a ferramenta, pode-se facilmente gerar um aplicativo autônomo em tempo real a partir de um modelo Simulink para um robô usando um sistema Linux.

Essas ferramentas consistem em um conjunto de blocos simulink que fornecem acesso direto às entradas e saíadas do computador. Os modelos Simulink são convertidos automaticamente em aplicações em tempo real. O uso dessas ferramentas é totalmente gratuito. Além disso, atualmente, o Gumstix Overo COM é totalmente compatatível com o sistema RT-MaG.

Entretanto, a ferramenta RT-MaG toma para si muitas das operações necessárias para a operação do nosso sistema, o que impossibilita utiliza-lo da maneira que ele foi idealizado, em consequência disto a demasiada simplificação da etapa poderia prejudicar aplicações futuras. Com essa ferramenta seria impossível utilizar o protocolo de comunicação "MAVLink"do piloto automático para comunicação entre os dispositivos ou aeronaves, por exemplo.

Destaca-se ainda a documentação desatualizada, que dificultou a instalação dos componentes da ferramenta como a toolbox do Matlab, que nunca chegou a funcionar, e o sistema operacional do computador embarcado. A complexidade na utilização do sistema aumentava a cada etapa enquanto mesmo as etapas iniciais mais simples ainda não funcionavam adequadamente.

Chegamos a instalar a ferramenta no sistema embarcado, entretanto, devido a complicações posteriores à instalação do sistema operacional, optou-se por não mais utilizar essa ferramenta.


Projeto Yocto
~~~~~~~~~~~~~~

Em seguida decidimos utilizar o núcleo oferecido pelo Projeto Yocto por ser específico para o modelo de computador embarcado utilizado por nós e recomendado pela fabricante. O projeto Yocto é um projeto de colaboração open source que fornece modelos, ferramentas e métodos para ajudar seus usuários a criar sistemas baseados em Linux para sistemas embarcados, independentemente da arquitetura do sistema. Mais detalhes do projeto Yocto podem ser encontrados em seu endereço eletrônico2.

Outra opção viável apresentada durante os trabalhos do laboratório foi a utilização do sistema operacional Ubuntu. A vantagem de se utilizar o sistema Ubuntu é que esse é um sistema operacional a partir do núcleo Linux muito difundido que já contém diversos softwares que podem ser úteis para algumas aplicações futuras, ele contém, por exemplo, um compilador o que facilita a criação e execução de códigos simples para testes rápidos. A desvantagem de se utilizar este sistema operacional é que podem ser executadas muitas tarefas desnecessárias que diminuem a especificidade e o desempenho do computador embarcado. Realizamos a instalação deste sistema em um dos computadores embarcados com o intuito de analisar as diferenças entre as duas principais opções de sistemas operacionais. O sistema Ubuntu instalado foi o Ubuntu 15.04 por ser uma versão estável e adaptada para o sistema em questão.

A instalação do sistema operacional não foi algo trivial, além disso existe uma escassez de documentação detalhada e completa que explique como instalar o sistema operacional no computador embarcado, logo será descrito os principais procedimentos necessários para a instalação de um sistema operacional. Na fase atual dos trabalhos instalamos ambos os sistemas, mais tarde podemos decidir qual dos dois sistemas será melhor para nossa aplicação. Nas seções seguintes irei traduzir, comentar e realizar pequenas modificações em tutoriais que podem ser encontrados no próprio site da gumstix3 e nos repositórios do GitHub do projeto Yocto4 e Ubuntu para a Gumstix5.

Obtenção de imagens do SO
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


