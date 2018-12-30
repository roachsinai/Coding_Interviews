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


class SortedStack:
    def __init__(self):
        self.stack = Stack()
        self.temp_stack = Stack()

    def push(self, item):
        if self.stack.is_empty() or item < self.stack.peek():
            self.stack.push(item)
        else:
            while not self.stack.is_empty() and item > self.stack.peek():
                self.temp_stack.push(self.stack.pop())
            self.stack.push(item)
            while not self.temp_stack.is_empty():
                self.stack.push(self.temp_stack.pop())

    def pop(self):
        return self.stack.pop()

    def peek(self):
        return self.stack.peek()

    def size(self):
        return self.stack.size()


class Tests(unittest.TestCase):
    def test_pop_one(self):
        queue = SortedStack()
        queue.push(1)
        self.assertEqual(queue.pop(), 1)

    def test_push_two(self):
        queue = SortedStack()
        queue.push(1)
        queue.push(2)
        self.assertEqual(queue.pop(), 1)
        self.assertEqual(queue.pop(), 2)

    def test_push_three(self):
        queue = SortedStack()
        queue.push(1)
        queue.push(2)
        queue.push(3)
        self.assertEqual(queue.pop(), 1)
        self.assertEqual(queue.pop(), 2)
        self.assertEqual(queue.pop(), 3)

    def test_push_mixed(self):
        queue = SortedStack()
        queue.push(3)
        queue.push(2)
        queue.push(1)
        queue.push(4)
        self.assertEqual(queue.pop(), 1)
        self.assertEqual(queue.pop(), 2)
        self.assertEqual(queue.pop(), 3)
        self.assertEqual(queue.pop(), 4)

if __name__ == "__main__":
    unittest.main()
