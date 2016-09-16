#include <iostream>

using namespace std; 

void merge(int arr1[], int l, int mid, int r) {
	//create two temporery empty arrays with following sizes
	int n1 = mid - l + 1;
	int n2 = r - mid; 

	int *L = new int [n1] ;
	int *R = new int [n2];

	int len = r - l + 1; 
	int *arr = new int[len]; 

	//fill array L
	for (int i = 0; i < n1; i++) {
		*(L + i) = arr[l + i];
	}

	//fill array R
	for (int j = 0; j < n2; j++) {
		*(R+ j) = arr[mid+j+1];
	}
	
	int i = 0; 
	int j = 0;
	int k = l; 
	//Merge them now in sorted order. 
	while ((i <= n1) && (j <= n2)){
		if (*(L + i) <= *(R + j)) {
			*(arr + k) = *(L + i);
			i++;
		}
		else {
			*(arr + k) = *(R + j);
			j++;
		}
		k++;
	}

	//merge items left in L
	while (i < n1) {
		*(arr + k) = *(L + i);
		i++; 
		k++;
	}
	//merge items left in L
	while (j < n2) {
		*(arr + k) = *(R + j);
		j++; 
		k++; 
	}
}

void merge_sort(int arr[], int l, int r) {

	while (l < r) {
		int mid = l + (r - l) / 2;
		
		merge_sort(arr, l, mid); 
		merge_sort(arr, mid + 1, r);

		//once sorted merge them 
		merge(arr, l, mid, r);
	}
} 

void print_arr(int arr[], int len) {
	for (int i = 0; i < len; i++) {
		cout << arr[i] << " "; 
	}
	cout << endl; 
} 

int main() {
	int int_arr[] = {5, 2, 3, 10, 15, 20, 30, 11};
	int len = sizeof(int_arr)/sizeof(int_arr[0]);
	cout << "before merge sort, array: " << endl; 
	print_arr(int_arr, len);
	
	merge_sort(int_arr, 0, len - 1);
	
	cout << "after merge sort, array: " << endl;
	print_arr(int_arr, len);
	
	return 0;
}