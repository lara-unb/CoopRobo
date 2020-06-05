Obtaining images from the Yocto Project
=======================================

.. https://github.com/gumstix/yocto-manifest/blob/warrior/README.md

.. Para realizar o processo de iniciação do sistema operacional Yocto Project no computador embarcado Gumstix, precisamos de três arquivos específicos, são eles o primeiro estágio do sistema de iniciação, o arquivo MLO (*Minimal Loader*), o segundo estágio do sistema de iniciação, o arquivo *u-boot.img* (a sigla vem de *Universal Bootloader*), e a imagem do sistema, que em nosso caso será o Yocto 1.8.2 com kernel Linux. 

In order to perform the Yocto Project operating system initiation process on the Gumstix embedded computer, we need three specific files, they are the first stage of the initiation system, the MLO (*Minimal Loader*) file, the second stage of the initiation system, the file *u-boot.img* (the acronym comes from *Universal Bootloader*), and the image of the system, which in our case will be Yocto 1.8.2 with Linux kernel.

.. figure:: /img/Aerial/yocto_exemple.png
   :align: center

.. A figura mostra um exemplo dos arquivos descritos no parágrafo anterior, observe que, neste caso, há também uma pasta compactada que contém os arquivos raiz do sistema operacional. O modo mais simples encontrado para se obter esses arquivos e a imagem do sistema operacional é seguindo os passos do arquivo `README.md`_ do `repositório do projeto Yocto para produtos Gumstix`_. A vantagem de se utilizar esse método ao invés de simplesmente obter a imagem pronta do sistema operacional é que caso seja necessário poderemos modifica-la.

The figure shows an example of the files described in the previous paragraph, note that, in this case, there is also a compressed folder that contains the root files of the operating system. The simplest way found to obtain these files and the operating system image is by following the steps in the `README.md`_ file of the `Yocto project repository for Gumstix products`_. The advantage of using this method instead of simply obtaining the ready image of the operating system is that if necessary, we can modify it.

.. _README.md: https://github.com/gumstix/yocto-manifest/blob/warrior/README.md

.. _Yocto project repository for Gumstix products: https://github.com/gumstix/yocto-manifest

.. Esse tutorial explica como construir manualmente a imagem do sistema Yocto e realizar todos os procedimentos através de linhas de comando do terminal do Linux, com enfase no **Ubuntu 14.04 (LTS)**. Porém, para executar essa etapa é altamente recomendado o cumprimento dos requisitos indicadas pelo projeto Yocto.

This tutorial explains how to manually build the image of the Yocto system and perform all procedures through command lines of the Linux terminal, with an emphasis on **Ubuntu 14.04 (LTS)**. However, to perform this step it is highly recommended to comply with the requirements indicated by the Yocto project.

.. Yocto: https://www.yoctoproject.org/docs/1.7/ref-manual/ref-manual.html

.. Essas versões do Linux podem ser encontradas, junto de mais informações úteis no manual de referência do projeto `Yocto`_ , mais especificamente no item 1.3.1 *Supported Linux Distributions*.

System Requirements
~~~~~~~~~~~~~~~~~~~

.. https://www.yoctoproject.org/docs/1.7/yocto-project-qs/yocto-project-qs.html#yp-resources

.. Note ::
   For more information regarding system requirements, see `System Requirements - Yocto Project Reference Manual`_.

.. _System Requirements - Yocto Project Reference Manual: https://www.yoctoproject.org/docs/1.7/ref-manual/ref-manual.html#intro-requirements

The development of projects in the Yocto Project environment requires that some requirements are met, they are:

	* A system with a minimum of 25 GB of free disk space running a supported Linux distribution. If the host system supports multiple cores and threads, you can configure the Yocto Project build system to significantly decrease the time required to build images.

	* Appropriate packages installed on the system used to perform the builds.

	* A distribution of the Yocto Project.

Project Yocto is currently supported on the following Linux distributions.

	*	Ubuntu 12.04 (LTS)
	*	Ubuntu 13.10
	*	Ubuntu 14.04 (LTS)
	*	Fedora release 19 (Schrödinger's Cat)
	*	Fedora release 20 (Heisenbug)
	*	CentOS release 6.4
	*	CentOS release 6.5
	*	Debian GNU/Linux 7.0 (Wheezy)
	*	Debian GNU/Linux 7.1 (Wheezy)
	*	Debian GNU/Linux 7.2 (Wheezy)
	*	Debian GNU/Linux 7.3 (Wheezy)
	*	Debian GNU/Linux 7.4 (Wheezy)
	*	Debian GNU/Linux 7.5 (Wheezy)
	*	Debian GNU/Linux 7.6 (Wheezy)
	*	openSUSE 12.2
	*	openSUSE 12.3
	*	openSUSE 13.1

.. Note::
   For a more detailed list of distributions that support the Yocto Project, see the `Supported Linux Distributions`_ section in the Yocto Project Reference Manual.

.. _Supported Linux Distributions: http://www.yoctoproject.org/docs/1.7/ref-manual/ref-manual.html#detailed-supported-distros

To build the operating system image, the build system must have the following versions of *software* Git, tar and Python.

	* Git 1.8.3.1 or greater

	* tar 1.27 or greater

	* Python 3.4.0  or greater

.. Note::
   See the `Required Git, tar, and Python Versions`_ section in the Yocto Project Reference Manual for information.

.. _Required Git, tar, and Python Versions: http://www.yoctoproject.org/docs/1.7/ref-manual/ref-manual.html#required-git-tar-and-python-versions

.. Além disso, recomenda-se atualizar os repositorios do Linux. Para tal, no caso de distribuição Ubuntu, basta executar o seguinte comando:  

In addition, it is recommended to update the Linux repositories. To do so, in the case of Ubuntu distribution, just run the following command:

	::

		$ sudo apt-get update && sudo apt-get upgrade

.. É necessária ainda a instalação dos pacotes de host essenciais para a construção da imagem. O comando a seguir instala os pacotes de host com base em sistemas com distribuição Ubuntu.

It is also necessary to install the essential host packages to build the image. The following command installs host packages based on systems with Ubuntu distribution.

	::

		$ sudo apt-get install gawk wget git-core diffstat unzip texinfo gcc-multilib build-essential chrpath socat libsdl1.2-dev xterm curl
	 
.. $ sudo apt-get install gawk wget git-core diffstat unzip texinfo gcc-multilib build-essential chrpath socat cpio python python3 python3-pip python3-pexpect xz-utils debianutils iputils-ping python3-git python3-jinja2 libegl1-mesa libsdl1.2-dev pylint3 xterm curl


.. Note::
   To install host packages on other supported Linux distributions, see the `Required Packages for the Build Host`_ section in Yocto Project Reference Manual.
   
.. _Required Packages for the Build Host: http://www.yoctoproject.org/docs/3.0.1/ref-manual/ref-manual.html#required-packages-for-the-build-host

Configuring the Image
~~~~~~~~~~~~~~~~~~~~~

.. Note::
   The operating system used to test the commands was Ubuntu 14.04 (LTS).

Linhas de comando Linux para obtenção e montagem da imagem.

1.  **Installing the repository**

.. Para fazer o download das imagens do Yocto, primeiro precisamos instalar o comando **repo**. Em resumo, o repo é basicamente um invólucro do git, que fornece uma maneira simples de agrupar vários repositórios git diferentes em um unico projeto. Caso tenha interesse em mais informações sobre o comando **repo**, acesse `repo - gerrit.googlesource.com`_.

To download Yocto images, we first need to install the **repo** command. In summary, the repo is basically a git wrapper, which provides a simple way to group several different git repositories into a single project. If you are interested in more information about the **repo** command, go to `repo - gerrit.googlesource.com`_.

.. _repo - gerrit.googlesource.com: https://gerrit.googlesource.com/git-repo/+/refs/heads/master/README.md

Download the scripts from the repository

	::

		$ curl http://commondatastorage.googleapis.com/git-repo-downloads/repo > repo

Make files executable

	::

		$ chmod a+x repo

Move files to the system path

	::

		$ sudo mv repo /usr/local/bin/

If everything goes well, a message similar to the image should appear when executing the following command. This command is not mandatory.

	::

		$ repo --help

.. figure:: /img/Aerial/yocto_repo.png
   :align: center

2. **Creating a local repository**

Create a directory for the files and change the execution directory for the new repository.

	:: 

		$ mkdir yocto
		$ cd yocto

.. Agora com o repositório já instalado, faremos o download de todas as configurações do Yocto para o nosso projeto. O comando **init** pode levar algum tempo, pois faz o download de todos os repositórios git associados ao projeto. Já o comando **-b** especifica a ramificação a ser usada e o comando **fido** seleciona o ramo mais estável do repositório.

Now with the repository already installed, we will download all the Yocto settings for our project. The **init** command can take some time, as it downloads all the git repositories associated with the project. The command **-b** specifies the branch to be used and the command **fido** selects the most stable branch of the repository.

	::
		
		$ repo init -u git://github.com/gumstix/yocto-manifest.git -b fido

.. Uma inicialização bem-sucedida terminará com uma mensagem informando que o **.repo** foi inicializado no seu diretório de trabalho. Agora seu diretório deve conter uma pasta *.repo* onde os arquivos de controle de repositório estão armazenados, mas não é necessário abrir o diretório.

A successful initialization will end with a message stating that **.repo** has been initialized in your working directory. Your directory should now contain a * .repo * folder where the repository control files are stored, but there is no need to open the directory.

.. figure:: /img/Aerial/yocto_init.png
   :align: center

3. **Downloading the files**

.. O comando a seguir é usado para garantir que todos os seus repositórios estejam atualizados e é útil para atualizar suas configurações do Yocto se você fizer uma compilação posteriormente.

The following command is used to ensure that all of your repositories are up to date and is useful for updating your Yocto settings if you do a build later.

	::

		$ repo sync

.. Note::
   This step can take more than 20 minutes, depending on your internet connection.

.. Force todos os arquivos temporários a serem escritos em dispositivos permanentes atraves do comando: 

Force all temporary files to be written to permanent devices using the command:

	::

		$ sync

4. **Starting the Yocto Project Build Environment**

.. Warning:: 
   If, for any reason, you cancel the activity before completing the Yocto compilation, you will need to execute this command each time before proceeding to the next steps. Keep in mind that this also applies to future builds.

.. Agora que temos nossas configurações básicas do Yocto, entraremos em nosso ambiente de compilação. Por meio do comando a seguir, iremos copiar as informações de configuração padrão no diretório **poky/build/conf** e configurar algumas variáveis de ambiente para o sistema de montagem da imagem.

Now that we have our basic Yocto settings, we will enter our build environment. Using the following command, we will copy the default configuration information into the **poky/build/conf** directory and set some environment variables for the image assembly system.

	::

		$ export TEMPLATECONF=meta-gumstix-extras/conf 
		$ source ./poky/oe-init-build-env

.. Note::
   This configuration directory is not under revision control, so you can edit these configuration files for your specific installation.


5. **Creating the image**

.. O project Yocto utiliza o bitbake para compilar a imagem do Yocto Linux. O Bitbake basicamente compila apenas o SO, o kernel, os módulos e todos os pacotes incluídos no SO Linux de destino. 

The Yocto project uses bitbake to compile the Yocto Linux image. Bitbake basically compiles only the OS, kernel, modules and all packages included in the target Linux OS.

.. Tip::
	(**OPCIONAL**)  
	If you are familiar with compiling via make, you can speed up the compilation process by telling bitbake to compile with more threads. This step is not necessary, but if you are compiling on a system with a high-end CPU with many cores, it will speed up the compilation time. For example:

	``$ export PARALLEL_MAKE="-j 8"``

	The number "8" indicates the number of nuclei to be used in the matching. 
	**It is worth mentioning that you should not specify a value -j greater than the amount of CPU cores present in your construction machine**.

.. Assim, para baixar os códigos fonte e compilar as imagens do sistema execute:

So, to download the source codes and compile the system images, run:

	::

		$ bitbake gumstix-console-image

.. Note::
   This process downloads several gigabytes of code and then makes a huge build. So, make sure you have at least 25GB of free space. This step may take a day or more to create the image, depending on your internet connection. Don't worry, it's just the first build that takes a while.

.. Após a finalização da execução de todos os comandos, recomenda-se verificar a pasta **/yocto/build/tmp/deploy/images/overo**, essa pasta deve conter arquivos binários de kernel e bootloaders e arquivos de diretório raiz no formato .tar. 

After completing the execution of all commands, it is recommended to check the folder **yocto/build/tmp/deploy/images/overo**, this folder must contain binary kernel files and bootloaders and root directory files in the format .tar.

.. A figura abaixo apresenta um exemplo do conteúdo da pasta descrita, essa pasta deve ser semelhante ao obtido após a execução dos procedimentos anteriores.

The figure below shows an example of the contents of the described folder, this folder must be like the one obtained after performing the previous procedures.

.. figure:: /img/Aerial/yocto_image.png
   :align: center

.. Na figura podemos encontrar tanto os bootloaders necessários descritos anteriormente como o binário (.ubi) e arquivos do diretório raiz de algumas versões do projeto Yocto. 

In the figure we can find both the necessary bootloaders described previously and the binary (.ubi) and files in the root directory of some versions of the Yocto project.

.. A versão utilizada foi a mais recente à época, "gumstix-console-image-overo-20180509042558.rootfs.tar.bz2", entretanto tudo o que foi implementado foi testado também, na versão recomendada, "gumstix-console-image-overo.tar.bz2", portanto as duas imagens podem ser utilizadas. Os bootloaders utilizados foram "MLO-overo" e "u-boot-overo.img".

.. Warning::
   Possible causes of failures are probably related to missing or outdated software, unsupported operating system or lack of free space.

References
----------

	* PITA, H. C. Desenvolvimento de sistema de comunicação multiplataforma para veículos aéreos de asa fixa. Faculdade de Tecnologia, Universidade de Brasília, 2018.

	* `Gumstix Repo Manifests for the Yocto Project Build System`_ - github.com

	* `Yocto Project Quick Start`_ - yoctoproject.org

	* `Yocto Project Reference Manual`_ - yoctoproject.org

	* `Building Yocto Linux Images for the Gumstix Overo`_ - hackgnar.com

.. _Gumstix Repo Manifests for the Yocto Project Build System: https://github.com/gumstix/yocto-manifest
.. _Yocto Project Reference Manual: https://www.yoctoproject.org/docs/1.7/ref-manual/ref-manual.html
.. _Yocto Project Quick Start: https://www.yoctoproject.org/docs/1.7/yocto-project-qs/yocto-project-qs.html
.. _Building Yocto Linux Images for the Gumstix Overo: http://www.hackgnar.com/2015/03/building-yocto-linux-images-for-gumstix.html
