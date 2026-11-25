#include <bits/stdc++.h>

using namespace std;

void repetir(int x){
    for(int i = 0; i < x; i++){
        cout << "Hola mundo." << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr);
    int x;
    cin >> x;
    
    repetir(x);

    return 0;
}