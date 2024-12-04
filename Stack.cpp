#include "Stack.h"

Stack::Stack(int size) {
    capacity = size;
    posts = new Post[capacity];
    top = -1;
}

Stack::~Stack() {
    delete[] posts;
}

void Stack::push(const Post& post) {
    if (isFull()) {
        std::cout << "Stack is full!\n";
        return;
    }
    posts[++top] = post;
}

Post Stack::pop() {
    if (isEmpty()) {
        std::cout << "Stack is empty!\n";
        return Post(-1, "", ""); // Return an invalid post
    }
    return posts[top--];
}

bool Stack::isEmpty() const {
    return top == -1;
}

bool Stack::isFull() const {
    return top == capacity - 1;
}

void Stack::display() const {
    if (isEmpty()) {
        std::cout << "No posts in stack.\n";
        return;
    }
    for (int i = 0; i <= top; i++) {
        std::cout << "Post ID: " << posts[i].postId << ", Content: " << posts[i].content << "\n";
    }
}
