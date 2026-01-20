#include <iostream>
#include <stack>
using namespace std;

void casoDePrueba(int n)
{
    unsigned int t;

    if (n==0)
    {
        cout << n;
        cout << '\n';
        return;
    }
    if (n==1)
    {
        cin >> t;
        cout << n;
        cout << '\n';
        return;
    }
    stack<unsigned int> s;
    
    unsigned int davant;
    int g = 1;
    unsigned int min;

    for (int i = 1; i < n; i++)
    {
        cin >> t;
        s.push(t);
    }
    cin >> davant;
    min = davant;

    while(!s.empty())
    {
        t = s.top();
        s.pop();
        if (t<=min && t != 0) g++;
        if (t == 0) g++;
        if (t < min) min = t;
    }


    cout << g;
    cout << '\n';
}

int main()
{

    while (true)
    {
        int n;
        cin >> n;
        if (!cin)
            return 0;
        casoDePrueba(n);
    }
}