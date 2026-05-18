---
problem_id: '3925'
platform: 'leetcode'
title: 'Concatenate Array With Reverse'
difficulty: 'easy'
language: 'cpp'
aliases:
  - '3925-concatenate-array-with-reverse'
primary_tags:
  - '[[simulation]]'
subtle_tags: []
candidate_tags: []
mistakes: []
related: []
---

## Explanations

`no_signal`. Single pass writes `ans[i] = nums[i]` and `ans[i + n] = nums[n - i - 1]` together so the reversed half is filled without a second loop or a `reverse` call. Constraints (`n <= 100`) make the tradeoff irrelevant; the contest reflex of "fuse both writes in one index" is the only thing the file shows. No comments, no commented-out code, no friction. Recorded only so the canonical [[simulation]] pattern stays linked.

### Signals
- single-loop fused write: `ans[i] = nums[i]; ans[i + n] = nums[n - i - 1];` covers both halves in one pass without an explicit reverse step
