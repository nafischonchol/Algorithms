// contiguous array sum
// Kadane's Algorithm
// Leet Code : 53. Maximum Subarray

using System;
class Program
{
    static int maxSubArraySum(int []nums)
    {
        int maxSum = int.MinValue;
        int sum = 0;
        for(int i=0;i<nums.Length;i++)
        {
            sum = nums[i] + sum;
            if(sum > maxSum)
                maxSum = sum;
            if(sum < 0 )
            {
                sum = 0;
            }
        }
        return maxSum;
    }
     
    public static void Main ()
    {
        int [] nums = {-2, -3, 4, -1, -2, 1, 5, -3};
        Console.Write("Maximum contiguous sum is " + maxSubArraySum(nums));
    }
 
}
