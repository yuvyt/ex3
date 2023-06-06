//
// Created by lanat on 05/06/2023.
//
#include "Queue.h"
#include <iostream>
#include <exception>


template<typename T>
void Queue<T>::pushBack(const T& object) {
    Node* newNode = new Node(object);
    if (m_size==0){
        m_first = newNode;
    } else {
        m_rear->next = newNode;
        m_rear = newNode;
    }
}
template <typename T>
T& Queue<T>::front() {
    if (m_size <= 0) {
        throw Empty();
    }
    return m_first->data;
}
template <typename T>
T& Queue<T>::popFront(){
    if (m_size == 0) {
        throw Empty(); // or handle the empty queue case in another way
    }
    Node* temp = m_first; // Store a pointer to the first node
    m_first = m_first->next; // Update the first pointer to the next node
    delete temp; // Deallocate memory for the first node
    m_size--; // Decrease the size of the queue
}
template<typename T>
bool Queue<T>::isEmpty(){
     return (m_size==0);
}
template<typename T>
int Queue<T>::size(){
    return m_size;
}
