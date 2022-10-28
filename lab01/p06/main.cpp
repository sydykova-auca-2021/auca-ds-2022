#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../../doctest/doctest.h"
#include <algorithm>
#include <iostream>

#include <vector>
using namespace std;

template <typename C>

string containerToString(const C &c)
{
    ostringstream sout;
    bool isFirst = true;
    sout << "{";
    for (const auto &e : c)
    {
        if (!isFirst)
        {
            sout << ", ";
        }
        sout << e;
        isFirst = false;
    }
    sout << "}";
    return sout.str();
}

int myAbsValue(int x)
{
    if (x < 0)
    {
        x = -x;
    }
    return x;
}
// changing the unsigned int to singed
template <typename C>
int sz(C c)
{
    return c.size();
}

TEST_CASE("Absolute value")
{
    REQUIRE(myAbsValue(-3) == 3);
    REQUIRE(myAbsValue(3) == 3);
    REQUIRE(myAbsValue(0) == 0);
}

TEST_CASE("Default constructro")
{
    vector<int> v;
    REQUIRE(v.empty());
    REQUIRE(v.size() == 0);
    REQUIRE(v.capacity() == 0);
}

TEST_CASE("Push back")
{
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);

    REQUIRE(sz(v) == 5);
    REQUIRE(containerToString(v) == "{1, 2, 3, 4, 5}");
    REQUIRE(v.capacity() == 8);
}

TEST_CASE("Copy constructor(value semantics)")
{
    vector<int> v = {1, 2, 3, 4, 5};

    vector<int> v2 = v;
    REQUIRE(v.size() == 5);
    // REQUIRE(containerToString(v2) == "{1, 2, 3, 4, 5}");

    v[3] = 43;
    v2[4] = 1000;
    REQUIRE(containerToString(v) == "{1, 2, 3, 43, 5}");
    REQUIRE(containerToString(v2) == "{1, 2, 3, 4, 1000}");
}

TEST_CASE("back")
{
    // refrence to the last element
    vector<int> v = {1, 2, 3, 4};
    REQUIRE(v.back() == 4);

    v.back() = 89;
    REQUIRE(v.back() == 89);
    REQUIRE(v[3] == 89);
}

TEST_CASE("Front")
{
    // reference to the first element
    vector<int> v = {1, 2, 3, 4, 5};
    REQUIRE(v.front() == 1);

    v.front() = 90;
    REQUIRE(v.front() == 90);
    REQUIRE(v[0] == 90);
}

TEST_CASE("pop_back")
{
    // removes the last element
    vector<int> v = {1, 2, 3, 4, 5, 6};
    v.pop_back();
    REQUIRE(v.size() == 5);
    REQUIRE(v[4] == 5);
    v[4] = 40;
    REQUIRE(v[4] == 40);
}

TEST_CASE("Default constructor")
{
    // default ready to work constructor
    vector<int> v;
    REQUIRE(v.empty());
    REQUIRE(sz(v) == 0);
}

TEST_CASE("Assingment operator")
{
    // assingment operator (value semantics)
    vector<int> v = {4, 5, 6};
    vector<int> v2;
    REQUIRE(v2.size() == 0);
    v2 = v;
    REQUIRE(v2.size() == 3);
}

TEST_CASE("Erase(pos)")
{
    vector<int> v;
    for (int i = 1; i <= 10; i++)
    {
        v.push_back(i);
    }
    // erase element 5
    v.erase(v.begin() + 4);
    REQUIRE(containerToString(v) == "{1, 2, 3, 4, 6, 7, 8, 9, 10}");
    REQUIRE(sz(v) == 9);
    v.erase(v.begin() + 7);
    REQUIRE(containerToString(v) == "{1, 2, 3, 4, 6, 7, 8, 10}");
    REQUIRE(sz(v) == 8);
}

TEST_CASE("Erase(beg, end")
{
    vector<int> v;
    for (int i = 1; i <= 10; i++)
    {
        v.push_back(i);
    }
    // v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}
    //  erase elements from 4th element until 8th element
    v.erase(v.begin() + 3, v.begin() + 7);
    REQUIRE(v.size() == 6);
    REQUIRE(containerToString(v) == "{1, 2, 3, 8, 9, 10}");
    // erase first three elements
    v.erase(v.begin(), v.begin() + 3);
    REQUIRE(sz(v) == 3);
    REQUIRE(containerToString(v) == "{8, 9, 10}");
}

TEST_CASE("Constructor with size and initial value")
{
    vector<int> v(5, 10);
    REQUIRE(containerToString(v) == "{10, 10, 10, 10, 10}");
    REQUIRE(v.size() == 5);
    // REQUIRE(v(0) == v(1) == v(2) == v(3) == v(4) == v(5) == 10);
}

TEST_CASE("Constructor with size")
{
    vector<int> vec(5);
    vec = {1, 2, 3, 4, 5};
    REQUIRE(sz(vec) == 5);
    REQUIRE(containerToString(vec) == "{1, 2, 3, 4, 5}");
    // int i;
    // vector<int> v(i);
    //  for (i = 1; i <= 10; ++i)
    // {

    //     v.push_back(i);
    // }
    // v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    // REQUIRE(sz(v) == 10);
    // REQUIRE(containerToString(v) == "{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}");
}

TEST_CASE("Subscript operator")
{
}

TEST_CASE("insert(pos, value)")
{

    // vector<int> vector_name{ 1, 2, 3, 4, 5 };

    // // Printing out the original vector
    // cout << "Original vector :\n";
    // for (auto x : vector_name)
    //     cout << x << " ";
    // cout << "\n";

    // // Inserting the value 100 at position 3(0-based
    // // indexing) in the vector
    // vector_name.insert(vector_name.begin() + 3,100);
    vector<int> v{1, 2, 3, 4, 5, 6};
    v.insert(v.begin() + 3, 100);
    REQUIRE(sz(v) == 7);
    REQUIRE(containerToString(v) == "{1, 2, 3, 100, 4, 5, 6}");
}

TEST_CASE("insert(pos, elementToBeInserted, finding the element)")
{
    vector<int> v = {1, 2, 3, 4, 5, 6, 7};
    // 3 is the num of copies to be inserted// 99 is the element to be inserted
    v.insert(v.begin() + 3, 3, 99);
    REQUIRE(sz(v) == 10);
    REQUIRE(containerToString(v) == "{1, 2, 3, 99, 99, 99, 4, 5, 6, 7}");

    // vector<int> vec  {3, 1, 4, 9, 0, 1};
    // vector<int> temp  {1, 101};
    // vec.insert(vec.begin() + 2, temp, temp.begin() + 1);// {3, 1, 101, 4, 9, 0, 1}

    // // REQUIRE(sz(vec) == 7);
    // REQUIRE(containerToString(vec) == "{3, 1, 101, 4, 9, 0, 1}")
}

TEST_CASE("min element")
{
    vector<int> v = {1, 2, 100000, 0, 10, -11111, 9};
    int mininum = 0;
    mininum = *min_element(v.begin(), v.end());
    REQUIRE(mininum == -11111);
}

TEST_CASE("max element")
{
    vector<int> v;
    int maximum = 0;

    for (int i = 1; i < 10; ++i)
    {
        v.push_back(i);
        maximum = *max_element(v.begin(), v.end());
    }
    REQUIRE(maximum == 9);
}

TEST_CASE("sort algorithm")
{
    vector<int> v = {5, 9, 2, 300, 1, 10, 4, 0};
    sort(v.begin() + 3, v.end());
    REQUIRE(containerToString(v) == "{5, 9, 2, 0, 1, 4, 10, 300}");
    sort(v.begin(), v.begin() + 3);
    REQUIRE(containerToString(v) == "{2, 5, 9, 0, 1, 4, 10, 300}");
    sort(v.begin(), v.end());
    REQUIRE(containerToString(v) == "{0, 1, 2, 4, 5, 9, 10, 300}");
}

TEST_CASE("reverse algorirthm")
{
    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8};
    reverse(v.begin(), v.end());
    REQUIRE(containerToString(v) == "{8, 7, 6, 5, 4, 3, 2, 1}");
    REQUIRE(v[0] == 8);
    REQUIRE(v[1] == 7);
    REQUIRE(v[4] == 4);
    REQUIRE(v[7] == 1);

    vector<double> v2 = {1.2222, 9.0, 10.11, 10.9999, 10.01};
    reverse(v2.begin(), v2.end());
    REQUIRE(containerToString(v2) == "{10.01, 10.9999, 10.11, 9, 1.2222}");
    REQUIRE(v2.at(2) == 10.11);
    REQUIRE(v2.at(4) == 1.2222);
}

TEST_CASE("method at")
{
    vector<int> v = {90000, 0, 3000, 8, -10, 3};
    REQUIRE(v.at(2) == 3000);
    REQUIRE(v.at(5) == 3);
    REQUIRE(v.at(0) == 90000);
}

TEST_CASE("binary search")
{
    vector<int> v = {1, 2, 3, 90000, 0, 41, 44};
    bool found = binary_search(v.begin(), v.end(), 0);

    REQUIRE(found == true);

    vector<int> v2 = {90, 4, 14, 12, 90, 80};
    bool found2 = binary_search(v2.begin(), v2.end(), 14);

    REQUIRE(found2 == false);
}
