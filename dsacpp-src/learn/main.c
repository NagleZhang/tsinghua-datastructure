#include <iostream>
#include "vector.h"

using namespace std;

int main() {
  Vector<int> v;
  cout << v.size() << " " << v.capicity() << endl;
  v.insert(0, 1);
  v.insert(10);
  v.insert(10);
  v.insert(30);
  cout << v[1] << endl;
  cout << v.size() << " " << v.capicity() << endl;
  v[4] = 16;
  cout << v[4] << endl;
  v[10] = 15;
  cout << v[10] << endl;
  cout << v.size() << " " << v.capicity() << endl;
}
