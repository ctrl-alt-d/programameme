#include <iostream>
#include <unordered_set>

using namespace std;

void processa(int m)
{
    int t;
    int max_mitjons = 0;

    unordered_set<int> llit; 

    for(int j=0; j<m; j++)
    {
        cin >> t;

        // miro si tinc un mitjó de tipus t al llit:
        if (llit.count(t) > 0)
        {
            llit.erase(t);
        }
        // si no hi ha cap mitjó d'aquell tipus a sobre del llit,
        // poso el mitjó a sobre del llit:
        else
        {
            llit.insert(t);
        }

        // si el nombre de mitjons a sobre el llit és el més
        // gran que he tingut mai, l'apuntu.
        if (llit.size() > max_mitjons)
        {
            max_mitjons = llit.size();
        }

    }

    cout << max_mitjons << endl;
}

int main() {
    int m;

    cin >> m;
    while(m != 0)
    {
        processa(m);
        cin >> m;
    }

    return 0;
}