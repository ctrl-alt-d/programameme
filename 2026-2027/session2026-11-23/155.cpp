#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr);
    int x, y;
    cin >> x >> y;
    while(x >= 0 && y >= 0){
        cout << 2*(x+y) << endl;
        cin >> x >> y;
    }
    return 0;
}