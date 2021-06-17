class Solution:
    def isNumber(self, s: str) -> bool:
        try:
            key=float(s)
            if 'inf' in s.lower():
                return False
            return True
        except:
            return False