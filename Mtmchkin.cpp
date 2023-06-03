#include "Mtmchkin.h" // Include the corresponding header file
#include "Card.h"
#include "Player.h"
#include <iostream>

Mtmchkin::Mtmchkin(const char* playerName, const Card* cardsArray, int numOfCards)
{
    m_player= Player(playerName);
    m_cards = new Card[numOfCards];
    for (int i = 0; i < numOfCards; ++i) {
        m_cards[i] = cardsArray[i];
    }
    m_status=GameStatus::MidGame;
    m_numOfCards=numOfCards;
    m_playedCard=START;
}

void Mtmchkin::playNextCard()
{
    if(m_playedCard==m_numOfCards)
    {
        m_playedCard=0;
    }
    m_cards[m_playedCard].printInfo();
    m_cards[m_playedCard].applyEncounter(m_player);
    m_player.printInfo();
    m_playedCard++;
    if(m_player.getLevel()==MAX_LEVEL){
        m_status=GameStatus::Win;
    }
    if(this->m_player.isKnockedOut()){
        m_status=GameStatus::Loss;
    }
}

bool Mtmchkin::isOver() const
{
    if(m_status==GameStatus::MidGame)
    {
        return false;
    }
    return true;
}

GameStatus Mtmchkin::getGameStatus() const
{
    return m_status;
}

Mtmchkin::~Mtmchkin()
{
    delete[] m_cards;
}