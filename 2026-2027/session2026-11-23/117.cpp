#include <bits/stdc++.h>

using namespace std;

void bucle(int n){
    for (int i = 0; i < n; i++){
        string a;
        string b;
        cin >> a >> b;
        cout << "Hola, " << b << ".\n";
    }
}

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr);
    int n;
    cin >> n;

    bucle(n);

    return 0;
}