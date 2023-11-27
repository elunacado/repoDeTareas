/*
 * quadratic.h
 *
 *  Created on: [DATE]
 *      Author: [AUTHOR]
 */

#ifndef QUADRATIC_H_
#define QUADRATIC_H_

#include <iostream>
#include <string>
#include <sstream>

template <class Key, class Value>
class Quadratic {
private:
    unsigned int (*func)(const Key);
    unsigned int size;
    unsigned int count;

    Key *keys;
    Key initialValue;
    Value *values;

    long indexOf(const Key) const;
    long quadraticProbe(const Key, unsigned int) const;

public:
    Quadratic(unsigned int, Key, unsigned int (*f)(const Key));
    ~Quadratic();
    bool full() const;
    bool put(Key, Value);
    bool contains(const Key) const;
    Value get(const Key);
    void clear();
    std::string toString() const;
};

template <class Key, class Value>
Quadratic<Key, Value>::Quadratic(unsigned int sze, Key init, unsigned int (*f)(const Key)) {
    size = sze;
    keys = new Key[size];
    if (keys == nullptr) {
        throw std::bad_alloc(); // or handle memory allocation failure in a better way
    }
    initialValue = init;
    for (unsigned int i = 0; i < size; i++) {
        keys[i] = init;
    }
    values = new Value[size];
    if (values == nullptr) {
        delete[] keys;
        throw std::bad_alloc(); // or handle memory allocation failure in a better way
    }
    for (int i = 0; i < sze; i++) {
        values[i] = 0;
    }

    func = f;
    count = 0;
}

template <class Key, class Value>
Quadratic<Key, Value>::~Quadratic() {
    delete[] keys;
    keys = nullptr;
    delete[] values;
    values = nullptr;
    size = 0;
    func = nullptr;
    count = 0;
}

template <class Key, class Value>
bool Quadratic<Key, Value>::full() const {
    return (count >= size);
}

template <class Key, class Value>
long Quadratic<Key, Value>::indexOf(const Key k) const {
    unsigned int i, start;

    start = i = func(k) % size;
    unsigned int attempts = 0;

    do {
        if (keys[i] == k) {
            return i;
        }
        i = quadraticProbe(k, attempts++);
    } while (start != i);

    return -1;
}

template <class Key, class Value>
long Quadratic<Key, Value>::quadraticProbe(const Key k, unsigned int attempts) const {
    return (func(k) + attempts * attempts) % size;
}

template <class Key, class Value>
bool Quadratic<Key, Value>::put(Key k, Value v) {
    size_t index = func(k) % size;
    size_t originalIndex = index;
    size_t attempt = 1;

    while (keys[index] != k && keys[index] != initialValue) {
        // Quadratic probing: move to the next position using a quadratic function
        index = (originalIndex + attempt * attempt) % size;
        attempt++;

        // You may need to handle collisions and resizing here

        if (index == originalIndex) {
            // Table is full or there's an issue with the hash function
            std::cerr << "Error: Unable to insert key-value pair." << std::endl;
            return false;
        }
    }

    keys[index] = k;
    values[index] = v;
    return true;
}



template <class Key, class Value>
Value Quadratic<Key, Value>::get(const Key k) {
    long pos = indexOf(k);

    if (pos != -1) {
        return values[pos];
    }

    throw std::out_of_range("Key not found");
}

template <class Key, class Value>
void Quadratic<Key, Value>::clear() {
    count = 0;
    for (unsigned int i = 0; i < size; i++) {
        keys[i] = initialValue;
    }
}

template <class Key, class Value>
std::string Quadratic<Key, Value>::toString() const {
    std::stringstream aux;

    for (unsigned int i = 0; i < size; i++) {
        if (keys[i] != initialValue) {
            aux << "(" << i << " " << keys[i] << " : " << values[i] << ") ";
        }
    }
    return aux.str();
}

#endif /* QUADRATIC_H_ */
