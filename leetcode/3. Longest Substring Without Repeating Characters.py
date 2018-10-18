# 3. Longest Substring Without Repeating Characters

# Example 1:

# Input: "abcabcbb"
# Output: 3 
# Explanation: The answer is "abc", with the length of 3. 

# Example 2:

# Input: "bbbbb"
# Output: 1
# Explanation: The answer is "b", with the length of 1.

# Example 3:

# Input: "pwwkew"
# Output: 3
# Explanation: The answer is "wke", with the length of 3. 
#              Note that the answer must be a substring, "pwke" is a subsequence and not a substring.



class Solution:
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        mymap = dict() # store index of char
        res = 0               
        last_dup_char=0
        curr=0        
        
        while(curr < len(s)):
            if s[curr] in mymap:
                last_dup_char = max(mymap[s[curr]],last_dup_char)
            res = max(res, curr-last_dup_char+1)
            mymap[s[curr]] = curr+1
            curr += 1        
     
        return res