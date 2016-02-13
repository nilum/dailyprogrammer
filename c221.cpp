/*
  Daily Programmer Challenge #221: Word Snake
  Link: https://www.reddit.com/r/dailyprogrammer/comments/3bi5na/20150629_challenge_221_easy_word_snake/
  Sample Input 1: CAN NINCOMPOOP PANTS SCRIMSHAW WASTELAND DIRK KOMBAT TEMP PLUNGE ESTER REGRET TOMBOY
*/
#define MAXX 80
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include "c221.h"
using namespace std;
#define BUFFER 200

// testing magit!

#define MAXY 25

int main ()
{
    cout << "Enter a list of words to snake." << endl;
    
    word word[20];
    
    char output[MAXY][MAXX] = {0}; //Y, X
    char input[BUFFER] = {0};

    gets(input);
    int numwords = charBufferToWords(input, word);

    word[0].startX = 0;
    word[0].startY = 0;

    word[0].endX = word[0].startX + word[0].length-2;
    word[0].endY = 0;

    for(int i = 0; i < word[0].length; i++)
    {
        output[0][i] = word[0].string[i];
    }

    int flipped = 1;
    for (int i = 1; i < numwords; i++) //start from the second word
    {
        
        if (!getNewEndY(&word[i-1], &word[i], flipped, output))
        {
            flipped = -flipped;
            if(!getNewEndY(&word[i-1], &word[i], flipped, output))
            {
                exit(0);
            }
        }

        ++i;
        if (i >= numwords)
            break;
        if (!getNewEndX(&word[i-1], &word[i], flipped, output))
        {
            flipped = -flipped;
            if(!getNewEndX(&word[i-1], &word[i], flipped, output))
            {
                exit(0);
            }
        }
    }
    cout << endl;
    
    for (int i = 0; i < MAXY; i++)
    {
        for (int j = 0; j < MAXX; j++)
        {
            if (output[i][j] == 0)
            {
                putchar(' ');
                continue;
            }
            putchar(output[i][j]);
        }
        putchar('\n');
    }
    


    cout << endl;
    
    return 0;
}

inline
int getNewEndX (word* last, word* next, int flipped, char output[][MAXX])
{
    next->startX = last->endX;
    next->startY = last->endY;
    next->endY = last->endY;
    int temp = last->endX + (flipped)*next->length - 2;
    if ((temp < MAXX) && (temp > 0))
    {
        next->endX = temp;
        for(int i = 1; i < next->length-1; i++)
        {
            if((output[last->endY][next->startX+(i*flipped)] != 0))
            {
                return 0;
            }
                output[last->endY][next->startX+(i*flipped)] = next->string[i];
                next->endX = next->startX+(i*flipped);
        }
        return 1;
    }

    else
        return 0;
}

inline
int getNewEndY (word* last, word* next, int flipped, char output[][MAXX])
{
    next->startY = last->endY;
    next->startX = last->endX;
    next->endX = last->endX;
    int temp = last->endY + (flipped)*next->length - 2;
    if ((temp < MAXY) && (temp > 0))
    {
        next->endY = temp;
        for(int i = 1; i < next->length-1; i++)
        {
            if((output[last->endY + (i*flipped)][next->startX] != 0))
            {
                return 0;
            }
                output[last->endY + (i*flipped)][next->startX] = next->string[i];
                next->endY = next->startY+(i*flipped);
                
        }
        return 1;
    }
        
    else
        return 0;
}

inline
int charBufferToWords(char input[], word word[])
{
    char length = 0;
    char numwords = 0;
    char* pointer;
    
    for(int i = 0; i < BUFFER; i++)
    {
        if (!(input[i] || input[i-1])) 
            break;
        
        length++;
        if((input[i] == ' ') || (input[i] == '\0'))
        {

            word[numwords].length = length--;
            pointer = &input[i-length];
            for(int j = 0; j <= length; j++)
            {
                word[numwords].string[j] = *pointer++;
            }
            word[numwords].string[length] = '\0';
            numwords++;
            length = 0;
        }

    }
    //add errorchecking probably
    return numwords;
}

