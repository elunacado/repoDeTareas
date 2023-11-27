#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <sstream>

template <class T>
class Link {
public:
    T value;
    Link<T>* next;
    Link(T val) : value(val), next(nullptr) {}
};

template <class T>
class List {
private:
    Link<T>* head;

public:
    List() : head(nullptr) {}   

    void insertion(T val)  {
    Link<T>* newVal = new Link<T>(val); 

    if (head == nullptr) {
        head = newVal;
    } else {
        Link<T>* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newVal;
    }
}
    int search(T objective) {
        Link<T> *current = head;
        int index = 0;
        while (current) {
            if (current->value == objective) {
                return index;
            }
            current = current->next;
            index++;
        }
        return -1; 
    }

    void update(int index, T newValue) {
        Link<T> *current = head;
        int currentIndex = 0;
        while (current) {
            if (currentIndex == index) {
                current->value = newValue;
                return;
            }
            current = current->next;
            currentIndex++;
        }
    }

     void deleteAt(int index) {
        if (index == 0) {
            Link<T> *target = head;
            head = head->next;
            delete target;
        } else {
            Link<T> *current = head;
            int currentIndex = 0;
            while (current) {
                if (currentIndex == index - 1) {
                    Link<T> *target = current->next;
                    current->next = target->next;
                    delete target;
                    return;
                }
                current = current->next;
                currentIndex++;
            }
        }
    }

    std::string toString() const {
        std::stringstream aux;
        Link<T>* p = head;
        aux << "[";
        while (p != nullptr) {
            aux << p->value;
            if (p->next != nullptr) {
                aux << ", ";
            }
            p = p->next;
        }
        aux << "]";
        return aux.str();
    }
};

#endif /* LIST_H */
