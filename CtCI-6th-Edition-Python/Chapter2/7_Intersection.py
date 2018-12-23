from LinkedList import LinkedList


def intersection(list1, list2):
    if list1.tail is not lis2.tail:
        return False

    diff = len(list1) - len(list2)
    shorter = list1 if diff < 0 else list2
    longer = list2 if diff < 0 else list1

    shorter_node, longer_node = shorter.head, longer.head

    for _ in range(abs(diff)):
        longer_node = longer_node.next

    while shorter_node is not longer_node:
        shorter_node = shorter_node.next
        longer_node = longer_node.next

    return longer_node
