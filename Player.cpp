#include "utilities.h"
#include "Player.h"
#include <string>
#include <iostream>
using std::cout;
using std::endl;
using std::string;



/* @param: name: name of new player
 * @param: force: force for new player (if not received then default is 5)
 * @param: maxHP: starting hp for new player (if not received then default is 100)
 *
 * c'tor for player, making a new player according to the input given
 */
Player::Player( const char *name, int maxHP, int force)
{
    this->m_name = name;
    if(maxHP<=0){//default values
        m_maxHP=MAXHP;
        m_HP=MAXHP;
    }
    else {
        m_maxHP=maxHP;
        m_HP=maxHP;
    }
    if(force<=0){
        m_force= FORCE;
    }
    m_force=force;
    m_coins =   COINS;
    m_level = LEVEL;
}
/* @param: playerToCopy: player To Copy
 *
 *  copy c'tor for player, making a new player according to the input given
 */
Player::Player(const Player& playerToCopy)
{
    m_name = playerToCopy.m_name;
    m_force = playerToCopy.m_force;
    m_level = playerToCopy.m_level;
    m_HP = playerToCopy.m_HP;
    m_maxHP = playerToCopy.m_maxHP;
    m_coins = playerToCopy.m_coins;
}

/* d'tor for player */
//Player::~Player()
////{
//   delete[]// m_name;
//}


/*printInfo prints all the uniqe information the player posses */
void Player:: printInfo() const
{
    printPlayerInfo(m_name.c_str(), m_level, m_force, m_HP, m_coins);
}

/*upgrades the players level by 1 */
void Player:: levelUp()
{
    if (m_level == MAX_LEVEL)
    {
        return;
    }
    m_level++;
}

/*getLevel returns players current level */
int Player::getLevel() const
{
    return m_level;
}

/*@param: forceToAdd: amount of force to add
*
* buff adds force points according to the input */
void Player::buff(int forceToAdd)
{
    m_force += forceToAdd;
}

/*@param: HPToAdd: amount of HP to add
*
* heal adds healing points according to the input */
void Player::heal(int HPToAdd)
{
    if (HPToAdd < 0)
    {
        return;
    }
    m_HP += HPToAdd;
    if (m_HP > m_maxHP)
    {
        m_HP = m_maxHP;
    }
}

/*@param: HPToTake: amount of HP to deduct
*
* removes healing points according to the input */
void Player:: damage(int HPToTake)
{
    if (HPToTake < 0)
    {
        return;//  i dont know if this is legal
    }
    m_HP = m_HP - HPToTake;
    if (m_HP < 0)
    {
        m_HP = 0;
    }

}

/* isKnockedOut checks if the players HP is at 0
* return true if the are*/
bool Player::isKnockedOut() const
{
    if (m_HP ==0)
    {
        return true;
    }
    return false;
}

/*@param: addCoins: amount of coins to add
*
* heal adds coins according to the input */
void Player::addCoins(int coinsToAdd)
{
        m_coins += coinsToAdd;

}

/*@param: price: amount of coins needed for transaction
*
* pay function attemps to make a purches with the players coins
* if the players has enough coins the function allows the purches,
* deducts the price from the players coins and returns true
* 
*if player doesn't have enough coins the fuctions won't 
*deduct coins and will return false*/
bool Player:: pay(int price)
{
    if (m_coins < price)
    {
        return false;
    }
    m_coins -= price;
    return true;
}

/*getAttackStrength returns players current strength
* calculated by the sum of his kevek and his force */
int Player:: getAttackStrength() const
{
    return (m_force + m_level);
}