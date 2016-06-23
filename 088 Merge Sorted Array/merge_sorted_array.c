void merge(int* nums1, int m, int* nums2, int n) {
	int p = m + n - 1; m--; n--;
	while (m >= 0 && n >= 0) 
		nums1[p--] = nums1[m] > nums2[n] ? nums1[m--] : nums2[n--];
	if (m < 0) 
		for (; n >= 0; n--, p--) nums1[p] = nums2[n];
}   // Author: Xinyu Chen