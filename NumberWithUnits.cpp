#include "NumberWithUnits.hpp"
#include <iterator>
#include <map>
using namespace std;
using namespace ariel;
//#include <bits/stdc++.h>



NumberWithUnits a(1, "km");
map<string, map<string,double>> NumberWithUnits::dic;
void NumberWithUnits::read_units(ifstream &file)
{
    double left_val;
    string left_units;
    char eq;
    double right_val;
    string right_unit;
    while(file>>left_val>>left_units>>eq>>right_val>>right_unit)
    {
        double val=right_val/left_val;
        // create conection for left_units
        map<string,double>::iterator iter = NumberWithUnits::dic[right_unit].begin();
        while(iter!=NumberWithUnits::dic[right_unit].end())
        {
            NumberWithUnits::dic[left_units][iter->first]=val*iter->second; // insert 
            NumberWithUnits::dic[iter->first][left_units]=1/(val*iter->second); // insert
            // cout<<"1 "<<left_units<<" = "<<val*iter->second<<" "<<iter->first<<endl;
            // cout<<"1 "<<iter->first<<" = "<<1/(val*iter->second)<<" "<<left_units<<endl;   
            ++iter;

        }
        iter=NumberWithUnits::dic[left_units].begin();
        while(iter!=NumberWithUnits::dic[left_units].end())
        {
            NumberWithUnits::dic[right_unit][iter->first]=1/(val/iter->second); // insert 
            NumberWithUnits::dic[iter->first][right_unit]=val/iter->second; // insert
            // cout<<"1 "<<right_unit<<" = "<<1/(val/iter->second)<<" "<<iter->first<<endl;
            // cout<<"1 "<<iter->first<<" = "<<val/iter->second<<" "<<right_unit<<endl;
            ++iter;
        }
        NumberWithUnits::dic[left_units][right_unit]=val; // insert 
        NumberWithUnits::dic[right_unit][left_units]=1/val; // insert
        //cout<<"insert one"<<endl;
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

int main()
{
    ifstream MyReadFile("units.txt");
    NumberWithUnits::read_units(MyReadFile);
    //NumberWithUnits::dic["hey"]["hoo"]=1.24;
    //NumberWithUnits::dic.at("hey").at("hoo")=1.24;
    return 0;
}