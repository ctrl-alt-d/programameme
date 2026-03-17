#include <iostream>
#include <deque>
#include <vector>

using namespace std;


struct Punt {
    int x;
    int y;
};

void calcularADif(char nova_dir, int &nou_dx, int &nou_dy){
    switch(nova_dir){
        case 'L':
            nou_dx = -1;
            nou_dy = 0;
            break;
        case 'R':
            nou_dx = 1;
            nou_dy = 0;
            break;
        case 'U':
            nou_dx = 0;
            nou_dy = -1;
            break;
        case 'D':
            nou_dx = 0;
            nou_dy = 1;
            break;
    }
}

void ompleSerpInicial(deque<Punt> &serp)
{
    for (int col = 11; col < 21; col++)
    {
        serp.push_back({11,col});
    }
}

bool ocupatserp(deque<Punt> &serp, int x, int y)
{
    for (int i = 0; i < serp.size(); i++) {
        if (serp[i].x == x && serp[i].y == y) return true;
    }
    return false;
} 

void pintaSerp(deque<Punt> &serp)
{
    for (int f = 1; f < 22; f++)
    {
        for (int c = 1; c < 22; c++)
            {
                auto hihaserp = ocupatserp(serp, c, f);
                if (hihaserp) cout << "*"; else cout << ".";
            }
        cout << endl;
    }
    // cin for debug
    cout << "===========================================" << endl;

}

void avancaSerp(deque<Punt> &serp, int t, int dx, int dy)
{
    // avançar cap
    Punt cap = serp.front();
    serp.push_front({cap.x + dx, cap.y + dy});

    // esborrar cua si t % 10 != 0
    if (t % 10 != 0 || t == 0)
    {
        serp.pop_back();        
    }
}

bool xoca(deque<Punt> &serp)
{
    Punt cap = serp.front();
    if (cap.x > 21 || cap.x < 1) return true;
    if (cap.y > 21 || cap.y < 1) return true;

    for(int i = 1; i < serp.size(); i++)
    {
        if (serp[i].x == cap.x && serp[i].y == cap.y) return true;
    }

    return false;
}

void snake(int casosEntrades){
    int d_x = 0, d_y = -1;

    deque<Punt> serp;

    ompleSerpInicial(serp);

    // llegim TOTS els moviments abans de simular
    vector<pair<int,char>> moviments(casosEntrades);
    for (int i = 0; i < casosEntrades; i++)
        cin >> moviments[i].first >> moviments[i].second;

    int t = 0;
    int idx = 0;

    while(true){
        if (idx < casosEntrades && t == moviments[idx].first)
        {
            calcularADif(moviments[idx].second, d_x, d_y);
            idx++;
        }        
        avancaSerp(serp, t, d_x, d_y);
        // pintaSerp(serp);
        bool haxocat = xoca(serp);
        if (haxocat)
        {
            cout << t << endl;
            return;
        }
        t++;
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int entrada;
    cin >> entrada;

    while (entrada != 0){
        snake(entrada);
        cin >> entrada;
    }
    return 0;
}