class Solution:
    def findMinArrowShots(self, points: list[list[int]]) -> int:
        if len(points) == 1:
            return 1
        points.sort()
        min_arrows = 1
        prev_arrow_max_x = points[0][1]
        for i in range(1, len(points)):
            if points[i][0] > prev_arrow_max_x:
                min_arrows += 1
                prev_arrow_max_x = points[i][1]
            else:
                prev_arrow_max_x = min(prev_arrow_max_x, points[i][1])
        return min_arrows