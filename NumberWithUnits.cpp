#include "NumberWithUnits.hpp"
using namespace std;
using namespace ariel;

NumberWithUnits a(1, "km");
void NumberWithUnits::read_units(ifstream &file)
{
    string line;
    while (getline(file,line))
    {
        cout<<line;
    }
    

}

//matemtic operator +
//
NumberWithUnits NumberWithUnits::operator+(const NumberWithUnits &other) const
{

    return a;
}

NumberWithUnits NumberWithUnits::operator+=(const NumberWithUnits &other)
{

    return a;
}
NumberWithUnits &NumberWithUnits::operator+() const
{
    return a;
}
// -
NumberWithUnits NumberWithUnits::operator-(const NumberWithUnits &other) const
{

    return a;
}
NumberWithUnits NumberWithUnits::operator-=(const NumberWithUnits &other)
{

    return a;
}
const NumberWithUnits &NumberWithUnits::operator-() const
{
    return a;
}

//comper operator
bool NumberWithUnits::operator==(const NumberWithUnits &other) const
{
    return true;
}
bool NumberWithUnits::operator!=(const NumberWithUnits &other) const
{
    return true;
}

const NumberWithUnits &NumberWithUnits::operator<=(const NumberWithUnits &other) const
{
    return a;
}
const NumberWithUnits &NumberWithUnits::operator>=(const NumberWithUnits &other) const
{
    return a;
}
const NumberWithUnits &NumberWithUnits::operator<(const NumberWithUnits &other) const
{
    return a;
}
const NumberWithUnits &NumberWithUnits::operator>(const NumberWithUnits &other) const
{
    return a;
}

//perfix\postfix
NumberWithUnits &NumberWithUnits::operator++()
{
    return *this;
}
NumberWithUnits &NumberWithUnits::operator++(int dummy_flag_for_postfix_increment)
{
    return *this;
}
NumberWithUnits &NumberWithUnits::operator--()
{
    return *this;
}
NumberWithUnits &NumberWithUnits::operator--(int dummy_flag_for_postfix_increment)
{
    return *this;
}
// multi
NumberWithUnits &ariel::operator*(const double n, NumberWithUnits &number)
{
    return a;
}
NumberWithUnits &NumberWithUnits::operator*(const double n)
{
    return *this;
}
//input output

ostream &ariel::operator<<(ostream &output, const NumberWithUnits &n)
{
    return output;
}
istream &ariel::operator>>(istream &input, NumberWithUnits &n)
{
    return input;
}