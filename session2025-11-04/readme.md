# Benviguts a la desesperació i a la dopamina

## Que necessitem?

Hem decidit que el llenguatge `c++` serà el llenguatge oficial per a `programameme`. Per què? Perquè és molt menys verbose que el `java`. Quan es pugui fer servir `java 25` a `Programame` llavors canviarem de llenguatge, perquè té molt de 'sytax sugar' que fa que sigui més senzill de fer servir.

## Com instal·lo `c++` al meu ordinador

**Nota**: Programame accepta C++11, C++14 i C++17. Recomanem instal·lar un compilador que suporti com a mínim C++17.

### Windows

**Opció recomanada: MSYS2** (més fàcil d'instal·lar i actualitzar)

1. Descarrega i instal·la **MSYS2** des de: https://www.msys2.org/
2. Obre la terminal MSYS2 i executa:
   ```bash
   pacman -S mingw-w64-x86_64-gcc
   ```
3. Afegeix `C:\msys64\mingw64\bin` al PATH del sistema
4. Verifica la instal·lació obrint CMD o PowerShell:
   ```bash
   g++ --version
   ```

**Alternativa**: Instal·la **Visual Studio Community** (gratuït) que inclou el compilador de C++.

### Ubuntu

Ubuntu ja sol portar g++ instal·lat. Si no és el cas:

```bash
sudo apt update
sudo apt install build-essential
```

Verifica la instal·lació:
```bash
g++ --version
```

Per assegurar-te que tens C++17:
```bash
sudo apt install g++-9
```

### Mac

1. Instal·la **Xcode Command Line Tools**:
   ```bash
   xcode-select --install
   ```

2. Verifica la instal·lació:
   ```bash
   g++ --version
   ```
   o
   ```bash
   clang++ --version
   ```

**Nota**: En Mac, `g++` és normalment un alias de `clang++`, que és totalment compatible amb C++17.

## Compilar i executar un programa

Un cop instal·lat, pots compilar i executar programes així:

```bash
# Compilar
g++ -std=c++17 -O2 -o programa programa.cpp

# Executar
./programa          # Linux/Mac
programa.exe        # Windows
```


## Com passar els cassos de prova

En `Programame` l'enunciat ens dona uns casos de prova i el programa els ha de llegir. Els programes llegeixen per l' `entrada standard`. Per exemple,:

```text
Entrada de ejemplo
9165 110 300
9165 110 299
12000 100 433
12000 100 431
12000 100 359
-1000 -50 -100
0 0 0
Salida de ejemplo
 
OK
MULTA
OK
MULTA
PUNTOS
ERROR
```

Per poder enviar les dades en mode debug per l'entrada standard farem el següent, posarem en un fitxer `data.txt` els casos d'entrada i executarem el programa passant el fitxer per l'entrada estàndard. En Linux/Mac podem fer:

```bash
# (Opcional) Compilar
g++ -std=c++17 -O2 -o programa programa.cpp

# Executar passant el fitxer per stdin
./programa < data.txt
```

En Windows:

CMD
```bat
REM (Opcional) Compilar
g++ -std=c++17 -O2 -o programa.exe programa.cpp

REM Executar passant el fitxer per stdin
programa.exe < data.txt
```

PowerShell
```powershell
# (Opcional) Compilar
g++ -std=c++17 -O2 -o programa.exe programa.cpp

# Executar passant el fitxer per stdin
./programa.exe < data.txt
```


## Quina és l'estructura dels programes?

A la web de programame la podem veure a l'apartat templates [https://aceptaelreto.com/doc/templates.php](https://aceptaelreto.com/doc/templates.php)


### Esquema 1: número de casos al principio

```c++
#include <iostream>
using namespace std;

void casoDePrueba() {

    // TU CÓDIGO AQUÍ

} // casoDePrueba

int main() {
    unsigned int numCasos;

    cin >> numCasos;
    for (unsigned int i = 0; i < numCasos; ++i) {
        casoDePrueba();
    }
  
    return 0;
}
```

### Esquema 2: caso de prueba que marca el final

```c++
#include <iostream>
using namespace std;

bool casoDePrueba() {

    leer caso de prueba
    if (es el caso que marca el final)
        return false;
    else {
        // CÓDIGO PRINCIPAL AQUÍ
        return true;
     }

} // casoDePrueba

int main() {

    while(casoDePrueba()) {
    }
  
    return 0;
}
```


### Esquema 3: fin de la entrada

```c++
#include <iostream>
using namespace std;

bool casoDePrueba() {

    leer el inicio del caso de prueba (cin)
    if (!cin)
        return false;
    else {
        // CÓDIGO PRINCIPAL AQUÍ (incluyendo el resto de la lectura)
        return true;
    }

} // casoDePrueba

int main() {

    while(casoDePrueba()) {
    }
  
    return 0;
}
```


## El meu primer programa

Programes que podem fer avui:

* https://aceptaelreto.com/problem/statement.php?id=116&cat=5
* https://aceptaelreto.com/problem/statement.php?id=217&cat=5
* https://aceptaelreto.com/problem/statement.php?id=112&cat=5