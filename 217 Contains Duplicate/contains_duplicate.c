/*	
 *	LeetCode Submissions by Xinyu Chen
 *	Contains Duplicate
 *	https://leetcode.com/problems/contains-duplicate/
 *	Runtime: 12 ms
 */
 
int cmp(const void* a, const void* b) {
	int x = *(int*)a;
	int y = *(int*)b;
	if (x > y) return 1;
	else return x == y ? 0 : -1;
}
bool containsDuplicate(int* nums, int numsSize) {
	qsort(nums, numsSize, sizeof(int), cmp);
	for (int i = 1; i < numsSize; i++) {
		if (nums[i - 1] == nums[i]) return true;
	}
	return false;
}
};