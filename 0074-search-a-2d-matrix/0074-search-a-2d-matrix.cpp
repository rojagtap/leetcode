/*
get the largest number smaller than target across rows (matrix[i][0])
search target in that row
*/
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int l = 0, r = matrix.size() - 1;
        
        int row = r;
        while (l <= r) {            
            int mid = l + (r - l) / 2;
            if (matrix[mid][0] < target) {
                row = mid;
                l = mid + 1;
            } else if (matrix[mid][0] > target) {
                r = mid - 1;
            } else {
                return true;
            }
        }
        
        l = 0;
        r = matrix[row].size() - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            
            if (matrix[row][mid] < target) l = mid + 1;
            else if (matrix[row][mid] > target) r = mid - 1;
            else return true;
        }
        
        return false;
    }
};