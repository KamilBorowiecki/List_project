#include "pch.h"
#include "NodeList.h"

template <typename T>
NodeList<T>::NodeList() : head(nullptr) {}


template <typename T>
NodeList<T>::NodeList(const NodeList& other) : head(nullptr) {
    copy(other);
    std::cout << "copy constructor" << std::endl;
}


template <typename T>
NodeList<T>::~NodeList() {
    deleteList();
}
template <typename T>
void NodeList<T>::addElement(T value) {
    Node<T>* newNode = new Node<T>(value);

    if (!head) {
        head = newNode;
        return;
    }
    Node<T>* current = head;
    while (current->next) {
        current = current->next;
    }
    current->next = newNode;
    newNode->next = nullptr;
}

template <typename T>
T NodeList<T>::findElement(int element) {
    Node<T>* current = head;
    while (element != 1)
    {
        if (!current || element < 1)
        {
            std::cout << "element doesnt exist" << std::endl;
            return T();
        }
        element--;
        current = current->next;
    }
    return current->data;
}

template <typename T>
T NodeList<T>::findSpecificElement(T object) {
    Node<T>* current = head;
    while (current) {
        if (current->data == object) {
            return object;
        }
        current = current->next;
    }
    std::cout << "element doesnt exist" << std::endl;
    return T();
}

template <typename T>
void NodeList<T>::deleteList() {
    Node<T>* current = head;
    while (current) {
        Node<T>* next = current->next;
        delete current;
        current = next;
    }
}

template <typename T>
void NodeList<T>::copy(const NodeList<T>& other) {
    Node<T>* otherCurrent = other.head;
    Node<T>* current = nullptr;

    while (otherCurrent) {
        // Tworzymy nowy wêze³ z danymi z otherCurrent
        Node<T>* newNode = new Node<T>(otherCurrent->data);

        // Dodajemy nowy wêze³ do listy
        if (!head) {
            head = newNode;
        }
        else {
            current->next = newNode;
        }
        current = newNode;
        otherCurrent = otherCurrent->next;
    }
}

// serializacja
template <typename T>
void NodeList<T>::serialization() {
    std::ofstream plik("data.txt");
    Node<T>* current = head;

    while (current) {
        plik << current->data << " ";
        current = current->next;
    }
    plik.close();
    std::cout << "serializacja" << std::endl;
}

// deserializacja
template <typename T>
void NodeList<T>::deserialization() {
    std::ifstream plik("data.txt");
    Node<T>* current = nullptr;
    T data;

    while (plik >> data)
    {
        // Tworzymy nowy wêze³ z danymi z otherCurrent
        Node<T>* newNode = new Node<T>(data);

        // Dodajemy nowy wêze³ do listy
        if (!head) {
            head = newNode;
        }
        else {
            current->next = newNode;
        }
        current = newNode;
    }
    plik.close();


    std::cout << "deserializacja" << std::endl;
}

template <typename T>
NodeList<T>& NodeList<T>::operator=(const NodeList<T>& object) {
    std::cout << "operator=" << std::endl;
    // sprawdz czy przypiywane dane nie sa identyczne
    if (this == &object)
        return *this;

    // Usun stare dane
    deleteList();
    head = nullptr;

    // Skopiuj (gleboko) dane z argumentu operatora
    copy(object);

    return *this;  // Zwroc obiekt po przypisaniu
}


