	map <int,char> memo;

bool isValid(char A){
    int a = A - '0';
    //cout << "|| a--> " << a;
    if (memo.find(a) != memo.end() && A != '0'){
        //cout  << " alid";
        return true;
    }else{
        return false;
    }
}

int ways(string s, int startIndex, int answer) {
    // BASE CASES
    if (startIndex >= s.length()){
        return 0;
    }
/*     if (startIndex == s.length()-1 && isValid(s[startIndex])){
        return 1;
    }*/
    
     if (isValid(s[startIndex])){
        // cout << "1el" << " ";
       answer +=  1 + ways(s, startIndex + 1, answer);
     } 
     int lm = s.length()-2;
    if ( startIndex <= lm && isValid(s[startIndex] + s[startIndex + 1])){
        cout << "2el" << " " << startIndex << " " << lm ;
        answer +=  1 + ways(s, startIndex + 2, answer);
    } 
    return answer;
 }


int Solution::numDecodings(string A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    for (int i = 0; i < 26; i++){
        memo[i+1] = (char)((int)'A'+i);
    }
/*    for(auto el : memo){
        cout << el.first << " : " << el.second << " ||| " << " ";
    }*/
    int a = ways(A,0,0);   
    return a;
}
