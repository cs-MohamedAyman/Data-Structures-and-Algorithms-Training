#include <bits/stdc++.h>
using namespace std;

// A single linked list node
struct node {
    string data;
    node* next;
};

// This function inserts a node at the begin of the linked list
node* insert_begin(node* curr_head, string key) {
    // allocate new node and put it's data
    node* new_node = new node();
    new_node->data = key;
    // check if the linked list is empty
    if (curr_head == NULL) {
        curr_head = new_node;
    }
    // otherwise insert the new node in the begin of the linked list
    else {
        // set next of the new node to be the head
        new_node->next = curr_head;
        // set the new node as a head
        curr_head = new_node;
    }
    return curr_head;
}

// This function require a node to delete the node after it in the linked list
node* delete_node(node* curr_head, string key) {
    // check if the linked list is empty
    if (curr_head == NULL)
        return curr_head;
    // check if the first node in the list is the deleted node
    if (curr_head->data == key) {
        // get the node which it will be deleted
        node* temp_node = curr_head;
        // shift the head to be the next node 
        curr_head = curr_head->next;
        // delete the temp node
        delete(temp_node);
    }
    // otherwise loop till reach the deleted node
    else {
        // get the deleted node and the prev node of it in the linked list
        node* curr = curr_head;
        node* prev = NULL;
        while (curr != NULL && curr->data != key) {
            prev = curr;
            curr = curr->next;
        }
        // jump the deleted node
        prev->next = curr->next;
        // delete the node which selected
        delete(curr);
    }
    return curr_head;
}

// This function searches for a node in the linked list
bool search_node(node* curr_head, string key) {
    // iterate on the nodes till reach the last node in the linked list
    node* curr = curr_head;
    while (curr != NULL) {
        // check if the given key exists in the linked list
        if (curr->data == key)
            return true;
        curr = curr->next;
    }
    return false;
}

// This function prints the contents of the linked list
void print_linked_list(node* curr_head) {
    // print the data nodes starting from head till reach the last node
    node* curr = curr_head;
    while (curr != NULL) {
        cout << curr->data << "\n";
        curr = curr->next;
    }
}

// Initialize a hash table with static length
const int hash_table_size = 1e3+9;
// Initialize a global array of pointer for heads
node* head[hash_table_size];

// This function calculates the hash value of the given key with type string
int hash_function_str_complex(string key) {
    int res = 0;
    for (int i = 0 ; i < key.size() ; i++)
        res = (res + 37LL * key[i]) % hash_table_size;
    return res;
}

// This function searches for an element in the hash table
bool search_item(string key) {
    // calculate the hash value of the given key
    int idx = hash_function_str_complex(key);
    // return whether the current position in the hash table contain the given key
    return search_node(head[idx], key);
}

// This function inserts an element in the hash table
void insert_item(string key) {
    // check if the given key exists or not 
    if (search_item(key) == true)
        return;
    // calculate the hash value of the given key
    int idx = hash_function_str_complex(key);
    // insert the new element
    head[idx] = insert_begin(head[idx], key);
}

// This function deletes an element at the given index in the hash table
void delete_item(string key) {
    // check if the given key exists or not 
    if (search_item(key) == false)
        return;
    // calculate the hash value of the given key
    int idx = hash_function_str_complex(key);
    // delete the given key from it's list
    head[idx] = delete_node(head[idx], key);
}

// This function prints the contents of the hash table
void print_hash_table() {
    // loop to print the elements in the hash table
    for (int i = 0 ; i < hash_table_size ; i++) {
        if (head[i] == NULL)
            continue;
        cout << "index " << i << ":\n";
        print_linked_list(head[i]);
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
            if (search_item(item) == false)
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
            if (search_item(item) == false)
                cout << item << " not found\n";
            item += i;
        }
    }

    print_hash_table();
    cout << "----------------------------------------------------\n";

}
