#include <iostream>
#include <cstdlib>
#include <string>
#include <map>
#include <iterator>
using namespace std;

map<int,string> convertStringToArray(string s){
    map<int,string> m;
    int len=s.length();
    int k=0;
    for(int i=0;i<len;){
        int j=i;
        string word="";
        while(j<len && s[j]!=' '){
            word += s[j];
            //cout<<word<<endl;
            ++j;
        }
        //cout<<"Final: "<<word<<endl;
        m[k++] = word;
        i = j+1;
    }
    return m;
}

int main(){
    string replacementArray="Smartprix site india comparison best",posArray="{} is {4} online {3} shopping {} in {}";
    map<int,string> m = convertStringToArray(replacementArray);
    map<int,string>::iterator it;
    for(it = m.begin(); it!= m.end(); ++it){
        cout << it->first << " : " << it->second << endl;
    }
    string ans="";
    int countOfBraces=0;
    int len=posArray.length();
    for(int i=0;i<len;){
        if(posArray[i]=='{'){
            int j=i+1;
            char word[1000];
            int k=0;
            bool isAlpha=false;
            while(posArray[j]!='}'){
                word[k++] = posArray[j];
                if(isalpha(posArray[j])){
                    isAlpha = true;
                }
                ++j;
            }
            if(isAlpha){
                for(int l=0;l<k;++l){
                    ans += word[l];
                }
            }
            else{
                int index;
                if(k==0){
                    index = countOfBraces;
                    ++countOfBraces;
                }
                else{
                    index = atoi(word);
                }
                ans += m[index];
            }
            i = j+1;
        }
        else{
            ans += posArray[i];
            ++i;
        }
    }
    cout<<ans<<endl;
    return 0;
}
