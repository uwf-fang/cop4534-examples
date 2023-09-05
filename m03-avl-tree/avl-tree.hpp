#ifndef AVL_TREE_HPP
#define AVL_TREE_HPP

struct AVLTreeNode {
  int value;
  AVLTreeNode* left;
  AVLTreeNode* right;
  int height;
  AVLTreeNode(int value, AVLTreeNode* left = nullptr,
              AVLTreeNode* right = nullptr, int height = 0)
      : value(value), left(left), right(right), height(height){};
};

class AVLTree {
  AVLTreeNode* root;
  bool contains(int value, AVLTreeNode* node);
  AVLTreeNode* insert(int value, AVLTreeNode* node);
  AVLTreeNode* remove(int value, AVLTreeNode* node);
  int height(AVLTreeNode* node);
  AVLTreeNode* balance(AVLTreeNode* node);
  AVLTreeNode* leftRotate(AVLTreeNode* node);
  AVLTreeNode* rightRotate(AVLTreeNode* node);
  AVLTreeNode* leftRightDoubleRotate(AVLTreeNode* node);
  AVLTreeNode* rightLeftDoubleRotate(AVLTreeNode* node);
  AVLTreeNode* findMin(AVLTreeNode* node);
  void updateHeight(AVLTreeNode* node);
  void printHierarchy(AVLTreeNode* node, int depth);
  AVLTreeNode* clear(AVLTreeNode* node);

 public:
  AVLTree() : root(nullptr){};
  ~AVLTree();
  void clear();
  bool contains(int value);
  void insert(int value);
  void remove(int value);
  void print();
};

#endif  // AVL_TREE_HPP
