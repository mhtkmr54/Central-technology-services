#include <iostream>
#include <vector>

using namespace std;


class Person{
  protected:
    string firstName;
    string lastName;
    int id;
  public:
    Person(string firstName, string lastName, int identification){
      this->firstName = firstName;
      this->lastName = lastName;
      this->id = identification;
    }
    void printPerson(){
      cout<< "Name: "<< lastName << ", "<< firstName <<"\nID: "<< id << "\n";
    }

};

class Student :  public Person{
  private:
    vector<int> testScores;
  public:
      Student(string firstName, string lastName, int id, vector<int> scores) : Person(firstName, lastName, id) {
            this->testScores = scores;
        }

      char calculate() {
            int sum = 0;
            int med;
            char grade = 'T';
            for (vector<int>::iterator it = testScores.begin() ; it != testScores.end(); ++it)
                sum+=*it;
            med = int(sum/testScores.size());

            if (med>=90 && med<=100) { grade='O'; }
            if (med>=80 && med<90)   { grade='E'; }
            if (med>=70 && med<80)   { grade='A'; }
            if (med>=55 && med<70)   { grade='P'; }
            if (med>=40 && med<=55)  { grade='D'; }

            return grade;
        }
};

int main() {
  string firstName;
    string lastName;
  int id;
    int numScores;
  cin >> firstName >> lastName >> id >> numScores;
    vector<int> scores;
    for(int i = 0; i < numScores; i++){
      int tmpScore;
      cin >> tmpScore;
    scores.push_back(tmpScore);
  }
  Student* s = new Student(firstName, lastName, id, scores);
  s->printPerson();
  cout << "Grade: " << s->calculate() << "\n";
  return 0;
}
