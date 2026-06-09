# Chuleta Programameme 2026

## Foreach
```
Només llegir: for (int numero : numeros)
Modificar valors: for (int numero& : numeros)
```

## Arrays
```
- C#: int[] numeros = new int[3];
o {10, 20}
- C++: int numeros[3]; o {10, 20}
```

## Listas Dinámicas
```
- C#: List<T>, Add(), Count
- C++: vector, push_back(),
size()
```

## Conjuntos
```
- C#: HashSet<int>
- C++: unordered_set<int>
```

## Diccionarios
```
- C#: Dictionary<int, string>
- C++: std::map<int, string>
```

---

## 7. Algoritmos Útiles en C++
```cpp
Requiere #include <algorithm>
sort(v.begin(), v.end());                    // ordenar
reverse(v.begin(), v.end());                 // dar la vuelta

auto it = find(v.begin(), v.end(), 5);       // buscar 5
int veces = count(v.begin(), v.end(), 7);    // contar 7

int menor = *min_element(v.begin(), v.end()); // * és per agafar el valor, no iterador
int mayor = *max_element(v.begin(), v.end());
bool existe = binary_search(v.begin(), v.end(), x);

// Muy útil:
auto it = lower_bound(v.begin(), v.end(), x);   // primer >= x
auto it2 = upper_bound(v.begin(), v.end(), x);  // primer > x

// Quitar duplicados
sort(v.begin(), v.end());
v.erase(unique(v.begin(), v.end()), v.end());
```

## Optimización IO
```cpp
ios_base::sync_with_stdio(false);
cin.tie(nullptr);
```

## Mediana (posición óptima)
```
Per calcular posició més propera d’un tauler es fa amb la mediana, que es fa creant una llista de les X, una de les Y, ordenarles de menor a major i agafar el punt mig.
```

## Unordered set usage
```cpp
Acción 
C# (HashSet<T>) 
C++ (std::unordered_set<T>)
Incluir
using System.Collections.Generic;
 #include <unordered_set>
Declarar
HashSet<int> s = new(); 
unordered_set<int> s;
Insertar
s.Add(valor);
s.insert(valor);
Buscar
s.Contains(valor);
s.find(valor) != s.end();
Borrar
s.Remove(valor);
s.erase(valor);
Tamaño
s.Count; 
s.size();
```

## Map usage
```cpp
std::map (C++)
#include <map>
m[key] = val
count(k).
insert({k,v})
Iteración ordenada: for (auto& [k,v] : m){ }
find(k)
erase(k)
```

## 45 grados
```cpp
double diffX = abs(vx - ix);
double diffY = abs(vy - iy);
return (diffX == diffY);

// ó
bool a45grados = (abs(x1 - x2) == abs(y1 - y2));
```

## Referencias
```
auto &variable
```

## Formato salida
```cpp
#include <iomanip>
void pintaNumeroLletra(int numero, string lletra) {
    cout << setw(4) << setfill('0') << numero << " " << lletra << "\n";
}
```

## Redondeo
```cpp
int res = (n + n2 - 1) / n2;
int arriba = (a + b - 1) / b;
```

## Cuadrado perfecto
```cpp
long long raiz = sqrt(entrada) + 0.5;
bool esCuadrado = (raiz * raiz == entrada);
```

## Decimales
```cpp
setprecision(2) << variable
```

## Stack
```cpp
#include <stack>
stack<int> s;
s.top();
s.back();
s.empty();
```

## Deque
```cpp
#include <deque>
deque<int> d;
```

## Criba
```cpp
const int MAX = 1000005;
vector<bool> esPrimo(MAX, true);

void criba() {
    esPrimo[0] = esPrimo[1] = false;
    for (long long i = 2; i * i < MAX; i++) {
        if (esPrimo[i]) {
            for (long long j = i * i; j < MAX; j += i) {
                esPrimo[j] = false;
            }
        }
    }
}
```

## BFS 2D
```cpp
#include <queue>

vector<vector<int>> dist(n, vector<int>(m, -1));
queue<pair<int,int>> q;

q.push({sx, sy});
dist[sx][sy] = 0;

while(!q.empty()) {
    auto [x, y] = q.front(); q.pop();

    for(int d = 0; d < 4; d++) {
        int nx = x + dx[d];
        int ny = y + dy[d];
        if(valido(nx, ny) && dist[nx][ny] == -1) {
            dist[nx][ny] = dist[x][y] + 1;
            q.push({nx, ny});
        }
    }
}
```

## Direcciones
```cpp
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
```

## Grid ejemplo
```
6 7
S..#...
.#.#..#
.#..#..
.#..#..
..##.#.
#..#E.#
```

## BFS completo
```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<string> grid(n);
    for(int i = 0; i < n; i++) {
        cin >> grid[i];
    }

    int sx = -1, sy = -1, ex = -1, ey = -1;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(grid[i][j] == 'S') { sx = i; sy = j; }
            if(grid[i][j] == 'E') { ex = i; ey = j; }
        }
    }

    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};

    vector<vector<int>> dist(n, vector<int>(m, -1));
    queue<pair<int,int>> q;

    q.push({sx, sy});
    dist[sx][sy] = 0;

    while(!q.empty()) {
        auto [x, y] = q.front(); 
        q.pop();

        for(int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];

            if(nx >= 0 && nx < n && ny >= 0 && ny < m && 
               grid[nx][ny] != '#' && dist[nx][ny] == -1) {

                dist[nx][ny] = dist[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }

    if(dist[ex][ey] == -1)
        cout << "No se puede llegar\n";
    else
        cout << dist[ex][ey] << "\n";

    return 0;
}
```
