class Solution:
    def findMaximizedCapital(self, k: int, w: int, profits: List[int], capital: List[int]) -> int:
      total = w

      capitalheap, profitsheap = [], []
      for i in range(len(capital)):
        if capital[i] <= w:
          heappush(profitsheap, -profits[i])
        else:
          heappush(capitalheap, (capital[i], i))

      for _ in range(k):
        if not profitsheap:
          break

        total += -heappop(profitsheap)

        while capitalheap and capitalheap[0][0] <= total:
          heappush(profitsheap, -profits[heappop(capitalheap)[1]])


      return total
