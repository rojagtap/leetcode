---
problem_id: '3926'
platform: 'leetcode'
title: 'Count Valid Word Occurrences'
difficulty: 'medium'
language: 'cpp'
aliases:
  - '3926-count-valid-word-occurrences'
primary_tags:
  - '[[simulation]]'
  - '[[hashmap]]'
subtle_tags: []
candidate_tags: []
mistakes: []
related: []
---

## Explanations

`no_signal`. Concatenate `chunks` into `s`, walk once with a separator predicate that defaults to `sep = true` and clears in two cases: alphabetic char, or hyphen with `isalpha(s[i-1]) && isalpha(s[i+1])`. On separator, flush the current `word` into the count map if non-empty and reset; otherwise append. After the loop, one more flush for the trailing word. Then map each query to its count. The hyphen rule is the only place that needs care, and the source already states it directly with the both-sides-alpha guard plus the explicit `i > 0 && i < n - 1` bounds check, so the boundary is never accessed unsafely. The trailing flush is the only "did I forget the last word" trap, and it is present. No comments, no commented-out code, no contest friction in the source.

### Signals
- hyphen acceptance requires alpha on both sides, gated by `i > 0 && isalpha(s[i - 1]) && i < n - 1 && isalpha(s[i + 1])` so the lookahead/lookbehind is bound-checked before the alpha test
- post-loop `if (word.size()) ++dict[word];` flushes the trailing token without a sentinel
