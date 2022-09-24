class Solution:
    def search(self, arr: List[int], x: int) -> int:
        left, right = 0, len(arr) - 1

        while left <= right:
            mid = left + (right - left) // 2

            if x < arr[mid]:
                right = mid - 1
            elif x > arr[mid]:
                left = mid + 1
            else:
                return mid

        return -1