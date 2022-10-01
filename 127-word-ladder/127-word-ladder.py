class Solution:
    def ladderLength(self, beginWord: str, endWord: str, wordList: List[str]) -> int:
        def diff(word1, word2):
            i = j = count = 0
            while i < len(word1) and j < len(word2):
                if word1[i] != word2[j]:
                    count += 1
                    
                i += 1
                j += 1
            
            return count
        
        if endWord not in wordList:
            return 0
        
        adjacency = defaultdict(set)
        for i in range(len(wordList)):
            word = wordList[i]
            for j in range(len(word)):
                adjacency[word[:j] + '_' + word[j + 1:]].add((word, i))
            
        closest_to_begin = set()
        for i in range(len(beginWord)):
            closest_to_begin = closest_to_begin.union(adjacency[beginWord[:i] + '_' + beginWord[i + 1:]])
                
        if not closest_to_begin:
            return 0
        
        distance = 1
        idx = wordList.index(endWord)
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
        
        
        