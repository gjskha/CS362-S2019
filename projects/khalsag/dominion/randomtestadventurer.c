#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include <math.h>
#include "rngs.h"

#define DEBUG 0
#define NOISY_TEST 1

int checkAdventureCard(int p, struct gameState *post) {

    struct gameState pre;
    memcpy (&pre, post, sizeof(struct gameState));

    int r;

    r = playAdventurer(p,post);
    assert (r == 0);

    /* after an Adventure card is played, you should see a smaller deck, a larger discard, and a greater hand. */
    assert(pre.deckCount[p] > post->deckCount[p]);
    assert(pre.discardCount[p] < post->discardCount[p]);
    assert(pre.handCount[p] < post->handCount[p]);
    assert(pre.coins == post->coins); // not incremented in function for some reason

}

int main () {

    int i, n, r, p, deckCount, discardCount, handCount;

    int k[10] = {adventurer, council_room, feast, gardens, mine,
	         remodel, smithy, village, baron, great_hall};

    struct gameState G;

    printf ("Testing Adventure Card.\n");

    SelectStream(2);
    PutSeed(3);

    for(i = 0; i < 200; i++) {
    
    SelectStream(2);
    PutSeed(3);
        r = initializeGame(2, k, 1, &G);
      
        assert(r == 0);
     
        p = floor(Random() * 2);
        G.deckCount[p] = floor(Random() * MAX_DECK);
        G.discardCount[p] = floor(Random() * MAX_DECK);
        G.handCount[p] = floor(Random() * MAX_HAND);
        printf("deckCount is %d, discardCount is %d, handCount is %d, p is %d\n",G.deckCount[p],G.discardCount[p],G.handCount[p],p);
        checkAdventureCard(p, &G);
        printf("deckCount is %d, discardCount is %d, handCount is %d, p is %d\n",G.deckCount[p],G.discardCount[p],G.handCount[p],p);

    }

    printf ("ALL TESTS OK\n");

    return 0;
}
