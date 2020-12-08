#include "gameoflife.h"
#include <stdio.h>
#include <string.h>  // for memcpy
#include <stdlib.h>  // for malloc

#include <time.h>
#include <unistd.h>
#include "gameoflife.h"


/* Exercise a: Allocates needed memory for the GameArea structure and
 * the actual game area. 'x_size' and 'y_size' indicate the horizontal and
 * vertical dimensions of the GameArea.
 * 
 * Returns: pointer to the GameArea structure allocated by this function.
 */
GameArea *createGameArea(unsigned int x_size, unsigned int y_size)
{
    GameArea *a = malloc(sizeof(GameArea));
    if(!a) return NULL;
    a->cells = malloc(x_size * y_size * sizeof(CellStatus));
    a->x_size = x_size;
    a->y_size = y_size;
    unsigned int y = 0;
    unsigned int x = 0;
    for(;!(y == y_size && x == x_size); y++) {
        a->cells[y] = malloc(x_size * sizeof(CellStatus));

        /*if(a->cells[y] == NULL)
			{
			return a;
			}
        */
        for(x=0;x != x_size;x++){
            //a->cells[y][x] = malloc(sizeof(CellStatus));
            a->cells[y][x] = DEAD;
        }
    }
    return a;
}

/* Free memory allocated for GameArea <a>.
 */
void releaseGameArea(GameArea *a)
{
    for(unsigned int i = 0; i != a->y_size; i++){
        free(a->cells[i]);
    }
    free(a->cells);
    free(a);
}

/* Exercise b: Initialize game GameArea by setting exactly <n> cells into
 * ALIVE CellStatus in the game GameArea <a>.
 */
void initGameArea(GameArea *a, unsigned int n)
{
    if(n<=a->x_size){
        for(unsigned int i=0; i!=n;i++){
            a->cells[0][i] = ALIVE;
        }
    }
    else if(n<=a->x_size*2){
        for(unsigned int i=0; i!=a->x_size;i++){
            a->cells[0][i] = ALIVE;
        }
        for(unsigned int i=0; i!=(n) - (a->x_size) ;i++){
            a->cells[1][i] = ALIVE;
        }
    }

    else if(n<=a->x_size*3){
        for(unsigned int i=0; i!=a->x_size;i++){
            a->cells[0][i] = ALIVE;
        }
        for(unsigned int i=0; i!=a->x_size ;i++){
            a->cells[1][i] = ALIVE;
        }
        for(unsigned int i=0; i!=(n) - 2*(a->x_size) ;i++){
            a->cells[2][i] = ALIVE;
        }
    }
}

/* Exercise c: Output the current CellStatus of GameArea <a>.
 */
void printGameArea(const GameArea *a)
{
    unsigned int y = 0;
    unsigned int x = 0;
    for(;y<a->y_size; y++) {
        for(x=0; x < a->x_size;x++){
            if(a->cells[y][x] == DEAD) {
                printf(".");
            }
            else {
                printf("*");
            }
        }
        printf("\n");
    }
}

/* Calculates number of live neighbours around position (x,y),
 * and returns the count.
 */


/*unsigned int live_neighbours(const GameArea *a, unsigned int x, unsigned int y)
{
    
}*/

/* Exercise d: Advance GameArea <a> by one generation.
 */
void gameTick(GameArea *a)
{
    GameArea *old = createGameArea(a->x_size, a->y_size);
    unsigned int y = 0;
    unsigned int x = 0;

    int yy=0;
    int xx=0;

    int xs = (int) old->x_size;
    int ys = (int) old->y_size;
    for(;y<a->y_size; y++) {
        for(x=0; x < a->x_size;x++){
            old->cells[y][x] = a->cells[y][x];
        }
    } //kopioi peliareenan oldiin

int hah = 0;

    for(yy=0, y=0;y<old->y_size; y++, yy++) { //!(y == a->y_size && x == a->x_size)
        for(xx=0,x=0; x < old->x_size; x++, xx++){
            int elos = 0;
            
            for(int i = -1; i <= 1; i++){
                for(int j = -1; j <= 1; j++){
                    if(yy+i >=0 && yy+i<ys){
                        if(xx+j >=0 && xx+j<xs){
                            if(yy+i == yy && xx+j == xx){
                                hah = hah+1;
                            }
                            else if(old->cells[yy+i][xx+j] == ALIVE) elos++;
                            
                        }
                    }
                }
            }

            //printf("%d", elos);
            if(a->cells[y][x] == ALIVE){
                if(elos <=1 || elos >=4){
                    a->cells[y][x] = DEAD;
                }
            }
            else{
                if(elos == 3){
                    a->cells[y][x] = ALIVE;
                }
            }
        }
    }



    releaseGameArea(old);
}

int main(void)
{
    /* Feel free to modify this function to test different things */

    // re-seed random number generator
    //srand((unsigned)time(NULL));

    GameArea *a = createGameArea(5,4);
    initGameArea(a, 1);

    // how many iterations we want
    int rounds = 30;

    // loop iterations, cancel with ctrl-c
    for(int i=0; i<rounds; i++) {
        printf("\nGeneration: %d\n", i+1);
        printGameArea(a);
        // slow down iterations
        //sleep(1);
        gameTick(a);
    }
    releaseGameArea(a);
    return 0;
}


/*void main(){
    GameArea *a = createGameArea(5,4);
    initGameArea(a, 6);
    printGameArea(a);
    releaseGameArea(a);
}*/