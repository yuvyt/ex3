//
// Created by lanat on 05/06/2023.
//

#ifndef MTMCHKIN_QUEUE_H
#define MTMCHKIN_QUEUE_H

#include <iostream>
#include <exception>

typedef void(*StaticFunctionPtr)();

template<typename T>
class Queue {
private:
    struct Node {
        T data;
        Node *next;

        Node(const T &value) : data(value), next(nullptr) {}

    };
    int m_size;
    Node *m_first;
    Node *m_rear;

public:
    Queue<T>(const Queue<T> &otherQueue) = default;
//    class Full{};
    class Empty {
    };

    T& front() {
        if (m_size <= 0) {
            throw Empty();
        }
        return m_first->data;
    }

    void pushBack(const T& object) {
        Node* newNode = new Node(object);
        if (m_size==0){
            m_first = newNode;
        } else {
            m_rear->next = newNode;
            m_rear = newNode;
        }
    }
    T& popFront(){
        if (m_size == 0) {
            throw Empty(); // or handle the empty queue case in another way
        }
        Node* temp = m_first; // Store a pointer to the first node
        m_first = m_first->next; // Update the first pointer to the next node
        delete temp; // Deallocate memory for the first node
        m_size--; // Decrease the size of the queue
    }
    bool isEmpty(){
        return (m_size==0);
    }

    int size(){
        return m_size;
    }
    class iterator {
    private:
        Node* current;

    public:
        iterator(Node* node) : current(node) {}

        T& operator*() const {
            return current->data;
        }

        iterator& operator++() {
            current = current->next;
            return *this;
        }

        iterator operator++(int) {
            iterator temp = *this;
            current = current->next;
            return temp;
        }

        bool operator==(const iterator& other) const {
            return current == other.current;
        }

        bool operator!=(const iterator& other) const {
            return !(*this == other);
        }
    };

    iterator begin() {
        return iterator(m_first);
    }

    iterator end() {
        return iterator(nullptr);
    }


};
template<typename T,typename Function>
Queue<T> filter(const Queue<T>& queue, Function functionPtr) {
    Queue<T> resultQueue;
    for (const T& element : queue){
        if (functionPtr(element)) {
            resultQueue.pushBack(element);
        }
    }
    return resultQueue;
}
template<typename T, typename Function>
void transform(Queue<T>& queue, Function functionPtr) {
    for (T& element : queue) {
        element = functionPtr(element);
    }
}
#endif //MTMCHKIN_QUEUE_H
