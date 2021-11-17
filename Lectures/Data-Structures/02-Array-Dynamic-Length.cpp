#include <bits/stdc++.h>
using namespace std;

// Initialize an array with dynamic length
int n;
int capacity;
int* arr;

// This function updates the capacity of the array
void reserve(int new_capacity) {
    // Initialize a new array with the new capacity
    int* temp = new int[new_capacity];
    // copy the elements in the current array to the new array
    for (int i = 0; i < n; i++)
        temp[i] = arr[i];
    // delete the old array
    delete[] arr;
    // set the temp array with new capacity to be the array
    arr = temp;
    // set the current capacity of the array to be the new capacity
    capacity = new_capacity;
}

// This function inserts an element at the given index in the array
void insert_element(int item, int idx) {
    // check for invalid index
    if (idx < 0 || idx > n)
        return;
    // check if we need to update the capacity of the array
    if (n == capacity)
        reserve(2 * capacity + 1);
    // loop to shif values till reach the given index
    int j = n - 1;
    while (j >= idx) {
        arr[j+1] = arr[j];
        j = j - 1;
    }
    // insert the new element
    arr[idx] = item;
    // update the size of the array
    n = n + 1;
}

// This function deletes an element at index idx in the array
void delete_element(int idx) {
    // check for invalid index
    if (idx < 0 || idx >= n)
        return;
    // loop to shif values till reach end of the array
    int j = idx;
    while (j < n - 1) {
        arr[j] = arr[j+1];
        j = j + 1;
    }
    // update the size of the array
    n = n - 1;
    // check if we need to update the capacity of the array
    if (n < capacity / 2)
        reserve(capacity / 2);
}

// This function searches for an element in the array
bool search_element(int item) {
    int j = 0;
    // loop to find the given element in the array
    while (j < n) {
        if (arr[j] == item)
            // return that the element in the array 
            return true;
        j = j + 1;
    }
    // return that the element not in the array 
    return false;
}

// This function prints the contents of the array
void print_array() {
    int i = 0;
    // loop to print the elements in the array
    while (i < n) {
        cout << arr[i] << ' ';
        i = i + 1;
    }
}

int main() {

    // Functionality Testing
    
    cout << "Array capacity: " << capacity << '\n';
    cout << "Array size: " << n << '\n';
    cout << "Array items: ";
    print_array();
    cout << '\n';
    cout << "----------------------------------------------------\n";

    /* Expected Output:
    Array capacity: 0
    Array size: 0
    Array items: 
    ----------------------------------------------------
    */

    cout << "adding the following elements 10 20 30 40 50\n";
    insert_element(10, n);
    insert_element(20, n);
    insert_element(30, n);
    insert_element(40, n);
    insert_element(50, n);
    cout << "the above elements have been added to the array\n";

    /* Expected Output:
    adding the following elements 10 20 30 40 50
    the above elements have been added to the array
    */

    cout << "Array capacity: " << capacity << '\n';
    cout << "Array size: " << n << '\n';
    cout << "Array items: ";
    print_array();
    cout << '\n';
    cout << "----------------------------------------------------\n";

    /* Expected Output:
    Array capacity: 7
    Array size: 5
    Array items: 10 20 30 40 50 
    ----------------------------------------------------
    */

    cout << "add element 60 at position " << n << " : \n";
    insert_element(60, n);
    cout << "Array capacity: " << capacity << '\n';
    cout << "Array size: " << n << '\n';
    cout << "Array items: ";
    print_array();
    cout << '\n';
    cout << "----------------------------------------------------\n";

    /* Expected Output:
    add element 60 at position 5 : 
    Array capacity: 7
    Array size: 6
    Array items: 10 20 30 40 50 60 
    ----------------------------------------------------
    */

    cout << "add element 20 at position 0 : \n";
    insert_element(20, 0);
    cout << "Array capacity: " << capacity << '\n';
    cout << "Array size: " << n << '\n';
    cout << "Array items: ";
    print_array();
    cout << '\n';
    cout << "----------------------------------------------------\n";

    /* Expected Output:
    add element 20 at position 0 : 
    Array capacity: 7
    Array size: 7
    Array items: 20 10 20 30 40 50 60 
    ----------------------------------------------------
    */

    cout << "add element 70 at position 4 : \n";
    insert_element(70, 4);
    cout << "Array capacity: " << capacity << '\n';
    cout << "Array size: " << n << '\n';
    cout << "Array items: ";
    print_array();
    cout << '\n';
    cout << "----------------------------------------------------\n";

    /* Expected Output:
    add element 70 at position 4 : 
    Array capacity: 15
    Array size: 8
    Array items: 20 10 20 30 70 40 50 60 
    ----------------------------------------------------
    */

    cout << "add element 90 at position " << n-1 << " : \n";
    insert_element(90, n-1);
    cout << "Array capacity: " << capacity << '\n';
    cout << "Array size: " << n << '\n';
    cout << "Array items: ";
    print_array();
    cout << '\n';
    cout << "----------------------------------------------------\n";

    /* Expected Output:
    add element 90 at position 7 : 
    Array capacity: 15
    Array size: 9
    Array items: 20 10 20 30 70 40 50 90 60 
    ----------------------------------------------------
    */

    cout << "delete element at position 0 : \n";
    delete_element(0);
    cout << "Array capacity: " << capacity << '\n';
    cout << "Array size: " << n << '\n';
    cout << "Array items: ";
    print_array();
    cout << '\n';
    cout << "----------------------------------------------------\n";

    /* Expected Output:
    delete element at position 0 : 
    Array capacity: 15
    Array size: 8
    Array items: 10 20 30 70 40 50 90 60 
    ----------------------------------------------------
    */

    cout << "delete element at position " << n-1 << " : \n";
    delete_element(n-1);
    cout << "Array capacity: " << capacity << '\n';
    cout << "Array size: " << n << '\n';
    cout << "Array items: ";
    print_array();
    cout << '\n';
    cout << "----------------------------------------------------\n";

    /* Expected Output:
    delete element at position 7 : 
    Array capacity: 15
    Array size: 7
    Array items: 10 20 30 70 40 50 90 
    ----------------------------------------------------
    */

    cout << "delete element at position 3 : \n";
    delete_element(3);
    cout << "Array capacity: " << capacity << '\n';
    cout << "Array size: " << n << '\n';
    cout << "Array items: ";
    print_array();
    cout << '\n';
    cout << "----------------------------------------------------\n";

    /* Expected Output:
    delete element at position 3 : 
    Array capacity: 7
    Array size: 6
    Array items: 10 20 30 40 50 90 
    ----------------------------------------------------
    */

    if (search_element(40))
        cout << "element " << 40 << " in the array\n";
    else
        cout << "element " << 40 << " not in the array\n";

    if (search_element(100))
        cout << "element " << 100 << " in the array\n";
    else
        cout << "element " << 100 << " not in the array\n";
    cout << "----------------------------------------------------\n";

    /* Expected Output:
    element 40 in the array
    element 100 not in the array
    ----------------------------------------------------
    */

}

