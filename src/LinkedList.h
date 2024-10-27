#ifndef LINKEDLIST_H
#define LINKEDLIST_H

class LinkedList {
public:
    LinkedList();
    ~LinkedList();

    void insert(int value);
    bool remove(int value);
    bool contains(int value) const;
    int size() const;

private:
    struct Node {
        int data;
        Node* next = nullptr;
    };
    Node* head = nullptr;
};

#endif // LINKEDLIST_H

