#include "BinarySearchTree.h"

BinarySearchTree::BinarySearchTree() {
    root = nullptr;
};

BinarySearchTree::~BinarySearchTree() {
    // post order to delete
    // left, right, root
    destroyTree(root);
};

void
BinarySearchTree::destroyTree(Node *node) {
    if (!node)
        return; // Base case: if the node is nullptr, do nothing

    // Recursively delete left and right subtrees
    destroyTree(node->left);
    destroyTree(node->right);

    // Delete the current node
    delete node;
}

void
BinarySearchTree::insert(int value) {
    Node *new_node = new Node();
    new_node->data = value;
    // not doing it explicit can cause a bug in sending nullptr and not setting this->root
    if (!root) {
        root = new_node;
        return;
    }

    insertSubTree(new_node, root, nullptr);
}

void
BinarySearchTree ::insertSubTree(Node *node, Node *root, Node *prev) {
    if (!root) {
        if (prev) {
            // left child in case it's smaller
            if (node->data < prev->data)
                prev->left = node;
            else
                prev->right = node;
        } else {
            root = node;
        }

        return;
    }

    // less then : left
    if (node->data < root->data)
        insertSubTree(node, root->left, root);
    // greater then or equal : right
    else
        insertSubTree(node, root->right, root);
}

bool
BinarySearchTree::remove(int value) {
    /*

    Binary Search Tree Node Removal Cases:

    1. Case (a) - Z is a leaf node:
       If Z is a leaf, simply remove Z by setting its parent's pointer to NULL.

           Parent
             |
             Z
            / \
          NIL  NIL   ->   Z is removed by setting Parent's pointer to NIL


    2. Case (b) - Z has only one child (left child):
       If Z has only one child, replace Z with its child.

           Parent                Parent
             |                     |
             Z            ->      Child
            /                         \
          Child                        (left or right child takes Z's place)


    3. Case (c) - Z has only one child (right child):
       Similar to case (b), replace Z with its only right child.

           Parent                Parent
             |                     |
             Z            ->      Child
              \                    (right child takes Z's place)
             Child


    4. Case (d) - Z has two children, and Y is Z's direct right child:
       If Z has two children, and its successor Y is Z's right child, replace Z with Y directly.

             Parent                  Parent
               |                       |
               Z                       Y
              / \                     / \
            ...  Y           ->      ... Z's left subtree
                  \
                 (Y's right child remains unchanged)


    5. Case (e) - Z has two children, and Y is within Z's right subtree but not the direct right
    child: If the successor Y lies in Z's right subtree but isn’t Z's direct right child, replace Y
    with its right child, and then replace Z with Y.

           Parent                    Parent
             |                         |
             Z                         Y
            / \                       / \
          ... Right        ->       ... Z's left subtree
               /                    (Y's right child is moved up)
              Y
               \
                (Y's right child)

    In each case, removing Z and replacing it with the appropriate successor or child ensures
    the BST properties are maintained.
    */

    Node *prev = nullptr;
    Node *ptr = root;
    if (!ptr)
        return false;

    while (ptr && ptr->data != value) {
        prev = ptr;
        if (value < ptr->data)
            ptr = ptr->left;
        else
            ptr = ptr->right;
    }
    if (!ptr)
        return false;

    // now we found the node, split into cases as explained in the comment

    // case a
    if (ptr->left == nullptr && ptr->right == nullptr) {
        prev->left == ptr ? prev->left = nullptr : prev->right = nullptr;
        delete ptr;
        return true;
    }

    // case b
    if (ptr->left && ptr->right == nullptr) {
        if (prev->left == ptr)
            prev->left = ptr->left;
        else
            prev->right = ptr->left;
        delete ptr;
        return true;
    }

    // case c
    if (ptr->left == nullptr && ptr->right) {
        if (prev)
            if (prev->left == ptr)
                prev->left = ptr->right;
            else
                prev->right = ptr->right;
        else
            root = ptr->right;
        delete ptr;
        return true;
    }

    // Case (d) - Node with two children, and successor is the immediate right child
    if (ptr->left && ptr->right && ptr->right->left == nullptr) {
        // Connect prev to ptr's right child (successor)
        if (prev == nullptr) {
            // If `ptr` is the root, update the tree's root to `ptr->right`
            root = ptr->right;
        } else if (prev->left == ptr) {
            prev->left = ptr->right;
        } else {
            prev->right = ptr->right;
        }

        // Move ptr's left subtree to ptr->right's left child
        ptr->right->left = ptr->left;
        delete ptr;
        return true;
    }

    // Case (e) - Node with two children, where the successor is in the right subtree but not the
    // immediate right child
    if (ptr->left && ptr->right && ptr->right->left != nullptr) {
        Node *successorParent = ptr->right; // Start from right child of `ptr`
        Node *successor = ptr->right->left; // Start with left child of `ptr->right`

        // Traverse to find the leftmost node in `ptr->right`
        while (successor->left != nullptr) {
            successorParent = successor;
            successor = successor->left;
        }

        // Adjust successorParent's left child to successor's right child
        if (successorParent->left == successor) {
            successorParent->left = successor->right;
        } else {
            successorParent->right =
                successor->right; // Just in case successorParent's left was null
        }

        // Replace `ptr` with `successor`
        successor->left = ptr->left;
        successor->right = ptr->right;

        if (prev == nullptr) {
            // If `ptr` is the root node, update the root pointer
            root = successor;
        } else if (prev->left == ptr) {
            prev->left = successor;
        } else {
            prev->right = successor;
        }

        delete ptr;
        return true;
    }
}

bool
BinarySearchTree::contains(int value) const {
    return contains_recursive(root, value);
}

bool
BinarySearchTree::contains_recursive(Node *node, int value) const {
    if (!node)
        return false;

    if (node->data == value)
        return true;

    if (value < node->data)
        return contains_recursive(node->left, value);
    else
        return contains_recursive(node->right, value);
}

int
BinarySearchTree::getMin() const {
    if (!root)
        return -1;

    Node *ptr = root;

    while (ptr->left)
        ptr = ptr->left;

    return ptr->data;
}
int
BinarySearchTree::getMax() const {
    if (!root)
        return -1;

    Node *ptr = root;

    while (ptr->right)
        ptr = ptr->right;

    return ptr->data;
}
