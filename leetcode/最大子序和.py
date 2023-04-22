def maxSubArray(nums):
    n = len(nums)
    dp = [0] * n
    dp[0] = nums[0]
    for i in range(1, n):
        dp[i] = max(dp[i-1] + nums[i], nums[i])
    return max(dp)

if __name__ == '__main__':
    s = input()
    lis = [int(_) for _ in s.split(" ")]
    print(maxSubArray(lis))