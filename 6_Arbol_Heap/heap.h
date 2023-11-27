#ifndef HEAP_H
#define HEAP_H

#include <vector>
#include <string>
#include <sstream>

template <class T>
class Heap {
public:
    Heap(int capacity);
    void push(T value);
    void pop();
    T top();
    bool empty();
    int size();
    std::string toString() const;

private:
    std::vector<T> data;
};

template <class T>
Heap<T>::Heap(int capacity) {
    data.reserve(capacity);
}

template <class T>
void Heap<T>::push(T value) {
    data.push_back(value);
    int current = data.size() - 1;

    while (current > 0) {
        int parent = (current - 1) / 2;
        if (data[current] < data[parent]) {
            std::swap(data[current], data[parent]);
            current = parent;
        } else {
            break;
        }
    }
}

template <class T>
void Heap<T>::pop() {
    if (data.empty()) {
        return;
    }

    data[0] = data.back();
    data.pop_back();

    int current = 0;
    int size = data.size();

    while (current < size) {
        int child = 2 * current + 1;

        if (child >= size) {
            break;
        }

        if (child + 1 < size && data[child + 1] < data[child]) {
            child++;
        }

        if (data[current] > data[child]) {
            std::swap(data[current], data[child]);
            current = child;
        } else {
            break;
        }
    }
}

template <class T>
T Heap<T>::top() {
    if (!data.empty()) {
        return data[0];
    } else {
        // You may want to handle this case differently.
        // For example, you could throw an exception.
        return T();
    }
}

template <class T>
bool Heap<T>::empty() {
    return data.empty();
}

template <class T>
int Heap<T>::size() {
    return data.size();
}

template <class T>
std::string Heap<T>::toString() const {
    std::stringstream aux;
    aux << "[";
    for (unsigned int i = 0; i < data.size(); i++) {
        if (i != 0) {
            aux << " ";
        }
        aux << data[i];
    }
    aux << "]";
    return aux.str();
}

#endif  // HEAP_H
