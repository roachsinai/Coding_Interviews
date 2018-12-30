import unittest


class Stack:

    def __init__(self):
        self.items = []

    def is_empty(self):
        return self.items == []

    def push(self, item):
        self.items.append(item)

    def pop(self):
        if self.is_empty():
            raise Exception('Stack is empty.')
        return self.items.pop()

    def peek(self):
        if self.is_empty():
            raise Exception('Stack is empty.')
        return self.items[-1]

    def size(self):
        return len(self.items)


class MyQueue:
    def __init__(self):
        self.output = Stack()
        self.input = Stack()

    def enqueue(self, item):
        while not self.output.is_empty():
            self.input.push(self.output.pop())
        self.input.push(item)

        while not self.input.is_empty():
            self.output.push(self.input.pop())

    def dequeue(self):
        if not self.output.is_empty():
            return self.output.pop()
        else:
            return None

    def is_empty(self):
        return self.output.is_empty()

    def size(self):
        return self.output.size()


class Tests(unittest.TestCase):

    def test_enqueue_one(self):
        queue = MyQueue()
        queue.enqueue(1)
        self.assertEqual(queue.size(), 1)

    def test_dequeue_one(self):
        queue = MyQueue()
        queue.enqueue(1)
        self.assertEqual(queue.dequeue(), 1)

    def test_enqueue_two(self):
        queue = MyQueue()
        queue.enqueue(1)
        queue.enqueue(2)
        self.assertEqual(queue.dequeue(), 1)
        self.assertEqual(queue.dequeue(), 2)

    def test_enqueue_three(self):
        queue = MyQueue()
        queue.enqueue(1)
        queue.enqueue(2)
        queue.enqueue(3)
        self.assertEqual(queue.dequeue(), 1)
        self.assertEqual(queue.dequeue(), 2)
        self.assertEqual(queue.dequeue(), 3)


if __name__ == '__main__':
    unittest.main()
