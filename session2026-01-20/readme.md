# Control de armas
 

https://aceptaelreto.com/problem/statement.php?id=748

solució:

```c++
#include <map>
#include <string>
#include <iostream>
using namespace std;

map<string, int> persones;
void tractarSortida(){
    int enter;
    cin >> enter;
    string payoQueEs;
    int acumulador = 0;
    for(int i = 0 ; i < enter ; i++){
        cin >> payoQueEs;
        acumulador += persones[payoQueEs];
        
        persones.erase(payoQueEs);

    }
    cout << acumulador;
    cout << "\n";
}

void tractarEntrada(string nom){
    int enter;
    cin >> enter;
    if(persones.count(nom) == 0){
        persones[nom] = enter;  
    } else{
        persones[nom] += enter;
    }
     
}

void tractarEntradaOsortida(){
    string nom;
    cin >> nom;
    if(nom == "?"){
        tractarSortida();
    }
    else{
        tractarEntrada(nom);
    }
}
void tractarN(int entrades)
{
    for (int i = 0; i < entrades; i++)
    {
        tractarEntradaOsortida();
    }
    cout << "---\n"; 
}

int main()
{
    int n;
    while (true)
    {
        cin >> n;
        if (n == 0)
        {
            break;
        }
        tractarN(n);
        persones.clear();
       
    }
}
```