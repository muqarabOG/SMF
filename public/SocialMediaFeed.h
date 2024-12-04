#ifndef SOCIALMEDIAFEED_H
#define SOCIALMEDIAFEED_H

#include "Post.h"
#include "Queue.h"
#include "Stack.h"
#include "HashTable.h"
#include <string>
#include <iostream>
#include "nlohmann/json.hpp"
using json = nlohmann::json;

class SocialMediaFeed {
private:
    Queue feedQueue;
    Stack recentPostsStack;
    HashTable userPosts;

public:
    // Constructor
    SocialMediaFeed(int feedSize, int stackSize);

    // Methods to interact with posts
    void createPost(int postId, const std::string& username, const std::string& content);
    void displayFeed();
    void undoPost();
    void displayUserPosts(const std::string& username);
    void saveFeedToJson(const std::string& filename);  // Method to save feed to JSON
};

#endif
