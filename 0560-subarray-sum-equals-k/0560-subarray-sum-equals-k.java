class Solution {
    public int subarraySum(int[] nums, int k) {
        Map<Integer, Integer> freq = new HashMap<>();
        freq.put(0, 1);
        
        int count = 0;
        int runningSum = 0;
        for (int num : nums) {
            runningSum += num;
            count += freq.getOrDefault(runningSum - k, 0);
            freq.put(runningSum, freq.getOrDefault(runningSum, 0) + 1);
            
        }
        
        return count;
    }
}
