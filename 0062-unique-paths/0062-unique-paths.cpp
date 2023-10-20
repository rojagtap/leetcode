/*
the basic approach is to dfs until you reach m - 1, n - 1
this will be O(2^mn)

we can do memoization to reduce this

in the current implementation, let's say the recursion returns back to i = 0, j = 5 for {0, 1} traversal
then, it will again do the traversal for i = 1, j = 6 -> i = 2, j = 6
that is it will trace the paths again every time

instead, we can cache the result for all given further i, j pairs so that the ones like i = 0, j = 5 will directly pick the cached value from it's bottom

this way, it will be O(mn) and O(mn) in space
*/

// dfs + memoization (top-down dp)
class Solution {
public:
    int uniquePaths(int m, int n) {
        this->m = m;
        this->n = n;
        this->memo = vector<vector<int>>(m, vector<int>(n, 0));

        return allpaths(0, 0);
    }
    
private:
    int m, n;
    vector<vector<int>> memo;

    int allpaths(int i, int j) {
        if (i < 0 || i >= m || j < 0 || j >= n) {
            return 0;
        }

        if (i == m - 1 && j == n - 1) {
            return 1;
        }

        if (memo[i][j] > 0) {
            return memo[i][j];
        }

        int paths = 0;
        paths += allpaths(i + 0, j + 1);
        paths += allpaths(i + 1, j + 0);

        return memo[i][j] = paths;
    }
};

// // simple dfs (TLE)
// class Solution {
// public:
//     int uniquePaths(int m, int n) {
//         this->m = m;
//         this->n = n;
//         allpaths(0, 0);

//         return paths;
//     }
    
// private:
//     int m, n;
//     int paths = 0;

//     void allpaths(int i, int j) {
//         if (i < 0 || i >= m || j < 0 || j >= n) {
//             return;
//         }

//         if (i == m - 1 && j == n - 1) {
//             ++paths;
//             return;
//         }

//         allpaths(i + 0, j + 1);
//         allpaths(i + 1, j + 0);
//     }
// };