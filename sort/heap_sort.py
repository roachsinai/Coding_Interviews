# 建堆过程
def heap_max(data, index, end):
    dad = index
    son = 2 * dad + 1

    while son <= end:
        if son+1 <= end and data[son+1] > data[son]:
            son += 1

        if data[dad] > data[son]:
            return
        else:
            data[dad], data[son] = data[son], data[dad]
            dad = son
            son = 2 * dad + 1

def heap_sort(data):
    end = len(data) -1

    for i in range(len(data)//2-1, -1, -1):
        heap_max(data, i, end)
    
    for i in range(end, 0, -1):
        data[i], data[0] = data[0], data[i]
        heap_max(data, 0, i-1)

def main():
    data = list(range(10))
    data = data[::-1]
    data = [3,41,2,5]
    print(data)

    heap_sort(data)
    print(data)

if __name__ == "__main__":
    main()