#include "pch.h"
#include "Node.h"

template <typename T>
Node<T>::Node(T value) : data(value), next(nullptr) {}
