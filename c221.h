#if !defined(C221_H)
/* ========================================================================
   $File: $
   $Date: $
   $Revision: $
   $Creator: Jared Boyd $
   ======================================================================== */

#define C221_H

struct word
{
    char string[20] = {}; //assume no word is longer than 20 characters
    char length;
    char startX;
    char startY;
    char endX;
    char endY;
};

int charBufferToWords(char input[], word word[]);
int getNewEndX (word* last, word* next, int flipped, char output[][MAXX]);
int getNewEndY (word* last, word* next, int flipped, char output[][MAXX]);
#endif
