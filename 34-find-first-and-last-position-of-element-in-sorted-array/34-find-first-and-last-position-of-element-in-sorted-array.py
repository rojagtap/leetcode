class Solution:
    def searchRange(self, arr: List[int], key: int) -> List[int]:
        def search(start, end):
          left, right = -1, -1
          l, r = start, end
          while l <= r:
            mid = l + (r - l) // 2
            if key < arr[mid]:
              r = mid - 1
            elif key > arr[mid]:
              l = mid + 1
            else:
              left = search(start, mid - 1)[0] if mid - 1 >= 0 and arr[mid - 1] == key else mid
              right = search(mid + 1, end)[1] if mid + 1 <= end and arr[mid + 1] == key else mid
              break

          return [left, right]
          
        return search(0, len(arr) - 1)