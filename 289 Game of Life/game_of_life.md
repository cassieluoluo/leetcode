# Game of Life
## Difficulty: Medium

According to the [Wikipedia's article](https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life): "The **Game of Life**, also known simply as Life, is a cellular automaton devised by the British mathematician John Horton Conway in 1970."

Given a *board* with *m* by *n* cells, each cell has an initial state *live* (1) or *dead* (0). Each cell interacts with its [eight neighbors](https://en.wikipedia.org/wiki/Moore_neighborhood) (horizontal, vertical, diagonal) using the following four rules (taken from the above Wikipedia article):

1. Any live cell with fewer than two live neighbors dies, as if caused by under-population.
2. Any live cell with two or three live neighbors lives on to the next generation.
3. Any live cell with more than three live neighbors dies, as if by over-population..
4. Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
Write a function to compute the next state (after one update) of the board given its current state.

**Follow up:** 
Could you solve it in-place? Remember that the board needs to be updated at the same time: You cannot update some cells first and then use their updated values to update other cells.
In this question, we represent the board using a 2D array. In principle, the board is infinite, which would cause problems when the active area encroaches the border of the array. How would you address these problems?

**Tags:** Array

## Explanation
The problem description is pretty straight forward. However, doing it in place is a little bit tricky.

The next state of each cell depends on the current states of all eight neighbhors. Therefore we cannot update any cells before we have completed updating all other cells. An initial thought is to create another board to store the next state and then copy it back. As we are not allowed to do so, we will need to exploit the space in the int variable. Only one bit is needed to store the state of each cell. We can use the second least significant bit to store its next state. After updating the whole board and storing its state in the second bit, just shiftting the variable to the right by one place will generate the correct result.

*Author: Xinyu Chen*