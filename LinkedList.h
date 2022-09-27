#pragma once

#include <iostream>
#include "LinkedListNode.h"
#include <climits>
using namespace std;

template<class T>
class LinkedList {
private:
    LinkedListNode<int> *head;
    LinkedListNode<int> *tail;
public:
    LinkedList() : head(nullptr), tail(nullptr) {}
    void reverse();
    void pop_front();
    int find_min_element();
    void empty();
    void remove(const T &data);
    void insert(LinkedListNode <T> *node);
    void insert(const T &data);
    int getSize()
    {
        return Size;
    }

    void print() {
        LinkedListNode <T> *node = this->head;
        while (node) {
            node->print();
            node = node->next;
        }
        std::cout << "/" << std::endl;
    }
    int Size;
};


template<class T>
void LinkedList<T>::insert(LinkedListNode <T> *node) {
    if (!this->head) {
        this->head = node;
    } else {
        this->tail->next = node;
    }
    this->tail = node;
    Size++;
}

template<class T>
void LinkedList<T>::insert(const T &data) {
    auto *node = new LinkedListNode<T>(data);
    insert(node);
    Size++;
}

template<class T>
void LinkedList<T>::reverse()
{
    LinkedListNode<T> *current = head;
    LinkedListNode<T> *prev = nullptr;
    LinkedListNode<T> *next = nullptr;
    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}

template<class T>
void LinkedList<T>::pop_front() {
    LinkedListNode<T> *temp = head;
    head = head->next;
    delete temp;
    Size--;
}

template<class T>
void LinkedList<T>::empty() {
    while (Size)
    {
        pop_front();
    }
}

template<class T>
int LinkedList<T>::find_min_element() {
    {
        LinkedListNode<T> *current = head;
        int min = INT_MAX;
        while (current != NULL) {
            if (min > current->data)
                min = current->data;
            current = current->next;
        }
        return min;
    }
}
