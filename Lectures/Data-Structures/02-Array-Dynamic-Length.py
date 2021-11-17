# Initialize an array with dynamic length
n = 0
capacity = 0
arr = []

# This function updates the capacity of the array
def reserve(new_capacity):
    global arr, capacity
    # Initialize a new array with the new capacity
    temp = [0] * new_capacity
    # copy the elements in the current array to the new array
    for i in range(n):
        temp[i] = arr[i]
    # delete the old array
    del arr
    # set the temp array with new capacity to be the array
    arr = temp
    # set the current capacity of the array to be the new capacity
    capacity = new_capacity

# This function inserts an element at the given index in the array
def insert_element(item, idx):
    global n
    # check for invalid index
    if idx < 0 or idx > n:
        return
    # check if we need to update the capacity of the array
    if n == capacity:
        reserve(2 * capacity + 1)
    # loop to shif values till reach the given index
    j = n - 1
    while j >= idx:
        arr[j+1] = arr[j]
        j = j - 1
    # insert the new element
    arr[idx] = item
    # update the size of the array
    n = n + 1

# This function deletes an element at index idx in the array
def delete_element(idx):
    global n
    # check for invalid index
    if idx < 0 or idx >= n:
        return
    # loop to shif values till reach end of the array
    j = idx
    while j < n - 1:
        arr[j] = arr[j+1]
        j = j + 1
    # update the size of the array
    n = n - 1
    # check if we need to update the capacity of the array
    if n < capacity // 2:
        reserve(capacity // 2)

# This function searches for an element in the array
def search_element(item):
    j = 0
    # loop to find the given element in the array
    while j < n:
        if arr[j] == item:
            # return that the element in the array 
            return True
        j = j + 1
    # return that the element not in the array 
    return False

# This function prints the contents of the array
def print_array():
    i = 0
    # loop to prthe elements in the array
    while i < n:
        print(arr[i], end=' ')
        i = i + 1


# Functionality Testing

print("Array capacity:", capacity)
print("Array size:", n)
print("Array items:", end=' ')
print_array()
print()
print("----------------------------------------------------")

''' Expected Output:
Array capacity: 0
Array size: 0
Array items: 
----------------------------------------------------
'''

print("adding the following elements 10 20 30 40 50")
insert_element(10, n)
insert_element(20, n)
insert_element(30, n)
insert_element(40, n)
insert_element(50, n)
print("the above elements have been added to the array")

''' Expected Output:
adding the following elements 10 20 30 40 50
the above elements have been added to the array
'''

print("Array capacity:", capacity)
print("Array size:", n)
print("Array items:", end=' ')
print_array()
print()
print("----------------------------------------------------")

''' Expected Output:
Array capacity: 7
Array size: 5
Array items: 10 20 30 40 50 
----------------------------------------------------
'''

print("add element 60 at position", n, ":")
insert_element(60, n)
print("Array capacity:", capacity)
print("Array size:", n)
print("Array items:", end=' ')
print_array()
print()
print("----------------------------------------------------")

''' Expected Output:
add element 60 at position 5 : 
Array capacity: 7
Array size: 6
Array items: 10 20 30 40 50 60 
----------------------------------------------------
'''

print("add element 20 at position 0 :")
insert_element(20, 0)
print("Array capacity:", capacity)
print("Array size:", n)
print("Array items:", end=' ')
print_array()
print()
print("----------------------------------------------------")

''' Expected Output:
add element 20 at position 0 : 
Array capacity: 7
Array size: 7
Array items: 20 10 20 30 40 50 60 
----------------------------------------------------
'''

print("add element 70 at position 4 :")
insert_element(70, 4)
print("Array capacity:", capacity)
print("Array size:", n)
print("Array items:", end=' ')
print_array()
print()
print("----------------------------------------------------")

''' Expected Output:
add element 70 at position 4 : 
Array capacity: 15
Array size: 8
Array items: 20 10 20 30 70 40 50 60 
----------------------------------------------------
'''

print("add element 90 at position", n-1, ":")
insert_element(90, n-1)
print("Array capacity:", capacity)
print("Array size:", n)
print("Array items:", end=' ')
print_array()
print()
print("----------------------------------------------------")

''' Expected Output:
add element 90 at position 7 : 
Array capacity: 15
Array size: 9
Array items: 20 10 20 30 70 40 50 90 60 
----------------------------------------------------
'''

print("delete element at position 0 :")
delete_element(0)
print("Array capacity:", capacity)
print("Array size:", n)
print("Array items:", end=' ')
print_array()
print()
print("----------------------------------------------------")

''' Expected Output:
delete element at position 0 : 
Array capacity: 15
Array size: 8
Array items: 10 20 30 70 40 50 90 60 
----------------------------------------------------
'''

print("delete element at position", n-1, ":")
delete_element(n-1)
print("Array capacity:", capacity)
print("Array size:", n)
print("Array items:", end=' ')
print_array()
print()
print("----------------------------------------------------")

''' Expected Output:
delete element at position 7 : 
Array capacity: 15
Array size: 7
Array items: 10 20 30 70 40 50 90 
----------------------------------------------------
'''

print("delete element at position 3 :")
delete_element(3)
print("Array capacity:", capacity)
print("Array size:", n)
print("Array items:", end=' ')
print_array()
print()
print("----------------------------------------------------")

''' Expected Output:
delete element at position 3 : 
Array capacity: 7
Array size: 6
Array items: 10 20 30 40 50 90 
----------------------------------------------------
'''

if search_element(40):
    print("element", 40, "in the array")
else:
    print("element", 40, "not in the array")

if search_element(100):
    print("element", 100, "in the array")
else:
    print("element", 100, "not in the array")
print("----------------------------------------------------")

''' Expected Output:
element 40 in the array
element 100 not in the array
----------------------------------------------------
'''
