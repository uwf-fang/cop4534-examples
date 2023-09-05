/**
 * @author Ian Fang <xfang@uwf.edu>
 * @brief Tree node declarations. Assuming the value stored in each node is an
 *        integer.
 *
 * @copyright Copyright (c) 2023
 *
 */
#ifndef TREE_NODES_HPP
#define TREE_NODES_HPP

#include <vector>

// Variable number of pointers to children
struct TreeNode1 {
  int value;
  std::vector<TreeNode1*> children;
};

// First child, next sibling pointers
struct TreeNode2 {
  int value;
  TreeNode2* firstChild;
  TreeNode2* nextSibling;
};

// Parent pointer
struct TreeNode3 {
  int value;
  TreeNode3* parent;
};

// Binary tree node
// left and right pointers
struct BinaryTreeNode {
  int value;
  BinaryTreeNode* left;
  BinaryTreeNode* right;
};

#endif // TREE_NODES_HPP