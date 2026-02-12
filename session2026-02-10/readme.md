* [154: ¿Cuál es la siguiente matrícula?](https://aceptaelreto.com/problem/statement.php?id=154&cat=59)

## 154: ¿Cuál es la siguiente matrícula?

En aquest programa ens donaven l'entrada d'un número sense definir de
matrícules, marcant el final amb la matrícula **9999 ZZZ**.

La dificultat o implementació d'aquest problema és el `.find()`, que
serveix per saber l'índex del que cerquem i com cercar i augmentar
caràcters de valor (A -> B, etc.).

``` cpp
#include <iostream>
#include <string>
using namespace std;

void pintaNumeroLletra(int numero, string lletra) {
    string numero_s = to_string(numero);
    while(numero_s.length() < 4)
        numero_s = "0" + numero_s;

    cout << numero_s << " " << lletra << "\n";
}

string calculaNovaLletra(string lletra) // ens arriba la lletra de la matrícula, ex: lletra = "FGT"
{
    string lletres = "BCDFGHJKLMNPQRSTVWXYZ";
    // int posZ = lletres.find('Z');
    // Per cercar l'índex d’on és.
    string resultat = "...";

    char lletra1 = lletra[0];
    char lletra2 = lletra[1];
    char lletra3 = lletra[2];

    if (lletra3 != 'Z') // cas en què no acaba en Z
    {
        int pos3 = lletres.find(lletra3);
        resultat[0] = lletra1;
        resultat[1] = lletra2;
        resultat[2] = lletres[pos3 + 1];
        return resultat;
    }

    // cas en què no acaba en ZZ
    if (lletra2 != 'Z')
    {
        int pos2 = lletres.find(lletra2);
        resultat[0] = lletra1;
        resultat[1] = lletres[pos2 + 1];
        resultat[2] = lletres[0];
        return resultat;
    }

    // cas en què acaba en ZZ
    int pos1 = lletres.find(lletra1);
    resultat[0] = lletres[pos1 + 1];
    resultat[1] = lletres[0];
    resultat[2] = lletres[0];
    return resultat;
}

void casoDePrueba(int numero, string lletra) {
    int nouNumero;
    string novaLletra;

    bool calNovaLletra = numero == 9999;

    if (calNovaLletra)
    {
        nouNumero = 0;
        novaLletra = calculaNovaLletra(lletra);
    }
    else
    {
        nouNumero = numero + 1;
        novaLletra = lletra;
    }

    pintaNumeroLletra(nouNumero, novaLletra);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int numero;
    string lletra;

    while(true)
    {
        cin >> numero >> lletra;
        if (numero == 9999 && lletra == "ZZZ") return 0;
        casoDePrueba(numero, lletra);
    }

    return 0;
}
```

El que es fa en aquest codi és rebre dues variables, `numero` i `lletra`
de la matrícula. El que fem és veure si cal que sigui un altre número o
lletra. Això se sap ja que si el número és 9999, es posaria a 0000 i
s'avançaria una lletra.

Per calcular la nova lletra tenim un string de 3 caràcters. Anem fent
verificacions: primer, si la lletra no acaba en Z (l'última que li
donem); si no acaba, agafem la següent. Si acaba, verifiquem si
l'anterior (posició 1) ho és; si no ho és, s'avança; si ho és, es
verifica la primera.

I s'imprimeix.

Una forma d'imprimir-ho més eficaç és:

``` cpp
#include <iomanip>
void pintaNumeroLletra(int numero, string lletra) {
    cout << setw(4) << setfill('0') << numero << " " << lletra << "\n";
}
```

Ja que agafa el següent valor a imprimir. Amb `setw(4)` li diem que serà
de 4 caràcters i amb `setfill('0')` li diem que s'emplenarà amb zeros.
