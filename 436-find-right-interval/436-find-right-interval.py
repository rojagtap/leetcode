class Solution:
    def findRightInterval(self, intervals: List[List[int]]) -> List[int]:
      result = []

      maxstarts, maxends = [], []
      for i in range(len(intervals)):
        heappush(maxstarts, (-intervals[i][0], i))
        heappush(maxends, (-intervals[i][1], i))
        result.append(-1)

      for _ in range(len(intervals)):
        maxend, i = heappop(maxends)

        nextstart, j = heappop(maxstarts)
        if -nextstart >= -maxend:
          while maxstarts and -maxstarts[0][0] >= -maxend:
            nextstart, j = heappop(maxstarts)

          result[i] = j

        heappush(maxstarts, (nextstart, j))

      return result