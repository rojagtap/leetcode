class Solution:
    # O(k2n), O(k2n) where k is number of chars and n is number of words
    def ladderLength(self, beginWord: str, endWord: str, wordList: List[str]) -> int:        
        if endWord not in wordList:
            return 0
        
        adjacency = defaultdict(set)
        for i in range(len(wordList)):
            word = wordList[i]
            for j in range(len(word)):
                # we can ofcourse go O(n2) but acc to constraints:
                # 1 <= wordList.length <= 5000 and 1 <= beginWord.length <= 10
                # so k2 is better
                adjacency[word[:j] + '_' + word[j + 1:]].add((word, i))
            
        closest_to_begin = set()
        for i in range(len(beginWord)):
            closest_to_begin = closest_to_begin.union(adjacency[beginWord[:i] + '_' + beginWord[i + 1:]])
                
        if not closest_to_begin:
            return 0
        
        idx = wordList.index(endWord)
        
        distance = 1
        queue = deque([(endWord, idx)])
        visited = [False] * len(wordList)
        visited[idx] = True
        while queue:
            distance += 1
            for _ in range(len(queue)):
                word, idx = queue.popleft()
                if (word, idx) in closest_to_begin:
                    return distance
                
                for i in range(len(word)):
                    for nextword, nextidx in adjacency[word[:i] + '_' + word[i + 1:]]:
                        if not visited[nextidx]:
                            visited[nextidx] = True
                            queue.append((nextword, nextidx))
            
        return 0
        
        
        