#include <bits/stdc++.h>

using namespace std;

class Node{
    public:
        int val;
        Node *next;
};

class Queue{
    public:
        int capacity, size;
        Node *front, *back;
};

Queue* createQueue(int capacity){
    Queue *queue=(Queue *)malloc(sizeof(Queue));
    queue->capacity = capacity;
    queue->size = 0;
    queue->front = NULL;
    queue->back = NULL;
    return queue;
}

int isEmpty(Queue *queue){
    return queue->size == 0;
}

int enqueue(Queue *queue, int val){
    Node *node = (Node *)malloc(sizeof(Node));
    node->val=val;
    node->next=NULL;
    if(isEmpty(queue)){
        queue->front = node;
    }
    else{
        queue->back->next=node;
    }
    queue->back=node;
    (queue->size)++;
    return 1;
}

int dequeue(Queue *queue){
    if(isEmpty(queue)) return -1;
    Node *t=queue->front;
    int val = t->val;
    queue->front=t->next;
    (queue->size)--;
    if(isEmpty(queue)){
        queue->back = NULL;
    }
    free(t);
    return val;
}

int main(){
    Queue *queue=createQueue(10);
    enqueue(queue, 1);
    enqueue(queue, 4);
    enqueue(queue, 8);
    enqueue(queue, 2);
    cout << dequeue(queue) << "\n";
    cout << dequeue(queue) << "\n";
    cout << dequeue(queue) << "\n";
    cout << dequeue(queue) << "\n";
    cout << dequeue(queue) << "\n";
    return 0;
}