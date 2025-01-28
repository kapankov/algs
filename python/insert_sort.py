# def insert_sort(arr):
#     n = len(arr)
#     for i in range(1, n): # [1, n)  
#         t = arr[i]
#         j = i - 1
#         while j >= 0 and t < arr[j]:
#             arr[j + 1] = arr[j]
#             j = j - 1
#         arr[j + 1] = t
def insert_sort(arr):
    n = len(arr)
    for i in range(1, n): # [1, n)  
        t = arr[i]
        j = i
        while j > 0 and arr[j - 1] > t:
            arr[j] = arr[j - 1]
            j = j - 1
        arr[j] = t
    
arr = [5, 7, 3, 9, 4, 1, 8, 2, 6]
insert_sort(arr)
for i in range(len(arr)):
    print(arr[i], end=' ')
