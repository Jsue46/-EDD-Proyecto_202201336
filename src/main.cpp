// main.cpp
#include <iostream>
#include "LinkedList.h"
#include "User.h"

void registerUser(LinkedList<User>& users) {
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
}

void loginUser(LinkedList<User>& users) {
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
}

int main() {
    LinkedList<User> users;

    // Ejemplo de usuario predefinido para pruebas
    users.add(User("test@example.com", "password123"));

    // Llamar a la función de registro
    registerUser(users);

    // Llamar a la función de inicio de sesión
    loginUser(users);

    return 0;
}
