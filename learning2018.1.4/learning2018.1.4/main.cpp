//
//  main.cpp
//  learning2018.1.4
//
//  Created by 高立人 on 2018/1/4.
//  Copyright © 2018年 高立人. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;
struct linknote{
    int num;
    struct linknote *next;
};
linknote *createlinklist(int n)
{
    int a=0;
    linknote *link=new linknote;
    cin>>a;
    link->num=a;
    link->next=NULL;
    linknote *tail=link;
    for(int i=1;i<n;i++)
    {
        tail->next=new linknote;
        cin>>a;
        tail->next->num=a;
        tail->next->next=NULL;
        tail=tail->next;
    }
    return link;
}
void mergelinklist(linknote *a,linknote *b)
{
    linknote *move=a;
    while(move->next!=NULL)
    {
        move=move->next;
    }
    move->next=b;
}
void outputlinklist(linknote *a)
{
    linknote *move=a;
    cout<<move->num;
    while(move->next!=NULL)
    {
        move=move->next;
        cout<<' '<<move->num;
    }
    delete move;
}
void deletelinklist(linknote *a)
{
    linknote *move=a;
    while(1)
    {
        if(a->next!=NULL)
        {
            a=a->next;
            delete move;
            move=a;
        }
        else
        {
            break;
        }
    }
}
int main() {
    int n1=0,n2=0;
    cin>>n1;
    linknote *num1=NULL;
    linknote *num2=NULL;
    num1=createlinklist(n1);
    cin>>n2;
    num2=createlinklist(n2);
    mergelinklist(num1,num2);
    
    outputlinklist(num1);
    deletelinklist(num1);
    return 0;
}
