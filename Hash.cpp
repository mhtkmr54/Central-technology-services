#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <queue>
#include <deque>
#include <iterator>
#include <string>
using namespace std;

class hash{ //lowe h
 private:
      static const int tableSize = 10;
     // whn hsh crrtd , it kws item mem
      struct item{
        string name;
        string drink;
        item* next;
      };
      item* HashTable[tableSize];
  public:
     hash();
     int Hash(string key);
     void AddItem(string name,string drink);
     int numberOfItemInIndex(int index);
     void printTable();
};

hash::hash(){ // constructer
  for (int i = 0; i < tableSize; i++)
  {
    HashTable[i]  = new item;
    HashTable[i]->name = "empty";
    HashTable[i]->drink = "empty";
    HashTable[i]->next = NULL;
  }
}

int hash::numberOfItemInIndex(int index)
{
  int count = 0;
  if(HashTable[index]->name == "empty"){
    return 0;
  }
  else{
    count++;
      item* n = HashTable[index];
      while (n->next != NULL){
         n = n->next;
         count++;
      }
  }

 return count;
}

void hash::printTable(){
  for (int i = 0; i < tableSize; i++)
  {
   int numberofit = numberOfItemInIndex(i);
   if(HashTable[i]->name != "empty"){
        item* nx = HashTable[i];
        while(nx != NULL){
        cout << "items at this index  " << numberofit << "    " << endl;
        cout << "name " << nx->name << " ";
        cout << "drink " << nx->drink << " ";
        cout << " " << "|" << " " << endl;
        nx = nx->next;
        }
   }
   else
   {
    cout << "items at this index  " << numberofit << endl;
   }
  cout << endl;
  }
}

void hash::AddItem(string name,string drink){

    int index = Hash(name);
    if (HashTable[index]->name == "empty")
    {
      HashTable[index]->name = name;
      HashTable[index]->drink = drink;
    }
    else{
      item* pt = new item;
      item* ptr = HashTable[index];
      cout << "name adding " << name << endl;
      cout << "drink " << drink << endl;
      pt->name = name;
      pt->drink = drink;
      pt->next = NULL;
      while (ptr->next != NULL){
         ptr = ptr->next;
      }
      ptr->next = pt;
    }
}



int hash::Hash(string key){
  int hash = 0;
  int index;
  cout << "key[0] = " << (int)key[0] << endl;
  cout << "key[1] = " << (int)key[1] << endl;
  cout << "key[2] = " << (int)key[2] << endl;
  cout << "key[3] = " << (int)key[3] << endl;
  cout << "key[4] = " << (int)key[4] << endl;
  for (int j =0; j < key.length(); j++){
    hash += (int)key[j];
  }
  cout << hash << endl;
  index = hash % tableSize;
  return index;
}









int main(){
   hash hashObj;
   hashObj.printTable();
   hashObj.AddItem("Mohit","Coca Cola");
   hashObj.AddItem("mila jovovich","Umbrella Corp");
   hashObj.AddItem("queue","monster");
   hashObj.printTable();
  return 0;
}
