class Solution:
    def threeSumSmaller(self, arr: List[int], target: int) -> int:
        count = 0
        arr.sort()
        
        for i in range(len(arr) - 2):
            l = i + 1
            r = len(arr) - 1
            while l < r:
                if arr[i] + arr[l] + arr[r] < target:
                    count += r - l
                    l += 1
                else:
                    r -= 1
                        
        return count
          