bool Compare(ListNode* a, ListNode* b)
{
    //return a.time_to_prep < b.time_to_prep;//max
    return a->val > b->val;//min heap ??
}


ListNode* Solution::mergeKLists(vector<ListNode*> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int a = A.size();
    //deque<ListNode*> mine;
    //deque<ListNode*> output;
    priority_queue<ListNode*, vector<ListNode*>, std::function<bool(ListNode* a, ListNode* b)> > my_pq(Compare);
    for(int i =0; i< a; i++){
        my_pq.push(A[i]);
        //mine.push_back(A[i]);
    }
    A.clear();
    ListNode* output = my_pq.top();
    ListNode* outputH = output;
    int flag = 1;
    while(my_pq.size()>0){
        //cout << "size" << my_pq.size() << " ";
        if (flag == 1){
            flag = 0;
        }else{
            output->next = my_pq.top();
            output = output->next;
        }
        ListNode* el = my_pq.top();
        ListNode* el_nxt = el->next;
        if (my_pq.top()->next != NULL){
               my_pq.push(el_nxt);
               my_pq.pop();
        }else{
            my_pq.pop();
        }
        //mine.push_front(el);
    }

    return outputH;
    
}
