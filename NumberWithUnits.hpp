#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <map>
#include <string>

namespace ariel
{
    class NumberWithUnits
    {

    private:
        static std::map<std::string, std::map<std::string, double>> dic;

    public:
        double value;
        std::string unit;
        //constructor
        NumberWithUnits(double n, std::string s)
        {
            if (dic.find(s) != dic.end())
            {
                value = n;
                unit = s;
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
        NumberWithUnits operator+() const;
        // -
        NumberWithUnits operator-(const NumberWithUnits &other) const; //friend??
        NumberWithUnits operator-=(const NumberWithUnits &other);
        NumberWithUnits operator-() const;

        //comper operator
        bool operator==(const NumberWithUnits &other) const;
        bool operator!=(const NumberWithUnits &other) const;
        bool operator<=(const NumberWithUnits &other) const;
        bool operator>=(const NumberWithUnits &other) const;
        bool operator<(const NumberWithUnits &other) const;
        bool operator>(const NumberWithUnits &other) const;

        //perfix\postfix
        NumberWithUnits &operator++();
        NumberWithUnits operator++(int dummy_flag_for_postfix_increment);

        NumberWithUnits &operator--();
        NumberWithUnits operator--(int dummy_flag_for_postfix_increment);
        // multi
        NumberWithUnits operator*(const double n) const;
        friend NumberWithUnits operator*(const double n, const NumberWithUnits &number);
        //input output

        friend std::ostream &operator<<(std::ostream &output, const NumberWithUnits &n);
        friend std::istream &operator>>(std::istream &input, NumberWithUnits &n);

        friend void compare_exaption(const NumberWithUnits &a, const NumberWithUnits &b)
        {
            if (a.unit == b.unit)
            {
                return;
            }
            if (dic[a.unit][b.unit] == 0)
            {
                throw std::out_of_range("can't compare this tow units!");
            }
        }
    };

}