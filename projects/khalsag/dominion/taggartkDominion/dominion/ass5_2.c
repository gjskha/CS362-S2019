/* testing the village function from assignment 2 */
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

/* playVillage is located in dominion.c */
//int checkPlayVillage(int p, struct gameState *post) {
//  
//    /* prior state of affairs */
//    struct gameState pre;
//    memcpy (&pre, post, sizeof(struct gameState));
//  
//    playVillage(p,post,0);
//  
//    /* the village card adds two actions. Lets verify */
//    assert(pre.numActions + 2 == post->numActions);
//    printf("pre numActions is %d\n",pre.numActions);
//    printf("post numActions is %d\n",post->numActions);
//    
//    /* the discard pile increases */
//    assert(pre.discardCount[p] <= post->discardCount[p]);
//    printf("pre discardCount is %d\n",pre.discardCount[p]);
//    printf("post discardCount is %d\n",post->discardCount[p]);
//
//    /* the handcount stays the same */
//    assert(pre.handCount[p] == post->handCount[p]);
//    printf("pre handcount is %d\n",pre.handCount[p]);
//    printf("post handcount is %d\n",post->handCount[p]);
//
//    /* the deck decreases by 1 */
//    assert(pre.deckCount[p] == post->deckCount[p] + 1 );
//    printf("pre deckCount is %d\n",pre.deckCount[p]);
//    printf("post deckCount is %d\n",post->deckCount[p]);
//    
//    return 0;
//}

int main () {
  
    /* seed the random generator */
    srand(time(NULL));
  
    int r, p, deckCount, discardCount, handCount;
  
    int k[10] = {adventurer, council_room, feast, gardens, mine,
  	       remodel, smithy, village, baron, great_hall};
  
    struct gameState G;
  
    printf ("Testing SeaHag.\n");
  
    /* random number of players */
    int numPlayers = getRandomNumber(1,4);
   
    assert(numPlayers < 5);
  
    memset(&G, 23, sizeof(struct gameState)); 
  
    r = initializeGame(2, k, 1, &G);
  
    assert(r == 0);
  
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
        assert(seahagEffect(&G, p) == 0);
    }
  
    return 0;
}
