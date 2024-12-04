#ifndef QUEUE_H
#define QUEUE_H

#include "Post.h"

class Queue {
private:
    Post* posts;
    int capacity;
    int front;
    int rear;
    int size;

public:
    Queue(int capacity);
    ~Queue();

    void enqueue(const Post& post);
    Post dequeue();
    void display() const;

    int getSize() const;  // To get the current size of the queue
    Post peek(int index) const;  // To access a post by its index
    bool isEmpty() const;  // To check if the queue is empty
};

#endif
