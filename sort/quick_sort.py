def partition(data, start, end):
    i,j,holder = start,end,data[start]

    while i < j:
        while i < j and data[j] >= holder:
            j -= 1
        if i < j:
            data[i] = data[j]
            i += 1
        
        while i < j and data[i] <= holder:
            i += 1
        if i < j:
            data[j] = data[i]
            j -= 1
    
    data[i] = holder
    return i

def qsort(data, start, end):
    if start < end:
        pivot = partition(data, start, end)
        qsort(data, start, pivot-1)
        qsort(data, pivot+1, end)

def main():
    data = list(range(10))
    data = data[::-1]
    print(data)

    qsort(data, 0, len(data)-1)
    print(data)

if __name__ == "__main__":
    main()