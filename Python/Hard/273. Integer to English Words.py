# https://leetcode.com/problems/integer-to-english-words/description/

less_then_20 = [
    "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten",
    "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen",
    "Eighteen", "Nineteen"]

teens = ["Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"]


def helper(num):
    result = ""
    if num >= 100:
        result += less_then_20[num // 100 - 1] + " " + "Hundred "
        num %= 100

    if num >= 20:
        result += teens[num // 10 - 2] + " "
        num %= 10
    if num > 0:
        result += less_then_20[num - 1] + " "
        return result
    return result


def generate_words(num):
    result = ""
    thirds = []
    big_nums = ["", "Thousand ", "Million ", "Billion "]
    while num:
        thirds.append(helper(num % 1000))
        num //= 1000
    for i in range(len(thirds) - 1, -1, -1):
        if thirds[i]:
            result += thirds[i] + big_nums[i]
    return result


class Solution:
    def numberToWords(self, num: int) -> str:
        if num == 0:
            return "Zero"
        return generate_words(num)[:-1]
