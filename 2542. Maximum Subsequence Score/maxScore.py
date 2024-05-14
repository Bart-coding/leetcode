class Solution:
    def maxScore(self, nums1: List[int], nums2: List[int], k: int) -> int:
        sorted_pairs = sorted(zip(nums1, nums2), key=itemgetter(1), reverse=True)
        priority_queue = []
        queue_sum = 0
        for i in range(k):
            queue_sum += sorted_pairs[i][0]
            heappush(priority_queue, sorted_pairs[i][0])
        max_score = queue_sum * sorted_pairs[k - 1][1]
        for i in range(k, len(sorted_pairs)):
            queue_min = heappop(priority_queue)
            queue_sum -= queue_min
            heappush(priority_queue, sorted_pairs[i][0])
            queue_sum += sorted_pairs[i][0]
            max_score = max(max_score, queue_sum * sorted_pairs[i][1])
        return max_score