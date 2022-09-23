#pragma once

#include <iostream>
#include "LinkedListNode.h"

template<class T>
class LinkedList {
private:
    LinkedListNode<int> *head;
    LinkedListNode<int> *tail;
public:
    LinkedList() : head(nullptr), tail(nullptr) {}

    void insert(LinkedListNode <T> *node);

    void insert(const T &data);

    void print() {
        LinkedListNode <T> *node = this->head;
        while (node) {
            node->print();
            node = node->next;
        }
        std::cout << "/" << std::endl;
    }
};


template<class T>
void LinkedList<T>::insert(LinkedListNode <T> *node) {
    if (!this->head) {
        this->head = node;
    } else {
        this->tail->next = node;
    }

    this->tail = node;
}

template<class T>
void LinkedList<T>::insert(const T &data) {
    auto *node = new LinkedListNode<T>(data);
    insert(node);
}