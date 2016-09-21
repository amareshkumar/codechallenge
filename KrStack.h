//
//  KrStack.h
//  CodeChallenge
//
//  Created by Amaresh Kumar on 21/09/16.
//  Copyright (c) 2016 Amaresh Kumar. All rights reserved.
//

#ifndef CodeChallenge_KrStack_h
#define CodeChallenge_KrStack_h

#include "KrCommon.h"

//Stack implementation using array
static int const SIZE = 100;

class KrStack{
private:
    int top;
    int arr[SIZE];
public:
    KrStack ();
    void push (int item);
    int pop ();
    
    int peek ();
    ~KrStack ();
};

#endif
