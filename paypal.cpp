/*
 * Complete the function below.
 */

int ispower(string s){
    int sum = 0;
    for(int i = s.length()-1 ; i>= 0; i--){
        int p = s.length()-1-i;
        sum += pow(2,p)*s[i]; 
    }
    if (sum % 5 == 0){
        return 1;
    }
    else{
        return 0;
    }
}

int flag = 0;

int do_to_s(string& str){
        std::size_t found = str.find("101");
        if (found!=std::string::npos)
        {
        ++minim;
        cout << " 101: " << found << '\n';
        s.erase(s.begin()+found, s.begin()+found+3);
        }else{
            break;
        }
    return 0;
}

int getMin(string s) {
    string dem = s;
    
    if (ispower(s)){
        return 1;
    }
    int minim = 0;
    reverse(s.begin(),s.end());
    
    while(1){
        std::size_t found = s.find("101");
        if (found!=std::string::npos)
        {
        ++minim;
        cout << " 101: " << found << '\n';
        s.erase(s.begin()+found, s.begin()+found+3);
        }else{
            break;
        }
    }
    
    if (minim == 0){
        return -1;
    }
    return minim;
   
    
}


