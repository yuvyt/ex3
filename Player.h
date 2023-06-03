#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <iostream>
const int FORCE = 5;
const int MAXHP = 100;
const int COINS = 0;
const int LEVEL = 1;
const int MAX_LEVEL=10;
class Player
{
public:
    /* @param: name: name of new player
 * @param: force: force for new player (if not received then default is 5)
 * @param: maxHP: starting hp for new player (if not received then default is 100)
 *
 * c'tor for player, making a new player according to the input given
 */
    Player(const char *name, int m_maxHP = MAXHP, int m_force = FORCE);

    /* @param: playerToCopy: player To Copy
 *
 *  copy c'tor for player, making a new player according to the input given
 */
   Player(const Player& playerToCopy);

   /*default constructor */
    Player () = default;

    /*defaulted destructor*/
    ~Player() = default; // check if ok

    /*printInfo prints all the uniqe information the player posses */
    void printInfo() const;

    /*upgrades the players level by 1 */
    void levelUp();

    /*getLevel returns players current level */
    int getLevel() const;

    /*@param: forceToAdd: amount of force to add
*
* buff adds force points according to the input */
    void buff(int forceToAdd);

    /*@param: HPToAdd: amount of HP to add
*
* heal adds healing points according to the input */
    void heal(int HPToAdd);

    /*@param: HPToTake: amount of HP to deduct
*
* removes healing points according to the input */
    void damage(int HPToTake);

    /* isKnockedOut checks if the players HP is at 0
* return true if the are*/
    bool isKnockedOut() const;

    /*@param: coinsToAdd: amount of coins to add
*
* heal adds coins according to the input */
    void addCoins(int coinsToAdd);

    /*@param: price: amount of coins needed for transaction
*
* pay function attemps to make a purches with the players coins
* if the players has enough coins the function allows the purches,
* deducts the price from the players coins and returns true
*
*if player doesn't have enough coins the fuctions won't
*deduct coins and will return false*/
    bool pay(int price);

    /*getAttackStrength returns players current strength
* calculated by the sum of his kevek and his force */
    int getAttackStrength() const;

    /*copy assignment operator*/
    Player& operator=(const Player&) = default;

    /* private member variables of the Player class.*/
private:
    std::string m_name;
    int m_level;
    int m_force;
    int m_maxHP;
    int m_HP;
    int m_coins;

};
#endif // PLAYER_H