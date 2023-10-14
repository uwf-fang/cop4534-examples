#include <iostream>
#include <string>

using namespace std;

void enumeratePhoneNumbers(int n, string prefix) {
  if (n == 0) {
    cout << prefix << endl;
    return;
  }
  for (int i = 0; i < 10; i++) {
    enumeratePhoneNumbers(n - 1, prefix + to_string(i));
  }
}

int main() {

  cout << "Phone numbers with 3 digits:" << endl;
  enumeratePhoneNumbers(3, "");

  return EXIT_SUCCESS;
}