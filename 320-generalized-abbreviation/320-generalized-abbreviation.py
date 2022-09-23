class Solution:
    def generateAbbreviations(self, word: str) -> List[str]:
        def recurse(abb, next_idx, curr_count):
          if next_idx == len(word):
            if curr_count != 0:
              abb += str(curr_count)

            result.append(abb)
            return

          recurse(abb, next_idx + 1, curr_count + 1)

          if curr_count != 0:
            abb += str(curr_count)
          abb += word[next_idx]
          recurse(abb, next_idx + 1, 0)

        result = []
        recurse('', 0, 0)
        return result