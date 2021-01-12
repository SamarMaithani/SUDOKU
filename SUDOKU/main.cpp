#include <iostream>

using namespace std;

void display(char s[][9])
{
    system("CLS");
    int i,j;
    cout<<"\n";
    for(i=0;i<9;i++)
    {
        for(j=0;j<9;j++)
        {
            if(j==3 || j==6)
                cout<<"  ";
            cout<<"  "<<s[i][j];
        }
        cout<<endl;
        if(i==2 || i==5)
            cout<<"\n";
    }
    cout<<"\n\n";
    system("pause");
}

int analysis(char s[][9],int x,int y)
{
    int i,j,t,t2,c=0;
    for(i=0;i<9;i++)
    {
        if(s[x][i]==s[x][y])
            c++;
        if(s[i][y]==s[x][y])
            c++;
    }
    if(c!=2)
        return 0;
    c=0;
   t=x/3, t2=y/3;
    if(t==1)
    t=3;
    if(t==2)
    t=6;
    if(t2==1)
    t2=3;
    if(t2==2)
    t2=6;
    for(i=t;i<t+3;i++)
    {
        for(j=t2;j<t2+3;j++)
        {
            if(s[x][y]==s[i][j])
                c++;
        }
    }
    if(c!=1)
        return 0;
    return 1;
}

bool sudoku(char s[][9])
{
   int i,j,t=0;
   char c;
   for(i=0;i<9;i++)
   {
       for(j=0;j<9;j++)
       {
           if(s[i][j]=='.')
           {
                t=1;
                break;
           }
       }
       if(t==1)
        break;
   }
   if(t==0)
    return true;
   for(c='1';c<='9';c++)
   {
       s[i][j]=c;
       if(analysis(s,i,j))
       {
           if(sudoku(s))
                return true;
       }
        s[i][j]='.';
   }
   return false;
}


int main()
{
    int i,j;
    char s[9][9];
    cout<<"Enter some numeric values ('1' - '9') in the SUDOKU (Enter '.' for empty space):\n";
    for(i=0;i<9;i++)
    {
        for(j=0;j<9;j++)
             cin>>s[i][j];
    }
    display(s);
    for(i=0;i<9;i++)
    {
        for(j=0;j<9;j++)
        {
            if(!((s[i][j]>='1' && s[i][j]<='9')||s[i][j]=='.'))
            {
                cout<<"\n\n\t INVALID SUDOKU!!\n\nOther Numeric Values or Characters other than what's mentioned Before are Not Permitted!"<<endl;
                return 0;
            }
            if(s[i][j]=='.')
                continue;
            int v=analysis(s,i,j);
            if(v==0)
            {
                cout<<"\n\n\t  INVALID SUDOKU!!"<<endl;
                return 0;
            }
        }
    }
    if(sudoku(s))
    {
        display(s);
        for(i=0;i<9;i++)
        {
            for(j=0;j<9;j++)
            {
                int v=analysis(s,i,j);
                if(v==0)
                {
                    cout<<"\n\n\t INVALID SUDOKU!!"<<endl;
                    return 0;
                }
            }
        }
        cout<<"\n\n\t SUDOKU SOLVED!!"<<endl;
    }
    else
        cout<<"\n\n\tNO SOLUTION EXISTS!!"<<endl;
    return 0;
}
