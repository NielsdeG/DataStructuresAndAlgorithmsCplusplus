//
// Created by niels on 25/07/2025.
//

#ifndef STACK_H
#define STACK_H
#include "DynamicArray.h"

// implementation of a stack using my own DynamicArray
template <typename T>
class Stack {
private:
    DynamicArray<T> data;


public:
    Stack() = default;

    void push(const T& value) {
        data.push(value);
    }

    T pop() {
        if (isEmpty()) {
            throw std::underflow_error("Stack underflow");
        }
        T itemToReturn = data.get(data.size() - 1);
        data.removeLast();
        return itemToReturn;
    }

    T peek() {
        if (isEmpty()) {
            throw std::underflow_error("Stack underflow");
        }
        T itemToReturn = data.get(data.size() - 1);
        return itemToReturn;
    }

    bool isEmpty() {
        return data.isEmpty();
    }


    int size() const {
        return data.size();
    }


};



#endif //STACK_H
