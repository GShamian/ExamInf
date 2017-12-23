from random import randint
class King:
    def __init__(self, start, size):
        self.start = start
        self.size = size
        self.hole = (randint(0, size-1), randint(0, size-1))

    def check(self, a, b):
        return a >= 0 and b >= 0 and a <= self.size - 1 and b <= self.size - 1

    def near(self, where):
        s = []
        for y in [-1, 0, 1]:
            for x in [-1, 0, 1]:
                if self.check(where[0] + x, where[1] + y):
                    s.append((where[0] + x, where[1] + y))
        s.remove(where)
        return s

def find(y_king):
    aue = []
    aue.append(y_king.start)
    searched = []
    while aue:
        where = aue.pop(0) # 0 ---- width // None ---- depth
        if where not in searched:
            if where == y_king.hole:
                return where
            else:
                aue += y_king.near(where)
                searched.append(where)

"""
y_king = King((0, 0), 5)
print(find(y_king))
print(y_king.hole)
"""
