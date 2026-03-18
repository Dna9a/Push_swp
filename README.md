*This project has been created as part of the 42 curriculum by yoabied.*

# push_swap

## Description

push_swap is a sorting algorithm project. The goal is to sort a stack of integers using two stacks (A and B) and a limited set of operations, while using the fewest moves possible.

The allowed operations are:

| Operation | Effect |
|---|---|
| `sa` / `sb` | Swap top 2 elements of stack A / B |
| `ss` | `sa` and `sb` at the same time |
| `pa` / `pb` | Push top of B to A / top of A to B |
| `ra` / `rb` | Rotate up (top goes to bottom) |
| `rr` | `ra` and `rb` at the same time |
| `rra` / `rrb` | Reverse rotate (bottom goes to top) |
| `rrr` | `rra` and `rrb` at the same time |

The algorithm used is a **greedy best-move approach**: for each element in stack B, the cost of inserting it into its correct position in A is calculated, and the cheapest one is always picked first.

## Instructions

**Compile:**
```bash
make
```

**Run:**
```bash
./push_swap 3 1 4 1 5 9 2 6
```

**Check move count:**
```bash
./push_swap 3 1 4 5 2 | wc -l
```

**Clean:**
```bash
make clean   # removes object files
make fclean  # removes object files + binary
make re      # recompiles everything
```

**Error handling:** the program prints `Error` to stderr and exits if:
- Arguments are not valid integers
- There are duplicate values
- A value overflows the int range

## Resources

- [Push Swap — A Complete Guide](https://medium.com/@ayogun/push-swap-c1f5d2d41e97) — overview of the project and common approaches
- [Sorting Algorithms Visualizer](https://visualgo.net/en/sorting) — helpful to understand sorting concepts visually
- [42 Docs — Push Swap](https://harm-smits.github.io/42docs/projects/push_swap) — project breakdown and tips

**AI usage:** Claude (claude.ai) was used throughout this project as a learning guide — explaining linked list concepts, walking through the algorithm logic step by step, reviewing code for bugs, and helping fix compilation errors. No code was blindly copied; every function was written and understood by the author.
