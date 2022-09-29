class Solution:
    # O(n), O(1)
    def canPlaceFlowers(self, flowerbed: List[int], n: int) -> bool:
        i = 0
        while i < len(flowerbed) and n:
            if flowerbed[i]:
                i += 2
            elif (i + 1) < len(flowerbed) and flowerbed[i + 1]:
                i += 1
            else:
                n -= 1
                i += 2
                
        return n == 0