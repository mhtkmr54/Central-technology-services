#include <iostream>
#include <cstring>
#include <deque>
#include <string>


using namespace std;

deque<int> numstack;
deque<char> charstack;

void executive_decision(){
	  int op3;
     charstack.pop_front();
     while(1){
     	  int op2 = numstack.front();
          numstack.pop_front();
          int op1 = numstack.front();
          numstack.pop_front();
          char a =  charstack.front();
           charstack.pop_front();
          if (a == '+'){
            op3 = op1 + op2;
          }
          if (a == '-'){
             op3 = op1 - op2;
          }
          if (a == '/'){
            op3 = op1 / op2;
          }
          if (a == '*'){
            op3 = op1 * op2;
          }
          a = charstack.front();
          numstack.push_front(op3);
          if ( a == '('){
            charstack.pop_front();
            break;
          }
     }
    return;
}

void expression_eval(char *str){

	for (int i =0; i < strlen(str); ){
		if (isdigit(str[i]) == 0 ){
          if(str[i] == ')'){
          	charstack.push_front(str[i]);
            executive_decision();
          }
          else{
            charstack.push_front(str[i]);
          }
		    i++;
		}
		else{
			string res = "";
			while ( isdigit(str[i]) != 0 ){
			  res += to_string(str[i] - '0');
              i++;
			}
			int num = stoi(res);
			numstack.push_front(num);
		}
	}
}

int main(){
	string str1 = "1+44+(4*(9/3)*10)";
	str1 += ")";
	str1 = "(" + str1;
    char str[str1.length()];
    strcpy(str,str1.c_str());
	expression_eval(str);
	for (auto el : numstack){
		cout <<  "answer is  " << el  << endl;
	}
	cout << endl;
	return 0;
}


/*

string tmp = "cat";
char tab2[1024];
strcpy(tab2, tmp.c_str());

g++ -std=c++11

*/