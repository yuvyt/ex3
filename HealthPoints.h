#ifndef HEALTHPOINTS_H
#define HEALTHPOINTS_H

#include <iostream>
#include <exception>

class HealthPoints
{
    public:
    HealthPoints() = default;
    /*c'tor for the class HealthPoints.
    *@param: maxHPInput: implemented as the max Health Points possible 
    * and as the starting amount of current points
    * 
    */
    HealthPoints(int maxHP = 100);
    HealthPoints(const HealthPoints& healthPointsToCopy);

    class InvalidArgument : public std::exception
    {
        public:
        const char* what()
        {
            return "Invalid Argument";
        }
    };
    
    
    HealthPoints operator+(const int numOfHpPoints) const;

    HealthPoints operator-(const int numOfHpPoints) const;

    HealthPoints& operator+=(const int numOfHpPoints);

    HealthPoints& operator-=(const int numOfHpPoints);

    HealthPoints& operator=(const int numOfHpPoints);

    bool operator==(const HealthPoints& otherHealthPoints) const;
    bool operator==(const int numOfHpPoints) const;

    bool operator!=(const HealthPoints& otherHealthPoints) const;
    bool operator!=(const int numOfHpPoints) const;

    bool operator>=(const HealthPoints& otherHealthPoints) const;
    bool operator>=(const int numOfHpPoints) const;

    bool operator<=(const HealthPoints& otherHealthPoints) const;
    bool operator<=(const int numOfHpPoints) const;

    bool operator<(const HealthPoints& otherHealthPoints) const;
    bool operator<(const int numOfHpPoints) const;

    bool operator>(const HealthPoints& otherHealthPoints) const;
    bool operator>(const int numOfHpPoints) const;

    std::ostream& operator<<(std::ostream& os)
    {
        os << this->m_currentHp << "(";
        os << this->m_maxHp << ")";
        return os;
    }

    private:
    int m_currentHp;
    int m_maxHp;
};

#endif