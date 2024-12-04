#ifndef POST_H
#define POST_H

#include <string>

class Post {
public:
    int postId;
    std::string content;
    std::string username;

    // Constructor that takes three arguments
    Post(int id, const std::string& user, const std::string& msg)
            : postId(id), username(user), content(msg) {}

    // Default constructor (needed for stack/queue initialization)
    Post() : postId(0), username(""), content("") {}
};

#endif // POST_H
