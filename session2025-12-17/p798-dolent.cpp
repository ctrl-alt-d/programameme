#include <iostream>

using namespace std;

inline void contruirbago(int numero)
{
    int VagoAnterior = 0;
    int vago;
    bool asc = true;
    for (int i = 0; i < numero; i++) 
    {
        cin >> vago;

        if((asc && VagoAnterior > vago) || (!asc && VagoAnterior < vago)){
            cout << "NO\n";
            for (int j = i + 1; j < numero; j++) {
                cin >> vago; // Leer los vagones restantes pero no hacer nada con ellos
            }
            return; 
        }
        if(vago == numero){
            asc = false;
            
        }
        VagoAnterior = vago;
    }
    cout << "SI\n";
}

int main()
{
    int numero;

    while (true)
    {
        cin >> numero;
        if (numero == 0)
        {
            return 0;
        }
        contruirbago(numero);
    }
}
