#include "utilities.h"
#include "Card.h"
#include <string>
#include <iostream>
using std::cout;
using std::endl;

/*
* C'tor of Card class
*
* @param type - The type of the card.
* @param stats - The numeral stats of the card.
* @return
*      A new instance of Card.
*/
Card::Card(CardType type, const CardStats& stats)
{
    m_effect = type;
    m_stats.buff = stats.buff;
    m_stats.cost = stats.cost;
    m_stats.force = stats.force;
    m_stats.heal = stats.heal;
    m_stats.hpLossOnDefeat = stats.hpLossOnDefeat;
    m_stats.loot = stats.loot;
}

/*
* Handling the player's applyEncounter with the card:
*
* @param player - The player.
* @return
*      void
*/

void Card:: applyEncounter(Player& player) const
{
    if (m_effect == CardType::Battle)
    {
        if(player.getAttackStrength() >= m_stats.force)
        {

            player.levelUp();
            player.addCoins(m_stats.loot);
            printBattleResult(true);
        }
        else
        {
            player.damage(this->m_stats.hpLossOnDefeat);
            printBattleResult(false);
        }

    }

    if (this->m_effect == CardType::Buff)
    {
        bool purchesd = player.pay(this->m_stats.cost);
        if (purchesd)
        {
            player.buff(this->m_stats.buff);
        }
    }

    if (this->m_effect == CardType::Heal)
    {
        bool purchesd = player.pay(this->m_stats.cost);
        if (purchesd)
        {
            player.heal(this->m_stats.heal);
        }
    }

    if (this->m_effect == CardType::Treasure)
    {
        player.addCoins(this->m_stats.loot);
    }
}

/*
 * Prints the card info:
 *
 * @return
 *      void
 */
void Card:: printInfo() const
{
    switch (this->m_effect)
    {
        case CardType::Battle:
            printBattleCardInfo(this->m_stats);
            break;
        case CardType::Buff:
            printBuffCardInfo(this->m_stats);
            break;
        case CardType::Heal:
            printHealCardInfo(this->m_stats);
            break;
        case CardType::Treasure:
            printTreasureCardInfo(this->m_stats);
            break;

    }
}