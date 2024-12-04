#include "HashTable.h"
#include <iostream>

int HashTable::hash(int postId) const {
    return postId % TABLE_SIZE;
}

void HashTable::insert(const Post& post) {
    int index = hash(post.postId);
    table[index].push_back(post);
}

Post HashTable::search(int postId) const {
    int index = hash(postId);
    for (const auto& post : table[index]) {
        if (post.postId == postId) {
            return post;
        }
    }
    return Post(-1, "", ""); // Return an invalid post if not found
}

void HashTable::display() const {
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (!table[i].empty()) {
            for (const auto& post : table[i]) {
                std::cout << "Post ID: " << post.postId << ", Content: " << post.content << "\n";
            }
        }
    }
}

