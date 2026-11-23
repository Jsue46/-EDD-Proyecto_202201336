# High-Performance Data Structures and Social Network Engine in C++

Academic project developed for the **Data Structures** course at the Universidad de San Carlos de Guatemala (Second Semester 2024).

This repository contains an implementation of linear and non-linear data structures written in modern C++ from scratch, applied to a social network platform simulation with Graphviz visualization.

---

## Overview

The application models a multi-user social network environment where users, friendships, friendship requests, and publications are maintained entirely through custom, in-memory pointer-based data structures without relying on the C++ Standard Template Library (STL) containers for underlying collections. The project supports JSON dataset imports via `nlohmann/json` and exports dynamic Graphviz DOT representations of all active data structures.

---

## Data Structures Implemented

- **Doubly Circular Linked List (`ListaCircularD`):** Used for ordered cyclical collections with bidirectional traversal.
- **Singly Linked List (`ListaSimple`):** Lightweight sequential container for pending requests and auxiliary tracking.
- **Doubly Linked List (`ListaDoble`):** Robust linear container supporting bidirectional insertions and removals.
- **Stack (`Pila` / `PilaSolicitudes`):** LIFO collection for historical operation logs and request queues.
- **Sparse Matrix (`DatosMatriz`):** 2D orthogonal linked structure for high-efficiency representation of user relations and multidimensional matrices.

---

## Key Features

- Direct pointer manipulation and explicit memory management in C++
- No STL collection wrappers for custom data structures
- Fast JSON deserialization and batch record loading
- Automated Graphviz diagram export for memory structure visual verification
- Interactive terminal menu for data manipulation, user browsing, and reporting

---

## Technologies

- **Language:** C++ (C++17 / C++20)
- **Build System:** CMake, Conan Package Manager
- **Libraries:** `nlohmann/json`
- **Visualization:** Graphviz (DOT language)

---

## Repository Structure

```
-EDD-Proyecto_202201336/
├── src/
│   ├── ListaCircularD.h / .cpp    # Doubly circular linked list
│   ├── ListaDoble.h               # Doubly linked list
│   ├── ListaSimple.h / .cpp       # Singly linked list
│   ├── Pila.h                     # Stack implementation
│   ├── DatosMatriz.h              # Orthogonal sparse matrix
│   ├── Usuario.h / Menu.h         # Domain models and interactive CLI
│   └── main.cpp                   # Application entry point
├── docs/                          # Technical and user manuals
├── CMakeLists.txt                 # CMake project specification
└── README.md
```

---

## Academic Context

| Field       | Detail                                         |
|-------------|------------------------------------------------|
| Course      | Data Structures (EDD)                          |
| Institution | Universidad de San Carlos de Guatemala         |
| Semester    | Second Semester 2024                           |
| Author      | Estuardo Josue Vaquiax Reyes (202201336)       |
