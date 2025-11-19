#include <iostream>
using namespace std;

bool casoDePrueba() {
  unsigned int vivienda;

  cin >> vivienda;

  if (vivienda == 0)
    return false;
  else {
    if (vivienda % 2 == 0) {
      cout << "DERECHA" << endl;
    } else {
      cout << "IZQUIERDA" << endl;
    }
  } // CÓDIGO PRINCIPAL AQUÍ
  return true;
} // casoDePrueba

int main() {

  while (casoDePrueba()) {
  }

  return 0;
}
