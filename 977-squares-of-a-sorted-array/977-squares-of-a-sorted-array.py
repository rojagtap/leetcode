class Solution:
    def sortedSquares(self, arr: List[int]) -> List[int]:
        squares = []

        # find the first non-zero number
        r = 0
        while r < len(arr) and arr[r] < 0:
            r += 1

        l = r - 1

        # negative in reverse and positive to the right
        while l >= 0 and r < len(arr):
            while l >= 0 and arr[l] * arr[l] <= arr[r] * arr[r]:
                squares.append(arr[l] * arr[l])
                l -= 1

            while r < len(arr) and arr[r] * arr[r] <= arr[l] * arr[l]:
                squares.append(arr[r] * arr[r])
                r += 1

        # residual l
        while l >= 0:
            squares.append(arr[l] * arr[l])
            l -= 1
            
        # residual r
        while r < len(arr):
            squares.append(arr[r] * arr[r])
            r += 1

        return squares
