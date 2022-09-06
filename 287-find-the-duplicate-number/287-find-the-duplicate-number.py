class Solution:
    '''
    each integer is in the range [1, n] inclusive, but we cannot modify the array
    so the element and the index cannot be in the correct place
    however if we jump from element to its index it will form a cycle since there is a duplicate
    hence we will take a slow and fast pointer
    '''
    def findDuplicate(self, nums: List[int]) -> int:
        slow = fast = nums[0]
        while True:
            slow, fast = nums[slow], nums[nums[fast]]
            if slow == fast:
                break
            
        slow = nums[0]
        while slow != fast:
            slow, fast = nums[slow], nums[fast]

        return slow