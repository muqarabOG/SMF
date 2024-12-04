#include "SocialMediaFeed.h"
#include <fstream>

SocialMediaFeed::SocialMediaFeed(int feedSize, int stackSize)
        : feedQueue(feedSize), recentPostsStack(stackSize) {}

void SocialMediaFeed::createPost(int postId, const std::string& username, const std::string& content) {
    Post newPost(postId, username, content);
    userPosts.insert(newPost);
    feedQueue.enqueue(newPost);
    recentPostsStack.push(newPost);
}

void SocialMediaFeed::displayFeed() {
    feedQueue.display();
}

void SocialMediaFeed::undoPost() {
    if (!recentPostsStack.isEmpty()) {
        Post post = recentPostsStack.pop();
        std::cout << "Post undone: " << post.content << "\n";
    }
}

void SocialMediaFeed::displayUserPosts(const std::string& username) {
    for (int i = 0; i < 10; i++) {
        Post post = userPosts.search(i);
        if (post.username == username) {
            std::cout << "Post ID: " << post.postId << ", Content: " << post.content << "\n";
        }
    }
}

// Save feed to a JSON file
void SocialMediaFeed::saveFeedToJson(const std::string& filename) {
    nlohmann::json j;

    // Add posts to the JSON object
    for (int i = 0; i < feedQueue.getSize(); ++i) {
        Post post = feedQueue.peek(i);
        j["posts"].push_back({
                                     {"postId", post.postId},
                                     {"username", post.username},
                                     {"content", post.content}
                             });
    }

    // Write the JSON object to a file
    std::ofstream file(filename);
    file << j.dump(4);  // Pretty print with 4 spaces indentation
    file.close();
}
