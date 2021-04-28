#include "NumberWithUnits.hpp"
#include <iterator>
#include <map>
#include <string>
using namespace std;
using namespace ariel;

const double EPS= 0.001;

// read the units from a text file
map<string, map<string, double>> NumberWithUnits::dic;
void NumberWithUnits::read_units(ifstream &file)
{
    double left_val=0;
    string left_units;
    char eq='\0';
    double right_val=0;
    string right_unit;
    while (file >> left_val >> left_units >> eq >> right_val >> right_unit)
    {
        double val = right_val / left_val;
        // create conection for left_units
        map<string, double>::iterator iter = NumberWithUnits::dic[right_unit].begin();
        while (iter != NumberWithUnits::dic[right_unit].end())
        {
            NumberWithUnits::dic[left_units][iter->first] = val * iter->second;       // insert
            NumberWithUnits::dic[iter->first][left_units] = 1 / (val * iter->second); // insert
            ++iter;
        }
        iter = NumberWithUnits::dic[left_units].begin();
        while (iter != NumberWithUnits::dic[left_units].end())
        {
            NumberWithUnits::dic[right_unit][iter->first] = 1 / (val / iter->second); // insert
            NumberWithUnits::dic[iter->first][right_unit] = val / iter->second;       // insert
            ++iter;
        }
        NumberWithUnits::dic[left_units][right_unit] = val;     // insert
        NumberWithUnits::dic[right_unit][left_units] = 1 / val; // insert
    }
}

//matemtic operator +
//
NumberWithUnits NumberWithUnits::operator+(const NumberWithUnits &other) const
{
    compare_exaption(*this, other);
    if (this->unit == other.unit)
    {
        return NumberWithUnits(this->value + other.value, this->unit);
    }
    return NumberWithUnits(this->value + (other.value * NumberWithUnits::dic[other.unit][this->unit]), this->unit);
}

NumberWithUnits NumberWithUnits::operator+=(const NumberWithUnits &other)
{
    compare_exaption(*this, other);
    if (this->unit == other.unit)
    {
        this->value += other.value;
    }
    else
    {
        this->value += (other.value * NumberWithUnits::dic[other.unit][this->unit]);
    }
    return *this;
}

// onary
NumberWithUnits NumberWithUnits::operator+() const
{
    return NumberWithUnits(this->value, this->unit);
}

// -
NumberWithUnits NumberWithUnits::operator-(const NumberWithUnits &other) const
{
    return *this + (-other);
}

NumberWithUnits NumberWithUnits::operator-=(const NumberWithUnits &other)
{
    compare_exaption(*this, other);
    if (this->unit == other.unit)
    {
        this->value -= other.value;
    }
    else
    {
        this->value -= (other.value * NumberWithUnits::dic[other.unit][this->unit]);
    }
    return *this;
}

NumberWithUnits NumberWithUnits::operator-() const
{
    return NumberWithUnits(-1 * this->value, this->unit);
}

//comper operator
bool NumberWithUnits::operator==(const NumberWithUnits &other) const
{
    NumberWithUnits temp = *this - other;
    return abs(temp.value) < EPS;
}
bool NumberWithUnits::operator!=(const NumberWithUnits &other) const
{
    return !(*this == other);
}

bool NumberWithUnits::operator<=(const NumberWithUnits &other) const
{
    return !(*this > other);
}

bool NumberWithUnits::operator>=(const NumberWithUnits &other) const
{
    return !(*this < other);
}

bool NumberWithUnits::operator<(const NumberWithUnits &other) const
{
    compare_exaption(*this, other);
    if (this->unit == other.unit)
    {
        return (this->value < other.value);
    }

    return (this->value < (other.value * NumberWithUnits::dic[other.unit][this->unit]));
}

bool NumberWithUnits::operator>(const NumberWithUnits &other) const
{
    return other < *this;
}

//perfix\postfix
NumberWithUnits &NumberWithUnits::operator++()
{
    this->value++;
    return *this;
}
NumberWithUnits NumberWithUnits::operator++(int dummy_flag_for_postfix_increment) // need reference??
{
    NumberWithUnits temp = *this;
    this->value++;
    return temp;
}
NumberWithUnits &NumberWithUnits::operator--()
{
    this->value--;
    return *this;
}
NumberWithUnits NumberWithUnits::operator--(int dummy_flag_for_postfix_increment)
{
    NumberWithUnits temp = *this;
    this->value--;
    return temp;
}
// multi
NumberWithUnits ariel::operator*(const double n, const NumberWithUnits &number)
{
    return number * n;
}
NumberWithUnits NumberWithUnits::operator*(const double n) const
{
    //this->value*=n;
    return NumberWithUnits(this->value * n, this->unit);
}
//input output

ostream &ariel::operator<<(ostream &output, const NumberWithUnits &n)
{
    output << n.value << "[" << n.unit << "]";
    return output;
}

static istream &getAndCheckNextCharIs(istream &input, char expectedChar)
{
    char actualChar='\0';
    input >> actualChar;
    if (!input)
    {
        return input;
    }

    if (actualChar != expectedChar)
    {
        // failbit is for format error
        input.setstate(ios::failbit);
    }
    return input;
}

istream &ariel::operator>>(istream &input, NumberWithUnits &n)
{
    string u;
    double v = 0;

    // remember place for rewinding
    ios::pos_type startPosition = input.tellg();

    if ((!(input >> v)) ||
        (!getAndCheckNextCharIs(input, '[')) ||
        (!(input >> u))) 
    {
        // rewind on error
        auto errorState = input.rdstate(); // remember error state
        input.clear();                     // clear error so seekg will work
        input.seekg(startPosition);        // rewind
        input.clear(errorState);           // set back the error flag
        throw invalid_argument("input is dont good");
    }
    if (u.at(u.length() - 1) == ']')
    {
        u = u.substr(0, u.length() - 1);
    }
    else
    {
        if (!(getAndCheckNextCharIs(input, ']')))
        {
            throw invalid_argument("input is dont good");
        }
    }
    NumberWithUnits a(v, u); // check input
    n.value = v;
    n.unit = u;
    return input;
}

//  int main()
//  {
//      // ifstream MyReadFile("units.txt");
//      // NumberWithUnits::read_units(MyReadFile);
//      // NumberWithUnits a(1,"km");
//      // 4*a;
//      // //NumberWithUnits::dic["hey"]["hoo"]=1.24;
//      // //NumberWithUnits::dic.at("hey").at("hoo")=1.24;
//      try
//      {
//          NumberWithUnits(0, "year");
//      }
//      catch (const std::exception &e)
//      {
//          cout << "catch exaption" << endl;
//      }

//      return 0;
//  }