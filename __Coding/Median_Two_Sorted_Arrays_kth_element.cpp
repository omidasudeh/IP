/*
leetcode: median of two sorted array (hard)
time:

There are two sorted arrays nums1 and nums2 of size m and n respectively.
Find the median of the two sorted arrays. 
The overall run time complexity should be O(log (m+n)).
You may assume nums1 and nums2 cannot be both empty.

Example 1:
nums1 = [1, 3]
nums2 = [2]
The median is 2.0

Example 2:
nums1 = [1, 2]
nums2 = [3, 4]
The median is (2 + 3)/2 = 2.5
*/

/*
Solution2:

Let me add some interpretation of the find kth function based on my understanding
We have two arrays:
nums1[0], nums1[1]....nums1[m - 1];
nums2[0], nums2[2]....nums2[n - 1];

the result after merging:
num[0],num[1],num[2]...num[m + n - 1];

Let‘s compare nums1[k / 2 - 1] and nums2[k / 2 - 1]
if nums1[k / 2 - 1] < nums2 [k / 2 - 1]
then the nums1[k / 2 - 1] and it's left side elements must smaller than kth number in num arrary(num[k - 1]).
Why?
Assume that nums1[k / 2 - 1] == num[k - 1];

Let's count the number of elements which smaller than nums1[k / 2 - 1].

Consider an extreme case : nums1[0]....nums1[k / 2 - 2] and nums2[0]...nums2[k / 2 - 2] smaller than nums1[k / 2 - 1];

In this special case, we only have k / 2 - 1 + k / 2 - 1 = k - 2 elements smaller than the nums1[k / 2 - 1]. so nums1[k / 2 - 1] only can be (k - 1)th smallest number (num[k - 2]);
So, it's a contradiction with our assumption.

And now we could say, The num[k / 2 - 1] and it's left side elements must smaller than the Kth smallest number.
so we could remove the elements which in this range and shrink the problem set.
same idea when nums1[k / 2 - 1] > nums2 [k / 2 - 1]. we could remove the elements in the nums2;

*/
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
	int m = nums1.size(), n = nums2.size();
	int k = (m + n) / 2;
	int num1 = findKth(nums1, 0, m, nums2, 0, n, k + 1);
	if ((n + m) % 2 == 0)
	{
		int num2 = findKth(nums1, 0, m, nums2, 0, n, k);
		return (num1 + num2) / 2.0;
	}
	else return num1;
}
int findKth(vector<int> & nums1, int l1, int r1, vector<int> & nums2, int l2, int r2, int k)
{
	int m = r1 - l1;
	int n = r2 - l2;
	if (m > n) return findKth(nums2, l2, r2, nums1, l1, r1, k);
	else if (m == 0)
		return nums2[l2 + k - 1];
	else if (k == 1)
		return min(nums1[l1], nums2[l2]);
	else {
		int k1 = min (k / 2, m);
		int k2 = k - k1;
		if (nums1[l1 + k1 - 1] == nums2[l2 + k2 - 1])
			return nums1[l1 + k1 - 1];
		else if (nums1[l1 + k1 - 1] < nums2[l2 + k2 - 1])
			return findKth(nums1, l1 + k1, r1, nums2, l2, r2, k - k1);
		else
		return findKth(nums1, l1, r1, nums2, l2 + k2, r2, k - k2);
	}
}

