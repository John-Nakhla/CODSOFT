#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    srand(time(0));
    int random=rand();
    int x;
    cout<<"Enter a guessing:\n";
    cin>>x;
    while(x!=random)
    {
        if(x<random)
        {
            cout<<"wrong guess ,you should gess a higher number\n";
            cout<<"Enter another guess:\n";
            cin>>x;
        }
         else if(x>random)
        {
            cout<<"wrong guess ,you should gess a lower number\n";
            cout<<"Enter another guess:\n";
            cin>>x;
        }

    }
    cout<<"You guessed the right number";
    return 0;
}
