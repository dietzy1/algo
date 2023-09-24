def h(x):
    return x % 11

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

keys = [22, 5, 16, 27, 1, 12, 25, 202007814]

array_size = 11
hash_table = [None] * array_size

for key in keys:
    quadratic_probe_insert(hash_table, key)

print(hash_table)

print (202007814 % 11)
#der ligger ikke noget i 8 så der kan den bare passes direkte ind