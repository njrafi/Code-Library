
/*
In general, for a given grid of width N, 
we can find out check if a N*N – 1 puzzle is solvable or not by following below simple rules :

If N is odd, then puzzle instance is solvable
if number of inversions is even in the input state.

If N is even, puzzle instance is solvable if

the blank is on an even row counting from the bottom  and number of inversions is odd.
the blank is on an odd row counting from the bottom and number of inversions is even.
For all other cases, the puzzle instance is not solvable.

*/