class LargerNumKey(str):
    def __lt__(x, y):
        return x + y < y + x


class Solution:
    def largestNumber(self, nums: List[int]) -> str:
        largest = "".join(sorted([str(num) for num in nums], key=LargerNumKey, reverse=True))
        return largest if largest[0] != '0' else '0'