---
problem_id: '3928'
platform: 'leetcode'
title: 'Minimum Cost to Buy Apples II'
difficulty: 'hard'
language: 'cpp'
aliases:
  - '3928-minimum-cost-to-buy-apples-ii'
primary_tags:
  - '[[dijkstra]]'
  - '[[graph-bfs]]'
subtle_tags:
  - '[[counterexample_disproof_pivot]]'
  - '[[constraint_driven_algorithm_choice]]'
candidate_tags: []
mistakes:
  - '[[knowledge_gap]]'
  - '[[wrong_path]]'
related:
  - '[[leetcode/3924-minimum-threshold-path-with-limited-heavy-edges/NOTES|3924-minimum-threshold-path-with-limited-heavy-edges]]'
---

## Explanations

The right shape is two single-source shortest-path runs from each starting shop: a forward run that accumulates `cost` (empty-trip outbound) and a backward run that accumulates `cost * tax` (loaded-trip return). The destination shop's contribution to `mincost[from]` is `prices[to] + forward[from][to] + backward[from][to]`. Forward and backward are run on the *same* graph but with different edge weights, so they are two independent Dijkstra calls per source; the `[[graph-bfs]]` tag is for the priority-queue traversal shape.

Future-self trap: this looks "all-pairs shortest path" because the answer is computed for every `from`. That triggers the Floyd–Warshall reflex, which is the pit the solver fell into. FW is `O(n^3)`. With `n = 1000`, that is `10^9` operations and times out cleanly. Dijkstra-from-each-source on a sparse graph is `O(n * (E + n) log n)`, and the constraint `roads.length <= min(n*(n-1)/2, 2000)` is the load-bearing fact: `E <= 2000` regardless of `n`, so the per-source cost is `~ 3000 log 1000 ~ 3e4`, and `n` runs is `~ 3e7`. The contest-time miss was not picking the right algorithm given the sparsity; the solver names the gap as something they "knew but forgot to apply".

The disproving counterexample chain in the block comment is worth retaining. The first FW attempt computed `forward` and `backward` matrices but never initialized self-distances `forward[v][v] = 0`, so for `prices = [4, 3], roads = []` the answer should be `[4, 3]` (no travel possible) but the code returned WA because `forward[v][v]` stayed at `LLONG_MAX` and the `min(prices[from], ...)` fallback was missing. The fix (set self-distances to zero, seed `mincost = prices`) repaired correctness but exposed the asymptotic problem. Two further FW variants in the block comment (folded `mincost` update inside the FW triple loop, then dropped self-edge initialization) only shaved constants and still TLE'd. The pivot to Dijkstra was the actual fix; the optimization spiral on FW is preserved as evidence that the wrong-asymptotic frame can absorb a lot of contest time before the algorithm choice is reconsidered.

Implementation note worth keeping: the AC version uses `priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>>` with the standard `if (dist > distance[curr]) continue;` lazy-skip after pop, which is the clean form that avoids `decrease-key`. The adjacency entries store both forward and backward weights as `tuple<int, long long, long long>` so a single graph build serves both runs and the lambda picks the right one via `isforward`.

### Subtle Tags
- [[counterexample_disproof_pivot]]: `prices = [4, 3], roads = []` directly disproved the no-self-loop FW invariant; the solver reproduces this case in the block comment as the WA-case witness, and uses it to fix self-distance init before discovering the deeper asymptotic problem
- [[constraint_driven_algorithm_choice]]: the right algorithm for "all-pairs shortest path" is determined by graph density, not by the all-pairs framing -- with `E <= 2000` and `n = 1000` the graph is sparse and Dijkstra-from-each-source dominates Floyd-Warshall asymptotically; the constraint that *bounds edge count* is the load-bearing fact

### Mistake Notes
- [[knowledge_gap]]: the sparse-vs-dense pivot was knowable from the constraint `roads.length <= min(n*(n-1)/2, 2000)` but did not surface during the contest; the solver's own diagnosis is `this was something i knew i guess but i forgot and couldn't apply`
- [[wrong_path]]: the entire FW attempt is preserved as commented-out code -- the first variant returned WA on the empty-roads counterexample, the second and third TLE'd despite mid-loop pruning and folded `mincost` updates. Each variant was disproved (WA, then TLE, then TLE) before being abandoned, so the failure mode is wrong-asymptotic frame, not the spiral shape of "right idea abandoned without disproving"

### Related Reasoning
- [[leetcode/3924-minimum-threshold-path-with-limited-heavy-edges/NOTES|3924-minimum-threshold-path-with-limited-heavy-edges]]: same biweekly contest, both share [[counterexample_disproof_pivot]] -- here `[4, 3], []` disproves "FW will work without self-distance init", in 3924 `[100, 1, 1, 1]` vs `[60, 60, 60]` disproves "minimax then skip k". Both also share [[knowledge_gap]] on choosing the right shortest-path inner loop (0/1 BFS there, multi-source Dijkstra here) under contest pressure

### Signals
- top-of-file block comment opens with the right framing then names the wrong choice: `my natural inclination was floyd-warshal's which i did implement. however it gave me TLE, so i did optimizations like combining the separate loop for mincost into the floyd warshal loop, eliminating the self edge loop, etc. but no luck. finally, i tried using dijkstra's and it worked`
- block comment records the constraint pivot: `roads.length <= min(n * (n - 1) / 2, 2000), so it's a sparse graph, a dense graph will have n^2 edges, which will be best solved by floyd warshal's but in this case dijkstra's wins. this was a bit atypical for a leetcode contest, but this was something i knew i guess but i forgot and couldn't apply`
- bottom-of-file block preserves the WA FW with the disproving input: `// wa, prices = [4,3], roads = []` (missing self-distance init)
- bottom-of-file block preserves the TLE FW chain: `// tle, for a big test case` and `// tle, prices = [1,1,1], roads = [[0,1,1000000000,100],[1,2,1000000000,100]]` -- both are FW variants that fix correctness but cannot beat `O(n^3)` at `n = 1000`
- AC structure: `vector<vector<tuple<int, long long, long long>>> adj` carries `(next, forward, backward)` per edge, single `dijkstra(source, isforward)` lambda, and `mincost[from] = min(mincost[from], prices[to] + forward[to] + backward[to])` over all `to`
