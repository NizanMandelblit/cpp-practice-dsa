#ifndef STACK_H
#define STACK_H

class Stack {
public:
    Stack();
    ~Stack();

    void push(int value);
    int pop();
    bool isEmpty() const;

private:
    struct Node {
        int data;
        Node* next;
    };
    Node* top;
};

#endif // STACK_H

