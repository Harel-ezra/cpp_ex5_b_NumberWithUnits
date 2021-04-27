#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <map>

namespace ariel
{
    class NumberWithUnits
    {
      
    private:
        double value;
        std::string unit;

    public:   
        static std::map<std::string, std::map<std::string,double>> dic;

        //constructor
        NumberWithUnits(double n, std::string s)
        {
            if(dic.find(s)!=dic.end())
            {
                value=n;
                unit=s;
            }
            else
            {
                throw std::out_of_range("Invalid Unit!");
            }
        }
        //distractor
        ~NumberWithUnits()
        {
        }
        static void read_units(std::ifstream &file);

        //matemtic operator +
        //
        NumberWithUnits operator+(const NumberWithUnits &other) const; // firend??
        NumberWithUnits operator+=(const NumberWithUnits &other);
        NumberWithUnits &operator+() const;
        // -
        NumberWithUnits operator-(const NumberWithUnits &other) const; //friend??
        NumberWithUnits operator-=(const NumberWithUnits &other);
        const NumberWithUnits &operator-() const;

        //comper operator
        bool operator==(const NumberWithUnits &other) const;
        bool operator!=(const NumberWithUnits &other) const;

        const NumberWithUnits &operator<=(const NumberWithUnits &other) const;
        const NumberWithUnits &operator>=(const NumberWithUnits &other) const;
        const NumberWithUnits &operator<(const NumberWithUnits &other) const;
        const NumberWithUnits &operator>(const NumberWithUnits &other) const;

        //perfix\postfix
        NumberWithUnits &operator++();
        NumberWithUnits &operator++(int dummy_flag_for_postfix_increment);

        NumberWithUnits &operator--();
        NumberWithUnits &operator--(int dummy_flag_for_postfix_increment);
        // multi
        NumberWithUnits &operator*(const double n);
        friend NumberWithUnits &operator*(const double n, NumberWithUnits &number);
        //input output

        friend std::ostream &operator<<(std::ostream &output, const NumberWithUnits &n);
        friend std::istream &operator>>(std::istream &input, NumberWithUnits &n);
        
        friend bool compare_exaption(const NumberWithUnits &a, const NumberWithUnits &b)
        {
            if (dic[a.unit][b.unit]==0)
            {
                return false;
            }
            return true;
        }
    };

}