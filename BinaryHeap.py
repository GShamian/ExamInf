class BinaryHeap:
    def __init__(self, s = []): #конструктор
        self.list = [] #list для кучи
        self.buildHeap(s) 

    def heapSize(self): #размер кучи
        return len(self.list)

    def push(self, x): #вставка элемента 
        self.list.append(x)
        i = self.heapSize() - 1
        parent = (i - 1) // 2
        while (i > 0 and self.list[parent] < self.list[i]):
            temp = self.list[i]
            self.list[i] = self.list[parent]
            self.list[parent] = temp

            i = parent
            parent = (i - 1) // 2

    def heapify(self, i):
        while(True):
            leftChild = 2 * i + 1
            rightChild = 2 * i + 2
            largestChild = i

            if (leftChild < self.heapSize() and self.list[leftChild] > self.list[largestChild]):
                largestChild = leftChild

            if (rightChild < self.heapSize() and self.list[rightChild] > self.list[largestChild]):
                largestChild = rightChild

            if (largestChild == i):
                break
            temp = self.list[i]
            self.list[i] = self.list[largestChild]
            self.list[largestChild] = temp
            i = largestChild

    def buildHeap(self, source):
        self.list = source
        i = len(source) // 2
        while (i >= 0):
            self.heapify(i)
            i -= 1

    def pop(self):
        result = self.list[0]
        self.list[0] = self.list[self.heapSize() - 1]
        del self.list[-1]
        self.buildHeap(self.list)
        return result
