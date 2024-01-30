/**
 * @param {number[]} nums
 * @return {number}
 */
var longestSubarray = function(nums) {
    if (nums.length === 1) return 0;
    let start = 0, end = 0;
    let maxSum = 0;
    let zeroes = 0;
    for (end; end < nums.length; ++end) {
        if (nums[end] === 0) ++zeroes;
        if (zeroes > 1 && nums[start++] === 0) --zeroes;
        if (zeroes <= 1 && maxSum < end - start + 1) maxSum = end - start + 1;
    }
    return maxSum - 1;
};