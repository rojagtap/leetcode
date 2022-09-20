from heapq import *

class MedianFinder:

    def __init__(self):
      self.low = []
      self.high = []
      self.size = 0

    def addNum(self, num: int) -> None:
        self.size += 1
        half = self.size // 2

        if not self.low or num < -self.low[0]:
          heappush(self.low, -num)
          if len(self.low) > (self.size - half):
            left = -heappop(self.low)
            heappush(self.high, left)
        else:
          heappush(self.high, num)
          if len(self.high) > half:
            right = heappop(self.high)
            heappush(self.low, -right)


    def findMedian(self) -> float:
      return -self.low[0] if self.size & 1 else (-self.low[0] + self.high[0]) / 2


# Your MedianFinder object will be instantiated and called as such:
# obj = MedianFinder()
# obj.addNum(num)
# param_2 = obj.findMedian()