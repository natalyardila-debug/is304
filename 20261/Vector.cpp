#include <iostream>
#include <cassert>
#include <string>
using namespace std;

template<typename T>
class Vector {
private:
    T* storage;
    unsigned int capacity;
    unsigned int sz;

    void resize() {
        if (sz == capacity) {
            unsigned int newCapacity = capacity * 2;
            T* newStorage = new T[newCapacity];
            for(unsigned int i = 0; i < sz; i++)
                newStorage[i] = storage[i];

            delete [] storage;
            storage = newStorage;
            capacity = newCapacity;
        }
    }

public:
    Vector() {
        capacity = 5;
        storage = new T[capacity];
        sz = 0;
    }

    unsigned int size() const { return sz; }
    unsigned int getCapacity() const { return capacity; }

    T& operator[](unsigned int index) { return storage[index]; }

    T at(unsigned int index) const {
        assert(index < sz);
        return storage[index];
    }

    void push_back(const T& elem) {
        resize();
        storage[sz++] = elem;
    }

    void pop_back() {
        if(sz > 0) sz--;
    }

    void pop_front() {
        erase(0);
    }

    void insert(unsigned int index, const T& value) {
        assert(index <= sz);
        resize();
        for(unsigned int i = sz; i > index; i--)
            storage[i] = storage[i-1];
        storage[index] = value;
        sz++;
    }

    T front() const { return storage[0]; }
    T back() const { return storage[sz-1]; }

    // =============================
    // EXERCISE 2.1
    void erase(unsigned int pos) {
        assert(pos < sz);
        for(unsigned int i = pos; i < sz-1; i++)
            storage[i] = storage[i+1];
        sz--;
    }

    // =============================
    // EXERCISE 2.2
    void erase(unsigned int from, unsigned int to) {
        assert(from <= to && to <= sz);
        unsigned int shift = to - from;
        for(unsigned int i = from; i + shift < sz; i++)
            storage[i] = storage[i + shift];
        sz -= shift;
    }

    // =============================
    // EXERCISE 2.3
    void clear() {
        sz = 0;
    }

    // =============================
    // EXERCISE 2.5 (find primero)
    int find(const T &elem) const {
        for(unsigned int i = 0; i < sz; i++)
            if(storage[i] == elem)
                return i;
        return -1;
    }

    // =============================
    // EXERCISE 2.4 (rewrite using find)
    bool contains(const T &elem) const {
        return find(elem) != -1;
    }

    // =============================
    // EXERCISE 2.6
    void remove(const T &elem) {
        int pos = find(elem);
        if(pos != -1)
            erase(pos);
    }

    // =============================
    // EXERCISE 2.7
    void replace(const T &oldVal, const T &newVal) {
        int pos = find(oldVal);
        if(pos != -1)
            storage[pos] = newVal;
    }

    // =============================
    // EXERCISE 2.8
    void remove_all(const T &elem) {
        unsigned int w = 0;
        for(unsigned int i = 0; i < sz; i++)
            if(storage[i] != elem)
                storage[w++] = storage[i];
        sz = w;
    }

    // =============================
    // EXERCISE 2.9
    void replace_all(const T &oldVal, const T &newVal) {
        for(unsigned int i = 0; i < sz; i++)
            if(storage[i] == oldVal)
                storage[i] = newVal;
    }

    // =============================
    // EXERCISE 2.10 (rewrite later)
    int count(const T &elem) const {
        return indices_of(elem).size();
    }

    // =============================
    // EXERCISE 2.11
    Vector<int> indices_of(const T &elem) const {
        Vector<int> result;
        for(unsigned int i = 0; i < sz; i++)
            if(storage[i] == elem)
                result.push_back(i);
        return result;
    }

    // =============================
    // EXERCISE 2.12
    void swap(unsigned int i, unsigned int j) {
        assert(i < sz && j < sz);
        if(i == j) return;
        T tmp = storage[i];
        storage[i] = storage[j];
        storage[j] = tmp;
    }

    // =============================
    // EXERCISE 2.13
    void reverse() {
        for(unsigned int i = 0; i < sz/2; i++)
            swap(i, sz-1-i);
    }
};
int main() {

    Vector<int> v;

    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(20);
    v.push_back(20);

    v.remove(20);
    v.replace(30, 99);
    v.remove_all(20);
    v.push_back(40);
    v.push_back(50);

    v.swap(0, 2);
    v.reverse();

    for(unsigned int i = 0; i < v.size(); i++)
        cout << v[i] << " ";

    cout << endl;

    // Strings (Exercise 1.3)
    Vector<string> words;
    words.push_back("the");
    words.push_back("quick");
    words.push_back("brown");
    words.push_back("fox");
    words.push_back("jumps");

    for(unsigned int i = 0; i < words.size(); i++)
        cout << words[i] << " ";

    return 0;
}