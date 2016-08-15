#include <iostream>
#include <vector>
#include <list>

using namespace std;

class Solution {
    //Write your code here
private:
    vector<int> p;
    list<int> q;
    int top = -1;
    int length;

public:
    void pushCharacter(int elem);
    void enqueueCharacter(int elem);
    char popCharacter();
    char dequeueCharacter();
};

void Solution::pushCharacter(int elem)
{
    top++;
    p.push_back(elem);
}

void Solution::enqueueCharacter(int elem)
{
    q.push_back(elem);
}

char Solution::popCharacter()
{
    char comp = p.at(top);
    p.pop_back();
    top--;
    return comp;
}

char Solution::dequeueCharacter()
{
    char temp = q.front();
    q.pop_front();
    return temp;
}
