#include<cstring>
#include<iostream>
#include "CircularQueue.hpp"

using namespace std;

typedef CircularQueue::QueueItem QueueItem;
const QueueItem CircularQueue::EMPTY_QUEUE = -999;

CircularQueue::CircularQueue(){
    capacity_=16;
    items_ = new QueueItem[capacity_];
    head_=0;
    tail_=0;
    size_=0;
}

CircularQueue::CircularQueue(unsigned int capacity){
    capacity_=capacity;
    items_ = new QueueItem[capacity_];
    head_=0;
    tail_=0;
    size_=0;
}

CircularQueue::~CircularQueue(){
}

bool CircularQueue::empty() const{
    if (size_==0){
        return true;
    }
    else{
        return false;
    }
}

bool CircularQueue::full() const{
    if (size_==capacity_){
        return true;
    }
    else{
        return false;
    }
}

int CircularQueue::size() const{
    return size_;
}

bool CircularQueue::enqueue(QueueItem value){
    if (full()){
        return false;
    }
    else{
        items_[tail_]=value;
        tail_=(tail_+1)%(capacity_);
        size_++;
        return true;
    }
}

QueueItem CircularQueue::dequeue(){
    if (empty()) {
        return EMPTY_QUEUE;
    }
    else{
        int temp = items_[head_];
        head_=(head_+1)%(capacity_);
        size_--;
        return temp;
    }
}

QueueItem CircularQueue::peek() const{
    if (empty()) {
        return EMPTY_QUEUE;
    }
    else{
        return items_[head_];
    }
}

void CircularQueue::print() const{
    int front = head_;
    int rear = tail_;
    while(front!=rear){
        cout<<items_[front]<<endl;
        front=(front+1)%(capacity_);
    }
}
