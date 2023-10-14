#include "avl-tree.hpp"

#include <cassert>
#include <iostream>

using namespace std;

int main() {
  AVLTree tree;

  tree.insert(20);
  tree.insert(10);
  tree.insert(30);
  cout << "Naturally balanced" << endl;
  cout << "All following insertions will trigger rotations and give the "
          "same result as this." << endl;
  tree.print();
  tree.clear();

  tree.insert(10);
  tree.insert(20);
  tree.insert(30);  // trigger left rotation
  cout << "Trigger left rotation" << endl;
  tree.print();
  tree.clear();

  tree.insert(30);
  tree.insert(20);
  tree.insert(10);  // trigger right rotation
  cout << "Trigger right rotation" << endl;
  tree.print();
  tree.clear();

  tree.insert(10);
  tree.insert(30);
  tree.insert(20);  // trigger right-left double rotation
  cout << "Trigger right-left double rotation" << endl;
  tree.print();
  tree.clear();

  tree.insert(30);
  tree.insert(10);
  tree.insert(20);  // trigger left-right double rotation
  cout << "Trigger left-right double rotation" << endl;
  tree.print();
  tree.clear();

  return EXIT_SUCCESS
}
