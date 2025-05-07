//Yash Gohel-24CE035
//Program No: 6.1
#include <iostream>
#include <stdexcept>
using namespace std;

class DynamicArray {
private:
    int* data;
    int size;
    int capacity;

    void resize(int newCapacity) {
        int* temp = new int[newCapacity];
        for (int i = 0; i < size; i++) {
            temp[i] = data[i];
        }
        delete[] data; 
        data = temp;
        capacity = newCapacity;
    }

public:
    DynamicArray(int initialCapacity = 10) : size(0), capacity(initialCapacity) {
        data = new int[capacity];
    }

    ~DynamicArray() {
        delete[] data;
    }

    void insert(int element) {
        if (size == capacity) {
            resize(capacity * 2); 
        }
        data[size++] = element;
    }

    void remove(int index) {
        if (index < 0 || index >= size) {
            throw out_of_range("Index out of bounds");
        }
        for (int i = index; i < size - 1; i++) {
            data[i] = data[i + 1];
        }
        size--;
        if (size < capacity / 4) {
            resize(capacity / 2);
        }
    }

    int get(int index) const {
        if (index < 0 || index >= size) {
            throw out_of_range("Index out of bounds");
        }
        return data[index];
    }

    int getSize() const {
        return size;
    }

    void print() const {
        for (int i = 0; i < size; i++) {
            cout << data[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    DynamicArray array;

    array.insert(10);
    array.insert(20);
    array.insert(30);
    cout << "Array after insertion: ";
    array.print();

    array.remove(1); 
    cout << "Array after removal: ";
    array.print();

    cout << "Element at index 0: " << array.get(0) << endl;

    return 0;
}