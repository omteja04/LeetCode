class Solution:
    def countConsistentStrings(self, allowed: str, words: List[str]) -> int:
        cnt = len(words)
        for string in words:
            for char in string:
                if char not in allowed:
                    cnt -= 1
                    break
                
        return cnt