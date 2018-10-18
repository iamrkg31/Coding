# 20. Valid Parentheses

# Example 1:

# Input: "()"
# Output: true

# Example 2:

# Input: "()[]{}"
# Output: true

# Example 3:

# Input: "(]"
# Output: false

# Example 4:

# Input: "([)]"
# Output: false

# Example 5:

# Input: "{[]}"
# Output: true

class Solution:
    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """
        _stack = []
        for i in s:
            if not _stack:
                _stack.append(i)
            elif(_stack[-1]=="(" and i==")"): 
                _stack.pop()
            elif(_stack[-1]=="{" and i=="}"): 
                _stack.pop()
            elif(_stack[-1]=="[" and i=="]"): 
                _stack.pop()
            else:
                _stack.append(i) 
 
        if _stack:
            return False
        else:
            return True