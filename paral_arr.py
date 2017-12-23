class Paral_arr():
    def __init__(self, a):
        self.len = a
        self.books = [[] for i in range(self.len)]

    def push(self, arr):
        for i in range(self.len):
            self.books[i].append(arr[i])

    def print(self):
        for i in self.books:
            print(i)
        print()

    def print_pos(self, k):
        for i in self.books[k]:
            print(i, end = ' ')


"""
arr = Paral_arr(int(input("Please, write length(the number of Parallels)\n")))

for i in range(arr.len):
    s = input().split()
    arr.push(s)
arr.print()
arr.print_pos(1)
"""
