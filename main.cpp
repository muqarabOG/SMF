#include <iostream>
#include "SocialMediaFeed.h"

int main() {
    // Create a SocialMediaFeed object with a feed size of 5 and a stack size of 5
    SocialMediaFeed feed(5, 5);

    // Create some posts
    feed.createPost(1, "Alice", "This is my first post!");
    feed.createPost(2, "Bob", "Learning C++ with frontend integration.");
    feed.createPost(3, "Charlie", "C++ is fun!");
    feed.createPost(4, "Alice", "Hey, how is everyone?");
    feed.createPost(5, "Bob", "Just completed a project.");

    // Display the feed
    std::cout << "Social Media Feed:\n";
    feed.displayFeed();

    // Undo a post
    std::cout << "\nUndoing last post...\n";
    feed.undoPost();

    // Display the feed again
    std::cout << "\nUpdated Social Media Feed:\n";
    feed.displayFeed();

    // Save the feed to a JSON file
    std::cout << "\nSaving feed to 'feed.json'...\n";
    feed.saveFeedToJson("feed.json");

    return 0;
}
