# 🧠 CHULETA – `unordered_set` en C++

## 📌 Qué es
- Contenedor basado en **hash**
- **NO ordenado**
- **NO permite duplicados**
- Complejidad: **O(1) promedio**

👉 Ideal para **existencia / visitados**

---

## 🔹 Declaración

```cpp
#include <bits/stdc++.h>
using namespace std;

unordered_set<int> s;
```

---

## 🔹 Insertar elementos
```cpp
s.insert(5);
s.insert(1);
s.insert(3);
```

---

## 🔹 Comprobar existencia
```cpp
if (s.count(x)) {
    // x existe
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

## 🔹 Recorrer elementos
```cpp
for (int x : s) {
    cout << x << " ";
}
```
⚠️ El orden es **arbitrario**

---

## 🔹 Tamaño
```cpp
int n = s.size();
```

---

## 🔹 Limpiar
```cpp
s.clear();
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

## 🔹 `unordered_set<pair<int,int>>` ❌ (no directo)
Necesita hash personalizado → **evitar en concurso**

---

## 🔥 Patrón PRO: coordenadas `(x,y)`

### Empaquetar coordenadas
```cpp
inline long long key(int x, int y) {
    return ( (long long)(uint32_t)x << 32 ) | (uint32_t)y;
}
```

### Declaración
```cpp
unordered_set<long long> s;
s.reserve(200000);
s.max_load_factor(0.7);
```

### Uso
```cpp
s.insert(key(x, y));

if (s.count(key(px, py))) {
    // existe
}
```

---

## 🔹 Recuperar coordenadas
```cpp
inline int get_x(long long k) {
    return (int)(k >> 32);
}

inline int get_y(long long k) {
    return (int)(k & 0xFFFFFFFF);
}
```

---

## ⚠️ Errores comunes

- ❌ Esperar orden
- ❌ Usar `lower_bound`
- ❌ No reservar memoria (rehash lento)
- ❌ Hash casero malo

---

## 🧠 Regla mental de concurso

```
¿Solo existe / no existe?
→ unordered_set
```

```
¿Necesito orden?
→ set
```

---

## 🏁 Resumen rápido

| Necesidad | Estructura |
|---------|------------|
| Existencia | unordered_set |
| Visitados | unordered_set |
| BFS / DFS | unordered_set |
| Coordenadas | unordered_set<long long> |

---

## 💡 Consejo final
Si estás dudando:
```
unordered_set > set
(salvo que necesites orden)
```
