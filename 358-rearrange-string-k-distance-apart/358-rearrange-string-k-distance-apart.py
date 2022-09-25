class Solution:
    def rearrangeString(self, s: str, k: int) -> str:
      rearrangement = ""

      freq = Counter(s)
      if len(freq) < k:
        return rearrangement
      if len(freq) == len(s) or k == 0:
        return s


      heap = [[-value, key] for key, value in freq.items()]
      heapify(heap)

      queue = deque()
      while heap:
        top = heappop(heap)
        rearrangement += top[1]

        top[0] += 1
        queue.append(top)

        if len(queue) == k:
          rear = queue.popleft()
          if rear[0] != 0:
            heappush(heap, rear)

      if len(rearrangement) == len(s):
        return rearrangement
      else:
        return ""
