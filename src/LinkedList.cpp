#include "LinkedList.h"

LinkedList::LinkedList() {
    head = nullptr;
};
LinkedList::~LinkedList() {
    Node *ptr = head;
    Node *ptrNext{ nullptr };
    while (ptr) {
        ptrNext = ptr->next;
        delete ptr;
        ptr = ptrNext;
    }
};

void
LinkedList::insert(int value) {
    Node *new_node = new Node();
    new_node->data = value;
    new_node->next = nullptr;

    if (!head) {
        head = new_node;
        return;
    }

    Node *ptr = head;
    while (ptr->next)
        ptr = ptr->next;
    ptr->next = new_node;
}

bool
LinkedList::remove(int value) {
    Node *ptr = head;
    Node *prev = nullptr;

    while (ptr) {
        if (ptr->data == value) {
            if (ptr == head)
                head = head->next;
            else
                prev->next = ptr->next;
            delete ptr;
            return true;
        }
        prev = ptr;
        ptr = ptr->next;
    }
    return false;
};

bool
LinkedList::contains(int value) const {
    Node *ptr = head;
    while (ptr) {
        if (ptr->data == value)
            return true;
        ptr = ptr->next;
    }
    return false;
};

int
LinkedList::size() const {
    int result = 0;
    Node *ptr = head;
    while (ptr) {
        result++;
        ptr = ptr->next;
    }
    return result;
};
