class Solution:
    def generateParenthesis(self, num: int) -> List[str]:
        class Brace:
          def __init__(self, val, open_count, closed_count):
            self.val = val
            self.open_count = open_count
            self.closed_count = closed_count


        result = []
        queue = deque([Brace("", 0, 0)])

        while queue:
          front = queue.popleft()

          if front.open_count == num and front.closed_count == num:
            result.append(front.val)
          else:
            if front.open_count < num:
              queue.append(Brace(front.val + '(', front.open_count + 1, front.closed_count))

            if front.open_count > front.closed_count:
              queue.append(Brace(front.val + ')', front.open_count, front.closed_count + 1))


        return result