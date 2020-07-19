#include <iostream>
#include <array>
#include <string>

using namespace std;

template<class T> class DynamicArray {
    int len = 0;
    const int capacity = 16;
    array<T, capacity> arr;
    int *ptr_to_capacity = (int*)(&a);
public:
    DynamicArray();
    int size();
    bool isEmpty();
    T get(int index);
    void set(int index, T elem);
    void clear();
    void add(T elem);
    T remove(int rm_index);
    string toString();
};

template<class T> DynamicArray<T>::DynamicArray() {

}

template<class T> int DynamicArray<T>::size() {
    return len;
}

template<class T> bool DynamicArray<T>::isEmpty() {
    return len == 0;
}

template<class T> T DynamicArray<T>::get(int index) {
    return arr.at(index);
}

template<class T> void DynamicArray<T>::set(int index, T elem) {
    arr.at(index) = elem;
}

template<class T> void DynamicArray<T>::clear() {
    for (auto element : arr) {
        element = null;
    }
    len = 0;
}

template<class T> void DynamicArray<T>::add(T elem) {
    if (len + 1 >= capacity) {
        if (capacity == 0) *ptr_to_capacity = 1;
        else *ptr_to_capacity *= 2;
        array<T, capacity> new_arr;
        for (int i=0; i < len; i++) new_arr.at(i) = arr.at(i);
        arr = new_arr;
    }
    arr.at(len++) = elem;
}

template<class T> T DynamicArray<T>::removeAt(int rm_index) {
    T data = arr.at(rm_index);
    for (int i=rm_index; i < len-1; i++) {
        arr.at(i) = arr.at(i+1);
    }
    return data;
}

template<class T> string DynamicArray<T>::toString() {
    if (isEmpty()) return "[]";
    else {
        string str = "[";
        for (auto element : arr) str.append(to_string(element) + ", ");
        str.append("]");
    }
}

int main() {

}
