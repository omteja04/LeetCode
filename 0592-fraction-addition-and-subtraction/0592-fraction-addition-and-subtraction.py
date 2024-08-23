from fractions import Fraction
class Solution:
    def fractionAddition(self, exp: str) -> str:
        result = Fraction(0, 1)
        i = 0
        n = len(exp)
        while i < n:
            sign = 1
            if exp[i] == '-':
                sign = -1
                i += 1
            elif exp[i] == '+':
                i += 1
            
            j = i
            while j < n and exp[j].isdigit():
                j += 1
            numerator = sign*int(exp[i:j])

            i = j + 1
            j = i

            while j < n and exp[j].isdigit():
                j += 1
            denominator = int(exp[i:j])

            result += Fraction(numerator, denominator)

            i = j
        return str(result.numerator) + "/" + str(result.denominator)





        