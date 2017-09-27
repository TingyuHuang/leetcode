class Solution {
	public:
		double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
			std::remove_reference<decltype(nums1)>::type nums;
			auto it1 = nums1.begin();
			auto it2 = nums2.begin();

			while (nums.size() <= ((nums1.size() + nums2.size()) / 2.0)) {
				if (nums1.end() == it1) {
					nums.push_back(*it2++);
				} else if (nums2.end() == it2) {
					nums.push_back(*it1++);
				} else if (*it1 <= *it2) {
					nums.push_back(*it1++);
				} else {
					nums.push_back(*it2++);
				}
			}

			if ((nums1.size() + nums2.size()) % 2 == 0) {
				return (nums[nums.size() - 2] + nums[nums.size() - 1]) / 2.0;
			} else {
				return nums.back();
			}
		}
};
