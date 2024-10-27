#include "LinkedList.h"

class LinkedList {
  public:
    LinkedList() {
        this->head = nullptr;
    };
    ~LinkedList() {
        Node *ptr = this->head;
        Node *ptrNext {nullptr};
        while (ptr) {
            ptrNext = ptr->next;
            delete ptr;
            ptr = ptrNext;
        }
    };

    void insert(int value) {

    }
    bool remove(int value);
    bool contains(int value) const;
    int size() const;

  private:
    struct Node {
        int data;
        Node *next;
    };
    Node *head;
};
