#pragma once
#include <iostream>
#include <fstream>
#include <string>


// Klasa reprezentuj�ca element listy
template <typename T>
class Node {
public:
    T data;
    Node* next;

    Node(T value);
};
