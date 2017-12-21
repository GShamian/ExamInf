class Dict():
    def __init__(self):
        self.data = []

    def check(self, k):
        for i in range(len(self.data)):
            if k == self.data[i][0]:
                return i + 1
        return False

    def append(self, key, val):
        pos = self.check(key)
        if not pos:
            self.data.append([key, [val]])
        else:
            self.data[pos-1][1].append(val)

    def pop(self, key):
        iter = self.data.copy()
        for i in range(len(iter)):
            if iter[i][0] == key:
                self.data.pop(i)
                return iter[i][1]

    def keys(self):
        return [i[0] for i in self.data]

    def values(self):
        return [i[1] for i in self.data]


"""
test_dict = Dict()
test_dict.append(1, 23)
test_dict.append(2, 12)
test_dict.append(1, 44)
print(test_dict.data)
print(test_dict.pop(2))
print(test_dict.data)
print(test_dict.keys())
print(test_dict.values())
"""
