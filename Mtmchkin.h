
#ifndef EX2_GAME_H
#define EX2_GAME_H
#include "Card.h"
#include "Player.h"
#include <iostream>

const int START = 0;
const int MAX_LEVEL= 10;
/*
 * GameStatus:
 * MidGame - The game is still active and the player continues to encounter cards.
 * Win - The player reached level 10.
 * Loss - The player's HP is 0.
*/
enum class GameStatus{Win, Loss, MidGame};

class Mtmchkin {


public:

    /*
     * C'tor of the game:
     *
     * @param playerName - The name of the player.
     * @param cardsArray - A ptr to the cards deck.
     * @param numOfCards - Num of cards in the deck.
     * @result
     *      An instance of Mtmchkin
    */
    Mtmchkin(const char* playerName, const Card* cardsArray, int numOfCards);


    /*
     * Play the next Card - according to the instruction in the exercise document
     *
     * @return
     *      void
    */
    void playNextCard();


    /*
     *  Check if the game ended:
     *
     *  @return
     *          True if the game ended
     *          False otherwise
     */
    bool isOver() const;


    /*
     *  Get the status of the game:
     *
     *  @return
     *          GameStatus - the current status of the running game
     */
    GameStatus getGameStatus() const;
/*destructor for Mtmchkin*/
    ~Mtmchkin();
    //TODO: complete the Mtmchkin class.

private:
    /* private member variables of the Mtmchkin class.*/
    Player m_player;
    Card* m_cards;
    GameStatus m_status;
    int m_numOfCards;
    int m_playedCard;

};


#endif //EX2_GAME_H