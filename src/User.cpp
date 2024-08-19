// User.cpp
#include "User.h"

User::User(const std::string& email, const std::string& password) : email(email), password(password) {}

std::string User::getEmail() const {
    return email;
}

std::string User::getPassword() const {
    return password;
}
