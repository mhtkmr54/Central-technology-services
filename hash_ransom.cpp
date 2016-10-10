#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;



class c_hash{ //lowe h
  public:
        static const int tableSize = 10;
      // whn hsh crrtd , it kws item mem
        struct item{
        string name;
        string drink;
        item* next;
      };
     item* c_hashTable[tableSize];
     c_hash();
     int hash_it(string key);
     void AddItem(string name,string drink);
     int numberOfItemInIndex(int index);
     bool SearchItem(string name);
     void printTable();
};

c_hash::c_hash(){ // constructer
  for (int i = 0; i < tableSize; i++)
  {
    c_hashTable[i]  = new item;
    c_hashTable[i]->name = "empty";
    c_hashTable[i]->drink = "empty";
    c_hashTable[i]->next = NULL;
  }
}

int c_hash::numberOfItemInIndex(int index)
{
  int count = 0;
  if(c_hashTable[index]->name == "empty"){
    return 0;
  }
  else{
    count++;
      item* n = c_hashTable[index];
      while (n->next != NULL){
         n = n->next;
         count++;
      }
  }

 return count;
}

void c_hash::printTable(){
  for (int i = 0; i < tableSize; i++)
  {
   int numberofit = numberOfItemInIndex(i);
   if(c_hashTable[i]->name != "empty"){
        item* nx = c_hashTable[i];
        while(nx != NULL){
        //cout << "items at this index  " << numberofit << "    " << endl;
        cout << "i " << i << " " << nx->name << " ";
        cout << endl;
        nx = nx->next;
        }
   }
   else
   {
    //cout << "items at this index  " << numberofit << endl;
   }
  }
}



void c_hash::AddItem(string name,string drink){

    int index = hash_it(name);
    if (c_hashTable[index]->name == "empty")
    {
      c_hashTable[index]->name = name;
      c_hashTable[index]->drink = drink;
    }
    else{
      item* pt = new item;
      item* ptr = c_hashTable[index];
      //cout << "name adding " << name << endl;
      //cout << "drink " << drink << endl;
      pt->name = name;
      pt->drink = drink;
      pt->next = NULL;
      while (ptr->next != NULL){
         ptr = ptr->next;
      }
      ptr->next = pt;
    }
}

bool c_hash::SearchItem(string name){

    int index = hash_it(name);
    if (c_hashTable[index]->name == "empty")
    {
      return 0;
    }
    else{

      item* ptr = c_hashTable[index];
      while (ptr != NULL){
          if (ptr->name == name && ptr->drink != "1"){
              ptr->drink = "1";
              return 1;
          }
          ptr = ptr->next;
          
      }
      return 0;
    }
}


int c_hash::hash_it(string key){
  int c_hash = 0;
  int index;
  for (int j =0; j < key.length(); j++){
    c_hash += (int)key[j];
  }
  index = c_hash % tableSize;
  return index;
}


bool ransom_note(vector<string> magazine, vector<string> ransom) {
    c_hash hashObj;
    for (auto el : magazine){
        hashObj.AddItem(el," ");
    }
    hashObj.printTable();
    for (auto elm : ransom){
        bool k = hashObj.SearchItem(elm);
        if (k == 0){
            return 0;
        }
    }
    return 1;
}

int main(){
    int m;
    int n;
    cin >> m >> n;
    vector<string> magazine(m);
    for(int magazine_i = 0;magazine_i < m;magazine_i++){
       cin >> magazine[magazine_i];
    }
    vector<string> ransom(n);
    for(int ransom_i = 0;ransom_i < n;ransom_i++){
       cin >> ransom[ransom_i];
    }
    if(ransom_note(magazine, ransom))
        cout << "Yes\n";
    else
        cout << "No\n";
    return 0;
}
