//
//  main.cpp
//  Lab0
//
//  Created by Gary Hicks on 2018-03-06.
//  Copyright © 2018 Gary Hicks. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h> // for using exit(EXIT_SUCCESS)instead of return 0
#include <iostream>

using namespace std;
#define N_TERMS 150// number of term in the geometric sequence. //32 for type int //16 for short //64 for long

int main () {
    long int seq_term, seq_sum;
    seq_term = seq_sum = 1;
    cout << "Term no. " << 1 << " = " << seq_term;
    cout << " and accumulated sum = " << seq_sum << "." << endl;
    for (int i = 1; i < N_TERMS; i++)
    {
        seq_term *= 2;  // double itself
        seq_sum += seq_term;  // add to tracking sum
        cout << "Term no." << i+1 << " = " << seq_term ;
        cout << " and accumulated sum = "<< seq_sum << ".\n";
    }
    system("pause");  // pause so we can view output
}

