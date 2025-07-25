//
// Created by niels on 25/07/2025.
//

#ifndef ARRAY_H
#define ARRAY_H
#include <stdexcept>


template <typename T>
class DynamicArray {
private:
    T* data;
    int length;
    int maxCapacity;

public:
    explicit DynamicArray(int initialCapacity = 2): length(0), maxCapacity(initialCapacity) {
        data = new T[maxCapacity];
    }

    ~DynamicArray() {
        delete[] data;
    }

    void push(T item) {
        if (length == maxCapacity) {
            resize(2 + maxCapacity);
        }
        data[length++] = item;
    }

    void resize(int newCapacity) {
        T* newData = new T[newCapacity];

        for (int i = 0; i < length; i++) {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
        maxCapacity = newCapacity;
    }

    int size() const {
        return length;
    }

    int capacity() const {
        return maxCapacity;
    }

    T get (int index) const {
        return data[index];
    }

    void set (int index, const T item) {
        data[index] = item;
    }

    bool isEmpty() {
        if (length == 0) {
            return true;
        }
        return false;
    }

    T removeLast() {
        if (length > 0) {
            T itemToReturn = data[length -1];
            length--;
            return itemToReturn;
        }
        throw std::out_of_range("Array is empty.");
    }

    void clear() {
        length = 0;
        resize(2);
    }

    // way index works                          [ 5, 10, 15, 20 ]
    // this is where the index inserts items     0  1   2   3  4

    void insert(int index, T value) {
        if (index < 0 || index > length) {
            throw std::out_of_range("index is out of range.");
        }

        if (length == maxCapacity) {
            resize(2 * maxCapacity);
        }

        T* newData = new T[maxCapacity];

        for (int i = 0; i < index; i++) {
            newData[i] = data[i];
        }
        newData[index] = value;

        for (int i = index; i < length; i++) {
            newData[i+1] = data[i];
        }
        delete[] data;
        data = newData;
        length++;
    }
};



#endif //ARRAY_H
