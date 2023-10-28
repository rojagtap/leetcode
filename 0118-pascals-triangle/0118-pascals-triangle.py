class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        triangle = [[1]]
        if numRows == 1:
            return triangle
        
        triangle.append([1, 1])
        for i in range(3, numRows + 1):
            triangle.append([1])
            for j in range(1, i - 1):
                triangle[-1].append(triangle[-2][j - 1] + triangle[-2][j])
            triangle[-1].append(1)

        return triangle
    