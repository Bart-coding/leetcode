class Solution:
    def compress(self, chars: List[str]) -> int:
        i = 0
        insert_index = 0
        def get_digit(number, n: int) -> str:
            return str(number // 10**n % 10)
        while i < len(chars):
            ch = chars[i]
            j = i
            while j < len(chars) and chars[j] == ch:
                j += 1
            chars[insert_index] = ch
            insert_index += 1
            num_of_ch = j - i
            if num_of_ch > 1 and num_of_ch < 10:
                chars[insert_index] = str(num_of_ch)
                insert_index += 1
            elif num_of_ch >= 10:
                for d in range(len(str(num_of_ch)) - 1, -1, -1):
                    chars[insert_index] = get_digit(num_of_ch, d)
                    insert_index += 1
            i = j
        return insert_index