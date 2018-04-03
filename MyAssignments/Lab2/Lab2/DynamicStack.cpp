#include "DynamicStack.hpp"
#include <iostream>

using namespace std;

typedef DynamicStack::StackItem StackItem;  // for simplicity
const StackItem DynamicStack::EMPTY_STACK = -999;

DynamicStack::DynamicStack(){
    capacity_=16;
    size_=0;
    init_capacity_=16;
    items_ = new StackItem[capacity_];
}

DynamicStack::DynamicStack(unsigned int capacity){
    capacity_=capacity;
    size_=0;
    init_capacity_=capacity;
    items_ = new StackItem[capacity];
}

DynamicStack::~DynamicStack(){
    delete [] items_;
    items_ = NULL;
}

bool DynamicStack::empty() const{
    if (size_==0){
        return true;
    }
    else{
        return false;
    }
}

int DynamicStack::size() const{
    return size_;
}

void DynamicStack::push(StackItem value){
    if (size_==capacity_){
        capacity_=capacity_*2;
        items_[size_]=value;
        size_++;
    }
    else{
        items_[size_]=value;
        size_++;
    }
}

StackItem DynamicStack::pop(){
    if (empty()){
        return EMPTY_STACK;
    }
    else{
        int temp = items_[size_-1];
        items_[size_-1] = NULL;
        size_--;
        if (size_ <= 0.25*capacity_ && capacity_*0.5>=init_capacity_){
            capacity_=capacity_/2;
        }
        return temp;
    }
}

StackItem DynamicStack::peek() const{
    if (empty()){
        return EMPTY_STACK;
    }
    else{
        return items_[size_-1];
    }
}

void DynamicStack::print() const{
    for (int i=0;i<size_;i++){
        cout<<items_[i]<<endl;
    }
}
