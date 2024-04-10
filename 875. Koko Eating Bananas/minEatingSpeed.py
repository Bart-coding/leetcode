import math
class Solution:
    def minEatingSpeed(self, piles: list[int], h: int) -> int:
        if len(piles) == h:
            return max(piles)
        
        def acceptable_speed(speed) -> bool:
            hours_sum = 0
            for pile in piles:
                hours_sum += math.ceil(pile / speed)
            return hours_sum <= h
        
        min_speed = math.ceil(sum(piles) / h)
        max_speed = max(piles)
        while min_speed < max_speed:
            mid_speed = (min_speed + max_speed) // 2
            if acceptable_speed(mid_speed):
                max_speed = mid_speed
            else:
                min_speed = mid_speed + 1
        return min_speed