//
//  main.cpp
//  Lab1
//
//  Created by Gary Hicks on 2018-03-06.
//  Copyright © 2018 Gary Hicks. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

#include "Lab1Tests.hpp"

string get_status_str(bool status)
{
    return status ? "Pass" : "Fail";
}

int main()
{
    SequentialListTest seq_test;
    DoublyLinkedListTest linked_test;
    
    bool seq_test1_passed = seq_test.test1();
    bool seq_test2_passed = seq_test.test2();
    bool seq_test3_passed = seq_test.test3();
    
    bool linked_test1_passed = linked_test.test1();
    bool linked_test2_passed = linked_test.test2();
    bool linked_test3_passed = linked_test.test3();
    
    cout << "---Sequential List Tests---" << endl;
    cout << "Test1: " << get_status_str(seq_test1_passed) << endl;
    cout << "Test2: " << get_status_str(seq_test2_passed) << endl;
    cout << "Test3: " << get_status_str(seq_test3_passed) << endl;
    cout << endl;
    cout << "---Linked List Tests---" << endl;
    cout << "Test1: " << get_status_str(linked_test1_passed) << endl;
    cout << "Test2: " << get_status_str(linked_test2_passed) << endl;
    cout << "Test3: " << get_status_str(linked_test3_passed) << endl;
    
    system("pause");
}

