class Solution:
    def searchRange(self, arr: List[int], key: int) -> List[int]:
      def search(key, upper):
        idx = -1
        l, r = 0, len(arr) - 1
        
        while l <= r:
          mid = l + (r - l) // 2
          if key < arr[mid]:
            r = mid - 1
          elif key > arr[mid]:
            l = mid + 1
          else:
            idx = mid
            
            if upper:
              l = mid + 1
            else:
              r = mid - 1

        return idx

      result = [- 1, -1]
      
      result[0] = search(key, False)
      if result[0] != -1:
        result[1] = search(key, True)
        
      return result