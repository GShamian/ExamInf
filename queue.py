class Queue():
    def __init__(self):
        self.arr = []
        self.len = len(self.arr)

    def push(self, n):
        self.arr = self.arr + [n]

    def pop(self):
        k = self.arr[0]
        self.arr = self.arr[1:]
        return k

    def print(self):
        for i in self.arr:
            print(i, end = ' ')


'''
arr = Queue()
for i in range(int(input())):
    arr.push(int(input()))

print(arr.pop())
arr.print()
'''