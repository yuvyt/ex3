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
    void pushBack(const T &object);

    Queue<T>(const Queue<T> &otherQueue) = default;

    bool isEmpty();

//    class Full{};
    class Empty {
    };

    T &front();

    T &popFront();

    int size();

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
    for (const T& element : queue) {
        if (functionPtr(element)) {
            resultQueue.pushBack(element);
        }
    }

    return resultQueue;
}
#endif //MTMCHKIN_QUEUE_H
