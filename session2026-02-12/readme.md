* [609: Reunión de torres](https://aceptaelreto.com/problem/statement.php?id=609)

## 609: Reunión de torres
Aquest exercici era difícil d’entendre el com es feia, ja que es tracta d’agafar una posició del tauler en la qual el moviment de totes les peces sigui el menor possible.

A primera vista podríem pensar a fer una mitjana, però no és l’opció correcta.

La forma correcta de calcular moviments mínims en un tauler 2D (vectors) és fer la mediana.
Agafarem tots els valors d’X i d’Y en dues llistes diferents, els ordenarem en ordre ascendent i, en cas d’impar, agafarem el del mig; en cas que sigui parell, agafarem el del mig - 1 (per agafar el més a l’esquerra/a baix).

En aquest cas, l’entrada de les dimensions del tauler és trampa, ja que no serveix per a res.

```cpp
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
vector<int> posicionsX, posicionsY;

void calcularPosicio(){
    int posX;
    int posY;

    int tamanyVector = posicionsX.size();
    
    if(tamanyVector%2!=0){
        posX = posicionsX[tamanyVector/2];
        posY = posicionsY[tamanyVector/2];
    } else {
        posX = posicionsX[tamanyVector/2-1];;
        posY = posicionsY[tamanyVector/2-1];
    }

    cout << posX << " " << posY << "\n";
}
void afegirEntrades(){
    int x, y;

    cin >> x >> y;
    posicionsX.push_back(x);
    posicionsY.push_back(y);
}

void calcular(int nEntrades){
    for (int i = 0; i < nEntrades; i++){
        afegirEntrades();
    }

    sort(posicionsX.begin(), posicionsX.end());
    sort(posicionsY.begin(), posicionsY.end());


    calcularPosicio();
}
bool casoDePrueba() {
    int dimensionsTauler, nEntrades;    
    if (!(cin >> dimensionsTauler >> nEntrades))
        return false;
    else {
        // CÓDIGO PRINCIPAL AQUÍ (incluyendo el resto de la lectura)
        calcular(nEntrades);
        posicionsX.clear();
        posicionsY.clear();

        return true;
    }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    while(casoDePrueba()) {
        
    }
    return 0;
}
```