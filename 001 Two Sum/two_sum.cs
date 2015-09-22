/*	
 *	LeetCode Submissions by Xinyu Chen
 *	Two Sum
 *	https://leetcode.com/problems/two-sum/
 *	Runtime: 480 ms
 */

public int[] TwoSum(int[] nums, int target)
{
    var map = new Dictionary<int, int>();
    for (var i = 0; i < nums.Length; i++)
    {
		if (map.ContainsKey(nums[i]))
		{
			var j = map[nums[i]] + 1;
			i++;
			var result = new int[2];
			result[0] = i < j ? i : j;
			result[1] = i < j ? j : i;
			return result;
		}
		else
		{
			var diff = target - nums[i];
			if (!map.ContainsKey(diff))	map.Add(target - nums[i], i);
		}
    }
    return null;
}