//
// Created by cbalb on 28/02/2026.
//

#ifndef QUEUE_PTR_V01_QUEUE_H
#define QUEUE_PTR_V01_QUEUE_H
#include <memory>
using namespace std;

class Queue {
private:
    struct Node {
        int value;
        shared_ptr<Node> ptr_Next;

        Node(int v);                            //Constructor
        Node(int v, shared_ptr<Node> node);     //Constructor con parametros
    };

    shared_ptr<Node> ptr_Rear;
    shared_ptr<Node> ptr_Front;
    int sizeQueue=0;
    void printPriv(shared_ptr<Node> node);
public:
    bool empty() const;
    void push(int v);
    int pop();
    int size();
    int front();
    int back();

    void print();
};


#endif //QUEUE_PTR_V01_QUEUE_H