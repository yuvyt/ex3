#include "HealthPoints.h"
#include <iostream>
#include <exception>


HealthPoints::HealthPoints(int maxHPInput)//checked
{
    if (maxHPInput <= 0) {
        throw HealthPoints::InvalidArgument();
    }
    this->m_maxHp = maxHPInput;
    this->m_currentHp = maxHPInput;
}

HealthPoints::HealthPoints(
        const HealthPoints &healthPointsToCopy)// i don't know weather it should be default or like this
{
    this->m_currentHp = healthPointsToCopy.m_currentHp;
    this->m_maxHp = healthPointsToCopy.m_maxHp;
}

HealthPoints HealthPoints::operator+( int numOfHpPoints) const //checked
{
    HealthPoints result=*this;
    result += numOfHpPoints;
    return result;
}

HealthPoints operator+(int number, const HealthPoints &healthPoints) //checked
{
    return healthPoints + number;
}

HealthPoints HealthPoints::operator-(const int numOfHpPoints)  {
    return *this + (-numOfHpPoints);
}

HealthPoints &HealthPoints::operator+=(const int numOfHpPoints) {
    int newNumOfPoints = this->m_currentHp + numOfHpPoints;
    if (newNumOfPoints > this->m_maxHp) {
        this->m_currentHp = this->m_maxHp;
    } else if (newNumOfPoints <= 0) {
        this->m_currentHp = 0;
    } else {
        this->m_currentHp = newNumOfPoints;
    }
    return *this;
}

HealthPoints &HealthPoints::operator-=(const int numOfHpPoints) {
    *this = *this - numOfHpPoints;
    return *this;
}

HealthPoints &HealthPoints::operator=(const int numOfHpPoints) {

    this->m_maxHp = numOfHpPoints;
    this->m_currentHp = numOfHpPoints;
    return *this;
}

bool HealthPoints::operator==(const HealthPoints &otherHealthPoints) const {
    if (this->m_currentHp == otherHealthPoints.m_currentHp) {
        return true;
    }
    return false;
}

bool HealthPoints::operator==(const int numOfHpPoints) const {
    if (this->m_currentHp == numOfHpPoints) {
        return true;
    }
    return false;
}

bool operator==(int number, const HealthPoints &healthPoints) {
    return (healthPoints == number);
}

bool HealthPoints::operator!=(const HealthPoints &otherHealthPoints) const {
    return (!(*this == otherHealthPoints));
}

bool HealthPoints::operator!=(const int numOfHpPoints) const {
    if (this->m_currentHp != numOfHpPoints) {
        return true;
    }
    return false;
}

bool operator!=(int number, const HealthPoints &healthPoints) {
    return (healthPoints != number);
}

bool HealthPoints::operator>=(const HealthPoints &otherHealthPoints) const {
    if (this->m_currentHp > otherHealthPoints.m_currentHp || *this == otherHealthPoints) {
        return true;
    }
    return false;
}

bool HealthPoints::operator>=(const int numOfHpPoints) const {
    if (this->m_currentHp >= numOfHpPoints) {
        return true;
    }
    return false;
}

bool operator>=(int number, const HealthPoints &healthPoints) {
    return (healthPoints >= number);
}

bool HealthPoints::operator<=(const HealthPoints &otherHealthPoints) const {
    if (this->m_currentHp < otherHealthPoints.m_currentHp || *this == otherHealthPoints) {
        return true;
    }
    return false;
}

bool HealthPoints::operator<=(const int numOfHpPoints) const {
    if (this->m_currentHp <= numOfHpPoints) {
        return true;
    }
    return false;
}

bool operator<=(int number, const HealthPoints &healthPoints) {
    return (healthPoints <= number);
}

bool HealthPoints::operator<(const HealthPoints &otherHealthPoints) const {
    return (!(*this >= otherHealthPoints));
}

bool HealthPoints::operator<(const int numOfHpPoints) const {
    if (this->m_currentHp < numOfHpPoints) {
        return true;
    }
    return false;
}

bool operator<(int number, const HealthPoints &healthPoints) {
    return (healthPoints < number);
}

bool HealthPoints::operator>(const HealthPoints &otherHealthPoints) const {
    return (!(*this <= otherHealthPoints));
}

bool HealthPoints::operator>(const int numOfHpPoints) const {
    if (this->m_currentHp > numOfHpPoints) {
        return true;
    }
    return false;
}

bool operator>(int number, const HealthPoints &healthPoints) {
    return (healthPoints > number);
}

std::ostream &operator<<(std::ostream &os, const HealthPoints &healthPoints) {
    os << healthPoints.m_currentHp << "(" << healthPoints.m_maxHp << ")";;
    return os;
}
