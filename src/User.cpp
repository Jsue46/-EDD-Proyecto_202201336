// User.cpp

#include "User.h"

// Definición del constructor
User::User(const std::string& email, const std::string& password)
    : email(email), password(password) {}

// Definición del operador ==
bool User::operator==(const User& other) const {
    return email == other.email && password == other.password;
}

// Definición de los métodos getEmail y getPassword, si los usas
std::string User::getEmail() const {
    return email;
}

std::string User::getPassword() const {
    return password;
}
