//
// Created by niels on 25/07/2025.
//

#ifndef SINGLELINKEDLIST_H
#define SINGLELINKEDLIST_H
#include <stdexcept>
#include <bits/locale_facets_nonio.h>


template <typename T>
class SingleLinkedList {
private:
    struct Node {
        T data;
        Node* next;
        Node(const T& val) : data(val), next(nullptr) {}
    };


    Node* head;
    int length;

public:
    SingleLinkedList() : head(nullptr), length(0) {}

    ~SingleLinkedList() {
        clear();
    }


    void push_front(T item) {
        Node* LinkToAdd = new Node(item);
        LinkToAdd->next = head;
        head = LinkToAdd;
        length++;
    }

    void push_back(T item) {
        Node* LinkToAdd = new Node(item);
        if (!head) {
            head = newNode;
        }else {
            Node* current = head;
            while (current->next) {
                current = current->next;
            }
            current->next = LinkToAdd;
        }
        length++;
    }


    void pop_front() {
        if (!head) {
            throw std::out_of_range("Stack is empty.");
        }
        Node* nextHead = head->next;
        delete head;
        head = nextHead;
        length--;
    }

    void pop_back() {
        if (!head) throw std::out_of_range("List is empty.");
        if (!head->next) {
            delete head;
            head = nullptr;
        }else {
            Node* current = head;
            Node* previous = current;
            while (current->next) {
                previous = current;
                current = current->next;
            }
            delete current->next;
            previous->next = nullptr;
        }
        length--;
    }

    void insert(int index, const T& item) {
        if (index < 0 || index > length) {
            throw std::out_of_range("Index out of bounds.");
        }
        if (index == 0) {
            push_front(item);
            return;
        }
        Node* linkToAdd = new Node(item);
        Node* current = head;

        for (int i = 0; i < index -1; i++) {
            current = current->next;
        }
        linkToAdd->next = current->next;
        current->next = linkToAdd;
        length++;
    }

    void remove(int index) {
        if (index < 0 || index > length) {
            throw std::out_of_range("Index out of bounds.");
        }
        if (index == 0) {
            pop_front();
            return;
        }
        Node* current = head;
        for (int i = 0; i < index - 1; i++) {
            current = current->next;
        }

        Node* toDelete = current->next;
        current->next = toDelete->next;
        delete toDelete;
        length--;
    }

    Node* get(int index) {
        if (index < 0 || index > length) {
            throw std::out_of_range("Index out of bounds.");
        }
        Node* current = head;
        for (int i = 0; i < index; i++) {
            current = current->next;
        }
        return current;
    }

    void set(int index, const T& item) {
        if (index < 0 || index >= length)
            throw std::out_of_range("Index out of bounds.");

        Node* current = head;
        for (int i = 0; i < index; i++) {
            current = current->next;
        }
        current->data = item;
    }

    int size() const {
        return length;
    }

    bool isEmpty() const {
        return length == 0;
    }

    void clear() {
        while (head) {
            Node* next = head->next;
            delete head;
            head = next;
        }
        length = 0;
    }

    bool contains(const T& item) const {
        Node* current = head;
        while (current) {
            if (current->data == item) return true;
            current = current->next;
        }
        return false;
    }
};





#endif //SINGLELINKEDLIST_H
