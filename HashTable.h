#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "Post.h"
#include <list>

class HashTable {
private:
    static const int TABLE_SIZE = 10;
    std::list<Post> table[TABLE_SIZE];

    int hash(int postId) const;

public:
    void insert(const Post& post);
    Post search(int postId) const;
    void display() const;
};

#endif // HASHTABLE_H
