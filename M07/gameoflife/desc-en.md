### Programming task 7.5: Game of life (25 pts)

**Objective:** Practice allocating and manipulating dynamic two-dimensional arrays.

Conway's [Game of Life](http://en.wikipedia.org/wiki/Conway%27s_Game_of_Life) 
is a traditional zero-player game that runs a cellular automaton
based on an initial system state and a simple set of rules. Game of Life operates 
on a two-dimensional grid, where each cell can have two states: "dead" or "alive".
The state of the grid progresses in discrete steps (or "ticks"), where each cell 
may change its state based on the states of its neighbors.

The rules determining state changes on an individual cell are:

  * Any **live** cell with **fewer than two live** neighbours **dies**

  * Any **live** cell with **two or three live** neighbours **lives** on to the next 
    generation.
  
  * Any **live** cell with **more than three live** neighbours **dies**

  * Any **dead** cell with **exactly three live** neighbours becomes a **live** cell.
  
Also diagonal cells are considered neighbors, i.e., each cell (that is not on the 
edge of the area) has 8 neighbors. Remember to consider cells that are on the edge
of the area: you should not access positions that are out of the bounds of the area.

The state changes on each cell occur simultaneously. (i.e.), as you process the area
one cell at a time, the intermediate changes made earlier during the current iteration
must not affect the result.

For example, a area with the following setting ('*' indicates live cell):

..........
.**.***...
.**......*
.*.*.....*
........*.

will in the next generation be:

.....*....
.***.*....
*...**....
.*......**
..........

The [wikipedia page](http://en.wikipedia.org/wiki/Conway%27s_Game_of_Life) 
on Conway's Game of Life gives further background, and examples 
of some interestingly behaving patterns.

In this exercise you will implement the necessary components for Game of Life such 
that you should be able to follow the progress of the game area between generations.
The main function in **main.c** has the core of the game, that generates the area 
and goes through the generations one by one using the functions you will implement.

The exercise has the following subtasks:

**a) Create and release game area**

Implement the function **creategameArea** that allocates the needed space for the **GameArea**
structure that holds the game area, and for a two-dimensional array of dimensions 
given in parameters 'x_size' and 'y_size'. Each cell in the area must be initialized
to 'DEAD' status, as well as the 'x_size' and 'y_size' areas in the structure.

**Note:** the tests assume that the pointers to the rows (y-axis) of the area are 
the first dimension of the array (and allocated first), and the rows are the second
dimension. I.e., the cells are indexed as [y][x]. See the picture in dynamically 
allocated multi-dimensional array.

You will also need to implement the function **releaseGameArea** that frees the memory 
allocated by createGameArea(). The tests will use this function for all memory releases,
so failing to implement this will result in Valgrind errors about memory leaks.

**b) Initialize area**

Implement the function **initGameArea** that turns a given number of cells into 'ALIVE'
state. You can decide the algorithm by which you set up the area, but the outcome
must be that exactly 'n' cells in the area are alive. One possibility is to use 
the *[rand](http://linux.die.net/man/3/rand)* function to choose the live cells randomly.

**c) Print area**

Implement the function **printGameArea** that outputs the current state of the area
to the screen. Each dead cell is marked with a period ('.') and each live cell 
is marked with an asterisk ('*'). There are no spaces between the cells, 
and each row ends in a newline ('\\n'), including the last line. The output 
should look similar, as in the above examples in this task description.

**d) Progress game area**

Implement the function **gameTick** that advances the game area by one generation according
to the rules given above. Note that all cells need to be evaluated "simultaneously".
One way to do this is to maintain two game areas: one that holds the state before 
the transition, and another where you will build the next generation of the game 
area.

(If you allocate new memory in this function, don't forget to release it.)

**Hint:** When counting neighbours, don't go through the border cases separately
with conditions. Instead, use loops and before accessing the cell value
check that it is not out of bounds.
