//
//  KrStack.cpp
//  
//
//  Created by Amaresh Kumar on 21/09/16.
//
//

#include "KrStack.h"

KrStack::KrStack ():top(-1) {
    
}

void KrStack::push (int item){
    arr[++top] = item;
}

int KrStack::pop (){
    if (top == -1) {
        cout << "No item in the stack!" << endl;
    }
    return arr[top--];
}

int KrStack::peek () {
    if (top == -1) {
        cout << "No element to display!" << endl;
    }
    return arr[top];
}

KrStack::~KrStack () {
}
