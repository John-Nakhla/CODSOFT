#include <iostream>

using namespace std;
typedef struct
{
    char a[3][3];
    int n;
} xo;

xo*newgame()
{
    xo*g=new xo;
    g->n=0;
    for (int i=0; i<3; i++)
    {
        for (int j=0; j<3; j++)
        {
            g->a[i][j]=' ';
        }
    }
    return g;
}
int isEmpty(xo*g)
{
    return g->n==0;
}
void display(xo*g)
{
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            cout<<" "<<g->a[i][j];
            if(j<2) cout<<"\t|\t";
        }
        cout<<"\n";
        if(i<2)cout<<"-------------------------------------";
        cout<<"\n";
    }
}
int checkwin(xo* g)
{
    for (int i=0; i<3; i++)
    {
        if (g->a[i][0]==g->a[i][1]&&g->a[i][1]==g->a[i][2]&&g->a[i][0]!=' ')
        {
            return 1;
        }
    }
    for (int i=0; i<3; i++)
    {
        if (g->a[0][i]==g->a[1][i]&&g->a[1][i]==g->a[2][i]&&g->a[0][i]!=' ')
        {
            return 1;
        }
    }
    if ((g->a[0][0]==g->a[1][1]&&g->a[1][1]==g->a[2][2]&&g->a[0][0]!=' ')||
            (g->a[0][2]==g->a[1][1]&&g->a[1][1]==g->a[2][0]&&g->a[0][2]!=' '))
    {
        return 1;
    }

    return 0;
}

int checkdraw(xo*g)
{
    if(g->n==9&&!checkwin(g))
        return 1;
    else return 0;
}
void enter(xo*g,char m,char c)
{
    if(!isdigit(m))
    {
        cout<<"please enter a number (1-9)\n";
        cin>>m;
        enter(g,m,c);
    }
    else if(m<'1'||m>'9')
    {
        cout<<"please enter a valid place (1-9)\n";
        cin>>m;
        enter(g,m,c);
    }
    else
    {
        switch (m)
        {
        case '1':
            if(g->a[0][0]==' ')
            {
                g->a[0][0]=c;
                g->n++;
            }
            else
            {
                cout<<"this place is occupied , please choose another\n";
                cin>>m;
                enter(g,m,c);
            }
            break;
        case '2':
            if(g->a[0][1]==' ')
            {
                g->a[0][1]=c;
                g->n++;
            }
            else
            {
                cout<<"this place is occupied , please choose another\n";
                cin>>m;
                enter(g,m,c);
            }
            break;
        case '3':
            if(g->a[0][2]==' ')
            {
                g->a[0][2]=c;
                g->n++;
            }
            else
            {
                cout<<"this place is occupied , please choose another\n";
                cin>>m;
                enter(g,m,c);
            }
            break;
        case '4':
            if(g->a[1][0]==' ')
            {
                g->a[1][0]=c;
                g->n++;
            }
            else
            {
                cout<<"this place is occupied , please choose another\n";
                cin>>m;
                enter(g,m,c);
            }
            break;
        case '5':
            if(g->a[1][1]==' ')
            {
                g->a[1][1]=c;
                g->n++;
            }
            else
            {
                cout<<"this place is occupied , please choose another\n";
                cin>>m;
                enter(g,m,c);
            }
            break;
        case '6':
            if(g->a[1][2]==' ')
            {
                g->a[1][2]=c;
                g->n++;
            }
            else
            {
                cout<<"this place is occupied , please choose another\n";
                cin>>m;
                enter(g,m,c);
            }
            break;
        case '7':
            if(g->a[2][0]==' ')
            {
                g->a[2][0]=c;
                g->n++;
            }
            else
            {
                cout<<"this place is occupied , please choose another\n";
                cin>>m;
                enter(g,m,c);
            }
            break;
        case '8':
            if(g->a[2][1]==' ')
            {
                g->a[2][1]=c;
                g->n++;
            }
            else
            {
                cout<<"this place is occupied , please choose another\n";
                cin>>m;
                enter(g,m,c);
            }
            break;
        case '9':
            if(g->a[2][2]==' ')
            {
                g->a[2][2]=c;
                g->n++;
            }
            else
            {
                cout<<"this place is occupied , please choose another\n";
                cin>>m;
                enter(g,m,c);
            }
            break;
        }
    }
}
void reset(xo*g)
{
    for (int i=0; i<3; i++)
    {
        for (int j=0; j<3; j++)
        {
            g->a[i][j]=' ';
        }
    }
    g->n=0;
}
void play(xo*g)
{
    char p1,p2;
    cout<<"player 1 choose x or o\nX\tO\n";
    cin>>p1;
    int v=0;
    while(!v)
    {
        if(p1!='x'&&p1!='X'&&p1!='o'&&p1!='O')
        {
            cout<<"please enter a valid option x or o\n";
            cin>>p1;
            continue;
        }
        v=1;
    }
    if(p1=='x'||p1=='X') p2='o';
    else p2='x';
    int w;
    int d;
    char m;
    int p=1;
    while(true)
    {
        display(g);
        cout<<"player "<<(p%2==1?1:2)<<" turn\n";
        cout<<"choose where to put "<<(p%2==1?p1:p2)<<"\n";
        cin>>m;
        enter(g,m,(p%2==1?p1:p2));
        w=checkwin(g);
        d=checkdraw(g);
        if(w)
        {
            int n;
            display(g);
            cout<<"player "<<(p%2==1?1:2)<<" won\n";
            cout<<"===============\nplay again?\t1)yes 2)no\n";
            cin>>n;
            if(n==1)
            {
                reset(g);
                play(g);
                break;
            }
            else
                break;
        }
        if(d)
        {
            int n;
            display(g);
            cout<<"it is a draw\n";
            cout<<"===============\nplay again?\t11)yes 2)no\n";
            cin>>n;
            if(n==1)
            {
                reset(g);
                play(g);
                break;
            }
            else
                break;
        }
        p++;
    }

}
int main()
{
    xo*g=newgame();
    play(g);
    return 0;
}
