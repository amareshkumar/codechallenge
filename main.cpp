#include "KrCommon.h"
#include "KrMergeSort.h"
#include "KrQuickSort.h"
#include "Dll.h"

int main() {
//    int int_arr[] = {5, 2, 3, 10, 15, 20, 30, 11, 18, 9};
    //int int_arr[] = {3, 8, 2, 5, 1, 4, 7, 6};
//    int len = sizeof(int_arr)/sizeof(int_arr[0]);
//    
//    cout << "before sort, array: " << endl;
//    print_arr(int_arr, len);
//    
//    //merge_sort(int_arr, 0, len - 1);
//    quick_sort (int_arr, 0, len-1);
//    
//    cout << "after sort, array: " << endl;
//    print_arr(int_arr, len);
    
//    vector <int> input_vector;
//    
//    entries(input_vector);
//    print_vector(input_vector);
//
//    int arr[3] = {5, 8, 3};
//    
//    Dll *dlist = new Dll (arr);
//    
//    dlist->add_to_last(10);
//    dlist->add_as_first(7);
//    dlist->add_as_first(1);
//    dlist->add_to_last(2);
//    
//    dlist->print_dll();
//    
//    dlist->delete_last();
//    dlist->print_dll();
//    dlist->add_to_last(12);
//    dlist->print_dll();
//    dlist->delete_last();
//    dlist->print_dll();
//    
//    dlist->delete_first();
//    dlist->print_dll();
//    dlist->add_as_first(11);
//    dlist->print_dll();
//    dlist->delete_nth_item(4);
//    dlist->print_dll();

    cout << endl;
    int arr1[5] = {1, 2, 3, 4, 5};
    Dll *newlist; //Why does Dll *newlist = new Dll(); gives segmentation fault
    newlist->list_initialize(arr1, 5);
    newlist->print_dll();
    newlist->add_to_last(8);
    newlist->add_to_last(9);
    newlist->add_as_first(5);
    newlist->print_dll();
    
    //delete [] dlist;
    //delete newlist;
    
    return 0;
}