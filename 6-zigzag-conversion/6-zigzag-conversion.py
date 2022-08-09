class Solution:
    '''
    Iterate throught the string and add the chars to the output array
        while doing so if you are at 0th row then we need to increment a row for each character until we reach the last row
        whereas if you are on the last row, we need to decrement the rows until we arrive at the 0th layer
    '''
    def convert(self, s: str, numRows: int) -> str:
        if numRows == 1 or numRows >= len(s):
            return s
        matrix = ["" for _ in range(numRows)]
        iterator = -1
        row = 0
        for char in s:
            if row == 0 or row == numRows - 1:
                iterator = -1 * iterator
                
            matrix[row] += char
            row = row + iterator
            
        return ''.join(matrix)