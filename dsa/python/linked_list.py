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

    def get_position(self, position):
        current = self.head
        for i in range(1, position):
            if current.next:
                current = current.next
            else:
                return None

        return current

    def insert(self, new_node, position):
        current = self.head
        for i in range(1, position-1):
            if current.next:
                current = current.next
            else:
                print("Position not found")
                return
        new_node.next = current.next
        current.next = new_node
    
    def delete(self, value):
        current = self.head
        if current.value == value:
            self.head = current.next
            return
        if self.head:
            while current.next:
                if current.next.value == value:
                    current.next = current.next.next
                    return                    
                current = current.next

        print("Value not found")
        

e1 = Node("one")
e2 = Node("two")
e3 = Node("three")
e4 = Node("four")
e5 = Node("five")
e6 = Node("six")
ll = LinkedList(e1)
ll.append(e2)
ll.append(e3)
ll.append(e4)
ll.append(e5)
ll.append(e6)
# print(ll.head.value)
# print(ll.head.next.value)
# print(ll.get_position(2))
# print(ll.get_position(4))
e2new = Node("twoagain")
ll.insert(e2new, 2)
print(ll.get_position(2).value)
print(ll.get_position(3).value)
print(ll.get_position(4).value)
print(ll.get_position(6).value)
print(ll.get_position(7).value)
ll.delete("twoagain")
print(ll.get_position(2).value)
print(ll.get_position(3).value)
print(ll.get_position(6).value)
ll.delete("one")
print(ll.get_position(1).value)
print(ll.get_position(2).value)

