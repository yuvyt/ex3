#ifndef HEALTHPOINTS_H
#define HEALTHPOINTS_H

#include <iostream>
#include <exception>

class HealthPoints
{

public:
    /*c'tor for the class HealthPoints.
    *@param: maxHPInput: implemented as the max Health Points possible 
    * and as the starting amount of current points
    * 
    */
    friend std::ostream& operator<<(std::ostream& os, const HealthPoints& healthPoints);

    HealthPoints(int maxHP = 100);
    HealthPoints(const HealthPoints& healthPointsToCopy);
    HealthPoints&operator=(const HealthPoints& healthPointsToCopy);
    class InvalidArgument : public std::exception
    {
    public:
        const char* what()
        {
            return "Invalid Argument";
        }
    };
    ~HealthPoints()=default;

    HealthPoints operator+(const int numOfHpPoints) const ;

    HealthPoints operator-(const int numOfHpPoints) ;

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

private:
    int m_currentHp;
    int m_maxHp;
};
HealthPoints operator+(const int numOfHpPoints,  const HealthPoints& healthPoint);//check


bool operator==(int number, const HealthPoints &healthPoints);

#endif
