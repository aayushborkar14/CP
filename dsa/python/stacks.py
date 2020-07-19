class Node:

    def __init__(self, value):
        self.value = value
        self.next = None

class LinkedList:

    def __init__(self, head = None):
        self.head = head

    def append(self, new_node):
        current = self.head
        if self.head:
            while current.next:
                current = current.next

            current.next = new_node
        else:
            self.head = new_node
    
    def insert_first(self, new_node):
        if self.head:
            new_node.next = self.head
            self.head = new_node
        else:
            self.head = new_node

    def delete_first(self):
        if self.head:
            deleted_node = self.head
            self.head = self.head.next
            return deleted_node
        else:
            return None

class Stack:
    
    def __init__(self, top = None):
        self.ll = LinkedList(top)

    def push(self, new_node):
        self.ll.insert_first(new_node)

    def pop(self):
        return self.ll.delete_first()



e1 = Node("one")
e2 = Node("two")
e3 = Node("three")
ll = LinkedList(e1)
ll.insert_first(e2)
ll.insert_first(e3)
print(ll.head.value)
print(ll.head.next.value)
print(ll.head.next.next.value)
ll.delete_first()
print(ll.head.value)
print(ll.head.next.value)
