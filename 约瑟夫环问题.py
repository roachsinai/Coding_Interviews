class Node(object):
    def __init__(self, value):
        self.value = value
        self.next = None
    
def create_circle_list(n):
    head = Node(1)
    pre = head
    for i in range(2, n+1):
        pre.next = Node(i)
        pre = pre.next
    pre.next = head
    return head


n = 5 # 人的个数
m = 2

if m == 1:
    pirnt(n)
else:
    head = create_circle_list(n)
    pre = None
    cur = head
    while cur.next != cur:
        for i in range(m-1):
            pre = cur
            cur = cur.next
        print(cur.value)
        pre.next = cur.next
        cur.next = None
        cur = pre.next
    print(cur.value)
