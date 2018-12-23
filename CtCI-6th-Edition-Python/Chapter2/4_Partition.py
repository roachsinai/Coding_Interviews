from LinkedList import LinkedList


def partition(ll, x):
    '''ll.tail = ll.head 类似于建立了一个有一个元素的链表，然后将原
    链表中的元素依据判断条件添加到新链表的表头或者表尾'''
    current = ll.tail = ll.head

    while current:
        next_node = current.next
        current.next = None
        if current.value < x:
            current.next = ll.head
            ll.head = current
        else:
            ll.tail.next = current
            ll.tail = current
        current = next_node

    # Error check in case all nodes are less than x
    if ll.tail.next is not None:
        ll.tail.next = None


ll = LinkedList()
ll.generate(10, 0, 99)
print(ll)
partition(ll, ll.head.value)
print(ll)
