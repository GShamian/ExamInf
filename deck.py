class Queue():
    def __init__(self):
        self.arr = []
        self.len = len(self.arr)

    def push_right(self, n):
        self.arr = self.arr + [n]

    def push_left(self, n):
        self.arr = [n] + self.arr

    def pop_left(self):
        k = self.arr[0]
        self.arr = self.arr[1:]
        return k

    def pop_right(self):
        k = self.arr[self.len - 1]
        self.arr = self.arr[:self.len - 1]
        return k

    def print(self):
        for i in self.arr:
            print(i, end=' ')


'''
arr = Queue()
for i in range(int(input())):
    arr.push_left(int(input()))

print(arr.pop_right())
arr.print()
'''