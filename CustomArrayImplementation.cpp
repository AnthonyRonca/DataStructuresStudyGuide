//
//  main.cpp
//  DSPractice
//
//  Created by Anthony Ronca on 8/15/19.
//  Copyright © 2019 AnthonyRonca. All rights reserved.
//

#include <iostream>

using namespace std;

class IntArray { // Custom Array Class
    private:
        int* m_ptr{nullptr}; // Index pointer
        int m_size{0};       // Size of array
    
    public:
    IntArray() = default;    // Default constructor (no-arg)
    
    explicit IntArray(int size){        // Explicit keyword prevents conversion of parameter size to Int array
        if (size != 0) {
            m_ptr = new int[size]{};    // Creates Array of provided size
            m_size = size;
        }
    }
    
    // Overloading [] operator to access elements in array style
    int& operator[](int index) {
        return m_ptr[index];
    }
    
    int operator[](int index) const {
        return m_ptr[index];
    } // overloads operator to allow read-only access
    
    int Size() const { // return size of array
        return m_size;
    }
    
    ~IntArray() { // deconstructor that allows memory to be deleted when done
        delete[] m_ptr;
    }
    
};

ostream& operator<<(ostream& os, const IntArray& a) { // Overloads << operator allowing arrays to be output with cout
    
    os << "[ ";
    for(int i = 0; i < a.Size(); i++) {
        os << a[i] << ' ';
    }
    os << ']';
    
    return os; // Since a generic ostream is used, any form of output including files can use this constructor
}

int main(int argc, const char * argv[]) {
    
    IntArray a{10}; // declare array of size 10
    for (int i = 0; i < a.Size(); i++) {
        a[i] = (i + 1) * 10; // populate array with integers
    }
    
    cout << " Array elements: " << a << "\n";
    // Terminal output:  "Array elements: [ 10 20 30 40 50 60 70 80 90 100 ]"
    
    return 0;
}


