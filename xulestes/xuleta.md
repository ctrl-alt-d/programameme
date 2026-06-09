# Xuleta programame — Concurs de Programació C++

## Plantilla base

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // codi aquí

    return 0;
}
```

---

## Estructures de dades i operacions

| Estructura | Include | Ordenat? | Duplicats? | Accés | Insert | Cerca | Ús típic |
|---|---|---|---|---|---|---|---|
| `vector<T>` | `<vector>` | No (manual) | Sí | O(1) | O(1) final | O(n) | Llistes, matrius |
| `set<T>` | `<set>` | Sí | No | — | O(log n) | O(log n) | Ordre dinàmic, lower_bound |
| `multiset<T>` | `<set>` | Sí | Sí | — | O(log n) | O(log n) | Ordre amb repetits |
| `unordered_set<T>` | `<unordered_set>` | No | No | — | O(1) avg | O(1) avg | Existència, visitats |
| `map<K,V>` | `<map>` | Per clau | No (clau) | O(log n) | O(log n) | O(log n) | Diccionari ordenat |
| `unordered_map<K,V>` | `<unordered_map>` | No | No (clau) | O(1) avg | O(1) avg | O(1) avg | Diccionari ràpid |
| `queue<T>` | `<queue>` | FIFO | Sí | front() | O(1) | — | BFS |
| `priority_queue<T>` | `<queue>` | Max-heap | Sí | top() | O(log n) | — | Dijkstra, greedy |
| `stack<T>` | `<stack>` | LIFO | Sí | top() | O(1) | — | Parèntesis, DFS |
| `deque<T>` | `<deque>` | No | Sí | O(1) | O(1) ambdós extrems | O(n) | Sliding window |
| `string` | `<string>` | — | — | O(1) | O(1) final | O(n) | Text |

---

## Lectura de dades

```cpp
// Llegir n elements a un vector
int n; cin >> n;
vector<int> v(n);
for (int& x : v) cin >> x;

// Llegir fins EOF
int x;
while (cin >> x) { v.push_back(x); }

// Llegir línia sencera
string linia;
getline(cin, linia);

// Llegir matriu n x m
int n, m; cin >> n >> m;
vector<vector<int>> mat(n, vector<int>(m));
for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
        cin >> mat[i][j];

// Llegir graella de caràcters
vector<string> grid(n);
for (int i = 0; i < n; i++) cin >> grid[i];
```

---

## Recorrer estructures

```cpp
// Vector — amb índex
for (int i = 0; i < (int)v.size(); i++) cout << v[i] << " ";

// Vector — range-based (només llegir)
for (int x : v) cout << x << " ";

// Vector — range-based (modificar)
for (int& x : v) x *= 2;

// Set / multiset (ordre creixent)
for (int x : s) cout << x << " ";

// Set ordre decreixent
for (auto it = s.rbegin(); it != s.rend(); it++) cout << *it << " ";

// Map
for (auto& [clau, valor] : m) cout << clau << " -> " << valor << "\n";

// Queue (buidar-la)
while (!q.empty()) { cout << q.front(); q.pop(); }

// Stack (buidar-la)
while (!st.empty()) { cout << st.top(); st.pop(); }
```

---

## Vector — operacions clau

```cpp
vector<int> v;
v.push_back(x);              // afegir al final
v.pop_back();                 // treure del final
v.size();                     // mida
v.empty();                    // és buit?
v[i];                         // accés directe
v.front(); v.back();          // primer / últim
v.insert(v.begin()+i, x);    // inserir a posició i
v.erase(v.begin()+i);        // esborrar posició i
v.clear();                    // buidar
v.resize(n, 0);              // redimensionar

// Vector 2D (matriu)
vector<vector<int>> mat(filas, vector<int>(cols, 0));

// Vector de pairs
vector<pair<int,int>> vp;
vp.push_back({1, 2});
int a = vp[0].first, b = vp[0].second;
```

---

## Set — operacions clau

```cpp
set<int> s;
s.insert(x);                  // inserir
s.erase(x);                   // esborrar per valor
s.count(x);                   // 1 si existeix, 0 si no
s.find(x);                    // iterador (s.end() si no trobat)
*s.begin();                   // mínim
*prev(s.end());               // màxim

// Trobar el menor element >= x
auto it = s.lower_bound(x);
if (it != s.end()) cout << *it;

// Trobar el menor element > x
auto it = s.upper_bound(x);

// NO es pot fer s[i] — no hi ha accés per índex
```

---

## Map — operacions clau

```cpp
map<int, string> m;
m[clau] = valor;               // inserir / modificar
m.count(clau);                 // existeix?
m.erase(clau);                 // esborrar
m[clau];                       // accés (crea si no existeix!)

// Iterar (ordenat per clau)
for (auto& [k, v] : m) { ... }

// unordered_map: igual però O(1) i sense ordre
unordered_map<string, int> um;
```

---

## Queue / Stack / Priority Queue

```cpp
// Queue (cua FIFO) — per BFS
queue<int> q;
q.push(x);     q.pop();     q.front();    q.empty();

// Stack (pila LIFO)
stack<int> st;
st.push(x);    st.pop();    st.top();     st.empty();

// Priority Queue (max-heap per defecte)
priority_queue<int> pq;
pq.push(x);    pq.pop();    pq.top();     pq.empty();

// Priority Queue min-heap
priority_queue<int, vector<int>, greater<int>> pq_min;

// Priority Queue amb pairs (ordena per first)
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
```

---

## Conversió entre estructures

```cpp
// Vector → Set (eliminar duplicats i ordenar)
vector<int> v = {3,1,2,1};
set<int> s(v.begin(), v.end());          // {1,2,3}

// Set → Vector
vector<int> v2(s.begin(), s.end());

// Vector → eliminar duplicats (mantenint vector)
sort(v.begin(), v.end());
v.erase(unique(v.begin(), v.end()), v.end());

// String → vector<char>
string s = "hola";
vector<char> vc(s.begin(), s.end());

// String → int
int n = stoi(s);
long long n = stoll(s);

// Int → String
string s = to_string(n);
```

---

## Algoritmes de la STL (`<algorithm>`)

```cpp
// Ordenar
sort(v.begin(), v.end());                        // creixent
sort(v.begin(), v.end(), greater<int>());         // decreixent
sort(v.begin(), v.end(), [](int a, int b) {       // personalitzat
    return a > b;
});

// Ordenar pairs per segon element
sort(v.begin(), v.end(), [](auto& a, auto& b) {
    return a.second < b.second;
});

// Invertir
reverse(v.begin(), v.end());

// Mínim / Màxim
int mn = *min_element(v.begin(), v.end());
int mx = *max_element(v.begin(), v.end());

// Buscar
auto it = find(v.begin(), v.end(), x);     // lineal O(n)
bool ok = binary_search(v.begin(), v.end(), x);  // binària O(log n), cal ordenat

// lower_bound / upper_bound (cal ordenat)
auto it = lower_bound(v.begin(), v.end(), x);   // primer >= x
auto it = upper_bound(v.begin(), v.end(), x);   // primer > x

// Comptar
int c = count(v.begin(), v.end(), x);

// Suma
long long suma = accumulate(v.begin(), v.end(), 0LL);

// Permutacions
sort(v.begin(), v.end());
do {
    // processar permutació actual de v
} while (next_permutation(v.begin(), v.end()));

// Rotar
rotate(v.begin(), v.begin() + k, v.end());  // k posicions a l'esquerra
```

---

## Strings

```cpp
string s = "hola";
s.size();  s.length();          // mida
s[i];                           // caràcter i
s += "abc";                     // concatenar
s.substr(pos, len);             // substring
s.find("ol");                   // posició (string::npos si no trobat)
s.push_back('x');               // afegir caràcter
s.pop_back();                   // treure últim caràcter

// Comparar
s1 == s2;  s1 < s2;            // lexicogràfic

// Convertir a minúscules/majúscules
for (char& c : s) c = tolower(c);
for (char& c : s) c = toupper(c);

// Comprovar dígit / lletra
isdigit(c);  isalpha(c);  isalnum(c);

// Split manual per espais
stringstream ss(linia);
string paraula;
while (ss >> paraula) { ... }
```

---

## Matemàtiques

### Redondeo per amunt (divisió entera)
```cpp
int arriba = (a + b - 1) / b;
```

### MCD i MCM
```cpp
int g = __gcd(a, b);
long long mcm = (long long)a / g * b;    // evita overflow
```

### Criba d'Eratòstenes (nombres primers)
```cpp
const int MAX = 1000005;
vector<bool> esPrimo(MAX, true);

void criba() {
    esPrimo[0] = esPrimo[1] = false;
    for (long long i = 2; i * i < MAX; i++) {
        if (esPrimo[i]) {
            for (long long j = i * i; j < MAX; j += i)
                esPrimo[j] = false;
        }
    }
}
```

### Quadrat perfecte
```cpp
long long raiz = sqrt(entrada) + 0.5;
bool esCuadrado = (raiz * raiz == entrada);
```

### Distància Manhattan
```cpp
int dist = abs(x1 - x2) + abs(y1 - y2);
```

### 45 graus (diagonals)
```cpp
bool a45 = (abs(x1 - x2) == abs(y1 - y2));
```

---

## Mediana (posició òptima)

Per trobar el punt que minimitza la suma de distàncies:
```cpp
// Ordenar les coordenades X i Y per separat
sort(xs.begin(), xs.end());
sort(ys.begin(), ys.end());
// La mediana és la posició òptima
int medX = xs[xs.size() / 2];
int medY = ys[ys.size() / 2];
```

---

## Cerca binària (binary search genèric)

```cpp
// Trobar el mínim valor que compleix una condició
long long lo = 0, hi = 1e18;
while (lo < hi) {
    long long mid = lo + (hi - lo) / 2;
    if (compleix(mid))
        hi = mid;
    else
        lo = mid + 1;
}
// lo = resposta
```

---

## BFS en graella 2D

```cpp
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int n, m;  // files, columnes
vector<vector<int>> dist(n, vector<int>(m, -1));
queue<pair<int,int>> q;

q.push({sx, sy});
dist[sx][sy] = 0;

while (!q.empty()) {
    auto [x, y] = q.front(); q.pop();
    for (int d = 0; d < 4; d++) {
        int nx = x + dx[d], ny = y + dy[d];
        if (nx >= 0 && nx < n && ny >= 0 && ny < m
            && dist[nx][ny] == -1 && grid[nx][ny] != '#') {
            dist[nx][ny] = dist[x][y] + 1;
            q.push({nx, ny});
        }
    }
}
```

---

## DFS en graella 2D

```cpp
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

vector<vector<bool>> vis(n, vector<bool>(m, false));

void dfs(int x, int y) {
    vis[x][y] = true;
    for (int d = 0; d < 4; d++) {
        int nx = x + dx[d], ny = y + dy[d];
        if (nx >= 0 && nx < n && ny >= 0 && ny < m
            && !vis[nx][ny] && grid[nx][ny] != '#') {
            dfs(nx, ny);
        }
    }
}
```

---

## BFS en graf (llista d'adjacència)

```cpp
int n;  // nombre de nodes
vector<vector<int>> adj(n);  // llista d'adjacència

// Construir graf
adj[u].push_back(v);
adj[v].push_back(u);  // si no dirigit

// BFS des del node start
vector<int> dist(n, -1);
queue<int> q;
dist[start] = 0;
q.push(start);

while (!q.empty()) {
    int u = q.front(); q.pop();
    for (int v : adj[u]) {
        if (dist[v] == -1) {
            dist[v] = dist[u] + 1;
            q.push(v);
        }
    }
}
```

---

## DFS en graf

```cpp
vector<bool> vis(n, false);

void dfs(int u) {
    vis[u] = true;
    for (int v : adj[u]) {
        if (!vis[v]) dfs(v);
    }
}

// Comptar components connexes
int components = 0;
for (int i = 0; i < n; i++) {
    if (!vis[i]) {
        dfs(i);
        components++;
    }
}
```

---

## Prefix Sum (sumes acumulades)

```cpp
vector<long long> pre(n + 1, 0);
for (int i = 0; i < n; i++) pre[i + 1] = pre[i] + v[i];
// Suma [l, r) = pre[r] - pre[l]
```

---

## Sortida amb format

```cpp
#include <iomanip>
// Zeros a l'esquerra
cout << setw(4) << setfill('0') << numero;   // 0042

// Decimals fixos
cout << fixed << setprecision(2) << 3.14159;  // 3.14

// Saltar línia (preferir \n a endl)
cout << "hola\n";
```

---

## Trucs útils

```cpp
// Min/Max de múltiples valors
int x = min({a, b, c, d});
int y = max({a, b, c, d});

// Swap
swap(a, b);

// Abs
int d = abs(a - b);

// INF segur
const int INF = 1e9;
const long long LINF = 1e18;

// Pair
pair<int,int> p = {3, 5};
auto [a, b] = p;   // structured bindings

// Tuple
tuple<int,int,int> t = {1, 2, 3};
auto [a, b, c] = t;

// Bit operations
x & 1       // és senar?
x >> 1      // dividir per 2
x << 1      // multiplicar per 2
__builtin_popcount(x)   // nombre de bits 1

// Lambda
auto cmp = [](int a, int b) { return a > b; };
```

---

## Regla mental: quina estructura?

```
Necessito ordre dinàmic / lower_bound? → set
Només existència / visitats?           → unordered_set
Llista amb accés per índex?            → vector
Clau → valor, ordenat?                → map
Clau → valor, ràpid?                  → unordered_map
FIFO (BFS)?                           → queue
Últim entrat, primer sortit?           → stack
Mínim/Màxim ràpid?                    → priority_queue
```

---

## Complexitat — límits orientatius

| n | Complexitat màxima |
|---|---|
| ≤ 10 | O(n!) |
| ≤ 20 | O(2^n) |
| ≤ 500 | O(n³) |
| ≤ 5.000 | O(n²) |
| ≤ 500.000 | O(n log n) |
| ≤ 10.000.000 | O(n) |

---

## Errors comuns a evitar

- `int` overflow → usa `long long` si els valors poden ser grans
- Oblidar `ios_base::sync_with_stdio(false); cin.tie(nullptr);`
- Comparar `int` amb `v.size()` (que és `unsigned`) → cast a `(int)`
- Off-by-one en bucles i rangs
- No inicialitzar distàncies / dp correctament
- Usar `endl` en lloc de `"\n"` (molt més lent)

