class Solution:
    def intervalIntersection(self, firstList: List[List[int]], secondList: List[List[int]]) -> List[List[int]]:
        i, j = 0, 0
        start, end = 0, 1
        intersection = []
        
        while i < len(firstList) and j < len(secondList):
            a = secondList[j][start] <= firstList[i][start] <= secondList[j][end]
            b = firstList[i][start] <= secondList[j][start] <= firstList[i][end]

            if a or b:
                intersection.append([max(firstList[i][start], secondList[j][start]), min(firstList[i][end], secondList[j][end])])
                
            if firstList[i][end] < secondList[j][end]:
                i += 1
            else:
                j += 1
                        
        return intersection