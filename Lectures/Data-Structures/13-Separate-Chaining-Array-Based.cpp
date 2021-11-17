#include <bits/stdc++.h>
using namespace std;

// Initialize a hash table with static length
const int hash_table_size = 1e3+9;
// Initialize a global array pointer for heads
int n[hash_table_size];
int capacity[hash_table_size];
string* head[hash_table_size];

// This function updates the capacity of the array
void reserve(int arr_idx, int new_capacity) {
    // Initialize a new array with the new capacity
    string* temp = new string[new_capacity];
    // copy the elements in the current array to the new array
    for (int i = 0; i < n[arr_idx]; i++)
        temp[i] = head[arr_idx][i];
    // delete the old array
    delete[] head[arr_idx];
    // set the temp array with new capacity to be the array
    head[arr_idx] = temp;
    // set the current capacity of the array to be the new capacity
    capacity[arr_idx] = new_capacity;
}

// This function inserts an element at the given index in the array
void insert_element(int arr_idx, string item, int idx) {
    // check for invalid index
    if (idx < 0 || idx > n[arr_idx])
        return;
    // check if we need to update the capacity of the array
    if (n[arr_idx] == capacity[arr_idx])
        reserve(arr_idx, 2 * capacity[arr_idx] + 1);
    // loop to shif values till reach the given index
    int j = n[arr_idx] - 1;
    while (j >= idx) {
        head[arr_idx][j+1] = head[arr_idx][j];
        j = j - 1;
    }
    // insert the new element
    head[arr_idx][idx] = item;
    // update the size of the array
    n[arr_idx] = n[arr_idx] + 1;
}

// This function deletes an element at index idx in the array
void delete_element(int arr_idx, int idx) {
    // check for invalid index
    if (idx < 0 || idx >= n[arr_idx])
        return;
    // loop to shif values till reach end of the array
    int j = idx;
    while (j < n[arr_idx] - 1) {
        head[arr_idx][j] = head[arr_idx][j+1];
        j = j + 1;
    }
    // update the size of the array
    n[arr_idx] = n[arr_idx] - 1;
    // check if we need to update the capacity of the array
    if (n[arr_idx] < capacity[arr_idx] / 2)
        reserve(arr_idx, capacity[arr_idx] / 2);
}

// This function searches for an element in the array
int search_element(int arr_idx, string item) {
    int j = 0;
    // loop to find the given element in the array
    while (j < n[arr_idx]) {
        if (head[arr_idx][j] == item)
            // return that the element in the array 
            return j;
        j = j + 1;
    }
    // return that the element not in the array 
    return -1;
}

// This function prints the contents of the array
void print_array(int arr_idx) {
    int i = 0;
    // loop to print the elements in the array
    while (i < n[arr_idx]) {
        cout << head[arr_idx][i] << ' ';
        i = i + 1;
    }
}

// This function calculates the hash value of the given key with type string
int hash_function_str_complex(string key) {
    int res = 0;
    for (int i = 0 ; i < key.size() ; i++)
        res = (res + 37LL * key[i]) % hash_table_size;
    return res;
}

// This function searches for an element in the hash table
int search_item(string key) {
    // calculate the hash value of the given key
    int idx = hash_function_str_complex(key);
    // return whether the current position in the hash table contain the given key
    return search_element(idx, key);
}

// This function inserts an element in the hash table
void insert_item(string key) {
    // check if the given key exists or not 
    if (search_item(key) != -1)
        return;
    // calculate the hash value of the given key
    int idx = hash_function_str_complex(key);
    // insert the new element
    insert_element(idx, key, n[idx]);
}

// This function deletes an element at the given index in the hash table
void delete_item(string key) {
    // check if the given key exists or not 
    if (search_item(key) == -1)
        return;
    // calculate the hash value of the given key
    int idx = hash_function_str_complex(key);
    // delete the given key from it's list
    delete_element(idx, search_element(idx, key));
}

// This function prints the contents of the hash table
void print_hash_table() {
    // loop to print the elements in the hash table
    for (int i = 0 ; i < hash_table_size ; i++) {
        if (n[i] == 0)
            continue;
        cout << "index " << i << ":\n";
        print_array(i);
        cout << '\n';
    }
}

int main() {

    // Functionality Testing 

    for (char i = 'a' ; i <= 'm' ; i++) {
        string item = "";
        item += i;
        item += i;
        item += i;
        for (int j = 0 ; j < 75 ; j++) {
            insert_item(item);
            item += i;
        }
    }

    for (char i = 'a' ; i <= 'm' ; i++) {
        string item = "";
        item += i;
        item += i;
        item += i;
        for (int j = 0 ; j < 75 ; j++) {
            if (search_item(item) == -1)
                cout << item << " not found\n";
            item += i;
        }
    }

    print_hash_table();
    cout << "----------------------------------------------------\n";

    for (char i = 'a' ; i <= 'm' ; i++) {
        string item = "";
        item += i;
        item += i;
        item += i;
        for (int j = 0 ; j < 75 ; j++) {
            if (j < 10) {
                item += i;
                continue;
            }
            delete_item(item);
            item += i;
        }
    }

    for (char i = 'a' ; i <= 'm' ; i++) {
        string item = "";
        item += i;
        item += i;
        item += i;
        for (int j = 0 ; j < 10 ; j++) {
            if (search_item(item) == -1)
                cout << item << " not found\n";
            item += i;
        }
    }

    print_hash_table();
    cout << "----------------------------------------------------\n";

}
