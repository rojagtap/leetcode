---
problem_id: '3934'
platform: 'leetcode'
title: 'Smallest Unique Subarray'
difficulty: 'hard'
language: 'cpp'
aliases:
  - '3934-smallest-unique-subarray'
primary_tags:
  - '[[binary-search]]'
  - '[[hashmap]]'
subtle_tags:
  - '[[binary_search_on_answer_space]]'
candidate_tags:
  - '[[rolling_hash_substring_equality]]'
mistakes:
  - '[[wrong_path]]'
  - '[[knowledge_gap]]'
related:
  - '[[leetcode/3924-minimum-threshold-path-with-limited-heavy-edges/NOTES|3924-minimum-threshold-path-with-limited-heavy-edges]]'
  - '[[leetcode/3899-angles-of-a-triangle/NOTES|3899-angles-of-a-triangle]]'
---

## Explanations

The right framing is binary search on the length and a feasibility predicate "does some length-`k` subarray occur exactly once". Monotonicity: if any length-`k` subarray is unique, then extending it on either side preserves uniqueness (any longer subarray containing it inherits the surrounding context and stays unique under the lexicographic match definition). The solver named this directly in the comment: "if you find a subarray of length n that is unique, then you add anything to it, it will be unique" — clean `[[binary_search_on_answer_space]]` instance with the proof done at the keyboard.

The load-bearing piece is the inner predicate. With `n <= 1e5`, the predicate runs `O(log n)` times, so the budget per check is `O(n)` or `O(n log n)`. The natural first reach is "hash the length-`k` window as a string into an `unordered_map<string, int>` and look for a count of 1", which costs `O(k)` per hash and `O(nk)` per check — `O(n^2 log n)` overall, well above budget. The solver's comment shows they computed exactly this and still started implementing it ("in the interest of time"), pivoting only when the string serialization itself got awkward. Future-self trap: when the per-check budget is `O(n)` and the natural hash key is a length-`k` window, the textbook substitution is rolling hash, not string serialization.

Rolling hash sketches the predicate cleanly: precompute polynomial-prefix `hash[i+1] = hash[i] * base + (a[i] + 1)` and `power[i+1] = power[i] * base`, then `hash(l..r) = hash[r+1] - hash[l] * power[r-l+1]`. The `+1` shift on the encoded value avoids the `0`-vs-`(0,0)` collision (two distinct windows hashing to the same value because leading zeros do not change the polynomial result). With `base = 100001 > max(nums) + 1`, the construction is collision-resistant in practice for the given bounds, and the per-window operation collapses to `O(1)`. The solver named the underlying insight as "prefix arrays property... invertible i guess" — the same range-subtraction trick that makes prefix sums work, generalized to polynomial aggregation. That generalization is the `[[rolling_hash_substring_equality]]` candidate worth carrying forward.

Future-self trap: the implementation knowledge gap. The solver knew rolling hash conceptually ("i knew how those work in principle") but could not write the formula on the spot and lifted a reference template. The pattern to internalize is the pair `hash[r+1] - hash[l] * power[r-l+1]` and the `base > alphabet` invariant; without that, the binary-search-on-length frame is half-finished.

### Subtle Tags
- [[binary_search_on_answer_space]]: the answer is the smallest length `k` for which a unique length-`k` subarray exists; uniqueness is monotone in `k` (any superset of a unique subarray remains unique), so binary search the length and let the feasibility predicate carry the algorithmic load

### Candidate Tags
- [[rolling_hash_substring_equality]]: polynomial rolling hash with prefix-style invertibility gives `O(1)` substring-equality queries after `O(n)` preprocessing, mirroring the prefix-sum range trick on associative-and-invertible aggregation; the move when the natural hash key is "the length-`k` window" and the budget is tighter than `O(k)` per query

### Mistake Notes
- [[wrong_path]]: started implementing the string-serialization predicate despite having computed its `O(n^2 log n)` cost first; the comment "in the interest of time, i actually started implementing this solution to later realize that handling the string serialization is a bit tricky" preserves the slip
- [[knowledge_gap]]: rolling hash was known in principle but the prefix-hash + power-array formula was not in muscle memory ("i knew how those work in principle... but i didn't know how to implement it on the spot, so i took the standard rolling hash from gpt"); the binary-search-on-length frame fails without an `O(1)` substring-equality primitive

### Related Reasoning
- [[leetcode/3924-minimum-threshold-path-with-limited-heavy-edges/NOTES|3924-minimum-threshold-path-with-limited-heavy-edges]]: both show [[binary_search_on_answer_space]] with shared [[knowledge_gap]] on the inner-loop technique — there the missing tool was 0/1 BFS for shortest path on a 0/1-weighted graph, here it is rolling hash for `O(1)` substring equality; in both, the outer binary-search frame was self-derived and the feasibility check was the bottleneck
- [[leetcode/3899-angles-of-a-triangle/NOTES|3899-angles-of-a-triangle]]: both show [[binary_search_on_answer_space]] with shared [[knowledge_gap]] — the answer-axis monotonicity is the right framing in both, and in both the inner-step technique was reached for from an external reference rather than self-derived

### Signals
- block comment: `i quickly, intuitively figured out that this a binary search over a monotonic solution set`
- block comment: `"minimum possible length" was the hook for this i believe but i had to prove that this is monotonic`
- block comment: `proof too came pretty quickly that if you find a subarray of length n that is unique, then you add anything to it, it will be unique, so the solution space is monotonic, so binary search is approved`
- block comment: `now to the checks, i was considering having the subarray serialized to a string and then putting it to a hash map of counts. but each hashing operation itself is O(n), so total is O(n^2) which gives O(n^2 logn), mostly not acceptable not sure because it is not exactly n^2.`
- block comment: `in the interest of time, i actually started implementing this solution to later realize that handling the string serialization is a bit tricky.`
- block comment: `it clicked, rolling hash! i knew how those work in principle-- basically it has the property of prefix arrays (not sure what it's called, invertible i guess), but i didn't know how to implement it on the spot, so i took the standard rolling hash from gpt`
- rolling hash construction: `hash[i + 1] = hash[i] * base + (a[i] + 1); power[i + 1] = power[i] * base;` with `base = 100001`
- range query: `hash[r + 1] - hash[l] * power[r - l + 1]`
- feasibility predicate counts window-hash frequencies in an `unordered_map<ull, int>` and returns `true` if any count equals `1`
