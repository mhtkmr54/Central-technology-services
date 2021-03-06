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

   // Reverse str[beign..end]
   reverse(str.begin(),str.end());

   -------------------------------------------------------PERMUTATIONS : 

   string str = "4321";
    if ( prev_permutation(str.begin(), str.end()) )
        cout << "Previous permutation is "<< str ;
    else
        cout << "Previous permutation doesn't exist" ;

----------------------------------------------------------------------

// MY DEQUE
// erase the 6th element
  mydeque.erase (mydeque.begin()+5);

 toupper(c) C IS A CHAR (str[i])
tolower(c)
  // erase the first 3 elements:
  mydeque.erase (mydeque.begin(),mydeque.begin()+3);

 for (std::deque<int>::iterator it = mydeque.begin(); it!=mydeque.end(); ++it)
    std::cout << ' ' << *it;


std::string str ("This is an example sentence.");
  std::cout << str << '\n';
                                           // "This is an example sentence."
  str.erase (10,8);                        //            ^^^^^^^^
  std::cout << str << '\n';
                                           // "This is an sentence."
  str.erase (str.begin()+9);               //           ^
  std::cout << str << '\n';
                                           // "This is a sentence."
  str.erase (str.begin()+5, str.end()-9);  //       ^^^^^
  std::cout << str << '\n';
                                           // "This sentence."

  std::string str2 = str.substr (3,5);     // "think"

  std::size_t pos = str.find("live");      // position of "live" in str

  std::string str3 = str.substr (pos);     // get from "live" to the end
}

std::map<char,int> mymap;
  std::map<char,int>::iterator it;

  // insert some values:
  mymap['a']=10;
  mymap['b']=20;
  mymap['c']=30;
  mymap['d']=40;
  mymap['e']=50;
  mymap['f']=60;

  it=mymap.find('b');
  mymap.erase (it);                   // erasing by iterator

  mymap.erase ('c');                  // erasing by key

  it=mymap.find ('e');
  mymap.erase ( it, mymap.end() );    // erasing by range
  
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
             case '+': cout <<" |" << val2 + val1 << "| "; s.push_back(val2 + val1); break;
             case '-': cout <<" |" << val2 - val1 << "| "; s.push_back(val2 - val1); break;
             case '*': cout <<" |" << val2 * val1 << "| "; s.push_back(val2 * val1); break;
             case '/': cout <<" |" << val2/val1 << "| ";   s.push_back(val2/val1);  break;

             9 5 1 2 + 4 * + 3 -