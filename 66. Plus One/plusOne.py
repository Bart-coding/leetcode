class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        if digits[-1] != 9:
            digits[-1] += 1
            return digits
        return [
            int(digit)
            for digit in str(int("".join(str(digit) for digit in digits)) + 1)
        ]