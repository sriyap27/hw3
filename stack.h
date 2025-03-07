#ifndef STACK_H
#define STACK_H

#include <vector>
#include <stdexcept>

// Use inheritance from std::vector (choose public/private) as appropriate
template <typename T>
class Stack : private std::vector<T>
{
public:
    Stack() {}
    ~Stack() {}
    bool empty() const {
        if (this->size() == 0) {
            return true;
        }
        return false;
    }
    size_t size() const {
        return std::vector<T>::size();
    }
    void push(const T& item) {
        this->push_back(item);
    }
    void pop() {
        if (empty()) {
            throw std::underflow_error("Empty Stack");
        }
        else {
            this->pop_back();
        }
    }  // throws std::underflow_error if empty
    const T& top() const {
        if (empty()) {
            throw std::underflow_error("Empty Stack");
        }
        else {
            return this->back();
        }
    } // throws std::underflow_error if empty
    // Add other members only if necessary
};


#endif