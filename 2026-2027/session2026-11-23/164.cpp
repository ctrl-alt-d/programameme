#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr);

    int a,b,c,d;
    cin >> a >> b >> c >> d;

    while (a <= c && b <= d){
        cout << (c-a)*(d-b) << endl;
        cin >> a >> b >> c >> d;

    }

    return 0;
}