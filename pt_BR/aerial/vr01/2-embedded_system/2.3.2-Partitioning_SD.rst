Particionando o Cartão SD
=========================

.. https://www.gumstix.com/support/getting-started/create-bootable-microsd-card

.. https://processors.wiki.ti.com/index.php/How_to_Make_3_Partition_SD_Card#How_to_Make_2_Partition_SD_Card

Este guia descreve o processo de particionamento, utilizando um sistema Linux, de um cartão microSD em duas partes, denominadas de **boot** e **rootfs** com o objetivo de gerar um cartão SD bootável. O procedimento descrito abaixo é realizado utilizando o gerenciador de discos do próprio Ubuntu, não sendo necessário instalar novos *softwares*. 

Usualmente, o cartão microSD é configurado em uma única partição formatada no padrão Windows FAT, configuração típica encontrada em cartões adquiridos em varejo. Porém, aqui particionaremos o cartão microSD em duas partes, que serão denominadas **boot** e **rootfs**, sendo o sistema de gestão de arquivos da partição **boot** "VFAT" e da partição **rootfs** "ext4".

A figura abaixo apresenta um exemplo de cartão de memória com as partições já definidas, montadas e contendo o sistema operacional do computador embarcado. No exemplo o cartão SD possui um total de 4 GB, porém, para o projeto Yocto, um cartão de memória de 2 GB deve ser suficiente.

.. figure:: /img/Aerial/SD_parted.png
	:align: center
	:width: 450 px

Procedimentos
~~~~~~~~~~~~~

	.. Warning::
		A versão do sistema operacional utilizada nas atividades foi o Ubuntu 20.04 (LTS), porém os comandos são os mesmos para versões mais antigas do Ubuntu, a partir do Ubuntu 14.04 (LTS). Os procedimentos podem ter algumas diferenças a depender da versão e distribuição do Linux a ser utilizada.

1.	Insira o cartão microSD ou um adaptador com ele em uma porta disponível no seu computador Linux.

2. Pesquise em seu computador um aplicativo chamado **Discos** (*Disks*) e o inicie. Logo ao abrir, o aplicativo exibira os dispositivos de memória conectados ao computador.

	.. figure:: /img/Aerial/SD_card/disks.png
		:align: center

3.	Na aba de **Discos**, selecione o cartão microSD que deseja particionar.

	.. figure:: /img/Aerial/SD_card/discos.png
		:align: center

4. Clique em "**Desmontar o sistema de arquivos**" abaixo de **Volumes** para habilitar modificações no cartão microSD.

	.. figure:: /img/Aerial/SD_card/desmontar.png
		:align: center

5. Para criar novas partições em diferentes formatos é recomendado excluir a partição do seu cartão microSD, para isso, clique em "**Excluir partição**".

	.. figure:: /img/Aerial/SD_card/excluir1.png
		:align: center

	.. Warning::
		Está etapa irá formatar o seu cartão microSD, portanto, todos os dados ali presentes serão excluídos permanentemente.

	.. figure:: /img/Aerial/SD_card/excluir2.png
		:align: center

6. Clique em "**Criar uma nova partição** para criar a primeira partição. 

	.. figure:: /img/Aerial/SD_card/nova_particao1.png
		:align: center

	Está partição será nomeada como "**boot**", terá um tamanho de 528MB e será configurado com o tipo de gestão de arquivos "FAT", como exemplificado abaixo. Após configurar, clique em "**Criar**" para gerar está nova partição.

	.. figure:: /img/Aerial/SD_card/nova_particao2.png
		:align: center

	.. figure:: /img/Aerial/SD_card/nova_particao3.png
		:align: center


	Em seguida, vá em **Mais Ações** > **Editar partição**, configure o **Tipo de partição** como "**W95 FAT32 (LBA)**" e ative a opção "**Iniciável** para determinar que é nesta partição que o sistema operacional deve ser carregado.

	.. figure:: /img/Aerial/SD_card/editar_particao1.png
		:align: center

	.. figure:: /img/Aerial/SD_card/editar_particao3.png
		:align: center

	.. Tip:: 
		Neste exemplo, foram reservados 528 MB para a partição de boot, entretanto, utilizam-se para inicialização menos de 100 MB. Sendo assim, caso futuramente venha a faltar espaço para armazenamento de dados será possível ampliar a partição roots refazendo esta divisão.

7. Agora iremos criar a segunda partição, chamada de **rootfs**. Portanto, selecione o espaço livre do cartão SD e clique em **Criar partição em espaço vazio**.

	.. figure:: /img/Aerial/SD_card/seg_part1.png
		:align: center

	Está partição será nomeada como "**rootfs**" e para ela destinaremos toda a memória remanescente no cartão SD. Esta partição será configurada com o tipo de gestão de arquivos "Ext4", sistema de arquivos padrão dos atuais sistemas GNU/Linux. Após configurar, clique em "**Criar**" para gerar está nova partição.

	.. figure:: /img/Aerial/SD_card/seg_part2.png
		:align: center

	.. figure:: /img/Aerial/SD_card/seg_part3.png
		:align: center

	Em uma execução bem-sucedida, o resultado será similar a figura abaixo, onde os procedimentos foram aplicados em um cartão de 8GB.

	.. figure:: /img/Aerial/SD_card/seg_part4.png
		:align: center

8. (Opcional) Para remontar as partições, basta apenas selecionar a partição e clicar em **Montar a partição selecionada**. Está ferramenta irá montar, automaticamente, a partição selecionada ao sistema de arquivos /media/<User_Name>

	.. figure:: /img/Aerial/SD_card/montando1.png
		:align: center

	.. figure:: /img/Aerial/SD_card/montando2.png
		:align: center


.. fontes
.. repositório GitHub: https://github.com/gumstix/meta-gumstix-extras/blob/dizzy/scripts/mk2partsd
.. How to Make 2 Partition SD Card: https://processors.wiki.ti.com/index.php/How_to_Make_3_Partition_SD_Card#How_to_Make_2_Partition_SD_Card


Referências
-----------

	* `Create Bootable MicroSD Card`_ - gumstix.com
	* `Script - Make 2 Partition SD Card`_ - github.com
	* `How to Make 2 Partition SD Card - Texas Instruments Processors Wiki`_ 	
	* PITA, H. C. Desenvolvimento de sistema de comunicação multiplataforma para veículos aéreos de asa fixa. Faculdade de Tecnologia, Universidade de Brasília, 2018.

.. _Create Bootable MicroSD Card: https://www.gumstix.com/support/getting-started/create-bootable-microsd-card
.. _Script - Make 2 Partition SD Card: https://github.com/gumstix/meta-gumstix-extras/blob/dizzy/scripts/mk2partsd
.. _How to Make 2 Partition SD Card - Texas Instruments Processors Wiki: https://processors.wiki.ti.com/index.php/How_to_Make_3_Partition_SD_Card#How_to_Make_2_Partition_SD_Card
