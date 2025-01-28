def select_sort(arr):
    n = len(arr)
    for i in range(n - 1): # [0, n - 1)
        m = i
        for j in range(i + 1, n): # [i + 1, n)
            if arr[j] < arr[m]:
                m = j
        arr[i], arr[m] = arr[m], arr[i] #swap
    
arr = [5, 7, 3, 9, 4, 1, 8, 2, 6]
select_sort(arr)
for i in range(len(arr)):
    print(arr[i], end=' ')