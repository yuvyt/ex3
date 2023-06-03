#include "HealthPoints.h"
#include <iostream>
#include <exception>


HealthPoints::HealthPoints(int maxHPInput)
{
    if(maxHPInput <= 0)
    {
        throw HealthPoints::InvalidArgument();
    }
    this->m_maxHp = maxHPInput;
    this->m_currentHp = maxHPInput;
}

HealthPoints::HealthPoints(const HealthPoints& healthPointsToCopy)
{
    this->m_currentHp = healthPointsToCopy.m_currentHp;
    this->m_maxHp = healthPointsToCopy.m_maxHp;
}

HealthPoints HealthPoints::operator+(const int numOfHpPoints) const
{
    HealthPoints result(this->m_currentHp + numOfHpPoints);
    return result;

}

HealthPoints operator+(int number, const HealthPoints& healthPoints)
{
    return healthPoints + number;
}

HealthPoints HealthPoints::operator-(const int numOfHpPoints) const
{
    HealthPoints result(this->m_currentHp - numOfHpPoints);
    return result;
}

HealthPoints operator-(int number, const HealthPoints& healthPoints)
{
    return healthPoints - number;
}

HealthPoints& HealthPoints::operator+=(const int numOfHpPoints)
{
    this->m_currentHp = this->m_currentHp + numOfHpPoints;
    if (this->m_currentHp < 0)
    {
        this->m_currentHp = 0;
    }
    if (this->m_currentHp > this->m_maxHp)
    {
        this->m_currentHp = this->m_maxHp;
    }
    return *this;
}

HealthPoints& HealthPoints::operator-=(const int numOfHpPoints)
{
    this->m_currentHp = this->m_currentHp - numOfHpPoints;
    if (this->m_currentHp < 0)
    {
        this->m_currentHp = 0;
    }
    if (this->m_currentHp > this->m_maxHp)
    {
        this->m_currentHp = this->m_maxHp;
    }
    return *this;
}


HealthPoints& HealthPoints::operator=(const int numOfHpPoints)
{
    if (numOfHpPoints <= 0)
    {
        this->m_maxHp = 0;
        this->m_currentHp = 0;
    }
    else
    {
        this->m_maxHp = numOfHpPoints;
        this->m_currentHp = numOfHpPoints;
    }
    return *this;
}

bool HealthPoints::operator==(const HealthPoints& otherHealthPoints) const
{
    if (this->m_currentHp == otherHealthPoints.m_currentHp)
    {
        return true;
    }
    return false;
}

bool HealthPoints::operator==(const int numOfHpPoints) const
{
    if (this->m_currentHp == numOfHpPoints)
    {
        return true;
    }
    return false;
}

bool operator==(int number, const HealthPoints& healthPoints)
{
    return (healthPoints == number);
}
//
//
bool HealthPoints::operator!=(const HealthPoints& otherHealthPoints) const
{
    return (!(*this == otherHealthPoints));
}

bool HealthPoints::operator!=(const int numOfHpPoints) const
{
    if (this->m_currentHp != numOfHpPoints)
    {
        return true;
    }
    return false;
}

bool operator!=(int number, const HealthPoints& healthPoints)
{
    return (healthPoints != number);
}
//
//
bool HealthPoints::operator>=(const HealthPoints& otherHealthPoints) const
{
    if (this->m_currentHp > otherHealthPoints.m_currentHp || *this == otherHealthPoints)
    {
        return true;
    }
    return false;
}

bool HealthPoints::operator>=(const int numOfHpPoints) const
{
    if (this->m_currentHp >= numOfHpPoints)
    {
        return true;
    }
    return false;
}

bool operator>=(int number, const HealthPoints& healthPoints)
{
    return (healthPoints >= number);
}
//
//
bool HealthPoints::operator<=(const HealthPoints& otherHealthPoints) const
{
    if (this->m_currentHp < otherHealthPoints.m_currentHp || *this == otherHealthPoints)
    {
        return true;
    }
    return false;
}

bool HealthPoints::operator<=(const int numOfHpPoints) const
{
    if (this->m_currentHp <= numOfHpPoints)
    {
        return true;
    }
    return false;
}

bool operator<=(int number, const HealthPoints& healthPoints)
{
    return (healthPoints <= number);
}
//
//
bool HealthPoints::operator<(const HealthPoints& otherHealthPoints) const
{
    return (!(*this >= otherHealthPoints));
}

bool HealthPoints::operator<(const int numOfHpPoints) const
{
    if (this->m_currentHp < numOfHpPoints)
    {
        return true;
    }
    return false;
}

bool operator<(int number, const HealthPoints& healthPoints)
{
    return (healthPoints < number);
}
//
//
bool HealthPoints::operator>(const HealthPoints& otherHealthPoints) const
{
    return (!(*this <= otherHealthPoints));
}

bool HealthPoints::operator>(const int numOfHpPoints) const
{
    if (this->m_currentHp > numOfHpPoints)
    {
        return true;
    }
    return false;
}

bool operator>(int number, const HealthPoints& healthPoints)
{
    return (healthPoints > number);
}




