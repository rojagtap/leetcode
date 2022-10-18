class Solution:
    def medianSlidingWindow(self, nums: List[int], k: int) -> List[float]:
        result = []

        odd = k & 1
        size = 0
        low, high = [], []

        l = 0
        for r in range(len(nums)):
            if not low or nums[r] <= -low[0]:
                heappush(low, -nums[r])
            else:
                heappush(high, nums[r])

            if len(low) > len(high) + 1:
                heappush(high, -heappop(low))
            elif len(low) < len(high):
                heappush(low, -heappop(high))

            if r >= k - 1:
                if odd:
                    result.append(-low[0])
                else:
                    result.append((-low[0] + high[0]) / 2)

                if nums[l] <= -low[0]:
                    idx = low.index(-nums[l])
                    low[idx] = low[-1]
                    low.pop()

                    if idx < len(low):
                        heapq._siftup(low, idx)
                        heapq._siftdown(low, 0, idx)
                else:
                    idx = high.index(nums[l])
                    high[idx] = high[-1]
                    high.pop()

                    if idx < len(high):
                        heapq._siftup(high, idx)
                        heapq._siftdown(high, 0, idx)

                l += 1
                if len(low) > len(high) + 1:
                    heappush(high, -heappop(low))
                elif len(low) < len(high):
                    heappush(low, -heappop(high))

        return result
