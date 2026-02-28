//
// Created by cbalb on 28/02/2026.
//

#include "Queue.h"
#include <memory>
#include <iostream>
using namespace std;

Queue::Node::Node(int v) {
    this->value=v;
    this->ptr_Next=nullptr;
}

Queue::Node::Node(int v, shared_ptr<Node> node) {
    this->value=v;
    this->ptr_Next=node;
}

bool Queue::empty() const{
    if (ptr_Front==nullptr) {
        cout << "Queue vacia"<<endl;
        return true;
    }
    else {
        cout << "Queue No vacia"<<endl;
        return false;
    }
}

void Queue::push(int v) {
    shared_ptr<Node> newNode = make_shared<Node>(v);
    if (ptr_Front==nullptr) {
        ptr_Front = ptr_Rear = newNode;
    }
    else {
        ptr_Rear->ptr_Next = newNode;       //Añadimos nuevo ultimo nodo
        ptr_Rear = newNode;                 //Actualizamos ptr_Rear -> nullptr
    }
    sizeQueue++;
}

int Queue::front() {
    return ptr_Front->value;
}

int Queue::back() {
    return ptr_Rear->value;
}

int Queue::pop() {
    if (empty()) {
        return -1;
    }
    const int i = ptr_Front->value;
    //Actualizamos el valor del ptr_Front a el siguiente valor (ptr_Next)
    ptr_Front = ptr_Front->ptr_Next;
    if (ptr_Front == nullptr) {
        //Si no quedan valores igualamos ambos ptr a nullptr
        ptr_Rear=nullptr;
    }
    sizeQueue--;
    return i;
}



int Queue::size() {
    return sizeQueue;
}

/*  ============================================
    Funciones para mostrar por pantalla la Queue
    usando la recursividad
    ============================================   */

void Queue::printPriv(shared_ptr<Node> node){
    if (node==nullptr) {
        return;
    }
    cout << node->value << " ";    //Imprimimos a la vuelta
    printPriv(node->ptr_Next);     //Nos metemos hasta el final
}

void Queue::print(){
    cout << "Lista en orden Front->Back: ";
    printPriv(ptr_Front);
    cout << endl;
}