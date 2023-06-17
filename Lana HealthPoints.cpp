#include "HealthPoints.h"
#include <iostream>


HealthPoints::HealthPoints(int maxHPInput)//checked
{
    if (maxHPInput <= 0) {
        throw HealthPoints::InvalidArgument();
    }
    this->m_maxHealthpoints = maxHPInput;
    this->m_currentHealthpoints = maxHPInput;
}

HealthPoints::HealthPoints(
        const HealthPoints &healthPointsToCopy)
{
    this->m_currentHealthpoints = healthPointsToCopy.m_currentHealthpoints;
    this->m_maxHealthpoints = healthPointsToCopy.m_maxHealthpoints;
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
    int newNumOfPoints = this->m_currentHealthpoints + numOfHpPoints;
    if (newNumOfPoints > this->m_maxHealthpoints) {
        this->m_currentHealthpoints = this->m_maxHealthpoints;
    } else if (newNumOfPoints <= 0) {
        this->m_currentHealthpoints = 0;
    } else {
        this->m_currentHealthpoints = newNumOfPoints;
    }
    return *this;
}

HealthPoints &HealthPoints::operator-=(const int numOfHpPoints) {
    *this = *this - numOfHpPoints;
    return *this;
}

HealthPoints &HealthPoints::operator=(const int numOfHpPoints) {
if(numOfHpPoints<=0){
    throw InvalidArgument();
}
    this->m_maxHealthpoints = numOfHpPoints;
    this->m_currentHealthpoints = numOfHpPoints;
    return *this;
}

bool HealthPoints::operator==(const HealthPoints &otherHealthPoints) const {
    if (this->m_currentHealthpoints == otherHealthPoints.m_currentHealthpoints) {
        return true;
    }
    return false;
}

bool HealthPoints::operator==(const int numOfHpPoints) const {
    if (this->m_currentHealthpoints == numOfHpPoints) {
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
    if (this->m_currentHealthpoints != numOfHpPoints) {
        return true;
    }
    return false;
}

bool operator!=(int number, const HealthPoints &healthPoints) {
    return (healthPoints != number);
}

bool HealthPoints::operator>=(const HealthPoints &otherHealthPoints) const {
    if (this->m_currentHealthpoints > otherHealthPoints.m_currentHealthpoints || *this == otherHealthPoints) {
        return true;
    }
    return false;
}

bool HealthPoints::operator>=(const int numOfHpPoints) const {
    if (this->m_currentHealthpoints >= numOfHpPoints) {
        return true;
    }
    return false;
}

bool operator>=(int number, const HealthPoints &healthPoints) {
    return (healthPoints >= number);
}

bool HealthPoints::operator<=(const HealthPoints &otherHealthPoints) const {
    if (this->m_currentHealthpoints < otherHealthPoints.m_currentHealthpoints || *this == otherHealthPoints) {
        return true;
    }
    return false;
}

bool HealthPoints::operator<=(const int numOfHpPoints) const {
    if (this->m_currentHealthpoints <= numOfHpPoints) {
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
    if (this->m_currentHealthpoints < numOfHpPoints) {
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
    if (this->m_currentHealthpoints > numOfHpPoints) {
        return true;
    }
    return false;
}

bool operator>(int number, const HealthPoints &healthPoints) {
    return (healthPoints > number);
}

std::ostream &operator<<(std::ostream &os, const HealthPoints &healthPoints) {
    os << healthPoints.m_currentHealthpoints << "(" << healthPoints.m_maxHealthpoints << ")";
    return os;
}
