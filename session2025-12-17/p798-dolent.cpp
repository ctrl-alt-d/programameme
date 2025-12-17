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
        if(vago == numero){
            asc = false;
            
        }
        else if((asc && VagoAnterior > vago) || (!asc && VagoAnterior < vago)){
            cout << "NO\n";
            return; 
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
