import math
class Solution:
    def successfulPairs(self, spells: list[int], potions: list[int], success: int) -> list[int]:
        potions_quantity = len(potions)
        sorted_potions = sorted(potions)
        successful_pairs = []
        for spell in spells:
            min_potion_strength = math.ceil(success / spell)
            if sorted_potions[0] >= min_potion_strength:
                successful_pairs.append(potions_quantity)
                continue
            if sorted_potions[-1] < min_potion_strength:
                successful_pairs.append(0)
                continue
            left = 0
            right = potions_quantity - 1
            mid = right // 2
            print(left, right)
            while left != right:
                if sorted_potions[mid] < min_potion_strength:
                    left = mid + 1
                else:
                    right = mid
                mid = (left + right) // 2
            successful_pairs.append(potions_quantity - right)
        return successful_pairs