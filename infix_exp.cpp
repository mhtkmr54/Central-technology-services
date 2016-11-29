#include <iostream>
#include <cstring>
#include <deque>
#include <string>
#include <stack>

using namespace std;

int GetResult( char * rpn ) 
{
    std::stack<int> myStack;

    int nr1, nr2; int length = strlen(rpn);

    for (int i = 0; i < length; i++)
    {
        if (isdigit(rpn[i]))
        {
            myStack.push(rpn[i] - '0');
        }
        else
        {
            switch(rpn[i])
            {
                case '+':
                    nr1 = myStack.top();
                    myStack.pop();
                    nr2 = myStack.top();
                    myStack.pop();
                    myStack.push(nr2 + nr1);
                    break;

                case '-':
                    nr1 = myStack.top();
                    myStack.pop();
                    nr2 = myStack.top();
                    myStack.pop();
                    myStack.push(nr2 - nr1);
                    break;

                case '*':
                    nr1 = myStack.top();
                    myStack.pop();
                    nr2 = myStack.top();
                    myStack.pop();
                    myStack.push(nr2 * nr1);
                    break;

                case '/':
                    nr1 = myStack.top();
                    myStack.pop();
                    nr2 = myStack.top();
                    myStack.pop();
                    myStack.push(nr2 / nr1);
                    break;
                default:
                    break;
            }
        }
    }

    return myStack.top();
}

int main(int argc, char* argv[])
{
    char *rpn = "34+12*-1+";

    int rez = GetResult(rpn);

    cout << rez;

    return 0;
}