#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

void processa(int m)
{
    int t;
    set<int> cartro; 
    vector<int> bombo;

    for(int j = 0; j<m; j++)
    {
        cin >> t;
        bombo.push_back(t);        
    }

    sort(bombo.begin(), bombo.end());

    for(int i = 0; i<m-1; i++)
    {
        for(int j = i+1; j<m; j++)
        {
            int resta = bombo[j] - bombo[i];
            cartro.insert(resta);
        }
    }

    auto espai = "";
    for (int x : cartro) {
        cout << espai << x;
        espai = " ";
    }
    cout << endl;
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