# 🧠 CHULETA – `set` en C++ (ordenado)

## 📌 Qué es
- Contenedor **ordenado automáticamente**
- Implementado como **árbol balanceado**
- **No permite duplicados**
- Complejidad: **O(log n)**

---

## 🔹 Declaración
```cpp
#include <bits/stdc++.h>
using namespace std;

set<int> s;
```

---

## 🔹 Insertar elementos
```cpp
s.insert(5);
s.insert(1);
s.insert(3);
```

Contenido del set:
```
1 3 5
```

---

## 🔹 Recorrer en orden creciente
```cpp
for (int x : s) {
    cout << x << " ";
}
```

---

## 🔹 Recorrer en orden decreciente
```cpp
for (auto it = s.rbegin(); it != s.rend(); it++) {
    cout << *it << " ";
}
```

---

## 🔹 Acceder a extremos

### Menor elemento
```cpp
int mn = *s.begin();
```

### Mayor elemento
```cpp
int mx = *prev(s.end());
```

---

## 🔹 Comprobar existencia
```cpp
if (s.count(x)) {
    // x existe
}
```

---

## 🔹 Buscar un elemento
```cpp
auto it = s.find(x);
if (it != s.end()) {
    // encontrado
}
```

---

## 🔹 lower_bound y upper_bound

### lower_bound(x)
👉 primer elemento **>= x**
```cpp
auto it = s.lower_bound(x);
if (it != s.end()) {
    cout << *it;
}
```

### upper_bound(x)
👉 primer elemento **> x**
```cpp
auto it = s.upper_bound(x);
```

---

## 🔥 Patrón típico de concurso
"Encontrar el menor elemento ≥ x"

```cpp
auto it = s.lower_bound(x);
if (it == s.end()) {
    cout << "no existe";
} else {
    cout << *it;
}
```

---

## 🔹 Borrar elementos

### Borrar por valor
```cpp
s.erase(x);
```

### Borrar con iterador
```cpp
auto it = s.find(x);
if (it != s.end()) s.erase(it);
```

---

## 🔹 `set<pair<int,int>>`

```cpp
set<pair<int,int>> s;
s.insert({2, 3});
s.insert({1, 10});
s.insert({1, 5});
```

Orden interno:
```
(1,5), (1,10), (2,3)
```

👉 Ordena por `first`, luego por `second`

---

## ⚠️ Cosas IMPORTANTES

- ❌ No existe `s[i]`
- ❌ No acceso por índice
- ✔ Siempre ordenado
- ❌ Más lento que `unordered_set`

---

## 🧠 Regla mental de concurso

```
¿Necesito orden dinámico?
¿Siguiente / anterior elemento?
¿Rangos?
→ set
```

```
¿Solo comprobar existencia?
→ unordered_set
```

---

## 🏁 Resumen rápido

| Necesidad | Estructura |
|---------|------------|
| Orden | set |
| Repetidos ordenados | multiset |
| Solo existencia | unordered_set |
| Coordenadas | unordered_set<long long> |

---

## 💡 Consejo final
Si dudas entre `set` y `unordered_set`:
```
Si no usas lower_bound → NO uses set
```
