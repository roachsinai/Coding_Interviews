import unittest
import time


class Node:
    def __init__(self, data, next_node=None):
        self.data = data
        self.next_node = next_node

    def __str__(self):
        return str(self.data)


class LinkedList:
    def __init__(self, head=None):
        self.head = head

    def insert(self, node):
        if self.head is None:
            self.head = node
            return
        current_node = self.head
        while current_node.next_node is not None:
            current_node = current_node.next_node
        current_node.next_node = node

    def pop_head(self):
        if self.head is not None:
            head_to_pop = self.head
            self.head = self.head.next_node
            return head_to_pop
        else:
            return None

    def size(self):
        current_node = self.head
        size = 0
        while current_node is not None:
            current_node = current_node.next_node
            size += 1
        return size


# Animal Definitions
class Animal:
    def __init__(self, name):
        self.time_admitted = time.time()
        self.name = name


class Cat(Animal):
    def __init__(self, name):
        super(Cat, self).__init__(name)


class Dog(Animal):
    def __init__(self, name):
        super(Dog, self).__init__(name)


class AnimalShelter:
    def __init__(self):
        self.linked_list = LinkedList()

    def enqueue(self, animal):
        animal_node = Node(animal)
        self.linked_list.insert(animal_node)

    def dequeue_any(self):
        return self.linked_list.pop_head()

    def dequeue_cat(self):
        prev_node = current_node = self.linked_list.head
        if current_node is None:
            return None
        if type(current_node.data) is Cat:
            self.linked_list.head = current_node.next_node
            return current_node.data
        current_node = self.linked_list.head.next_node
        while current_node:
            if type(current_node.data) is Cat:
                prev_node.next_node = current_node.next_node
                return current_node.data
            else:
                prev_node.next_node = current_node
                current_node.next_node = current_node.next_node


class Tests(unittest.TestCase):
    def test_dequeue_cat(self):
        animal_shelter = AnimalShelter()
        animal_shelter.enqueue(Cat('Fluffy'))
        animal_shelter.enqueue(Dog('Sparky'))
        animal_shelter.enqueue(Cat('Sneezy'))
        self.assertEqual(type(animal_shelter.dequeue_cat()), Cat, 'Receive a cat')
        self.assertEqual(type(animal_shelter.dequeue_cat()), Cat, 'Receive a cat')
        self.assertEqual(animal_shelter.linked_list.size(), 1, 'Amount of animals in queue should be 1')


if __name__ == "__main__":
    unittest.main()
