class Solution:
    def countAndSay(self, n: int) -> str:
        s  = "1"
        if n==1: return s
        for i in range(1,n):
            count = 0
            prev = "nill"
            out = ""
            for j in s:
                count += 1
                if prev=="nill":
                    prev = j
                elif prev != j:
                    out += str(count-1)
                    out += prev
                    count = 1
                    prev = j
            out += str(count)
            out += prev
            count = 0
            prev = "nill"
            s = out
            out = ""
        return s
