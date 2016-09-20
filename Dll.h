//
//  Dll.h
//  CodeChallenge
//
//  Created by Amaresh Kumar on 20/09/16.
//  Copyright (c) 2016 Amaresh Kumar. All rights reserved.
//

#ifndef CodeChallenge_Dll_h
#define CodeChallenge_Dll_h

struct Dll_node{
    
    Dll_node *next;
    Dll_node *prev;
    int content;
    
    Dll_node (int item = 0) {
        content = item;
        next = nullptr;
        prev = nullptr;
    }
};

class Dll{
private:
    Dll_node* head;
public:
    Dll () {
        head->next = nullptr;
        head->prev = nullptr;
        head->content = 0;
    }
    
    Dll (int arr[]) {
        
        
        Dll_node* first = new Dll_node(arr[0]);
        head = first;
        
        Dll_node* second = new Dll_node(arr[1]);
        Dll_node* third = new Dll_node(arr[2]);
        
        
        first->next = second;
        first->prev = nullptr;
        
        second->next = third;
        second->prev = first;
        
        third->prev = second;
        third->next = nullptr;
    }
    
    void list_initialize (int arr[], int n) {
        Dll_node* list = new Dll_node[n];
        head = &list[0];
        
        for (int i = 0; i < n; i++) {
            
            list[i].content = arr[i];
            list[i].next = &list[i+1];
            list[i+1].prev = &list[i];
            
            if (i == n-1) {
                list[i].next = nullptr;
                list[i].prev = &list[i-1];
                break;
            }
        }
    }

    void add_to_last (int item) {
        Dll_node* current = head;
        
        //if existing list was empty
        if (!head) {
            head = new Dll_node(item);
            
            return;
        }
        
        while (current->next != nullptr) {
            current = current->next;
        }
        //found the last node in current list. crete a new node and add it as last
        
        Dll_node* last = new Dll_node(item);
        current->next = last;
        last->prev= current;
    }
    
    void add_as_first (int item) {
        Dll_node* first = new Dll_node (item);
        Dll_node *temp = head;
        head = first;
        first->next = temp;
    }
    
    void delete_first () {
        Dll_node* to_Delete = head;
       
        head = head->next;
        head->prev = nullptr;
        
        delete to_Delete;
    }
    
    void delete_last () {
        Dll_node* current = head;

        Dll_node* temp = nullptr;
        
        while (current->next->next != nullptr) {
            current = current->next;
        }
      
        //found the second last node in current list. make this node as last ndoe and delete the old last node using temp
        temp = current->next->next;
        current->next = nullptr;
        delete temp;
    }
    
    void delete_nth_item (int n) {
        Dll_node* current = head;
        int position = 1;
        
        Dll_node* temp = nullptr;
        
        while (current != nullptr) {
            if (position == n-1) {
                temp = current->next;
                
                current->next = temp->next;
                temp->next->prev = current;
            }
            current = current->next;
            position++;
        }
        cout << "item deleted was: " << temp->content << " at position: " << n << endl; 
        delete temp;
    }
    
    void print_dll () {
        Dll_node *current = head; 
        
        while(current != nullptr){
            cout << current->content << "  ";
            current = current->next;
        }
        cout << endl;
    }
    
    ~Dll () {
        // to do
    }
};

#endif
