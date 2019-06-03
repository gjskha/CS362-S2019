/* testing the great hall function from assignment 2 */
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>
#include "rngs.h"

#define DEBUG 0
#define NOISY_TEST 1

int getRandomNumber(int min, int max) {

    return rand() % max + min;

}

int main () {
  
    /* seed the random generator */
    srand(time(NULL));
  
    int i, n, r, p, deckCount, discardCount, handCount;
  
    int k[10] = {adventurer, council_room, feast, gardens, mine,
  	       remodel, smithy, village, baron, great_hall};
  
    struct gameState G;
  
    printf ("Testing smithyEffect.\n");
  
    /* random number of players */
    int numPlayers = getRandomNumber(1,4);
   
    assert(numPlayers < 5);
  
    memset(&G, 23, sizeof(struct gameState)); 
  
    r = initializeGame(2, k, 1, &G);
  
    assert(r == 0);
  
    //printf ("numPlayers is %d, deckCount is %d, discardCount is %d, r is %d.\n",numPlayers,deckCount,discardCount,r);
  
    for (p = 0; p < numPlayers; p++) {
    
        /* random number of cards */
        deckCount = getRandomNumber(1,5);
        assert(deckCount < 6);
  
        /* random number of discards */
        discardCount = getRandomNumber(1,5);
        assert(discardCount < 6);
  
        /* random number for handCount  */
        handCount = getRandomNumber(1,5);
        assert(handCount < 6);
  
        G.deckCount[p] = deckCount;
        memset(G.deck[p], 0, sizeof(int) * deckCount);
        G.discardCount[p] = discardCount;
        memset(G.discard[p], 0, sizeof(int) * discardCount);
        G.handCount[p] = handCount;
        memset(G.hand[p], 0, sizeof(int) * handCount);
        smithyEffect(&G, p, handCount);
    }
  
    return 0;
}
