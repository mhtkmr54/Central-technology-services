//Write MyBook class
class MyBook : public Book{
    private:
        int price;
    public:
        MyBook(string t,string a, int p): Book(title,author){ ////// WRONG t variable,type titleA P
            this->price = p;
        }
    void display(){
        cout << title << endl;
        cout << author << endl;
        cout << price << endl;
    };

};

/*void MyBook::display(){
    cout << title;
    cout << author;
    cout << price;
}*/
