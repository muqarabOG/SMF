#ifndef STACK_H
#define STACK_H

#include <iostream>
#include "Post.h"

class Stack {
private:
    Post* posts;
    int top;
    int capacity;

public:
    Stack(int size);
    ~Stack();

    void push(const Post& post);
    Post pop();
    bool isEmpty() const;
    bool isFull() const;
    void display() const;
};

#endif // STACK_H
