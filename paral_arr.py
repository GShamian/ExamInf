class Paral_arr():
    def __init__(self, a):
        self.len = a
        self.books = [[] for i in range(self.len)]

    def push(self, arr):
        for i in range(self.len):
            self.books[i].append(arr[i])

    def print(self):
        for j in range(self.len):
            for i in range(self.len):
                print(self.books[i][j], end = ' ')
            print()


'''
arr = Paral_arr(int(input("Please, write length(the number of Parallels)\n")))

for i in range(arr.len):
    s = input().split()
    arr.push(s)
arr.print()
'''