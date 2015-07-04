/*
  Daily Programmer Challenge #221: Word Snake
  Link: https://www.reddit.com/r/dailyprogrammer/comments/3bi5na/20150629_challenge_221_easy_word_snake/
  Sample Input 1: CAN NINCOMPOOP PANTS SCRIMSHAW WASTELAND DIRK KOMBAT TEMP PLUNGE ESTER REGRET TOMBOY
*/

#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include "c221.h"
using namespace std;
#define BUFFER 200
#define MAXX 80
#define MAXY 25

int main ()
{
    word word[20];
    
    char output[MAXY][MAXX] = {0}; //Y, X
    char input[BUFFER] = {0};

    gets(input);
    int numwords = charBufferToWords(input, word);

    word[0].startX = 0;
    word[0].startX = 0;

    word[0].endX = word[0].startX + word[0].length;
    word[0].endY = 0;
    
    int isvalid = 0;
    int attempts = 0;
    while((!isvalid) && (attempts < 25000))
    {
        int i = 1;
        while (i < numwords) //start from the second word
        {
            if (!getNewEndY(&word[i-1], &word[i], 1))
            {
                if(!getNewEndY(&word[i-1], &word[i], -1))
                {
                    exit(0);
                }
            }
            if (++i >= numwords)
                break;
            if (!getNewEndX(&word[i-1], &word[i], 1))
            {
                if(!getNewEndX(&word[i-1], &word[i], -1))
                {
                    exit(0);
                }
            }
        }
    }

    int i = 0;
    while (i < MAXX * MAXY)
    {
        i++;
    }
    
    cout << "The string is " << word[0].string;
    
    return 0;
}

inline
int getNewEndX (word* last, word* next, int flipped)
{
    int temp = last->endX + (flipped)*next->length - 2;
    if ((temp < MAXX) && (temp > 0))
    {
        next->endX = temp;
        return 1;
    }

    else
        return 0;
}

inline
int getNewEndY (word* last, word* next, int flipped)
{
    int temp = last->endY + (flipped)*next->length - 2;
    if ((temp < MAXY) && (temp > 0))
    {
        next->endY = temp;
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

