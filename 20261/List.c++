#include <iostream>
using namespace std;

template <typename T>
struct Node {

    T data;
    Node* next;

    Node(T value) {
        data = value;
        next = nullptr;
    }
};

int main() {

    List<int> lista;

    lista.push_back(10);
    lista.push_back(20);
    lista.push_back(30);
    lista.push_back(40);

    cout << "Lista inicial" << endl;
    lista.print();

    lista.push_front(5);

    cout << "Agregar al inicio" << endl;
    lista.print();

    lista.insert(2, 15);

    cout << "Insertar en posicion 2" << endl;
    lista.print();

    lista.erase(3);

    cout << "Eliminar posicion 3" << endl;
    lista.print();

    cout << "Buscar 20: " << lista.find(20) << endl;

    lista.replace(20, 100);

    cout << "Reemplazar 20 por 100" << endl;
    lista.print();

    lista.reverse();

    cout << "Lista invertida" << endl;
    lista.print();
}


template <typename T>
class List {

private:

    Node<T>* head;
    int sz;

public:

    List() {
        head = nullptr;
        sz = 0;
    }

    void push_back(T value) {

    Node<T>* newNode = new Node<T>(value);

    if (head == nullptr) {
        head = newNode;
    }
    else {

        Node<T>* temp = head;

        while (temp->next != nullptr)
            temp = temp->next;

        temp->next = newNode;
    }

    sz++;
}
void push_front(T value) {

    Node<T>* newNode = new Node<T>(value);

    newNode->next = head;
    head = newNode;

    sz++;
}

void pop_front() {

    if (head == nullptr)
        return;

    Node<T>* temp = head;

    head = head->next;

    delete temp;

    sz--;
}

void pop_back() {

    if (head == nullptr)
        return;

    if (head->next == nullptr) {

        delete head;
        head = nullptr;
    }
    else {

        Node<T>* temp = head;

        while (temp->next->next != nullptr)
            temp = temp->next;

        delete temp->next;
        temp->next = nullptr;
    }

    sz--;
}

void insert(int pos, T value) {

    if (pos == 0) {
        push_front(value);
        return;
    }

    Node<T>* newNode = new Node<T>(value);

    Node<T>* temp = head;

    for (int i = 0; i < pos - 1; i++)
        temp = temp->next;

    newNode->next = temp->next;
    temp->next = newNode;

    sz++;
}
void erase(int pos) {

    if (pos == 0) {
        pop_front();
        return;
    }

    Node<T>* temp = head;

    for (int i = 0; i < pos - 1; i++)
        temp = temp->next;

    Node<T>* del = temp->next;

    temp->next = del->next;

    delete del;

    sz--;
}
int find(T value) {

    Node<T>* temp = head;
    int index = 0;

    while (temp != nullptr) {

        if (temp->data == value)
            return index;

        temp = temp->next;
        index++;
    }

    return -1;
}
bool contains(T value) {

    return find(value) != -1;
}

void remove(T value) {

    int pos = find(value);

    if (pos != -1)
        erase(pos);
}

void replace(T oldVal, T newVal) {

    Node<T>* temp = head;

    while (temp != nullptr) {

        if (temp->data == oldVal) {

            temp->data = newVal;
            return;
        }

        temp = temp->next;
    }
}

void reverse() {

    Node<T>* prev = nullptr;
    Node<T>* current = head;
    Node<T>* next = nullptr;

    while (current != nullptr) {

        next = current->next;

        current->next = prev;

        prev = current;

        current = next;
    }

    head = prev;
}
int count(T value) {

    Node<T>* temp = head;
    int c = 0;

    while (temp != nullptr) {

        if (temp->data == value)
            c++;

        temp = temp->next;
    }

    return c;
}

void clear() {

    while (head != nullptr)
        pop_front();
}
void print() {

    Node<T>* temp = head;

    while (temp != nullptr) {

        cout << temp->data << " -> ";
        temp = temp->next;
    }

    cout << "NULL" << endl;
}
};