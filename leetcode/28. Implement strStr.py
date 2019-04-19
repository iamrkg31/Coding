class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        if not needle:
            return 0
        i = 0
        j = 0
        index = -1
        while (True):
            if j > len(needle) - 1: return index
            if i > len(haystack) - 1: return index
            if (len(needle) - j - 1 > len(haystack) - i - 1):
                return -1
            if (haystack[i] == needle[j]):
                if index == -1:
                    index = i
                i += 1
                j += 1
            elif index == -1:
                i += 1
            else:
                i = index + 1
                j = 0
                index = -1
        return index