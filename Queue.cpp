#include "Queue.h"
#include <iostream>

Queue::Queue(int capacity) : capacity(capacity), front(0), rear(0), size(0) {
    posts = new Post[capacity];
}

Queue::~Queue() {
    delete[] posts;
}

void Queue::enqueue(const Post& post) {
    if (size < capacity) {
        posts[rear] = post;
        rear = (rear + 1) % capacity;
        ++size;
    } else {
        std::cout << "Queue is full\n";
    }
}

Post Queue::dequeue() {
    if (size > 0) {
        Post post = posts[front];
        front = (front + 1) % capacity;
        --size;
        return post;
    } else {
        std::cout << "Queue is empty\n";
        return Post(0, "", ""); // Return a default post
    }
}

void Queue::display() const {
    if (size == 0) {
        std::cout << "No posts to display\n";
        return;
    }

    int i = front;
    for (int count = 0; count < size; ++count) {
        std::cout << "Post ID: " << posts[i].postId << ", User: " << posts[i].username
                  << ", Content: " << posts[i].content << "\n";
        i = (i + 1) % capacity;
    }
}

int Queue::getSize() const {
    return size;
}

Post Queue::peek(int index) const {
    if (index < 0 || index >= size) {
        std::cout << "Index out of bounds\n";
        return Post(0, "", "");
    }
    int i = (front + index) % capacity;
    return posts[i];
}

bool Queue::isEmpty() const {
    return size == 0;
}
