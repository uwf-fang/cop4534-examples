/**
 * @file b-tree.hpp
 * @author Ian Fang
 * @brief Interface of a B-tree
 *        Implementation not included due to its complexity
 *
 * @copyright Copyright (c) 2023
 *
 */
#ifndef B_TREE_HPP
#define B_TREE_HPP

// B-tree node
struct BTreeNode {

  bool isLeaf;

  // Up to order-1 keys
  int *keys;

  // Up to order children
  BTreeNode **children;

  // Number of keys
  // Number of children is numKeys + 1
  int numKeys;

  BTreeNode(int order, bool isLeaf);
  ~BTreeNode();
};


// B-tree class
class BTree {
  BTreeNode *root;
  int order;

 public:
  BTree(int order);
  ~BTree();

  void insert(int key);
  void remove(int key);
  bool contains(int key);
  void traverse();
};

#endif  // B_TREE_HPP
