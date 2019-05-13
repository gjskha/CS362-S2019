/* Gurujiwan McIntire 
 * CS 362 Sprint 19
 * Random Quiz
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>

/* Our strategy is to simply return and integer that is pseudo-randomly selected from the 
 * range of ASCII codes for alphanumeric characters
 */
char inputChar()
{
    int max = 94; // this is the delta between relevant low and high chars in ASCII
    int min = 32; // this is the minimum relevant ASCII code
    assert(max + min <= 126);
    int c = rand() % max + min;
    assert(c >= 32);
    //printf("c is %d -> %c\n", c, c);
    return c;
}

char *inputString()
{
 static const char gibberish[] = "rste";
        
  char s[5];
   for (int i = 0; i < 5; ++i) {
        s[i] = gibberish[rand() % (sizeof(gibberish) - 1)];
    }

   s[5] = 0;

   assert(sizeof(s) <= 5);
   //printf("s is %s\n", s);
   return strdup(s);
}

void testme()
{
  int tcCount = 0;
  char *s;
  char c;
  int state = 0;
  while (1)
  {
    tcCount++;
    c = inputChar();
    s = inputString();
    printf("Iteration %d: c = %c, s = %s, state = %d\n", tcCount, c, s, state);

    assert(s[5] == '\0');
    assert(state >= 0);
    assert(state <= 9);

    if (c == '[' && state == 0) state = 1;
    if (c == '(' && state == 1) state = 2;
    if (c == '{' && state == 2) state = 3;
    if (c == ' ' && state == 3) state = 4;
    if (c == 'a' && state == 4) state = 5;
    if (c == 'x' && state == 5) state = 6;
    if (c == '}' && state == 6) state = 7;
    if (c == ')' && state == 7) state = 8;
    if (c == ']' && state == 8) state = 9;


    if (s[0] == 'r' && s[1] == 'e'
       && s[2] == 's' && s[3] == 'e'
       && s[4] == 't' && s[5] == '\0'
       && state == 9)
    {
      printf("error ");
      exit(200);
    }
  }
}

int main(int argc, char *argv[])
{
    srand(time(NULL));
    testme();
    return 0;
}
