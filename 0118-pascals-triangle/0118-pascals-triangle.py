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

# class Solution:
#     def ncr(self, n, r):
#         if n == 0:
#             return 1
#         soln = 1
#         for i in range(r):
#             soln *= (n - i) / (i + 1)
#         return soln

#     def generate_row(self, row_num):
#         row = []
#         for i in range(row_num):
#             row.append(round(self.ncr(row_num - 1, i)))
#         return row

#     def generate(self, numRows: int) -> List[List[int]]:
#         ret = []
#         for i in range(1, numRows + 1):
#             ret.append(self.generate_row(i))
#         return ret
