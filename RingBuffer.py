class RingBuffer:
    def __init__(self, s = []):
        self.data = s
        self.cur = 0

    def next(self, k = 1):
        assert(len(self.data))
        self.cur = (self.cur + k) % (len(self.data))
        return self.data[self.cur]

    def pop(self, k = None):
        assert(len(self.data) > 0)
        if k is None:
            self.data.pop(self.cur)
        else:
            self.data.pop(k)

    def append(self, m, k=None):
        assert (len(self.data) > 0)
        if k is None:
            self.data.insert(self.cur, m)
        else:
            self.data.insert(k, m)

a = RingBuffer([1,2,3,4])

"""
print(a.data)
print(a.data)
for i in range(10):
   print(a.next(1))
a.append(5)
a.next(1)
a.append(6)
print(a.data)
"""
