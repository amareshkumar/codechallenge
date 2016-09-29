//
//  KrQueue.h
//  CodeChallenge
//
//  Created by Amaresh Kumar on 28/09/16.
//  Copyright (c) 2016 Amaresh Kumar. All rights reserved.
//

#ifndef CodeChallenge_KrQueue_h
#define CodeChallenge_KrQueue_h

#include "KrCommon.h"
#include "Dll.h"

class KrQueue {
    Dll_node* front;
    Dll_node* back;
public:
    
    KrQueue () :front (nullptr), back(nullptr) {
    }
    
    int front_item () {
        if (empty()) {
            return 0;
        }
        return front->content;
    }
    
    int back_item () {
        if (empty()) {
            return 0;
        }
        return back->content ;
    }
    
    void push_back (int item) {
        if (empty()) {
            back = front = new Dll_node(item);
            return;
        }
        
        Dll_node *newite = new Dll_node(item);
        newite->next = back; //front
        back = newite;
    }
    
    void pop_front () {
        
    }
    
    int size () {
        if (empty()) { return 0;}
        
        int size = 1;
        Dll_node *temp = back;
        while (temp != front) {
            size++;
            temp = temp->next;
        }
        return size;
    }
    
    bool empty () {
        return (front == nullptr && back == nullptr);
    }
    
    ~KrQueue () {
    }
};

#endif
