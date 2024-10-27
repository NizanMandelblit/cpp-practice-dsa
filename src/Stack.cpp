#include "Stack.h"
#include <stdexcept>

Stack::Stack(){};

Stack::~Stack() {
    while (!isEmpty())
        pop();
};

void
Stack::push(int value) {
    Node *new_node = new Node();
    new_node->data = value;
    new_node->next = top; // Set the new node's next to the current top
    top = new_node;       // Update top to the new node
}

int
Stack::pop() {
    if (isEmpty())
        throw std::underflow_error("Stack is empty");
    Node *ptr = top;
    int result = ptr->data;
    top = top->next;
    delete ptr;
    return result;
}

bool
Stack::isEmpty() const {
    return top ? false : true;
}
