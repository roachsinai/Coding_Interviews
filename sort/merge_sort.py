def merge_sort(data, start, end, data_temp):
    if start < end:
        mid = (start + end) // 2
        merge_sort(data, start, mid, data_temp)
        merge_sort(data, mid+1, end, data_temp)
        merge_array(data, start, mid, end, data_temp)

def merge_array(data, start, mid, end, data_temp):
    i,j = start, mid+1
    index = start
    while i <= mid and j <= end:
        if data[i] > data[j]:
            data_temp[index] = data[j]
            j += 1
            index += 1
        else:
            data_temp[index] = data[i]
            i += 1
            index += 1

    while i <= mid:
        data_temp[index] = data[i]
        i += 1
        index += 1
    while j <= end:
        data_temp[index] = data[j]
        j += 1
        index += 1

    for i in range(start, end+1):
        data[i] = data_temp[i]

def main():
    data = list(range(10))
    data = data[::-1]
    data = [3,41,2,5]
    data_temp = [0] * len(data)
    print(data)

    merge_sort(data, 0, len(data)-1, data_temp)
    print(data)

if __name__ == "__main__":
    main()