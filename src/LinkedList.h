// LinkedList.h
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

template <typename T>
class LinkedList {
private:
    struct Node {
        T data;
        Node* next;
        Node(const T& data) : data(data), next(nullptr) {}
    };
    
    Node* head;

public:
    LinkedList() : head(nullptr) {}
    ~LinkedList();

    void add(const T& data);
    bool find(const T& data) const;
};

template <typename T>
LinkedList<T>::~LinkedList() {
    Node* current = head;
    while (current != nullptr) {
        Node* nextNode = current->next;
        delete current;
        current = nextNode;
    }
}

template <typename T>
void LinkedList<T>::add(const T& data) {
    Node* newNode = new Node(data);
    newNode->next = head;
    head = newNode;
}

template <typename T>
bool LinkedList<T>::find(const T& data) const {
    Node* current = head;
    while (current != nullptr) {
        if (current->data == data) {
            return true;
        }
        current = current->next;
    }
    return false;
}

#endif // LINKEDLIST_H
