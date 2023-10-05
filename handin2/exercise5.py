import math

def isPrime(n):
     
    # Corner cases
    if(n <= 1):
        return False
    if(n <= 3):
        return True
     
    # This is checked so that we can skip
    # middle five numbers in below loop
    if(n % 2 == 0 or n % 3 == 0):
        return False
     
    for i in range(5,int(math.sqrt(n) + 1), 6):
        if(n % i == 0 or n % (i + 2) == 0):
            return False
     
    return True
 
# Function to return the smallest
# prime number greater than N
def nextPrime(N):
 
    # Base case
    if (N <= 1):
        return 2
 
    prime = N
    found = False
 
    # Loop continuously until isPrime returns
    # True for a number greater than n
    while(not found):
        prime = prime + 1
 
        if(isPrime(prime) == True):
            found = True
 
    return prime

def checkLambda(length: int, maxLambda: float, capacity: int):
    Lambda = length / capacity
    print("Capacity: ", capacity)
    print("Lambda: ", Lambda)
    print("MaxLambda: ", maxLambda)
    if Lambda >= maxLambda:
    # Find the next prime number as the new modulo
        newCapacity = nextPrime(capacity*2)
        ok = checkLambda(length, maxLambda, newCapacity)
        
        if ok > maxLambda:
            return ok
    else:
        print("New capacity: ", capacity)
        return capacity
    

# Define the hash function
def h(x):
    return x % capacity
    
#input keys
keys = [5, 28, 19, 15, 20, 33, 12, 17, 33, 10]
#input capacity
start_capacity = 7
capacity = start_capacity


#remove duplicates
keys = list(set(keys))
#lambda for quadratic probing is 50%
#lampda for linear probing is 70%
capacity = checkLambda(len(keys), 0.5, start_capacity)
print("Capacity: ", capacity)

def quadratic_probe_insert(arr, key):
    index = h(key)
    if arr[index] is None:
        arr[index] = key
    else:
        # Quadratic probing
        i = 1
        while True:
            new_index = (index + i * i) % len(arr)
            if arr[new_index] is None:
                arr[new_index] = key
                break
            i += 1

def linear_probe_insert(arr, key):
    index = h(key)
    if arr[index] is None:
        arr[index] = key
    else:
        # Linear probing
        while arr[index] is not None:
            index = (index + 1) % len(arr)
        arr[index] = key

class Node:
    def __init__(self, key):
        self.key = key
        self.next = None

def insert_into_hash_table(arr, key):
    index = h(key)
    new_node = Node(key)
    if arr[index] is None:
        arr[index] = new_node
    else:
        current = arr[index]
        while current.next:
            current = current.next
        current.next = new_node



hash_table = [None] * capacity

for key in keys:
    quadratic_probe_insert(hash_table, key)

print("Quadratic probing")
print("Index\tValue")
for index, value in enumerate(hash_table):
    print(f"{index}\t{value}")


capacity = checkLambda(len(keys), 0.7, start_capacity)
print("Capacity: ", capacity)

hash_table = [None] * capacity
for key in keys:
    linear_probe_insert(hash_table, key)

# Print the hash table in a table format
print("Linear probing")
print("Index\tValue")
for index, value in enumerate(hash_table):
    print(f"{index}\t{value}")


capacity = checkLambda(len(keys), 0.7, start_capacity)
print("Capacity: ", capacity)

hash_table = [None] * capacity
print("Chaining")
for key in keys:
    insert_into_hash_table(hash_table, key)

for i, head in enumerate(hash_table):
    current = head
    if current is not None:
        print(f"Slot {i}:", end=" ")
        while current:
            print(current.key, end=" -> ")
            current = current.next
        print("None")

