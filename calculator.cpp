#include <iostream>

using namespace std;
float solve(float x,float y, char c)
{
    if(c=='+') return x+y;
    if(c=='-') return x-y;
    if(c=='*') return x*y;
    if(c=='/') return x/y;
}
void OnOff(int n)
{
    if(n==1) return ;
    else if(n==2) exit(0);
    else
    {
        cout<<"Please enter a valid answer\n1)yes\n2)no\n";
        cin>>n;
        OnOff(n);
    }
}

int main()
{
    while(true)
    {
        float n1,n2;
        cout<<"Enter first number: \n";
        cin>>n1;
        cout<<"Enter second number: \n";
        cin>>n2;
        char op;
        cout<< "choose an operation from the following \n +\t-\t*\t/\t%\n";
        cin>>op;
        float sol=solve(n1,n2,op);
        cout<<sol<<"\n";
        int c;
        cout<<"Do you want to calculate something else\n1)yes\n2)no\n";
        cin>>c;
        OnOff(c);

    }
    return 0;
}
