#include "DoublyLinkedList.hpp"
#include <iostream>

using namespace std;

DoublyLinkedList::Node::Node(DataType data){
    value = data;
}

DoublyLinkedList::DoublyLinkedList(){
    head_ = NULL;
    tail_ = NULL;
    size_ = 0;
}

DoublyLinkedList::~DoublyLinkedList(){
}

bool DoublyLinkedList::empty() const{
    if (size_==0) {
        return true;
    }
    else{
        return false;
    }
}

unsigned int DoublyLinkedList::size() const{
    return size_;
}

void DoublyLinkedList::print() const{
    if (empty()){
        return;
    }
    cout<<"(";
    Node* node = head_;
    while (node != NULL){
        cout<<"["<<node->value<<"]";
        node = node-> next;
        if (node != NULL) {
            cout<<"->";
            
        }
    }
    cout<<")\n";
}

bool DoublyLinkedList::insert_front(DataType value){
    return insert(value, 0);
}

bool DoublyLinkedList::remove_front(){
    return remove(0);
}

bool DoublyLinkedList::insert_back(DataType value){
    return insert(value, size_);
}

bool DoublyLinkedList::remove_back(){
    //cout<<size_<<endl;
    return remove(size_-1);
}

bool DoublyLinkedList::insert(DataType value, unsigned int index){
    if (full()){
        return false;
    }
    else{
        if (head_==NULL){
            Node* newNode = new Node(value);
            newNode -> next = NULL;
            newNode -> prev = NULL;
            newNode -> value = value;
            head_ = newNode;
            tail_ = newNode;
            size_++;
            print();
            
            return true;
        }
        else if (tail_ == head_){
            Node* newNode = new Node(value);
            newNode -> next = NULL;
            newNode -> prev = head_;
            (newNode -> prev) -> next = newNode;
            newNode -> value = value;
            tail_ = newNode;
            size_++;
            print();
            
            return true;
        }
        else{
            
            Node* current = head_;
            int count = 0;
            cout<<index<<endl;
            
            while (count<=size_ && index<=size_){
                if (count == index-1){
                    if (index==size_){
                        Node* newNode = new Node(value);
                        newNode->value = value;
                        cout<<count<<endl;
                        newNode-> prev = current;
                        (newNode -> prev) -> next = newNode;
                        newNode -> next = NULL;
                        tail_=newNode;
                        size_++;
                        print();
                        return true;
                    }
                    Node* newNode = new Node(value);
                    newNode->value = value;
                    current->next = newNode;
                    newNode-> prev = current;
                    //(current -> prev) -> next = newNode->prev;
                    newNode -> next = current->next->next;
                    (current -> next -> next) -> prev = newNode;
                    size_++;
                    print();
                    return true;
                }
                if (index == 0){
                    Node* newNode = new Node(value);
                    newNode->value = value;
                    newNode -> prev = NULL;
                    newNode->next = current;
                    current->prev = newNode;
                    head_=newNode;
                    size_++;
                    return true;
                }
                cout<<"hi"<<endl;
                count++;
                current = current -> next;
            }
            return false;
        }
    }
}

bool DoublyLinkedList::remove(unsigned int index){
    if (empty()){
        return false;
    }
    else{
        if (head_!= NULL && head_->next != NULL){ //at least 2 items
            
            Node* current = head_;
            int counter = 0;
            
            while (index<size_){
                if (index == 0 ){
                    (current->next)->prev = current->prev;
                    head_= current->next;
                    delete current;
                    size_--;
                    //cout<<(size_)<<endl;
                    //print();
                    return true;
                }
                else if (index == size_-1) {
                    (current->prev)->next = current -> next;
                    tail_= current->prev;
                    delete current;
                    size_--;
                    return true;
                }
                else if (index == counter){
                    (current->next)->prev = current->prev;
                    (current->prev)->next = current->next;
                    delete current;
                    size_--;
                    return true;
                }
                current = current -> next;
                counter++;
            }
            return false;
        }
        else{
            //cout<<head_<<"    "<<tail_<<endl;
            delete head_;
            head_=NULL;
            tail_=NULL;
            size_--;
            return true;
        }
    }
}

unsigned int DoublyLinkedList::search(DataType value) const{
    if (empty()){
        return size_;
    }
    else{
        Node* current = head_;
        int count = 0;
        
        while (current != NULL){
            if (current->value == value){
                cout<<(current->value)<<endl;
                return count;
            }
            current = current -> next;
            count++;
        }
        return size_;
    }
}

DoublyLinkedList::DataType DoublyLinkedList::select(unsigned int index) const{
    if (empty()) {
        return size_;
    }
    else{
        Node* current = head_;
        int count = 0;
        
        while (current != NULL){
            if (count == index){

                return current->value;
            }
            count++;
            current = current -> next;
        }
        return size_;
    }
}

bool DoublyLinkedList::replace(unsigned int index, DataType value){
    if (empty()) {
        return false;
    }
    else{
        Node* current = head_;
        int count = 0;
        
        while (current->next != NULL){
            if (count == index){
                current->value = value;
                return true;
            }
            count++;
            current = current -> next;
        }
        return false;
    }
}

//DoublyLinkedList::Node* DoublyLinkedList::getNode(unsigned int index) const{
//}

bool DoublyLinkedList::full() const{
    if (size_ == CAPACITY) {
        return true;
    }
    else{
        return false;
    }
}
