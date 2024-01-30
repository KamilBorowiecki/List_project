#pragma once

#include "Node.cpp"

// Klasa zarz�dzaj�ca list� jednokierunkow�
template <typename T>
class NodeList {
public:
    Node<T>* head;

    NodeList();
    NodeList(const NodeList& o);
    ~NodeList();
    void addElement(T value);
    T findElement(int element);
    T findSpecificElement(T object);
    void copy(const NodeList& o);
    void deleteList();
    void serialization();
    void deserialization();

    NodeList<T>& operator=(const NodeList<T>& object);

};