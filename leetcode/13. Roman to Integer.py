# 13. Roman to Integer

# Example 1:

# Input: "III"
# Output: 3

# Example 2:

# Input: "IV"
# Output: 4

# Example 3:

# Input: "IX"
# Output: 9

# Example 4:

# Input: "LVIII"
# Output: 58
# Explanation: L = 50, V= 5, III = 3.

# Example 5:

# Input: "MCMXCIV"
# Output: 1994
# Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.

class Solution:
    def romanToInt(self, s):
        """
        :type s: str
        :rtype: int
        """
        dict = {"I":1,"V":5,"X":10,"L":50,"C":100,"D":500,"M":1000}
        mymap = {"I":1,"V":2,"X":3,"L":4,"C":5,"D":6,"M":7}
        
        res = 0
        i = 0
        while(i<len(s)):
            if(i+1<len(s)):
                if (mymap[s[i]]<mymap[s[i+1]]):
                    res = res + dict[s[i+1]] - dict[s[i]]
                    i = i + 2
                else:
                    res =res + dict[s[i]]
                    i = i + 1
            else:
                res =res + dict[s[i]]
                i = i + 1
            
        
        return res