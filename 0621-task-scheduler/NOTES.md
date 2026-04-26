---
problem_id: '0621'
platform: 'leetcode'
title: 'Task Scheduler'
difficulty: 'medium'
language: 'cpp'
aliases:
  - '0621-task-scheduler'
primary_tags:
  - '[[greedy]]'
  - '[[heap]]'
subtle_tags: []
candidate_tags: []
mistakes: []
related: []
---

## Explanations

The solver derives the mathematical solution by case-splitting on whether the most-frequent task dominates (idle slots appear) or not (tasks fill all slots). Keeping both the `O(n)` math solution and the `O(n log n)` heap simulation suggests the mathematical insight was arrived at after implementing the simulation, or both were explored for completeness.

### Signals
- Two complete approaches: mathematical formula and heap+queue simulation
- Comment walks through two example scenarios to derive the formula: high-frequency dominated vs low-frequency dominated
- 'two things can happen' followed by detailed case analysis
