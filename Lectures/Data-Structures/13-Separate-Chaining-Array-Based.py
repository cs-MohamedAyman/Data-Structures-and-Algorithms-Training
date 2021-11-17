# Initialize a hash table with static length
hash_table_size = int(1e3)+9
# Initialize a global array of pointer for heads
n = [0] * hash_table_size
capacity = [0] * hash_table_size
head = [None] * hash_table_size

# This function updates the capacity of the array
def reserve(arr_idx, new_capacity):
    # Initialize a new array with the new capacity
    temp = [""] * new_capacity
    # copy the elements in the current array to the new array
    for i in range(n[arr_idx]):
        temp[i] = head[arr_idx][i]
    # delete the old array
    for i in range(n[arr_idx]-1, -1, -1):
        del head[arr_idx][i]
    # set the temp array with new capacity to be the array
    head[arr_idx] = temp
    # set the current capacity of the array to be the new capacity
    capacity[arr_idx] = new_capacity

# This function inserts an element at the given index in the array
def insert_element(arr_idx, item, idx):
    # check for invalid index
    if idx < 0 or idx > n[arr_idx]:
        return
    # check if we need to update the capacity of the array
    if n[arr_idx] == capacity[arr_idx]:
        reserve(arr_idx, 2 * capacity[arr_idx] + 1)
    # loop to shif values till reach the given index
    j = n[arr_idx] - 1
    while j >= idx:
        head[arr_idx][j+1] = head[arr_idx][j]
        j = j - 1
    # insert the new element
    head[arr_idx][idx] = item
    # update the size of the array
    n[arr_idx] = n[arr_idx] + 1

# This function deletes an element at index idx in the array
def delete_element(arr_idx, idx):
    # check for invalid index
    if idx < 0 or idx >= n[arr_idx]:
        return
    # loop to shif values till reach end of the array
    j = idx
    while j < n[arr_idx] - 1:
        head[arr_idx][j] = head[arr_idx][j+1]
        j = j + 1
    # update the size of the array
    n[arr_idx] = n[arr_idx] - 1
    # check if we need to update the capacity of the array
    if n[arr_idx] < capacity[arr_idx] // 2:
        reserve(arr_idx, capacity[arr_idx] // 2)

# This function searches for an element in the array
def search_element(arr_idx, item):
    j = 0
    # loop to find the given element in the array
    while j < n[arr_idx]:
        if head[arr_idx][j] == item:
            # return that the element in the array 
            return j
        j = j + 1
    # return that the element not in the array 
    return -1

# This function prints the contents of the array
def print_array(arr_idx):
    i = 0
    # loop to prthe elements in the array
    while (i < n[arr_idx]):
        print(head[arr_idx][i], end=' ')
        i = i + 1


# This function calculates the hash value of the given key with type string
def hash_function_str_complex(key):
    res = 0
    for i in range(len(key)):
        res = (res + 37 * ord(key[i]) * (i+1)) % hash_table_size
    return res

# This function searches for an element in the hash table
def search_item(key):
    # calculate the hash value of the given key
    idx = hash_function_str_complex(key)
    # return whether the current position in the hash table contain the given key
    return search_element(idx, key)

# This function inserts an element in the hash table
def insert_item(key):
    # check if the given key exists or not
    if search_item(key) != -1:
        return
    # calculate the hash value of the given key
    idx = hash_function_str_complex(key)
    # insert the new element
    insert_element(idx, key, n[idx])

# This function deletes an element at the given index in the hash table
def delete_item(key):
    # check if the given key exists or not
    if search_item(key) == -1:
        return
    # calculate the hash value of the given key
    idx = hash_function_str_complex(key)
    # delete the given key from it's list
    delete_element(idx, search_element(idx, key))

# This function prints the contents of the hash table
def print_hash_table():
    # loop to prthe elements in the hash table
    for i in range(hash_table_size):
        if n[i] == 0:
            continue
        print("index", i, ":")
        print_array(i)
        print()


# Functionality Testing


for i in range(13):
    c = chr(ord('a')+i)
    item = ""
    item += c
    item += c
    item += c
    for j in range(75):
        insert_item(item)
        item += c

for i in range(13):
    c = chr(ord('a')+i)
    item = ""
    item += c
    item += c
    item += c
    for j in range(75):
        if search_item(item) == -1:
            print(item, "not found")
        item += c

# print_hash_table()
print("----------------------------------------------------")

for i in range(13):
    c = chr(ord('a')+i)
    item = ""
    item += c
    item += c
    item += c
    for j in range(75):
        if j < 10:
            item += c
            continue
        delete_item(item)
        item += c

for i in range(13):
    c = chr(ord('a')+i)
    item = ""
    item += c
    item += c
    item += c
    for j in range(10):
        if search_item(item) == -1:
            print(item, "not found")
        item += c

# print_hash_table()
print("----------------------------------------------------")
