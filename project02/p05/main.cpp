#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

struct Skill
{
    int conSalary;
    string conSkill;
    
    Skill(string skill, int salary)
        : conSkill(skill), conSalary(salary)
    {
    }
};

int main()
{
    iostream::sync_with_stdio(false);

    int nOfSkills, nOfTexts;
    cin >> nOfSkills;
    cin >> nOfTexts;
    vector<Skill> skills;

    for (int i = 0; i < nOfSkills; i++)
    {
        string skill;
        int salary;
        cin >> skill >> salary;
        skills.push_back(Skill(skill, salary));
    }

    sort(begin(skills), end(skills), [](Skill skill1, Skill skill2)
        { return skill1.conSkill < skill2.conSkill; });

    int result = 0;
    string skill;

    while (cin >> skill)
    {
        if (skill == ".")
        {
            cout << result << endl;
            result = 0;
        }

        auto it = lower_bound(begin(skills), end(skills), skill, [](Skill a, string b)
            { return a.conSkill < b; });
        if (it != skills.end() && (it->conSkill == skill))
        {
            result += (it->conSalary);
        }
    }
}