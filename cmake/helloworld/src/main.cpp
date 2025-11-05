#include <iostream>
using namespace std;

bool casoDePrueba() {
  unsigned int quantitat;

  // llegir casos
  cin >> quantitat;

  if (!cin)
    return false;
  else {
    for (int i = 0; i < quantitat; i++) {
      cout << "Hola mundo." << endl;
    }
    return true;
  }
} // casoDePrueba

int main() {

  while (casoDePrueba()) {
  }

  return 0;
}
