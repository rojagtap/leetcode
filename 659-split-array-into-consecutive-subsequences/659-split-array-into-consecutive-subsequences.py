class Solution:
    '''
    O(n), O(n)
    
    For any given element in the array, there are 2 options:
    1. Add to an existing subsequence if possible
    2. Start a new subsequence
    
    So we need 2 pieces of info to work:
    1. A way to store exisitng subsequences
    2. A way to check if a new subsequence is possible with the given element
    
    Let's see how we can store subsequences
    We can ofcourse have a list of list for the subseqs. But do we really need it?
    We can have the first and last element only in the list. Do we really need the first one?
    We can only have the last element of the subsequence and since there can be multiple occurrences of that element and thus, multiple subsequences can end with a given element, we can keep a count
        Thus, a map of last element of the subsequence v/s the count of subsequences with that last element
        So if one wants to extend this subsequence, we can simply decrement the count for this and increment the count for the next number. For example, say the map is {..., 3: 2, 4: 1, ...} and I want to extend one of the subsequence ending in 3, then I will update the map to {..., 3: 1, 4: 2, ...}
        
    Next is starting a new subseq
    Since it is given that the subseq should have only consecutive numbers and should have min length 3, we can check if for a given num, num + 1 and num + 2 are present in the array
        The best way for this is hashing (fetch is O(1))
        We can use a set but there may be multiple instances of the same number in the array which will be ignored in the set and we won't be able to use that number in a different subsequence even if it is available
        For this we can have a freq table with number v/s count in the array
        We can reduce the count every time the number is used in a subsequence
    
    
    So we follow these steps:
    
    For all elements in the array, first construct a frequency table
    
    For all num in the array
        If the frequency of num is 0, it means all the instances of the number are already in a subsequence so ignore
        If frequency is > 0 and there exists a subsequence with (num - 1) as the last element, then we extend it by updating the map as explained above
        If frequency is > 0 and there is no subsequence present, then create a new subsequence given that num + 1 and num + 2 are present in the array. Update the freq and subseq maps accordingly
        If frequency is > 0, but none of the subsequence or the next 2 consecutive numbers are present, then a subsequence is not possible, so return false
        
    
    Note that it won't ever happen that you add a number to a subsequence, and later another subsequence was possible starting with that number and now your function will return false since that subsequence could not be created
    This is because while creating a new subsequence we are checking and using the next 2 consecutive numbers beforehand so all the numbers possible will be probed at least once
    '''
    def isPossible(self, nums: List[int]) -> bool:
        freq = dict()
        subseq = dict()
        
        for num in nums:
            freq[num] = freq.get(num, 0) + 1
            
        for num in nums:
            if freq.get(num, 0) == 0:
                continue
                
            if subseq.get(num - 1, 0) > 0:
                subseq[num] = subseq.get(num, 0) + 1
                subseq[num - 1] -= 1
                freq[num] -= 1
            elif freq.get(num + 1, 0) > 0 and freq.get(num + 2, 0) > 0:
                subseq[num + 2] = subseq.get(num + 2, 0) + 1
                freq[num] -= 1
                freq[num + 1] -= 1
                freq[num + 2] -= 1
            else:
                return False
            
        return True