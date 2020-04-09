
def merge_sort(a, start, end):
    if end-start == 1:
        return [a[start]]
    if end-start == 2:
        return [min(a[start], a[end-1]), max(a[start], a[end-1])]

    mid = (start+end)//2

    left_arr = merge_sort(a, start, mid+1)
    right_arr = merge_sort(a, mid+1, end)

    left_len = mid+1-start
    right_len = end-mid-1

    k = 0
    i = 0
    j = 0
    while i<left_len and j<right_len:
        if left_arr[i] < right_arr[j]:
            a[k] = left_arr[i]
            k += 1
            i += 1
        elif left_arr[i] > right_arr[j]:
            a[k] = right_arr[j]
            k += 1
            j += 1
        else:
            a[k] = right_arr[j]
            k += 1
            a[k] = left_arr[i]
            k += 1
            i += 1
            j += 1

    while i<left_len:
        a[k] = left_arr[i]
        k += 1
        i += 1

    while j<right_len:
        a[k] = right_arr[j]
        j += 1
        k += 1

    return a




if __name__ == '__main__':
    arrays = [[1, 4, 6, 3, 5, 8, 2], [4, 6, 10, 12, 15, 23, 28, 35], [12, 15, 23, 4 , 6, 10, 35], [35, 28, 23, 15, 12, 10, 6, 4], [12], [12, 4], [12, 15, 23, 4 , 6, 10, 35, 28, 100, 130, 500, 1000, 235, 554, 75, 345, 800, 222, 333, 888, 444, 111, 666, 777, 60], [12, 15, -23, -4 , 6, 10, -35, 28], [12, 12, 23, 4 , 6, 6, 10, -35, 28], [12, 12, 12, 12, 12]]

    for arr in arrays:
        answer = merge_sort(arr, 0, len(arr))
        # print(answer)
