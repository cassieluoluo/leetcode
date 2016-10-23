public class Solution {
	public IList<IList<int>> ThreeSum(int[] nums) {
		IList<IList<int>> res = new List<IList<int>>();
		int len = nums.Length;
		if (len < 3) return res;
		Array.Sort(nums);
		for (int i = 0; i < len - 1; i++) {
			if (i > 0 && nums[i] == nums[i - 1]) continue;
			int j = i + 1, k = len - 1;
			while (j < k) {
				int s = nums[i] + nums[j] + nums[k];
				if (s == 0) {
					List<int> t = new List<int>{nums[i], nums[j], nums[k]};
					res.Add(t);
					++j; --k;
					while (j < k && nums[j] == nums[j - 1]) ++j;
					while (j < k && nums[k] == nums[k + 1]) --k;
				} else if (s < 0) ++j;
				else --k;
			}
		}
		return res;
	}
} // Author: XC
