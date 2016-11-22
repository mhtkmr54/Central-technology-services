bool is_number(string str){
    int flag = 0;
    for(int i = 0; i <= (str.length() - 1); i++) {
        if(isdigit(str[i]) || str[i] == '-' && i == 0 && str.length() > 1) {
            
        } else {
            flag = 1;
            break;
        }
    }
    if (flag == 1){
        return false;
    }else{
        return true;
    }
}


int Solution::evalRPN(vector<string> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
     // Create a stack of capacity equal to expression size
    int i;
 
    // See if stack was created successfully
    deque<int> s;
 
    // Scan all characters one by one
    for (i = 0; i < A.size(); i++)
    {
        // If the scanned character is an operand or number,
        // push it to the stack.
        if (is_number(A[i])){
            //cout << " an-> "<< stoi(A[i]) << "|"; 
            int el = stoi(A[i]);
            s.push_front(el);
        }
            
 
        //  If the scanned character is an operator, pop two
        // elements from stack apply the operator
        else
        {
            int val1 = s.front();
            s.pop_front();
            int val2 = s.front();
            s.pop_front();
            if (val1 == 0 && A[i][0] == '/'){
                return 0;
            }
            switch (A[i][0])
            {
             case '+':  s.push_front(val2 + val1); break;
             case '-': s.push_front(val2 - val1); break;
             case '*':  s.push_front(val2 * val1); break;
             case '/':  s.push_front(val2/val1);  break;
            }
        }
    }
    return s.front();
    
}
