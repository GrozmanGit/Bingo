// C headers
#include <stdio.h>
#include <stdlib.h> 
#include <stdbool.h> 
#include <stddef.h>
#include <conio.h>

#include <string.h> 

// C++ STL
#include <vector>

// matrix marcos
#define ROW 5
#define COL 5

#define strBuffer sizeof(char)*16

/*int fileHistory(FILE* fptr);

int fileHistory(FILE* fptr)
{
    FILE* fptr;

    char getHistory; 
    getHistory = getchar();
    if (getHistory == 'h')
    {
        fptr = fopen("C:\\Users\apoll\source\repos\Bingo\history.txt", "w");

        if (fptr == nullptr)
        {
            puts("(0x6E)_ERROR::FILE::FAILED");
            return 110;
        }

        std::vector<int> store;
        std::vector<int>::iterator iter;
        int size = sizeof(int) * 5 / sizeof(int);

        if (store.size() == 5 || store.capacity() == size)
        {
            fputs("Total rolls: ", fptr);
            fputc('[', fptr);
            for (iter = store.begin(); iter != store.end(); ++iter)
            {
                fprintf(fptr, "%d", *iter);
                if (iter == store.end() - 1)
                {
                    break;
                }
                fputc(',', fptr);
                fputc(' ', fptr);
            }
            fputc(']', fptr);
            fputs("\n\n", fptr);
            fprintf(fptr, "Array has reached max capacity: cap.[%d]", store.size());
            fclose(fptr);
            free(fptr);
            fptr = NULL;
        }
    }
}*/

int main(int argc, char** argv)
{
    // code
    // declare bingo board (2 dimensional array (5x5 matrix))
    int mat[ROW][COL] =
    {
        {14, 20, 32, 52, 71,},
        {10, 27, 42, 55, 64,},
        {86, 23,  0, 58, 72,},
        {11, 28, 34, 56, 69,},
        {15, 25, 33, 53, 66}
    };

    puts("B   I   N   G   O");
    puts("------------------");

    // program prints out bingo board
    int iPrint, jPrint;
    int size = sizeof(int) * 5 / sizeof(int);

    for (iPrint = 0; iPrint < size; iPrint++) // loop through row
    {
        for (jPrint = 0; jPrint < size; jPrint++) // loop through col[umn]
        {
            if (mat[iPrint][jPrint] == 7)
            {
                fputs("  ", stdout);
            }

            printf("%d  ", mat[iPrint][jPrint]); // Print elements to screen
        }
        putchar('\n'); // Print elements to new line 
    }
    putchar('\n');

    // --------------------------------------------------------------------------------------------
    // --------------------------------------------------------------------------------------------
    std::vector<int> store;
    while (store.size() <= 5 || store.capacity() < 8)
    {

    // generate a bingo number aka (tile)
    int i;
    unsigned int tile = rand() % 100 + 1;
    
    const char str_input[strBuffer] = "", str_output[strBuffer] = "roll";

    fputs("Enter \"roll\" to roll a number: ", stdout); // Prompt for input
    scanf_s("%s", &str_input, strBuffer); // Get keyboard input and store into reference

    int compare = strcmp(str_input, str_output);

    if (compare == 0) { // check if compare is true (return 0 if true)
        for (i = 0; i < 1; i++)
        {
            // Roll random number & print result
            tile;
            printf("You rolled: [%d]\n", tile);
        }
        fflush(stdout); // flush output buffer
    }
    else if (compare > 1 || compare < 1)
    {
        putchar('\n');
        puts("(0xD)_ERROR::INVALID::DATA"); 
        puts("INPUT::NOT_RECOGNIZED");
        return 74;
    }
    putchar('\n');

    // --------------------------------------------------------------------------------------------
    // --------------------------------------------------------------------------------------------
    // loop through matrix -> check if element == tile
    int xCheck, yCheck;
    //std::vector<int> store;
    std::vector<int>::iterator iter; 

    fputs("Generated rolls: ", stdout); 
    putchar('[');
    for (xCheck = 0; xCheck < size; xCheck++)
    {
        for (yCheck = 0; yCheck < size; yCheck++)
        {
            // push back tile under conditions
            if (mat[xCheck][yCheck] == tile)
            {
                store.push_back(tile);
            }
            else if (mat[xCheck][yCheck] != tile)
            {
                continue; 
            }
        }
    }
    // iterate through vec arr, print results 
    for (iter = store.begin(); iter != store.end(); iter++)
    {
        printf("%d", *iter);
        if (iter == store.end() - 1)
        {
            break;
        }
        putchar(',');
        putchar(' ');
        if (store.size() > 5  || store.capacity() > 8)
        {
            putchar(']');
            fputs("\n\n", stdout);
            puts("(0xE)_ERROR::OUT::OF::MEMORY");
            puts("ERROR::INSUFFICIENT::BUFFER");
            return 14;
        }
    }
    putchar(']');
    putchar('\n');

    // --------------------------------------------------------------------------------------------
    // --------------------------------------------------------------------------------------------
    // print all stored (size/cap.max[5]) tiles within vector array
    if (store.size() == 5 || store.capacity() == size)
    {
        fputs("Total rolls: ", stdout);
        putchar('[');
        for (iter = store.begin(); iter != store.end(); ++iter)
        {
            printf("%d", *iter);
            if (iter == store.end() - 1)
            {
                break;
            }
            putchar(',');
            putchar(' ');
        }
        putchar(']');
        fputs("\n\n", stdout);
        printf("Array has reached max capacity: cap.[%zd]", store.size()); 
    }

    // --------------------------------------------------------------------------------------------
    // --------------------------------------------------------------------------------------------
    // loop through matrix -> replace element with tile  
    int conv_ascii = -1;

    for (xCheck = 0; xCheck < size; xCheck++)
    {
        for (yCheck = 0; yCheck < size; yCheck++)
        {
            if (mat[xCheck][yCheck] == tile)
            {
                mat[xCheck][yCheck] = (char)conv_ascii;
                break;
            }
        }
    }
    fputs("\n\n", stdout);
    
    puts("B   I   N   G   O");
    puts("------------------");

    // loop through matrix, print new matrix (with replaced element)
    for (iPrint = 0; iPrint < size; iPrint++) // loop through row
    {
        for (jPrint = 0; jPrint < size; jPrint++) // loop through col[umn]
        {
            if (mat[iPrint][jPrint] == 7)
            {
                fputs("  ", stdout);
            }
            printf("%d  ", mat[iPrint][jPrint]); // Print elements to screen
        }
        putchar('\n'); // Print elements to new line 
    }
    putchar('\n');
    }
    putchar('\n');
    return EXIT_SUCCESS;
}