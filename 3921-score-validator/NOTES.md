---
problem_id: '3921'
platform: 'leetcode'
title: 'Score Validator'
difficulty: 'easy'
language: 'cpp'
aliases:
  - '3921-score-validator'
primary_tags:
  - '[[simulation]]'
subtle_tags: []
candidate_tags: []
mistakes: []
related: []
---

## Explanations

`no_signal`. Linear pass over the event tape, dispatch by `isdigit(event[0])` for the numeric scores and `event == "W"` for the counter, with a default `++score` arm covering `"WD"` and `"NB"` since both add 1. Early break on `counter == 10` matches the spec exactly. No comments, no commented-out code, no friction artifacts in the source. Recorded only so the canonical [[simulation]] pattern stays connected.

### Signals
- single solution file, no commentary
- the `++score` default arm collapses `"WD"` and `"NB"` into one branch instead of explicitly comparing both strings, which is the only mild compression in the file
