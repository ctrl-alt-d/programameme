#include <iostream>
#include <ostream>

#include <map>
#include <vector>
#include <algorithm>

using namespace std;

void Renumera(){

    // mapa per convertir les línies en valors multiples de 10
    map<unsigned int,unsigned int> valors;

    // Estructura per emmagatzemar el programa en basic
    vector<unsigned int> primerValor;
    vector<string> segundoValor;
    vector<unsigned int> tercerValor;

    while (true){

        unsigned int numero;
        string caract;
        cin >> numero;

        // Si llegim un 0, s'acaba el programa basic
        if (numero == 0){
            break;
        }

        primerValor.push_back(numero);
        cin >> caract;
        segundoValor.push_back(caract);

        // si arriba RETURN no llegim tercer valor
        if (caract != "RETURN"){
            cin >> numero;
            tercerValor.push_back(numero);
        } else tercerValor.push_back(0);
    }

    // Preparem el diccionari de valors multiples de 10
    int aMul = 10;
    for (unsigned int &valorsPrin : primerValor){

        valors[valorsPrin] = aMul;
        aMul += 10;
    }

    // Imprimim el programa renumerat
    for (unsigned int i = 0; i < primerValor.size(); i++){
        cout << valors[primerValor[i]] << " " << segundoValor[i];
        if (segundoValor[i] != "RETURN"){
            cout << " " << valors[tercerValor[i]];
        }
        cout << "\n";
    }
    cout << "---\n";
}
int main() {
    // optimitzacions per a velocitat en les entrades i sortides
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // llegim el nombre de casos de prova
    int n;
    cin >> n;

    // per cada cas de prova renumerem el programa
    for(int i = 0; i < n; i++){
        Renumera();
    }

}