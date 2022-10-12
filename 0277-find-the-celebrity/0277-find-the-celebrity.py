# The knows API is already defined for you.
# return a bool, whether a knows b
# def knows(a: int, b: int) -> bool:

'''
1. Start from 0 and check if it 'knows' anyone from 1 to n. If yes, then it means it cannot be a celebrity.
2. Now start with the 'person' 0 'knows' and check if they 'know' the rest of the 'people'
3. Finally, check if the 'person' who does not 'know' the rest of the 'people' is not 'known' by anyone and if 'they' don't 'know' anyone in a separate loop. If this is true, this 'person' is the celebrity

Corner cases:

Scenario 1: if 0 doesn't 'know' 1-4 and 'knows' 5, but 5 'knows' just 1 and no one else
-> This won't be a problem because 5 'knows' 1 will be covered in the second iteration where we are checking both

Scenario 2: if 0 doesn't 'know' 1-4 and 'know' 5, but 1 knows no one
-> 1 might look like a potential candidate at first but 0 doesn't 'know' 1 so anyway it isn't a celebrity

Scenario 3: After the first loop we find that 'n - 1' is the only candidate left, rest everyone 'knows' someone, even 'n - 1' knows say, 2 but that wasn't covered in the loop because we only look ahead.
-> This will be same as Scenario 1, i.e., it will be covered in the second loop
'''

class Solution:
    # O(n), O(n)
    def findCelebrity(self, n: int) -> int:   
        @lru_cache(maxsize=None)
        def _knows(a, b):
            return knows(a, b)
            
        candidate = 0
        for person in range(1, n):
            if _knows(candidate, person):
                candidate = person
        
        for person in range(n):
            if person == candidate:
                continue
            
            if _knows(candidate, person) or not _knows(person, candidate):
                return -1
        
        return candidate