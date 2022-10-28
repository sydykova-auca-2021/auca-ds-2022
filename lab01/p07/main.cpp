#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
 #include "../../doctest/doctest.h"
 
using namespace std;
 
template <typename C>
string containerToStr(const C &c)
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

TEST_CASE("default constructor")
{
string v;
REQUIRE(v.empty());
REQUIRE(v.size() == 0);
}

TEST_CASE("Copy constructor")
{
string s1("hello");
string s2 = s1; 
REQUIRE(s1 == s2);
}

TEST_CASE("default constructor")
{
string s;
REQUIRE(s.length() == 0);
REQUIRE(s == "");
} 
TEST_CASE("constructor with size and initial value")
{
string s(7, 'c'); 
REQUIRE(s.length() == 7); 
REQUIRE(s == "ccccccc");
} 

TEST_CASE("copy constructor")
{ 
    string s1("hello"); 
    string s2(s1); 
    REQUIRE(s1 == s2); 
    s1 = "hi"; 
    s2 = "Hello"; 
    REQUIRE(s1 == "hi"); 
    REQUIRE(s2 == "Hello");
    } 

TEST_CASE("assignment operator")
{
string s("cow"); 
REQUIRE(s == "cow"); 
s = "cowboy"; 
REQUIRE(s == "cowboy");
} 

TEST_CASE("move constructor")
{ 
string s1("notempty"); 
string s2 = move(s1); 
REQUIRE(s1 == ""); 
REQUIRE(s2 == "notempty");
} 

TEST_CASE("move assignment")
{ 
string s1("notempty"); 
string s2; s2 = move(s1); 
REQUIRE(s1 == ""); 
REQUIRE(s2 == "notempty");
} 
TEST_CASE("subscript operator")
{ 
string s("movie"); 
REQUIRE(s[0] == 'm');
} 

TEST_CASE("at(index)")
{ 
string s("aware"); 
REQUIRE(s.at(4) == 'e'); 
REQUIRE_THROWS_AS(s.at(5), out_of_range);
} 
TEST_CASE("push_back")
{ 
string s; 
s.push_back('a'); 
s.push_back('n'); 
s.push_back('n'); 
s.push_back('a'); 
REQUIRE(s.length() == 4); 
REQUIRE(s == "anna");
} 
TEST_CASE("pop_back")
{ 
    string s("peach"); 
    REQUIRE(s.length() == 5); 
    REQUIRE(s == "peach"); 
    s.pop_back(); 
    s.pop_back();
    REQUIRE(s.length() == 3); 
    REQUIRE(s == "pea");
    } 
TEST_CASE("+, += operators")
{ 
    string s1("Hello"); 
    string s2("World"); 
    string s3 = s1 + s2; 
    REQUIRE(s3 == "HelloWorld");
    }
TEST_CASE("comparison operators, method compare")
{ 
string s1("sun"); 
string s2("moon"); 
bool a = s1 == s2; 
bool b = s1 != s2; 
bool c = s1.length() < s2.length(); 
bool d = s1.length() >= s2.length(); 
REQUIRE(a == false); REQUIRE(b == true); 
REQUIRE(c == true); REQUIRE(d == false); 
REQUIRE(s1.compare(s2) != 0);
} 
TEST_CASE("for (auto &c : str)")
{
    string s1("CASUAL"); 
    string s2;
    for (auto c : s1)
    { 
    s2 += c + 32;
    }
    REQUIRE(s2 == "casual");
} 
TEST_CASE("front()")
{ 
string s("abcde"); 
REQUIRE(s.front() == 'a'); 
s.front() = 'A'; 
REQUIRE(s.front() == 'A');
} 
TEST_CASE("back()")
{ 
string s("abcde"); 
REQUIRE(s.back() == 'e'); 
s.back() = 'E'; 
REQUIRE(s.back() == 'E');
} 
TEST_CASE("substr(index, length), find(char ch)")
{ 
string str("Love and peace"); 
string sbstr = str.substr(0, 4); 
REQUIRE(sbstr == "Love"); 
REQUIRE(sbstr.find('L') == 0);
} 
TEST_CASE("iterators, operators")
{ 
string str("TOMATO"); 
REQUIRE(*str.begin() == 'T'); 
++*str.begin(); 
REQUIRE(*str.begin() == 'U'); --*str.begin(); 
REQUIRE(*str.begin() == 'T'); *str.begin() += 34; 
*str.begin() -= 2; REQUIRE(*str.begin() == 't');
}

TEST_CASE("insert(index, length, char)")
{ 
string str("bay");
str.insert(str.begin(), 1, 'e'); 
REQUIRE(str == "ebay");
} 
TEST_CASE("erase(index, length)")
{ 
string str("volleyball"); 
str.erase(0, 6); 
REQUIRE(str == "ball"); 
REQUIRE(str.length() == 4);
}
TEST_CASE("constructor string(beg, end)")
{ 
string s1("banana"); 
string s2(s1.begin() + 3, s1.end()); 
REQUIRE(s2 == "ana"); 
REQUIRE(s2.length() == 3);
} 

TEST_CASE("reverse algorithm")
{ 
string str("apple"); 
reverse(str.begin(), str.end()); 
REQUIRE(str == "elppa");
} 
// TEST_CASE("sort algorithm")
// { 
//   string str("cebda"); 
//   sort(str.begin(), str.end()); 
//   REQUIRE(str == "binary_search");
//   { 
//     string str("aaaa"); 
//     REQUIRE(binary_search(str.begin(), str.end(), 'a'));
//     }
// }