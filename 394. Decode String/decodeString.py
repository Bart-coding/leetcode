class Solution:
    def decodeString(self, s: str) -> str:
        decoded_string = []
        for ch in s:
            if ch != ']':
                decoded_string.append(ch)
            else:
                encoded_substring = []
                stack_ch = decoded_string.pop()
                while stack_ch != '[':
                    encoded_substring.append(stack_ch)
                    stack_ch = decoded_string.pop()
                encoded_substring.reverse()
                k_digits = [decoded_string.pop()]
                while decoded_string and decoded_string[-1].isdigit():
                    k_digits.append(decoded_string.pop())
                k_digits.reverse()
                k = int("".join(k_digits))
                decoded_substring = k * encoded_substring
                decoded_string.extend(decoded_substring)
        return "".join(decoded_string)