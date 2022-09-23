class Solution:
  def letterCasePermutation(self, s: str) -> List[str]:
    permutations = []
    permutations.append(s)
    # process every character of the string one by one
    for i in range(len(s)):
      if s[i].isalpha():  # only process characters, skip digits
        # we will take all existing permutations and change the letter case appropriately
        n = len(permutations)
        for j in range(n):
          chs = list(permutations[j])
          # if the current character is in upper case, change it to lower case or vice versa
          chs[i] = chs[i].swapcase()
          permutations.append(''.join(chs))

    return permutations
        