class Solution:
  def leastInterval(self, tasks: List[str], k: int) -> int:
    time = 0
  
    freq = Counter(tasks)
    heap = []
    for key, value in freq.items():
      heappush(heap, [-value, 0])

    queue = deque()
    while heap or queue:
      time += 1

      if heap:
        top = heappop(heap)
        top[0] += 1
        top[1] = time
        if top[0] != 0:
          queue.append(top)

      if queue and time - queue[0][1] == k:
        heappush(heap, queue.popleft())

    return time