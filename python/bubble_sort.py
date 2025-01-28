def bubble_sort(arr):
    n = len(arr)
    for i in range(n): # [0, n)
        for j in range(0, n - i - 1): # [0, n - i - 1)
            if arr[j + 1] < arr[j]:
                arr[j + 1], arr[j] = arr[j], arr[j + 1] # swap

def bubble_imp_sort(arr):
    n = len(arr)
    for i in range(n): # [0, n)
        swapped = False
        for j in range(0, n - i - 1): # [0, n - i - 1)
            if arr[j + 1] < arr[j]:
                arr[j + 1], arr[j] = arr[j], arr[j + 1] # swap
                swapped = True
        if (swapped == False):
            break
    
def bubble_imp2_sort(arr):
    n = len(arr)
    l = 0
    for i in range(n): # [0, n)
        m = l
        for j in range(l, n - i - 1): # [l, n - i - 1)
            if arr[j + 1] < arr[j]:
                arr[j + 1], arr[j] = arr[j], arr[j + 1] # swap
                if m == l and j > 0:
                    m = -1
                    l = j
        if m == l:
            break
        elif l > 0:
            l = l - 1

def bubble_imp3_sort(arr):
    n = len(arr)
    l = 0
    while (n):
        m = 0
        for j in range(l, n - 1): # [l, n - 1)
            if arr[j] > arr[j + 1]:
                arr[j], arr[j + 1] = arr[j + 1], arr[j] # swap
                if j == 0:
                    l = j + 1
                elif m == 0:
                    l = j - 1
                m = m + 1
        if m == 0:
            break
        n = n - 1

arr = [5, 7, 3, 9, 4, 1, 8, 2, 6]
bubble_imp3_sort(arr)
for i in range(len(arr)):
    print(arr[i], end=' ')