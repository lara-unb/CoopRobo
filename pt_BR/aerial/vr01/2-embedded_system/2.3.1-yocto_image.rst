Obtenção das imagens do Yocto Project
=====================================

.. https://github.com/gumstix/yocto-manifest/blob/warrior/README.md

Para realizar o processo de iniciação do sistema operacional Yocto Project no computador embarcado Gumstix, precisamos de três arquivos específicos, são eles o primeiro estágio do sistema de iniciação, o arquivo MLO (*Minimal Loader*), o segundo estágio do sistema de iniciação, o arquivo *u-boot.img* (a sigla vem de *Universal Bootloader*), e a imagem do sistema, que em nosso caso será o Yocto 1.8.2 com kernel Linux. 

.. figure:: /img/Aerial/yocto_exemple.png
   :align: center

A figura mostra um exemplo dos arquivos descritos no parágrafo anterior, observe que, neste caso, há também uma pasta compactada que contém os arquivos raiz do sistema operacional. O modo mais simples encontrado para se obter esses arquivos e a imagem do sistema operacional é seguindo os passos do arquivo `README.md`_ do `repositório do projeto Yocto para produtos Gumstix`_. A vantagem de se utilizar esse método ao invés de simplesmente obter a imagem pronta do sistema operacional é que caso seja necessário poderemos modifica-la.

.. _README.md: https://github.com/gumstix/yocto-manifest/blob/warrior/README.md
.. _repositório do projeto Yocto para produtos Gumstix: https://github.com/gumstix/yocto-manifest

Esse tutorial explica como construir manualmente a imagem do sistema Yocto e realizar todos os procedimentos através de linhas de comando do terminal do Linux, com ênfase no **Ubuntu 14.04 (LTS)**. Porém, para executar essa etapa é altamente recomendado o cumprimento dos requisitos indicadas pelo projeto Yocto.

.. Yocto: https://www.yoctoproject.org/docs/1.7/ref-manual/ref-manual.html

.. Essas versões do Linux podem ser encontradas, junto de mais informações úteis no manual de referência do projeto `Yocto`_ , mais especificamente no item 1.3.1 *Supported Linux Distributions*.

Requisitos do Sistema
~~~~~~~~~~~~~~~~~~~~~

.. https://www.yoctoproject.org/docs/1.7/yocto-project-qs/yocto-project-qs.html#yp-resources

.. Note ::
   Para mais informações a respeito dos requisitos do sistema, consulte `System Requirements - Yocto Project Reference Manual`_.

.. _System Requirements - Yocto Project Reference Manual: https://www.yoctoproject.org/docs/1.7/ref-manual/ref-manual.html#intro-requirements

O desenvolvimento de projetos no ambiente do Yocto Project requer que alguns requisitos sejam cumpridos, são eles:

	* Um sistema com no mínimo 25 GB de espaço livre em disco executando uma distribuição Linux suportada. Se o sistema host suportar vários núcleos e encadeamentos, você poderá configurar o sistema de construção do Yocto Project para diminuir significativamente o tempo necessário para construir imagens.

	* Pacotes apropriados instalados no sistema utilizado para realizar as compilações.

	* Uma distribuição do Projeto Yocto.

Atualmente, o Project Yocto é suportado nas seguintes distribuições Linux.

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
   Para obter uma lista mais detalhada de distribuições que suportam o Projeto Yocto, consulte a seção `Supported Linux Distributions`_ em Yocto Project Reference Manual.

.. _Supported Linux Distributions: http://www.yoctoproject.org/docs/1.7/ref-manual/ref-manual.html#detailed-supported-distros

Para a construção da imagem do sistema operacional, o sistema de compilação deve possuir as seguintes versões do *softwares* Git, tar e Python.

	* Git 1.8.3.1 ou posterior

	* tar 1.27 ou posterior

	* Python 3.4.0 ou posterior

.. Note::
   Consulte a seção `Required Git, tar, and Python Versions`_ no Yocto Project Reference Manual para obter informações.

.. _Required Git, tar, and Python Versions: http://www.yoctoproject.org/docs/1.7/ref-manual/ref-manual.html#required-git-tar-and-python-versions

Além disso, recomenda-se atualizar os repositórios do Linux. Para tal, no caso de distribuição Ubuntu, basta executar o seguinte comando:  

	::

		$ sudo apt-get update && sudo apt-get upgrade

É necessária ainda a instalação dos pacotes de host essenciais para a construção da imagem. O comando a seguir instala os pacotes de host com base em sistemas com distribuição Ubuntu.

	::

		$ sudo apt-get install gawk wget git-core diffstat unzip texinfo gcc-multilib build-essential chrpath socat libsdl1.2-dev xterm curl
	 
.. $ sudo apt-get install gawk wget git-core diffstat unzip texinfo gcc-multilib build-essential chrpath socat cpio python python3 python3-pip python3-pexpect xz-utils debianutils iputils-ping python3-git python3-jinja2 libegl1-mesa libsdl1.2-dev pylint3 xterm curl


.. Note::
   Para instalar os pacotes de host em outras distribuições Linux suportadas, consulte a seção `Required Packages for the Build Host`_ em Yocto Project Reference Manual.
   
.. _Required Packages for the Build Host: http://www.yoctoproject.org/docs/3.0.1/ref-manual/ref-manual.html#required-packages-for-the-build-host

Configurando a imagem
~~~~~~~~~~~~~~~~~~~~~

.. Note::
   O sistema operacional utilizado para testar os comandos foi Ubuntu 14.04 (LTS).

Linhas de comando Linux para obtenção e montagem da imagem.

1.  **Instalando o repositório**

Para fazer o download das imagens do Yocto, primeiro precisamos instalar o comando **repo**. Em resumo, o repo é basicamente um invólucro do git, que fornece uma maneira simples de agrupar vários repositórios git diferentes em um único projeto. Caso tenha interesse em mais informações sobre o comando **repo**, acesse `repo - gerrit.googlesource.com`_.

.. _repo - gerrit.googlesource.com: https://gerrit.googlesource.com/git-repo/+/refs/heads/master/README.md

Baixe os scripts do repositório

	::

		$ curl http://commondatastorage.googleapis.com/git-repo-downloads/repo > repo

Torne os arquivos executáveis

	::

		$ chmod a+x repo

Mova os arquivos para o caminho do sistema

	::

		$ sudo mv repo /usr/local/bin/

Se tudo ocorrer bem, deverá aparecer uma mensagem de utilização similar a imagem ao executar o comando a seguir. Esse comando não é obrigatório.

	::

		$ repo --help

.. figure:: /img/Aerial/yocto_repo.png
   :align: center

2. **Criando um repositório local**

Crie um diretório para os arquivos e altera o diretório de execução para o novo repositório

	:: 

		$ mkdir yocto
		$ cd yocto

Agora com o repositório já instalado, faremos o download de todas as configurações do Yocto para o nosso projeto. O comando **init** pode levar algum tempo, pois faz o download de todos os repositórios git associados ao projeto. Já o comando **-b** especifica a ramificação a ser usada e o comando **fido** seleciona o ramo mais estável do repositório.

	::
		
		$ repo init -u git://github.com/gumstix/yocto-manifest.git -b fido

Uma inicialização bem-sucedida terminará com uma mensagem informando que o **.repo** foi inicializado no seu diretório de trabalho. Agora seu diretório deve conter uma pasta *.repo* onde os arquivos de controle de repositório estão armazenados, mas não é necessário abrir o diretório.

.. figure:: /img/Aerial/yocto_init.png
   :align: center

3. **Baixando os arquivos**

O comando a seguir é usado para garantir que todos os seus repositórios estejam atualizados e é útil para atualizar suas configurações do Yocto se você fizer uma compilação posteriormente.

	::

		$ repo sync

.. Note::
   Está etapa pode demorar mais de 20 minutos, dependendo da sua conexão de internet.

Force todos os arquivos temporários a serem escritos em dispositivos permanentes através do comando: 

	::

		$ sync

4. **Iniciando o Yocto Project Build Environment**

.. Warning:: 
   Se, por algum motivo, você cancelar a atividade antes de concluir a compilação do Yocto, será necessário executar este comando todas as vezes antes de seguir para as próximas etapas. Lembre-se de que isso também se aplica a compilações futuras.

Agora que temos nossas configurações básicas do Yocto, entraremos em nosso ambiente de compilação. Por meio do comando a seguir, iremos copiar as informações de configuração padrão no diretório **poky/build/conf** e configurar algumas variáveis de ambiente para o sistema de montagem da imagem.

	::

		$ export TEMPLATECONF=meta-gumstix-extras/conf 
		$ source ./poky/oe-init-build-env

.. Note::
   Este diretório de configuração não está sob controle de revisão, portanto você pode editar esses arquivos de configuração para sua instalação específica. 

5. **Criando a imagem**

O project Yocto utiliza o bitbake para compilar a imagem do Yocto Linux. O Bitbake basicamente compila apenas o SO, o kernel, os módulos e todos os pacotes incluídos no SO Linux de destino. 

.. Tip::
	(**OPCIONAL**)  
	Se você tiver familiaridade com a compilação via make, poderá acelerar o processo de compilação dizendo ao bitbake para compilar com mais threads. Esta etapa não é necessária, mas se você estiver compilando em um sistema com uma CPU de ponta com muitos núcleos, isso acelerará o tempo de compilação. Por exemplo:

	``$ export PARALLEL_MAKE="-j 8"``

	O número "8" indica a quantidade de núcleos a ser utilizada na compilação. 
	**Vale ressaltar que você não deve especificar um valor -j maior que a quantidade de núcleos de CPU presentes em sua máquina de construção**.

Assim, para baixar os códigos fonte e compilar as imagens do sistema execute:

	::

		$ bitbake gumstix-console-image

.. Note::
   Esse processo baixa vários gigabytes de código e, em seguida, faz uma enorme compilação. Portanto, certifique-se de ter pelo menos os 25GB de espaço livre. Esta etapa pode levar um dia ou mais para a criação da imagem, a depender da sua conexão de internet. Não se preocupe, é apenas a primeira compilação que demora um pouco.

Após a finalização da execução de todos os comandos, recomenda-se verificar a pasta **/yocto/build/tmp/deploy/images/overo**, essa pasta deve conter arquivos binários de kernel e bootloaders e arquivos de diretório raiz no formato .tar. 

A figura abaixo apresenta um exemplo do conteúdo da pasta descrita, essa pasta deve ser semelhante ao obtido após a execução dos procedimentos anteriores.

.. figure:: /img/Aerial/yocto_image.png
   :align: center

Na figura podemos encontrar tanto os bootloaders necessários descritos anteriormente como o binário (.ubi) e arquivos do diretório raiz de algumas versões do projeto Yocto. 

.. A versão utilizada foi a mais recente à época, "gumstix-console-image-overo-20180509042558.rootfs.tar.bz2", entretanto tudo o que foi implementado foi testado também, na versão recomendada, "gumstix-console-image-overo.tar.bz2", portanto as duas imagens podem ser utilizadas. Os bootloaders utilizados foram "MLO-overo" e "u-boot-overo.img".

.. Warning::
   Possíveis causas de falhas provavelmente estão relacionadas com softwares faltosos ou desatualizados, sistema operacional não compatível ou falta de espaço livre.

Referências
-----------
	* PITA, H. C. Desenvolvimento de sistema de comunicação multiplataforma para veículos aéreos de asa fixa. Faculdade de Tecnologia, Universidade de Brasília, 2018.

	* `Gumstix Repo Manifests for the Yocto Project Build System`_ - github.com

	* `Yocto Project Quick Start`_ - yoctoproject.org

	* `Yocto Project Reference Manual`_ - yoctoproject.org

	* `Building Yocto Linux Images for the Gumstix Overo`_ - hackgnar.com

.. _Gumstix Repo Manifests for the Yocto Project Build System: https://github.com/gumstix/yocto-manifest
.. _Yocto Project Reference Manual: https://www.yoctoproject.org/docs/1.7/ref-manual/ref-manual.html
.. _Yocto Project Quick Start: https://www.yoctoproject.org/docs/1.7/yocto-project-qs/yocto-project-qs.html
.. _Building Yocto Linux Images for the Gumstix Overo: http://www.hackgnar.com/2015/03/building-yocto-linux-images-for-gumstix.html
