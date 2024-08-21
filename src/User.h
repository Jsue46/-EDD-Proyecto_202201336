#ifndef USER_H
#define USER_H

#include <string>

class User {
private:
    std::string email;
    std::string password;

public:
    User(const std::string& email, const std::string& password);  // Declaración del constructor

    std::string getEmail() const;
    std::string getPassword() const;

    bool operator==(const User& other) const;  // Declaración del operador ==
};

#endif // USER_H
