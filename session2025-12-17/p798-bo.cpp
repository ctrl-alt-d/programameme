#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    while (cin >> n && n) {
        vector<int> target(n);
        for (int i = 0; i < n; i++) {
            cin >> target[i];
        }

        stack<int> pila;
        int j = 0;

        for (int i = 1; i <= n; i++) {
            pila.push(i);
            while (!pila.empty() && pila.top() == target[j]) {
                j++;
                pila.pop();
            }
        }

        if (j == n) {
            cout << "SI" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
