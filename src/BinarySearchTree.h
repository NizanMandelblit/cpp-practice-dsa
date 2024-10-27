#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

class BinarySearchTree {
  private:
    struct Node {
        int data;
        Node *left = nullptr;
        Node *right = nullptr;
    };
    Node *root = nullptr;
    void destroyTree(Node* node);

  public:
    BinarySearchTree();
    ~BinarySearchTree();

    void insert(int value);
    void insertSubTree(Node *node, Node *root, Node *prev);
    bool remove(int value);
    bool contains(int value) const;
    bool contains_recursive(Node *node, int value) const;
    int getMin() const;
    int getMax() const;
};

#endif // BINARYSEARCHTREE_H
