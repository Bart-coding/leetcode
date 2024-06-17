class Solution:
    def eraseOverlapIntervals(self, intervals: List[List[int]]) -> int:
        intervals.sort(key=lambda x: x[0])
        erase_count = 0
        i = 0
        j = 1
        while j < len(intervals):
            if intervals[i][1] > intervals[j][0]:
                erase_count += 1
                if intervals[i][1] >= intervals[j][1]:
                    i = j
            else:
                i = j
            j += 1
        return erase_count