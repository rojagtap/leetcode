class Solution:
    def get_failure_function(self, needle):
        i, j, n = 1, 0, len(needle)
        failureFunction = [0] * len(needle)
        while i < n:
            if needle[j] == needle[i]:
                failureFunction[i] = j + 1
                i += 1
                j += 1
            elif needle[j] != needle[i] and j > 0:
                j = failureFunction[j - 1]
            else:
                failureFunction[i] = 0
                i += 1

        return failureFunction

    def KMP(self, failureFunction, haystack, needle):
        i, j, = 0, 0
        n, m = len(haystack), len(needle)

        while i < n and j < m:
            if haystack[i] == needle[j]:
                i += 1
                j += 1
            
            if j == m:
                return i - j
            elif i < n and j < m and haystack[i] != needle[j]:
                if j != 0:
                    j = failureFunction[j - 1]
                else:
                    i += 1

        return -1
    
    
    def strStr(self, haystack: str, needle: str) -> int:
        failureFunction = self.get_failure_function(needle)
        
        return self.KMP(failureFunction, haystack, needle);
        