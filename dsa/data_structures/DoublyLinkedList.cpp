#include <iostream>

using namespace std;

template<class T> class Node {
    T data;
    Node* next;
    Node* previous;
public:
    Node(T data);
}
template<class T> Node<T>::Node(T data) {
    
}