#include <iostream>

using namespace std;
#include <string>
#include <sstream>


int main()
{
    std::string str1 = "45";
    std::string str2 = "3.14159";
    std::string str3 = "31337 with words";


    int myint1 = std::stoi(str1);
    int myint2 = std::stoi(str2);
    int myint3 = std::stoi(str3);


    std::cout << "std::stoi(\"" << str1 << "\") is " << myint1 << '\n';
    std::cout << "std::stoi(\"" << str2 << "\") is " << myint2 << '\n';
    std::cout << "std::stoi(\"" << str3 << "\") is " << myint3 << '\n';
   std::string str="We think in generalities, but we live in details.";
                                           // (quoting Alfred N. Whitehead)

  std::string str2 = str.substr (3,5);     // "think"

  std::size_t pos = str.find("live");      // position of "live" in str

  std::string str3 = str.substr (pos);     // get from "live" to the end
}
/*
char arr[ ] = "This is a test";

string str(arr);


OTHER WAY ROUND 
string tmp = "cat";
char tab2[1024];
strcpy(tab2, tmp.c_str());


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
int main(){

    string str;
    cin >> str;
    int i = 0;
    int count = 0;
    for (int i=0; i<str.length(); ++i)
    {
    std::cout << str[i];
    }
    while (i < str.length() - 2){
        if (str[i] == '0' && str[i+1] == '1' && str[i+2] == '0'){
            //cout << str[i] - '0' + 99 << endl;  
            i = i + 3;
            count++;
        }
        else{
            i++;
        }
    }
    cout << count << endl;
    return 0;
}
