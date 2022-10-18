class MedianFinder:

    def __init__(self):
        self.size = 0
        self.lt = []
        self.gt = []

    def addNum(self, num: int) -> None:
        self.size += 1
        
        if self.gt and num > self.gt[0]:
            heappush(self.gt, num)
            if len(self.gt) > self.size // 2:
                heappush(self.lt, -heappop(self.gt))
        else:
            heappush(self.lt, -num)
            if len(self.gt) < self.size // 2:
                heappush(self.gt, -heappop(self.lt))
        

    def findMedian(self) -> float:
        return -self.lt[0] if self.size & 1 else (-self.lt[0] + self.gt[0]) / 2
        


# Your MedianFinder object will be instantiated and called as such:
# obj = MedianFinder()
# obj.addNum(num)
# param_2 = obj.findMedian()