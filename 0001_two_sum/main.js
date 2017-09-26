/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function(nums, target) {
	var mapping = {};
	var ret = [];

	nums.forEach(function(num, index, nums) {
		mapping[target - num] = index;
	});

	nums.some(function(num, index, nums) {
		if (mapping.hasOwnProperty(num) && mapping[num] != index) {
			ret = [index, mapping[num]];
			return true;
		}
	}, this);

	return ret;
};
