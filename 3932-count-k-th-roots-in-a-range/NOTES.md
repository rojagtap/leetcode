---
problem_id: '3932'
platform: 'leetcode'
title: 'Count K-th Roots in a Range'
difficulty: 'medium'
language: 'cpp'
aliases:
  - '3932-count-k-th-roots-in-a-range'
primary_tags:
  - '[[math]]'
  - '[[complete-search]]'
subtle_tags: []
candidate_tags:
  - '[[constraint_driven_algorithm_choice]]'
mistakes: []
related:
  - '[[leetcode/3927-minimize-array-sum-using-divisible-replacements/NOTES|3927-minimize-array-sum-using-divisible-replacements]]'
---

## Explanations

The framing trap is "search the value range `[l, r]` for `k`-th powers", which suggests sieve-style work over up to `1e9` integers. The actual axis to iterate is the base `x`, not the power `y`: `y = x^k` grows so fast that for `k = 30` only `x <= 1` produces `y <= 1e9`, and for `k = 2` the bound is `x <= sqrt(1e9) ~ 31623`. Iterating `x` upward with early break on `y > r` is `O(r^(1/k))` per query, which dominates any sieve over `[l, r]`. The solver named the same reasoning shape: considered sieve given the constraints, then concluded "the bruteforce works well and i think is the only working solution" — same `[[constraint_driven_algorithm_choice]]` pattern as `[[leetcode/3927-minimize-array-sum-using-divisible-replacements/NOTES|3927-minimize-array-sum-using-divisible-replacements]]`, where the value-range cap selected sieve over factor enumeration; here the joint constraint on `k` and `r` selects bounded-base iteration over a sieve.

The visible loop bound `for (int i = 0; i <= r; ++i)` is misleadingly large — the `if (y > r) break;` is what actually terminates iteration. `pow(i, k)` is computed in `double` and stored to `long long`, which is safe here because the early break fires well before any precision-relevant magnitude.

Mid-solve slip: the solver initially constrained the iterator `x` to `[l, r]` ("i took x and y both between l and r, but only y is between l and r"). This is a problem-statement read, not a representation choice: the range `[l, r]` applies to the *output* `y`, not the *iterator* `x`. Caught fast and patched by sweeping `x` from `0` and filtering on `y in [l, r]`. Not material enough for a mistake tag.

### Candidate Tags
- [[constraint_driven_algorithm_choice]]: `k <= 30` joint with `y <= 1e9` bounds the iteration axis to `x <= r^(1/k)`; the constraint is what makes bounded-base bruteforce optimal rather than a sieve over `[l, r]`

### Related Reasoning
- [[leetcode/3927-minimize-array-sum-using-divisible-replacements/NOTES|3927-minimize-array-sum-using-divisible-replacements]]: both show [[constraint_driven_algorithm_choice]] on value-range bounds — 3927's `nums[i] <= 1e5` selects sieve over factor enumeration, 3932's joint `k`-and-`r` bound selects bounded-base iteration over a sieve; the constraint is the load-bearing fact in both

### Signals
- block comment: `i had no problems arriving at a solution here, simple bruteforce`
- block comment: `i also spent some time considering if there is any more optimal approach like sieve because the constraints were l, r <= 1e9 and k <= 30, but the bruteforce works well and i think is the only working solution`
- block comment: `one minor miss during implementation was that i took x and y both between l and r, but only y is between l and r. so i simply modified the range and it was good to go.`
- final loop: `for (int i = 0; i <= r; ++i) { long long y = pow(i, k); count += (y >= l && y <= r); if (y > r) break; }`
- explicit `k == 1` short-circuit returns `r - l + 1` and `k == 0` short-circuit returns `1`
