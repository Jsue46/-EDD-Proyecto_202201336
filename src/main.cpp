// main.cpp
#include <iostream>
#include "LinkedList.h"
#include "User.h"

int main() {
    LinkedList<User> users;

    std::string email, password;

    std::cout << "Registro de usuario" << std::endl;
    std::cout << "Email: ";
    std::cin >> email;
    std::cout << "Password: ";
    std::cin >> password;

    User newUser(email, password);

    if (!users.find(newUser)) {
        users.add(newUser);
        std::cout << "Usuario registrado con éxito." << std::endl;
    } else {
        std::cout << "El usuario ya existe." << std::endl;
    }

    return 0;
}


int main() {
    LinkedList<User> users;

    // Agregar usuarios predefinidos para pruebas
    users.add(User("test@example.com", "password123"));

    std::string email, password;

    std::cout << "Inicio de sesión" << std::endl;
    std::cout << "Email: ";
    std::cin >> email;
    std::cout << "Password: ";
    std::cin >> password;

    User loginUser(email, password);

    if (users.find(loginUser)) {
        std::cout << "Inicio de sesión exitoso." << std::endl;
    } else {
        std::cout << "Credenciales incorrectas." << std::endl;
    }

    return 0;
}
