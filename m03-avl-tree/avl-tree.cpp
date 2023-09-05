#include "avl-tree.hpp"

#include <algorithm>
#include <iostream>
#include <queue>
#include <string>

using namespace std;
bool AVLTree::contains(int value, AVLTreeNode* node) {
  if (node == nullptr) return false;
  if (node->value == value) return true;
  if (value < node->value) return contains(value, node->left);
  return contains(value, node->right);
}

AVLTreeNode* AVLTree::insert(int value, AVLTreeNode* node) {
  if (node == nullptr) node = new AVLTreeNode(value);
  if (value < node->value)
    node->left = insert(value, node->left);
  else if (value > node->value)
    node->right = insert(value, node->right);
  node = balance(node);
  return node;
}

AVLTreeNode* AVLTree::remove(int value, AVLTreeNode* node) {
  if (node == nullptr) return nullptr;
  if (value < node->value)
    node->left = remove(value, node->left);
  else if (value > node->value)
    node->right = remove(value, node->right);
  else if (node->left != nullptr && node->right != nullptr) {
    // found match; two children
    node->value = findMin(node->right)->value;
    node->right = remove(node->value, node->right);
  } else {
    // found match; single child or no child
    AVLTreeNode* oldNode = node;
    node = (node->left != nullptr) ? node->left : node->right;
    delete oldNode;
  }
  node = balance(node);
  return node;
}

int AVLTree::height(AVLTreeNode* node) {
  return node == nullptr ? -1 : node->height;
}

AVLTreeNode* AVLTree::balance(AVLTreeNode* node) {
  if (node == nullptr) return nullptr;
  if (height(node->left) - height(node->right) > 1) {
    if (height(node->left->left) >= height(node->left->right))
      node = rightRotate(node);  // LL
    else
      node = leftRightDoubleRotate(node);  // LR
  } else if (height(node->right) - height(node->left) > 1) {
    if (height(node->right->right) >= height(node->right->left))
      node = leftRotate(node);  // RR
    else
      node = rightLeftDoubleRotate(node);  // RL
  }
  updateHeight(node);
  return node;
}

AVLTreeNode* AVLTree::leftRotate(AVLTreeNode* node) {
  AVLTreeNode* temp = node->right;
  node->right = temp->left;
  temp->left = node;
  updateHeight(node);
  updateHeight(temp);
  return temp;
}

AVLTreeNode* AVLTree::rightRotate(AVLTreeNode* node) {
  AVLTreeNode* temp = node->left;
  node->left = temp->right;
  temp->right = node;
  updateHeight(node);
  updateHeight(temp);
  return temp;
}

AVLTreeNode* AVLTree::leftRightDoubleRotate(AVLTreeNode* node) {
  node->left = leftRotate(node->left);
  return rightRotate(node);
}

AVLTreeNode* AVLTree::rightLeftDoubleRotate(AVLTreeNode* node) {
  node->right = rightRotate(node->right);
  return leftRotate(node);
}

AVLTreeNode* AVLTree::findMin(AVLTreeNode* node) {
  if (node == nullptr) return nullptr;
  if (node->left == nullptr) return node;
  return findMin(node->left);
}

void AVLTree::updateHeight(AVLTreeNode* node) {
  if (node == nullptr) return;
  node->height = max(height(node->left), height(node->right)) + 1;
}

AVLTree::~AVLTree() {
  clear();
}

void AVLTree::clear() {
  root = clear(root);
}

bool AVLTree::contains(int value) { return contains(value, root); }

void AVLTree::insert(int value) { root = insert(value, root); }

void AVLTree::remove(int value) { root = remove(value, root); }

// Print the tree in a hierarchical fashion
void AVLTree::print() { printHierarchy(root, 0); }

void AVLTree::printHierarchy(AVLTreeNode* node, int depth) {
  if (node == nullptr) {
    return;
  }
  string spaces(depth * 2, ' ');
  cout << spaces << "|_" << node->value << std::endl;

  // Recursively print left and right subtrees with increased depth
  printHierarchy(node->left, depth + 1);
  printHierarchy(node->right, depth + 1);
}

AVLTreeNode* AVLTree::clear(AVLTreeNode* node) {
  if (node == nullptr) return nullptr;
  node->left = clear(node->left);
  node->right = clear(node->right);
  delete node;
  return nullptr;
 }
