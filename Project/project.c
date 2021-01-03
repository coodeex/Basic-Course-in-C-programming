#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_GAME_NAME_LENGTH 20

struct Gameinfo{
    char name[MAX_GAME_NAME_LENGTH + 1];
    double price;
    double sales;
};

// Helper function to find a specific game. Returns the index or -1 if not found.
int findGame(struct Gameinfo* games, int gameCount, char const* name)
{
    for (int i = 0; i < gameCount; ++i)
    {
        if (strcmp(games[i].name, name) == 0)
        {
            return i;
        }
    }

    return -1;
}

// Add a new game into the store memory. Returns NULL in case the game already exists or memory allocation fails.
struct Gameinfo* addGame(struct Gameinfo* games, int gameCount, char const* name, double price)
{
    if (findGame(games, gameCount, name) != -1)
    {
        printf("Error: Game \"%s\" already in store\n", name);
        return NULL;
    }
    
    struct Gameinfo* newGames = realloc(games, (gameCount + 1) * sizeof(struct Gameinfo));
    if (!newGames)
    {
        printf("Error: Unable to allocate memory\n");
        return NULL;
    }

    newGames[gameCount].price = price;
    newGames[gameCount].sales = 0.0;
    strncpy(newGames[gameCount].name, name, MAX_GAME_NAME_LENGTH);
    newGames[gameCount].name[MAX_GAME_NAME_LENGTH] = '\0';
    printf("Game \"%s\" added successfully\n", name);

    return newGames;
}

// Compare games and arrange in decreasing order of sales.
int orderDecreasingSale(void const* g1, void const* g2)
{
    struct Gameinfo const* game1 = (struct Gameinfo const*)g1;
    struct Gameinfo const* game2 = (struct Gameinfo const*)g2;

    if (game1->sales > game2->sales)
    {
        return -1;
    }
    else if (game1->sales < game2->sales)
    {
        return 1;
    }
    else 
    {
        // In case of matching sales, order alphabetically.
        return strcmp(game1->name, game2->name);
    }
}

// Print the contents of the store in decreasing order of sales.
void listGames(struct Gameinfo* games, int gameCount)
{
    if (gameCount == 0)
    {
        printf("No games in store\n");
    }

    qsort(games, gameCount, sizeof(struct Gameinfo), orderDecreasingSale);
    for (int i = 0; i < gameCount; ++i)
    {
        printf("Name: %s, Unit price: %.2f, Total sales: %.2f \n", games[i].name, games[i].price, games[i].sales);
    }
}

// Increase the sales of a specific game by the specified number of units
void buyGame(struct Gameinfo* games, int gameCount, char const* name, int unitCount)
{
    int index = findGame(games, gameCount, name);
    if (index == -1)
    {
        printf("Error: Game \"%s\" not found\n", name);
        return;
    }

    if (unitCount < 0)
    {
        printf("Error: Cannot buy a negative count\n");
        return;
    }

    games[index].sales += (games[index].price * unitCount);
    printf("Game \"%s\" bought successfully\n", name);
}

// Write the contents of the game store to a text file.
void saveStore(struct Gameinfo const* games, int gameCount, char const* fileName)
{
    FILE* file = fopen(fileName, "w");
    if (!file)
    {
        printf("Error: Unable to open file \"%s\"\n", fileName);
        return;
    }

    fprintf(file, "%d\n", gameCount);
    for (int i = 0; i < gameCount; ++i)
    {
        fprintf(file, "%s %f %f\n", games[i].name, games[i].price, games[i].sales);
    }
    printf("Store successfully saved to file\n");
    fclose(file);
}

// Restore the contents of the game store from a file. NOTE: If successful, discards the current contents.
void loadStore(struct Gameinfo** games, int* gameCount, char const* fileName)
{
    struct Gameinfo* newGames;
    int newGameCount;
    FILE* file = fopen(fileName, "r");
    if (!file)
    {
        printf("Error: Unable to open file \"%s\"\n", fileName);
        return;
    }

    if (fscanf(file, "%d\n", &newGameCount) != 1)
    {
        printf("Error: Unable to read number of games\n");
        return;
    }

    newGames = malloc(newGameCount * sizeof(struct Gameinfo));
    if (!newGames)
    {
        printf("Error: Unable to allocate memory\n");
        return;
    }

    for (int i = 0; i < newGameCount; ++i)
    {
        if (fscanf(file, "%s %lf %lf\n", newGames[i].name, &newGames[i].price, &newGames[i].sales) != 3)
        {
            printf("Error: Unable to read game data\n");
            free(newGames);
            return;
        } 
    }

    free(*games);
    *games = newGames;
    *gameCount = newGameCount;

    printf("Store successfully restored from file\n");
    fclose(file);
}

int main()
{
    struct Gameinfo* games = NULL;
    int gameCount = 0;
    bool isEnding = false;

    do 
    {
        char userInput[80];
        char name[MAX_GAME_NAME_LENGTH + 1];
        double price;
        int unitCount;
        char fileName[256];

        printf("Please give a command: ");
        fgets(userInput, 80, stdin);
        if (feof(stdin) || strncmp("Q", userInput, 1) == 0)
        {
            printf("Quitting\n");
            isEnding = true;
            free(games);
        }
        else if (sscanf(userInput, "A %20s %lf", name, &price) == 2)
        {
            struct Gameinfo* newGames = addGame(games, gameCount, name, price);
            if (newGames)
            {
                games = newGames;
                gameCount++;
            }
        }
        else if (strncmp("L", userInput, 1) == 0)
        {
            listGames(games, gameCount);
        }
        else if (sscanf(userInput, "B %20s %d", name, &unitCount) == 2)
        {
            buyGame(games, gameCount, name, unitCount);
        }
        else if (sscanf(userInput, "W %255s", fileName) == 1)
        {
            saveStore(games, gameCount, fileName);
        }
        else if (sscanf(userInput, "O %255s", fileName) == 1)
        {
            loadStore(&games, &gameCount, fileName);
        }
        else
        {
            printf("Error: Invalid command: %s\n", userInput);
        }
        
    }
    while (!isEnding);

    return 0;
}
