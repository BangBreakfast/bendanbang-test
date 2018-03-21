#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
using namespace std;
const int MAX = 110;
class CHugeInt {
private:
    bool type;
    char* num1;
    int num0;
public:
    CHugeInt(const int a)
    {
        type=0;
        num0=a;
        num1=NULL;
    }
    CHugeInt(const char*s)
    {
        type=1;
        num1= new char[strlen(s) + 1];
        strcpy(num1,s);
        num0=0;
    }
    CHugeInt operator + (const int b)
    {
        char* num;
        int temp=b;
        num=new char[210];
        strcpy(num,num1);
        for(int i=int(strlen(num1)-1),j=0;i>j;i--,j++)
        {
            char c=num[i];
            num[i]=num[j];
            num[j]=c;
        }
        int i=0;
        bool cir=0;
        while(temp>0||cir==1)
        {
            int dir=temp%10;
            if(num[i]=='\0')
            {
                num[i]='0';
            }
            num[i]=num[i]+dir+cir;
            if(num[i]>'9')
            {
                num[i]=num[i]-10;
                cir=1;
            }
            else
            {
                cir=0;
            }
            i++;
            temp=temp/10;
        }
        for(int i=int(strlen(num)-1),j=0;i>j;i--,j++)
        {
            char c=num[i];
            num[i]=num[j];
            num[j]=c;
        }
        i=0;
        while(num[i]=='0'&&num[i+1]!='\0')
        {
            num++;
        }
        return CHugeInt(num);
    }
    CHugeInt operator + (const CHugeInt b)
    {
        char* num;
        num =new char[210];
        int temp=b.num0;
        strcpy(num,num1);
        for(int i=int(strlen(num1)-1),j=0;i>j;i--,j++)
        {
            char c=num[i];
            num[i]=num[j];
            num[j]=c;
        }
        int i=0;
        bool cir=0;
        while(temp>0||cir==1)
        {
            int dir=temp%10;
            if(num[i]=='\0')
            {
                num[i]='0';
            }
            num[i]=num[i]+dir+cir;
            if(num[i]>'9')
            {
                num[i]=num[i]-10;
                cir=1;
            }
            else
            {
                cir=0;
            }
            i++;
            temp=temp/10;
        }
        for(int i=int(strlen(num)-1),j=0;i>j;i--,j++)
        {
            char c=num[i];
            num[i]=num[j];
            num[j]=c;
        }
        i=0;
        while(num[i]=='0'&&num[i+1]!='\0')
        {
            num++;
        }
        return CHugeInt(num);
    }
    friend ostream &operator  << (ostream &cout,const CHugeInt &a)
    {
        if(a.type)
        {
            cout<<a.num1;
        }
        else
        {
            cout<<a.num0;
        }
        return cout;
    }
    friend CHugeInt operator + (const int n,const CHugeInt &b)
    {
        char* num;
        num =new char[210];
        int temp=n;
        strcpy(num,b.num1);
        for(int i=int(strlen(b.num1)-1),j=0;i>j;i--,j++)
        {
            char c=num[i];
            num[i]=num[j];
            num[j]=c;
        }
        int i=0;
        bool cir=0;
        while(temp>0||cir==1)
        {
            int dir=temp%10;
            if(num[i]=='\0')
            {
                num[i]='0';
            }
            num[i]=num[i]+dir+cir;
            if(num[i]>'9')
            {
                num[i]=num[i]-10;
                cir=1;
            }
            else
            {
                cir=0;
            }
            i++;
            temp=temp/10;
        }
        for(int i=int(strlen(num)-1),j=0;i>j;i--,j++)
        {
            char c=num[i];
            num[i]=num[j];
            num[j]=c;
        }
        i=0;
        while(num[i]=='0'&&num[i+1]!='\0')
        {
            num++;
        }
        return CHugeInt(num);
    }
    CHugeInt & operator += (const int n)
    {
        num0=num0+n;
        return *this;
    }
    CHugeInt & operator ++ ()
    {
        ++num0;
        return *this;
    }
    CHugeInt operator ++ (int _tmp) {
        CHugeInt preValue(*this);
        ++num0;
        return preValue;
    }
};

int  main()
{
    char s[210];
    int n;
    
    while (cin >> s >> n) {
        CHugeInt a(s);
        CHugeInt b(n);
        cout << a + b << endl;
        cout << n + a << endl;
        cout << a + n << endl;
        b += n;
        cout  << ++ b << endl;
        cout << b++ << endl;
        cout << b << endl;
    }
    return 0;
}
