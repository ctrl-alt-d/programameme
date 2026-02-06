Avuí s'han fet dos exercicis.
* [736: Pasos en la escalera](https://aceptaelreto.com/problem/statement.php?id=736&cat=166)
* [734: Noches de 12 horas](https://aceptaelreto.com/problem/statement.php?id=734&cat=166)

## 736: Pasos en la escalera
Aquest programa la única dificultat que tenía era que **no es podien utilitzar doubles**, eren operacions únicament amb int.

`(n + n2 - 1) / n2` és per arrodonir cap a dalt, sense cenessitat de math.h o doubles.
```cpp
#include <iostream>

using namespace std;

void calcularItineracions(int n, int n2){
    //double res = (double)n/(double)n2;
    int res = (n + n2 - 1) / n2;
    cout << res /*ceil(res)*/ << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    if (!(cin >> n)) {
        return 0;
    }

    for (int i = 0; i < n; i++) {
        int valor, valor2;
        cin >> valor >> valor2;
        calcularItineracions(valor, valor2);
    }
  
    return 0;
}
```

## 734: Noches de 12 horas

Aquest exercici la difícultat que tenía era la de comprendre el que demana i que cal fer. 

El que cal calcular és quants ml posar cada vegada perquè el rellotge es buidi exactament 12 vegades durant tota la nit (independentment de si és llarga o curta).

1. Convertir l'hora d'inici (la de la posta de sol) a minuts totals des de les 00:00
Exemple: 20:30 -> 20×60 + 30 = 1230 minuts

2. Calcular quants minuts falten des de l'hora d'inici fins a les 24:00
-> 24×60 − minuts de l'inici
Exemple: 1440 − 1230 = 210 minuts fins a mitjanit

3. Convertir l'hora final (la de la sortida de sol) també a minuts totals des de les 00:00
Exemple: 8:15 -> 8×60 + 15 = 495 minuts

4. Ara ja tenim els minuts totals de la nit:
minuts_fins_mitjanit + minuts_desde_mitjanit_fins_final
Exemple: 210 + 495 = 705 minuts de nit

5. Multiplicar aquests minuts totals per 48 (perquè cauen 48 ml cada minut)
i després dividir-ho per 12 (perquè es vol que es buidi exactament 12 vegades durant tota la nit)
→ (minuts totals × 48) / 12

```cpp
#include <iostream>
#include <string>
using namespace std;
void separarValors(string n, int &h, int &m){

    if (n[1] == ':'){
        h = (n[0]-'0');
        m = (n[2]-'0')*10 + n[3]-'0';
    }
    else {
        h = (n[0]-'0')*10 + n[1]-'0';
        m = (n[3]-'0')*10 + n[4]-'0';
    }
}

void calcularItineracions(string n, string n2){
    int h1, m1, h2, m2;
    separarValors(n, h1, m1);
    separarValors(n2, h2, m2);


    int totalminuts = (24*60 - (h1*60+m1)) + (h2*60+m2);

    int resTotal = (totalminuts*48)/12;

    cout << resTotal << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    if (!(cin >> n)) {
        return 0;
    }

    for (int i = 0; i < n; i++) {
        string valor, valor2;
        cin >> valor >> valor2;
        calcularItineracions(valor, valor2);
    }
  
    return 0;
}
```