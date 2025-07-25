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
            resize(maxCapacity * 2);
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
        if (index < 0 || index >= length) throw std::out_of_range("Index out of bounds");
        return data[index];
    }

    void set (int index, const T item) {
        if (index < 0 || index >= length) throw std::out_of_range("Index out of bounds");
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

    // TODO free memory for improved memory management
    void clear() {
        length = 0;
    }

    // way index works                          [ 5, 10, 15, 20 ]
    // this is where the index inserts items     0  1   2   3  4

    void insert(int index, T value) {
        if (index < 0 || index > length) {
            throw std::out_of_range("index is out of range.");
        }

        if (length == maxCapacity) {
            resize(maxCapacity * 2);
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

    // normal index
    void remove(int index) {
        if (index < 0 || index > length) {
            throw std::out_of_range("index is out of range.");
        }

        T* newData = new T[maxCapacity];
        for (int i = 0; i < index; i++) {
            newData[i] = data[i];
        }

        for (int i = index + 1 ; i < length; i++) {
            newData[i - 1] = data[i];
        }
        delete[] data;
        data = newData;
        length--;
    }

    bool contains(T item) const {
        for (int i = 0; i < length; i++) {
            if (data[i] == item) {
                return true;
            }
        }
        return false;
    }

    int indexOf(T item) {
        for (int i = 0; i < length; i++) {
            if (data[i] == item) {
                return i;
            }
        }
        return -1;
    }

    void reserve(int newCapacity) {
        if (newCapacity > maxCapacity) {
            resize(newCapacity);
        }
    }


};



#endif //ARRAY_H
