Partitioning the SD Card
========================

.. https://www.gumstix.com/support/getting-started/create-bootable-microsd-card

.. https://processors.wiki.ti.com/index.php/How_to_Make_3_Partition_SD_Card#How_to_Make_2_Partition_SD_Card

.. Este guia descreve o processo de particionamento, utilizando um sistema Linux, de um cartão microSD em duas partes, denominadas de **boot** e **rootfs** com o objetivo de gerar um cartão SD bootável. O procedimento descrito abaixo é realizado utilizando o gerenciador de discos do próprio Ubuntu, não sendo necessário instalar novos *softwares*. 

This guide describes the partitioning process, using a Linux system, of a microSD card in two parts, called **boot** and **rootfs** in order to generate a bootable SD card. The procedure described below is performed using the disk manager of Ubuntu itself, it is not necessary to install new *software*.

.. Usualmente, o cartão microSD é configurado em uma única partição formatada no padrão Windows FAT, configuração típica encontrada em cartões adquiridos em varejo. Porém, aqui particionaremos o cartão microSD em duas partes, que serão denominadas **boot** e **rootfs**, sendo o sistema de gestão de arquivos da partição **boot** "VFAT" e da partição **rootfs** "ext4".

Usually, the microSD card is configured in a single partition formatted in the Windows FAT standard, a typical configuration found in cards purchased at retail. However, here we will partition the microSD card into two parts, which will be called **boot** and **rootfs**, with the file management system of the **boot** partition "VFAT" and the **rootfs** partition "ext4".

.. A figura abaixo apresenta um exemplo de cartão de memória com as partições já definidas, montadas e contendo o sistema operacional do computador embarcado. No exemplo o cartão SD possui um total de 4 GB, porém, para o projeto Yocto, um cartão de memória de 2 GB deve ser suficiente.

The figure below shows an example of a memory card with the partitions already defined, mounted and containing the operating system of the embedded computer. In the example the SD card has a total of 4 GB, however, for the Yocto project, a 2 GB memory card should be enough.



.. figure:: /img/Aerial/SD_parted.png
	:align: center
	:width: 450 px

Procedures
~~~~~~~~~~

	.. Warning::
		The operating system version used in the activities was Ubuntu 20.04 (LTS), however the commands are the same for older versions of Ubuntu, starting with Ubuntu 14.04 (LTS). The procedures may differ depending on the version and distribution of Linux being used.

1.	Insert the microSD card or an adapter with it into an available port on your Linux computer.

2. Search your computer for an application called **Disks** and launch it. Upon opening, the application will display the memory devices connected to the computer.

	.. figure:: /img/Aerial/SD_card/disks.png
		:align: center

3.	In the **Disks** tab, select the microSD card you want to partition.

	.. figure:: /img/Aerial/SD_card/discos.png
		:align: center

4. Click "**Unmount the file system**" below **Volumes** to enable modifications to the microSD card.

	.. figure:: /img/Aerial/SD_card/desmontar.png
		:align: center

5. To create new partitions in different formats it is recommended to delete the partition on your microSD card, for this, click on "**Delete partition**".

	.. figure:: /img/Aerial/SD_card/excluir1.png
		:align: center

	.. Warning::
		This step will format your microSD card, so all data on it will be permanently deleted.

	.. figure:: /img/Aerial/SD_card/excluir2.png
		:align: center

6. Click "**Create a new partition** to create the first partition. 

	.. figure:: /img/Aerial/SD_card/nova_particao1.png
		:align: center

	This partition will be named "**boot**", will have a size of 528MB and will be configured with the file management type "FAT", as shown below. After configuring, click on "**Create**" to generate this new partition.

	.. figure:: /img/Aerial/SD_card/nova_particao2.png
		:align: center

	.. figure:: /img/Aerial/SD_card/nova_particao3.png
		:align: center


	Then, go to **More Actions**> **Edit partition**, set the **Partition type** to "**W95 FAT32 (LBA)**" and activate the option **Startable** to determine that this partition is where the operating system should be loaded.

	.. figure:: /img/Aerial/SD_card/editar_particao1.png
		:align: center

	.. figure:: /img/Aerial/SD_card/editar_particao3.png
		:align: center

	.. Tip:: 
		In this example, 528 MB has been reserved for the boot partition, however, less than 100 MB is used for boot. Therefore, if there is a lack of space for data storage in the future, it will be possible to expand the roots partition by redoing this division.

7. Now we are going to create the second partition, called **rootfs**. Therefore, select the free space of the SD card and click **Create partition in empty space**.

	.. figure:: /img/Aerial/SD_card/seg_part1.png
		:align: center

	This partition will be named "**rootfs**" and we will allocate all the remaining memory on the SD card to it. This partition will be configured with the "Ext4" file management type, the default file system for current GNU / Linux systems. After configuring, click on "**Create**" to generate this new partition.

	.. figure:: /img/Aerial/SD_card/seg_part2.png
		:align: center

	.. figure:: /img/Aerial/SD_card/seg_part3.png
		:align: center

	On a successful run, the result will be similar to the figure below, where the procedures were applied to an 8GB card.

	.. figure:: /img/Aerial/SD_card/seg_part4.png
		:align: center

8. (Optional) To reassemble the partitions, just select the partition and click **Mount the selected partition**. This tool will automatically mount the selected partition to the file system /media/<User_Name>



	.. figure:: /img/Aerial/SD_card/montando1.png
		:align: center

	.. figure:: /img/Aerial/SD_card/montando2.png
		:align: center


.. fontes
.. repositório GitHub: https://github.com/gumstix/meta-gumstix-extras/blob/dizzy/scripts/mk2partsd
.. How to Make 2 Partition SD Card: https://processors.wiki.ti.com/index.php/How_to_Make_3_Partition_SD_Card#How_to_Make_2_Partition_SD_Card
.. Create Bootable MicroSD Card: https://www.gumstix.com/support/getting-started/create-bootable-microsd-card

References
----------

	* `Create Bootable MicroSD Card`_ - gumstix.com
	* `Script - Make 2 Partition SD Card`_ - github.com
	* `How to Make 2 Partition SD Card - Texas Instruments Processors Wiki`_ 	
	* PITA, H. C. Desenvolvimento de sistema de comunicação multiplataforma para veículos aéreos de asa fixa. Faculdade de Tecnologia, Universidade de Brasília, 2018.

.. _Create Bootable MicroSD Card: https://www.gumstix.com/support/getting-started/create-bootable-microsd-card
.. _Script - Make 2 Partition SD Card: https://github.com/gumstix/meta-gumstix-extras/blob/dizzy/scripts/mk2partsd
.. _How to Make 2 Partition SD Card - Texas Instruments Processors Wiki: https://processors.wiki.ti.com/index.php/How_to_Make_3_Partition_SD_Card#How_to_Make_2_Partition_SD_Card