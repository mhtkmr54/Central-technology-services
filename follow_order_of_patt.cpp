#include <iostream>
#include <cstring>
#include <deque>
#include <string>


using namespace std;

string str1;
string patt1;

/*
char arr[ ] = "This is a test";

string str(arr);


//  You can also assign directly to a string.
str = "This is another string";


single conversion of char to str st str[0]
string firstLetter(1,str[0]);

//str1.length()
//str.append(str2);  
 unsigned sz = str.size();

  str.resize (sz+2,'+');
I like to code in C++



  std::string str="to be question";
  std::string str2="the ";
  std::string str3="or not to be";
  std::string::iterator it;

  // used in the same order as described above:
  str.insert(6,str2);                 // to be (the )question
  str.push_back(char C)
  

// string::find
#include <iostream>       // std::cout
#include <string>         // std::string

int main ()
{
  std::string str ("There are two needles in this haystack with needles.");
  std::string str2 ("needle");

  // different member versions of find in the same order as above:
  std::size_t found = str.find(str2);
  if (found!=std::string::npos)
    std::cout << "first 'needle' found at: " << found << '\n';

  found=str.find("needles are small",found+1,6);
  if (found!=std::string::npos)
    std::cout << "second 'needle' found at: " << found << '\n';

  found=str.find("haystack");
  if (found!=std::string::npos)
    std::cout << "'haystack' also found at: " << found << '\n';

  found=str.find('.');
  if (found!=std::string::npos)
    std::cout << "Period found at: " << found << '\n';

  // let's replace the first needle:
  str.replace(str.find(str2),str2.length(),"preposition");
  std::cout << str << '\n';

  return 0;
}


*/


void remwaste(char * X, char *Y, int big, int patt){
  for (int m = 0; m < str1.length() ; m++) {
    size_t found = patt1.find(X[m]);
    if (found == std::string::npos){
      cout << m <<endl;
      str1.erase (str1.begin()+m); 
      strcpy(X,str1.c_str());
      m = 0;
    }
    
  }
  cout << str1 << endl;
  for (int k =1; k < str1.length(); k++){
  	cout << " " << k << endl;
     if (str1[k] == str1[k-1]){
     	str1.erase(str1.begin()+k);
     	k--; 
     }
  }
  cout << " final ----> " << str1 << endl;
  char Z[str1.length()];
  strcpy(Z,str1.c_str());
  X = Z;
  return;
}


int main(){
	str1 = "bfbaeadeacc";
    patt1 = "bac";
    char str[str1.length()];
    strcpy(str,str1.c_str());

    char patt[patt1.length()];
    strcpy(patt,patt1.c_str());
    remwaste(str, patt, str1.length(),strlen(str));
    cout << " len " << strlen(str) << endl;
    for (auto el : str){
    	cout << el << " ";
    }
     cout << endl;
	return 0;
}