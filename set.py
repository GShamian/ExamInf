class Set():
    def __init__(self):
        self.data = dict()
        self.values = []

    def append(self, k):
        if k not in self.values:
            self.data[k] = True
        self.values = list(self.data.keys())

    def update(self, s):
        for i in s:
            self.data[i] = True
        self.values = list(self.data.keys())

    def intersection(self, s):
        iter = self.data.copy()
        for i in iter:
            if i not in s:
                self.data.pop(i)
        self.values = list(self.data.keys())

    def differense(self, s):
        iter = self.data.copy()
        for i in iter:
            if i in s:
                self.data.pop(i)
        self.values = list(self.data.keys())


'''
test_set = Set()
test_set.append(5)
print(test_set.values)
test_set.append(3)
print(test_set.values)
test_set.update([1, 3, 5, 8])
print(test_set.values)
test_set.differense([5, 1])
print(test_set.values)
test_set.intersection([5, 1, 2])
print(test_set.values)
'''