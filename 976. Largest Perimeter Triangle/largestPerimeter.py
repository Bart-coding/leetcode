from heapq import heapify, heappush, heappop

class Solution:
    def largestPerimeter(self, nums: List[int]) -> int:
        sidelengths_heap = []
        heapq.heapify(sidelengths_heap)

        for num in nums:
            heapq.heappush(sidelengths_heap, -1 * num)

        c = -1 * heapq.heappop(sidelengths_heap)
        b = -1 * heapq.heappop(sidelengths_heap)
        a = -1 * heapq.heappop(sidelengths_heap)

        while sidelengths_heap:
            if a + b > c:
                return a + b + c
            else:
                c = b
                b = a
                a = -1 * heapq.heappop(sidelengths_heap)
        
        if a + b > c:
            return a + b + c
        else:
            return 0