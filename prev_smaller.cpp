vector<int> Solution::prevSmaller(vector<int> &A) {
    vector<int> ans;
    int i = 0;
    stack<int> s;
    //s.top = -1;
    int element, next;
    map<int,deque<int> > mine;
    /* push the first element to stack */
    reverse(A.begin(),A.end());
    s.push(A[0]);
    int n = A.size(); 
    if (n==1){
        ans.push_back(-1);
        return ans;
    }
    // iterate for rest of the elements
    for (int i=1; i<n; i++)
    {
        next = A[i];
        if (!s.empty())
        {
            // if stack is not empty, then pop an element from stack
            int element = s.top();
            s.pop();
            /* If the popped element is smaller than next, then
                a) print the pair
                b) keep popping while elements are smaller and
                stack is not empty */
            while (element > next)
            {
                //cout << " |" << element << " - " << next << "| ";
                mine[element].push_back(next);
                if(s.empty()){
                    break;
                }
                element = s.top();
                s.pop();
            }
 
            /* If element is greater than next, then push
               the element back */
            if (element < next)
                s.push(element);
        }
 
        /* push next to stack so that we can find
           next greater for it */
        s.push(next);
    }
 
    /* After iterating over the loop, the remaining
       elements in stack do not have the next greater
       element, so print -1 for them */
    while (!s.empty())
    {
        int element = s.top();
        s.pop();
        next = -1;
         //cout << " |" << element << " - " << next << "| ";
         mine[element].push_back(next);
    }
    for(auto el : A){
        if(mine[el].size() >= 1){
            ans.push_back(mine[el].front());
            mine[el].pop_front();
        }
        
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
