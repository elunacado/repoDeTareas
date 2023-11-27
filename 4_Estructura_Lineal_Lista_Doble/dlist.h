#ifndef DLIST_H
#define DLIST_H

#include <iostream>
#include <sstream>

template <typename T>
class DList {
private:
    struct Item {
        T data;
        Item* next;
        Item* prev;

        Item(const T& value) : data(value), next(nullptr), prev(nullptr) {}
    };

    Item* head;
    Item* tail;

public:
    DList() : head(nullptr), tail(nullptr) {}

    // Function to insert an element at the end of the list
    void insertion(const T& value) {
         Item* newItem = new Item(value);
        if (!head) {
            head = newItem;
            tail = newItem;
        } else {
            newItem->prev = tail;
            tail->next = newItem;
            tail = newItem;
        };
    };

    // Function to search for an element in the list
    T search(const T& value) const {
        Item* current = head;
        int pos = 0;

        while(current){
            if (current->data == value){
                return pos;
            }
            current = current->next;
            pos++;
        }
        return -1;
    }

    // Function to update an element at a specific index
    void update(int index, const T& value) {
        int pos = 0;
        Item* current = head;
        while(current){
            if (pos == index){
                current->data = value;
                break;
            }
            current = current->next;
            pos++;
        }
    }

    // Function to delete an element at a specific index
    void deleteAt(int index) {
        if(index == 0){
            Item* objective = head;
            head = head->next;
            if (head){
                head->prev =nullptr;
            }else{
                tail = nullptr;
            }
            delete objective;
            return;
        };
        int pos = 0;
        Item* current = head;
        while (current){
            if (pos == index){
                if (current->next){
                    current->next->prev = current->prev;
                }
                if (current->prev){
                    current->prev->next = current->next;
                }
                if (current==tail){
                    tail = current->prev;
                }
                delete current;
                break;
            }
            current = current->next;
            pos++;
        }
    }

    // Destructor to clean up memory
    ~DList() {
        Item* current = head;
        while (current) {
            Item* next = current->next;
            delete current;
            current = next;
        }
    }

    // Function to convert the list to a forward string representation
    std::string toStringForward() const {
        std::stringstream ss;
        ss << "[";
        Item* current = head;
        while (current) {
            ss << current->data;
            if (current->next) {
                ss << ", ";
            }
            current = current->next;
        }
        ss << "]";
        return ss.str();
    }

    // Function to convert the list to a backward string representation
    std::string toStringBackward() const {
        std::stringstream ss;
        ss << "[";
        Item* current = tail;
        while (current) {
            ss << current->data;
            if (current->prev) {
                ss << ", ";
            }
            current = current->prev;
        }
        ss << "]";
        return ss.str();
    }
};

#endif
