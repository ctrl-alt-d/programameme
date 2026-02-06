# Hello World amb CMake

## CMake

Cmake (cross-platform make) és una eina de desenvolupament de programari gratuïta i multiplataforma per crear aplicacions mitjançant instruccions independents del compilador.

- Pot automatitzar proves, embalatge i instal·lació. 
- Suporta una gran quantitat de sistemes: Windows, Linux, IOS, Android, OS2, BSDOS, DOS, OpenBSD, SunOS, etc.
- Tot i que per defecte funciona amb C i C++ es pot usar en diferents llenguatges de programació: C, C++, CSharp, CUDA, Objective-C, Fortran, HIP, ISPC, Swift, ASM

La clau de CMake és que no intenta ser un sistema de construcció sinó que simplement fa servir algun sistema existent. (Make, Visual Studio, Ninja, Qt, ...). També es pot fer servir per compilar, executar proves unitàries (CTest) i generar automàticament paquets per diferents plataformes que van des d'instal·ladors Windows, comprimir resultats en zip o .tar.gz, generar paquets d'instal·lació .deb o .rpm, etc. (CPack)

No li diem *"Compila el fitxer main.cpp"* sinó que el que fem és dir-li *"agafa aquesta llista de codi i genera un executable"* i el que fa és generar les instruccions sobre com es construeix l'executable, no intenta construir-lo ell mateix.

El fet que generi instruccions de compilació li no ser una eina de compilació com Make, Ninja o MSBuild sinó que proporciona un llenguatge que serà transformat a les instruccions del sistema de construcció que trobi on el fem servir (Unix Make,  Ninja, CodeBlocks, Eclipse CDT,  KDevelop, Sublime Text 2,  Borland Make, MSYS Make, MinGW Make,  NMake, NMake JOM, Watcom WMake, Kate, CodeLite, Xcode, Visual Studio, ...)

## Instal·lació

A part del compilador i alguna eina de construcció (Make, Ninja, MSBuild). Per fer servir CMake cal instal·lar el programa. En la pàgina de descàrregues hi ha paquets binaris d'instal·lació per als sistemes operatius més importants (Windows, Linux, MacOS, SunOS). Per compatibilitat recomano la darrera versió 3.x

En Windows es pot instal·lar amb MSYS2 (suoosant que ja l'has instal·lat per instal·lar el compilador) i de pas ens assegurem que hi ha algun sistema de construcció: make i ninja (només en cal un però ...)

```bash
pacman -S cmake make ninja
```

En sistemes Linux es pot instal·lar directament a través dels repositoris.

```bash
apt install cmake make ninja # Debian i derivats (Ubuntu, ...)
dnf install cmake make ninja # Red Hat i derivats (Fedora, ...)
pacman -Syu cmake make ninja # ArchLinux i derivats (Manjari, ...)
```

## Funcionament

Es genera un fitxer amb les instruccions en l'arrel del projecte que s'ha de
dir `CMakeLists.txt`.

L'exemple més bàsic té tres línies:

- Versions de CMake que es poden fer servir
- Nom del projecte (s'hi poden definir la versió i el llenguatge)
- Generació de l'executable

```cmake
cmake_minimum_required(VERSION 3.10...4.0)
project(hello)
add_executable(hello src/main.cpp)
```

En l'exemple que hi ha en el repositori defineix que la versió de C++ a fer
servir ha de ser de la versió 17.

### Generar un executable

Per generar un executable el primer es generar les instruccions de compilació
(es recomana fer-ho en una carpeta exclosa de GIT per no emplenar de codi
innecessari el repositori). És habitual que la carpeta es digui **build**

```bash
mkdir buid
cd build
cmake ..
```

> En el pas de generar el codi per compilar el programa es pot forçar el
generador amb el paràmetre `-G` ( -G "Unix Makefiles", -G Ninja, etc..). Si no
es proporciona, CMake en busca un en el sistema de forma automàtica.

Després per compilar només cal executar el programa que es fa servir `make` ...
o bé fer-ho a traǘes de CMake:

```bash
cmake --build .
```

## IDES

La major part dels grans IDEs de C o C++ suporten CMake nadiuament o a través
de components: Visual Studio, CLion, Eclipse, NeoVim, VSCode, ...

El component normalment es sol anomenar **cmake-tools**

### VSCode

En VSCode s'instal·len els components CMake (per la sintaxi del fitxer
CMakeLists.txt) i CMake-Tools (per compilar i debuggar automàticament)

![cmake-tools](../assets/cmake-tools.png)

Després s'ha d'executar el programa amb els botons que surten a la barra
inferior del IDE.

![build](../assets//vscmake.png)

Per defecte l'executable sortirà en la carpeta `build`

## Exemples

### Hello World

En la carpeta [cmake/helloworld](helloworld/) hi ha un exemple bàsic que
implementa el [problema 116](https://aceptaelreto.com/problem/statement.php?id=116&cat=5)
de la web "Acepta el reto"

> CMake intenta afavorir les bones pràctiques i recomana que el codi font
> estigui en la carpeta **src**, els *.h estiguin a **includes**, etc.. Ho
> he fet, però no és obligatòri

El fitxer `CMakeLists.txt`que és la base de la generació de projectes, es pot
usar de base per pràcticament tots els problemes de la web. (Podeu canviar el
nom del projecte o les versions de CMake si en teniu una que està fora del
rang),

Per generar el programa des de la línia de comandes primer cap generar les
instruccions de compilació

```bash
mkdir build
cd build
cmake ..
```

I després ja es pot compilar amb:

```bash
cmake build ..
```

En la carpeta build apareixerà l'executable

> De totes maneres es pot fer de forma transparent des de quasevol dels IDEs
> de C++

### Números de carrer

En la carpeta [cmake/calle/](calle/) hi ha l'exempe  que implementa el [problema 217](https://aceptaelreto.com/problem/statement.php?id=217&cat=5) de la web "Acepta el reto"

En aquest problema s'hi ha implementat la opció de que el projecte tingui tests
per comprovar si el programa està funcionant bé

Com que CMake va sobre automatització de programari (normalment construir el
projecte i instal·lar-lo) també suporta altres coses com empaquetat de
programari amb CPack i execució de testos amb CTest.

Normalment no n'hi sol haver prou amb que el programa hagi compilat sinó que el
que es busca és que el programa faci el que ha de fer correctament. Per tant a
CMake hi han tota una sèrie de funcions per ajudar a la creació de tests de
forma senzilla, i després es registren a través del component CTest.

Un dels avantatges de fer tests amb CMake és que no et força afer servir cap
framework de tests. De fet, es poden fer tests sense fer-ne servir cap! Només
fent servir les funcions que ofereix es poden fer tests.

Per executar els tests amb CTest només cal executar-ne la eina `ctest` i
per pantalla sortirà el resultat de lexecució de cada un dels tests: si han
passat, si han fallat, etc...

CTest es pot integrar amb els framework de tests de programari però per fer
tests bàsics es pot fer sense usar-ne cap.

Per generar el programa des de la línia de comandes primer cap generar les
instruccions de compilació

```bash
mkdir build
cd build
cmake ..
```

I després ja es pot compilar amb:

```bash
cmake build ..
```

En la carpeta build apareixerà l'executable **programa** (en Linux) o 
**programa.exe** (en Windows)

Per executar els tests de programari només cal executar. Que treurà un informe
per cada un dels fitxers que hi ha en la carpeta de tests:

```bash
$ ctest
Test project /XXXXXXXXXXXXXXXx/calle/build
    Start 1: data1
1/4 Test #1: data1 ............................   Passed    0.01 sec
    Start 2: data2
2/4 Test #2: data2 ............................   Passed    0.01 sec
    Start 3: data34
3/4 Test #3: data34 ...........................   Passed    0.01 sec
    Start 4: data45
4/4 Test #4: data45 ...........................   Passed    0.01 sec

100% tests passed, 0 tests failed out of 4

Total Test time (real) =   0.03 sec
```
