class Solution:
    def findMaxConsecutiveOnes(self, nums: List[int]) -> int:
        maxCount, count = 0, 0
        for num in nums:
            if num == 1:
                count += 1
            else:
                maxCount = count if maxCount < count else maxCount
                count = 0
        maxCount = count if maxCount < count else maxCount

        return maxCount            