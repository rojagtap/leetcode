---
problem_id: '3927'
platform: 'leetcode'
title: 'Minimize Array Sum Using Divisible Replacements'
difficulty: 'medium'
language: 'cpp'
aliases:
  - '3927-minimize-array-sum-using-divisible-replacements'
primary_tags:
  - '[[math]]'
subtle_tags: []
candidate_tags:
  - '[[constraint_driven_algorithm_choice]]'
mistakes:
  - '[[knowledge_gap]]'
related:
  - '[[leetcode/3932-count-k-th-roots-in-a-range/NOTES|3932-count-k-th-roots-in-a-range]]'
---

## Explanations

The right framing is "for each `nums[i]`, find the minimum `nums[j]` that divides it (where `j` ranges over the array, including `i` itself)". Replacement is non-destructive in the sense that `nums[a] := nums[b]` does not alter `nums[b]` or any other entry, so for every position the optimum is the smallest divisor of `nums[i]` that appears anywhere in the array. There is no chain to reason about: even though replacement is a sequence of operations, each position can be optimized independently against the *original* multiset, because the divisor it ends up at must already exist as some `nums[b]`.

The algorithmic trap is choosing the inner loop. Two regimes:
- per-element factor enumeration is `O(n * sqrt(m))` where `m = max(nums)`. Each `num` looks at `O(sqrt(num))` factor pairs and tests membership in a hash set of array values; the smallest hash hit wins. This works at any value range and is the only viable option when `nums[i] <= 1e9`.
- a one-shot sieve is `O(m log m)`. Initialize `sieve[k] = k`, walk array values in sorted ascending order, and for each `num` with `sieve[num] == num` (still its own smallest divisor in the array, i.e. nothing smaller has claimed it) sweep multiples and write `sieve[multiple] = num` only when `sieve[multiple] == multiple`. The "only when self" guard keeps the smallest divisor that is in the array, since smaller divisors process first. This is faster only when `m` is small enough that `m log m << n sqrt(m)`, i.e. roughly `nums[i] <= 1e5`.

The chosen regime here was the sieve, because the constraints cap `nums[i] <= 1e5`. The pivot worth remembering is that the better algorithm depends on the *value range*, not on `n`. Future-self trap: when constraints later say `nums[i] <= 1e9`, the sieve disappears and the factor-enumeration version (preserved as the bottom-of-file commented class) is the right shape.

Two micro-correctness pieces in the sieve version that are easy to miss on rewrite:
- iterate the source values via `set<int> sorted(begin(nums), end(nums))` so duplicates collapse and the ascending order is automatic; without that, the `sieve[num] == num` check still works but you redo the same sweep for every duplicate.
- the inner sweep starts at `multiple = num`, not `num * 2`, so `sieve[num]` is asserted to be `num` (true on entry) and self-loops do not corrupt smaller divisors of `num` that may have been written by an earlier (smaller) array value.

### Candidate Tags
- [[constraint_driven_algorithm_choice]]: the algorithm is determined by which constraint bounds the structural quantity that drives cost -- here the value-range constraint `nums[i] <= 1e5` bounds `m`, which is what makes the `O(m log m)` sieve cheaper than the `O(n sqrt(m))` factor enumeration; the framing ("smallest-divisor-in-array per element") admits both, and the constraint picks one. At `nums[i] >= 1e9` the same framing flips to factor enumeration.

### Mistake Notes
- [[knowledge_gap]]: the sieve framing was not the first thing that came up; the solver's own comment is `i didn't stress much on this and went ahead. however, i see a faster solution (it probably wouldn't have clicked anyway)`. The `O(n sqrt(m))` solution would also AC at this `m`, so this is a future-self gap, not a contest blocker

### Related Reasoning
- [[leetcode/3932-count-k-th-roots-in-a-range/NOTES|3932-count-k-th-roots-in-a-range]]: both show [[constraint_driven_algorithm_choice]] on value-range bounds — 3927's `nums[i] <= 1e5` selects sieve over factor enumeration, 3932's joint `k`-and-`r` bound selects bounded-base iteration over a sieve; the constraint is the load-bearing fact in both

### Signals
- block comment narrates both regimes: `a naive factor search for each number is a reasonable O(n*sqrt(m)) where m = max(nums)` and `we can sort and do a sieve for each number. this will be O(m log m) where m = max(nums)`
- block comment names the value-range pivot: `however this is only better for nums[i] <= 1e5. for much larger values, nums[i] >= 1e9, the sieve is not feasible, we'd have to go for the factors approach`
- bottom-of-file commented class preserves the factor-enumeration alternative with `for (long long factor = 2; factor * factor <= num; ++factor)` and a hash set of array values; kept as evidence that the solver knows when this version becomes mandatory
- sieve is keyed on `set<int> sorted(begin(nums), end(nums))` so duplicates do not retrigger the sweep; inner sweep is `for (multiple = num; multiple <= m; multiple += num) if (sieve[multiple] == multiple) sieve[multiple] = num;`
