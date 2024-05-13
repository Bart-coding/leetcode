class Solution:
    def minFlips(self, a: int, b: int, c: int) -> int:
        flips = 0
        while a or b or c:
            a_bit = a & 1
            b_bit = b & 1
            c_bit = c & 1
            if a_bit != b_bit:
                flips += int(not c_bit)
            elif a_bit == 0:
                flips += c_bit
            else:
                flips += 2 * int(not c_bit)
            a >>= 1
            b >>= 1
            c >>= 1
        return flips