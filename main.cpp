#include <iostream>

#include "Queue.h"

int main() {
    std::cout << "Hello, World!" << std::endl;


    Queue cola;
    cola.empty();
    for (int i=0; i<10; i++) {
        cola.push(i);
    }
    cola.empty();
    cout << "cola.front= " << cola.front()<<endl;
    cout << "cola.back= "<<cola.back()<<endl;
    cola.print();

    cola.pop();
    cola.print();
    cout << "La cola (Queue) tiene size: "<< cola.size()<<endl;
    return 0;
}
