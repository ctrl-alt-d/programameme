# Calle

Determina si una llista de números de carrer estan a l'esquerra o a la dreta.

L'entrada són una llista de números acabats en un zero.

## Compilar i executar

En els projectes CMake s'han de generar les instruccions de construcció i 
després compilar. Per tant:

Generem les instruccions de compilació

```bash
mkdir build
cd build 
cmake ..
```

Compilem el programa

```bash
cma1ke build .
```

El programa apareixerà en la carpeta build i ja es pot executar.

```bash
$ echo 3 > data.txt
$ ./programa < data.txt
Hola mundo.
Hola mundo.
Hola mundo.
```

### Tests del projecte

Com que els programes són tots molt senzills, en aquest exemple no es fa servir
cap framework de test. Només es fan servir els mètodes de CMake per definir els
tests

En el CMakeList.txt principal s'activen els tests `enable_testing()` i per
facilitar el manteniment es crea un nou CMakeLists.txt` en la carpeta de
tests que activem afegint-li el directori on hi haurà els tests.

```cmake
enable_testing()
add_subdirectory(tests)
```

Per tant la carpeta `tests` serà la que contindrà els tests. En aquesta
carpeta s'hi crea el fitxer de creació `CMakeLists.txt` i s'hi defineixen
els tests que es volen fer amb instruccions CMake.

Quan es generin les instruccions de construcció del projecte també es
generaran els tests.

En el aquest exemple els tests s'han adaptat a l'enunciat del problema. Són
arxius de text on hi ha la llista de números de carrer que s'ha d'avaluar
acabant amb un zero.

```bash
$ cat data2.txt
2
4
0
```

Es poden crear tants arxius com calgui però s'hauran de referenciar en el
fitxer `CMakeLists.txt`.

Per evitar repeticions de codi he definit un mètode per afegir nous
tests anomenada `execute_tests()`-

La funció rep com a paràmetres:

- El nom del fitxer que es farà servir en el test
- El resultat esperat (amb els salts de línia corresponents)

```cmake
execute_test("data.txt, "IZQUIERDA\nDERECHA\n)
```

Si s'afegeixen nous tests s'ha de regenerar el codi de construcció:

```bash
cd build
cmake ..
```

## Execució dels tests

Es poden exeutar els tests amb la comanda que proporciona cmake: `ctest`

```bash
$ ctest
Test project /home/xavier/work-personal/programming/programame/01-helloworld/2-calle/build
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
