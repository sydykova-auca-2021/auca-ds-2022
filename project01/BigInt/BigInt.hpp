#pragma once

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>


class BigInt
{
    friend std::ostream &operator<<(std::ostream &out, const BigInt &x);
    friend std::istream &operator>>(std::istream &inp, BigInt &x);
    friend bool operator==(const BigInt &x, const BigInt &y);
    
    std::vector<int> mDigits;
    bool mIsNegative;

    static BigInt addAbsValues(const BigInt &x, const BigInt &y)
    {
        auto itX = x.mDigits.rbegin();
        auto itY = y.mDigits.rbegin();

        BigInt z;
        z.mDigits.resize(std::max(x.mDigits.size(), y.mDigits.size()) + 1);
        auto itZ = z.mDigits.rbegin();
        int carry = 0;

        while (itX != x.mDigits.rend() || itY != y.mDigits.rend())
        {
            int s = carry;

            if (itX != x.mDigits.rend())
            {
                s += *itX;
                ++itX;
            }
            if (itY != y.mDigits.rend())
            {
                s += *itY;
                ++itY;
            }

            *itZ = s % 10;
            carry = (s > 9) ? 1 : 0;
            ++itZ;
        }

        if (carry != 0)
        {
            *itZ = carry;
        }
        if (z.mDigits.size() > 1 && z.mDigits.front() == 0)
        {
            z.mDigits.erase(z.mDigits.begin());
        }
        return z;
    }

public:
    BigInt()
        : mIsNegative(false)
    {
        mDigits.push_back(0);
    }
    BigInt(const std::string &s)
        : mIsNegative(false)
    {
        if (s.empty())
        {
            throw std::runtime_error("Cannot be empty");
        }
        if (s[0] == '-')
        {
            mIsNegative = true;
        }

        for (int i = 0; i < s.size(); ++i)
        {
            if (i == 0 && (s[i] == '-' || s[i] == '+'))
            {
                continue;
            }
            if (isdigit(s[i]))
            {
                mDigits.push_back(s[i] - '0');
            }
            else
            {
                throw std::runtime_error("Invalid number");
            }
        }
    }

    BigInt(const int &num)
        : mIsNegative(false)
    {
        if (num < 0)
        {
            mIsNegative = true;
        }
        std::string s = std::to_string(num);
        for (auto d : s)
        {
            mDigits.push_back(d - '0');
        }
    }
    
    BigInt(long long x)
        : BigInt(std::to_string(x))
    {      
    }
};

inline std::ostream &operator<<(std::ostream &out, const BigInt &x)
{
    if (x.mIsNegative)
    {
        out << "-";
    }
    for (auto digit : x.mDigits)
    {
        out << digit;
    }
    return out;
}

inline std::istream &operator>>(std::istream &inp, BigInt &x)
{
    char ch;
    if(!(inp >> ch))
    {
        return inp;
    }
    if(!(std::isdigit(ch) || ch == '+' || '-'))
    {
        inp.putback(ch);
        inp.setstate(std::ios_base::failbit);
        return inp; 
    }
    std::string s;
    if(std::isdigit(ch))
    {
        s += ch;
    }
    while (inp.get(ch) && std::isdigit(ch))
    {
        s += ch;
    }
    x = BigInt(s);
    return inp;
}

inline bool operator==(const BigInt &x, const BigInt &y)
{
    return x.mIsNegative == y.mIsNegative && x.mDigits == y.mDigits;
}
