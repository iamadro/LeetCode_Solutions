class Solution:
    def shuffle(self, nums: List[int], n: int) -> List[int]:
        # mid = n // 2
        ans = [0] * (n * 2)
        j = 0
        for i in range(0, 2 * n - 1, 2):
            ans[i] = nums[j]
            ans[i+1] = nums[n + j]
            j += 1
        return ans