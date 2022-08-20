class Solution:
    def isAlienSorted(self, words: List[str], order: str) -> bool:
        wordlen = len(words)
        ordermap = {order[i]: i for i in range(len(order))}
        
        lengths = [len(word) for word in words]
        
        
        for i in range(wordlen - 1):
            for l in range(lengths[i]):
                if l == lengths[i + 1] or ordermap[words[i][l]] > ordermap[words[i + 1][l]]:
                    return False
                if ordermap[words[i][l]] < ordermap[words[i + 1][l]]:
                    break
                
        return True