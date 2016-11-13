// INCLUDE HEADER FILES NEEDED BY YOUR PROGRAM
// SOME LIBRARY FUNCTIONALITY MAY BE RESTRICTED
// DEFINE ANY FUNCTION NEEDED
// FUNCTION SIGNATURE BEGINS, THIS FUNCTION IS REQUIRED
using namespace std;
void writePatternSpiral(int size)
{
    // WRITE YOUR CODE HERE
    int a1 = 1;
    int a2 = 2;
    for(int k = 1; k < size+1; k++){
        if(k%2 != 0){
            for(int z = 1; z<= size+1; z++){
                if(z == size+1){
                    cout << a2;
                }else{
                    cout << a1;
                }
            }
            cout << endl;
        }else{
            for(int z = 1; z<= size+1; z++){
                if(z == 1){
                    cout << a2;
                }else{
                    cout << a1;
                }
            }
            cout << endl;
        }
        ++a1;
        ++a2;
    }
    cout << endl;

}
// FUNCTION SIGNATURE ENDS
