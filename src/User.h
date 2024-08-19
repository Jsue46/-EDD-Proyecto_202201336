// User.h
#ifndef USER_H
#define USER_H

#include <string>

class User {
private:
    std::string email;
    std::string password;

public:
    User(const std::string& email, const std::string& password);

    std::string getEmail() const;
    std::string getPassword() const;
};

#endif // USER_H
