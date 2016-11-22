#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <queue>
#include <deque>
#include <iterator>
#include <string>
#include <sstream>
#include <functional>

using namespace std;


class IceCream
{
 public:
   int time_to_prep;
    IceCream(int flav) {
          time_to_prep = flav;
       }
};

bool Compare(IceCream a, IceCream b)
{
    //return a.time_to_prep < b.time_to_prep;//max
    return a.time_to_prep > b.time_to_prep;//min heap ??
}

int main()
{
    priority_queue<IceCream, vector<IceCream>, std::function<bool(IceCream a, IceCream b)> > my_pq(Compare);
    my_pq.push(IceCream(4));
    my_pq.push(IceCream(33));
    my_pq.push(IceCream(9));
    my_pq.push(IceCream(11));
    cout << "b4 top  " << my_pq.top().time_to_prep << endl;
    //my_pq.pop();
    IceCream buf = my_pq.top();
    buf.time_to_prep = 5;
    my_pq.pop();
    my_pq.push(buf);
    cout << "New top " << my_pq.top().time_to_prep << endl;
    //cout << my_pq[2].time_to_prep << endl;
    cout << endl;
    return 0;
}