//DIVIDED DIFFERENCE TABLE AND DIFERNCE TABLE BOTH
//ACCORDING TO USER INPUT
#include<iostream>
using namespace std;
int main()
{
    int i, j;
    cout<<"Enter No. of Column's Data you want to insert: ";
    int s;
    cin>>s;
    double y[s][s], x[s];
    cout<<"\nEnter value of X: \n";
    for(i = 0; i<s;i++)
    {
        cout<<"x>>";
        cin>>x[i];
    }
    cout<<"Enter Values of Y: \n";
    for(i=0; i<s;i++)
    {
        cout<<"y>>";
        cin>>y[0][i];
    }
    if((x[1]-x[0])==(x[2]-x[1]))
    {
    //DIVIDED DIFFERENCE TABLE (EQUAL INTERVAL) ALGORITHM
     for(j = 1; j<s;j++)
        {
            for (i = 0; i < (s - j); i++)
            {
                y[j][i] = y[j - 1][i + 1] - y[j - 1][i];
            }
        }
        cout << "DIFFERENCE TABLE\n";
    }   
    else
    {
    //DEVIDED DIFFERENCE TABLE (UNEQUEAL INTERVAL) ALGORITHM
        for(j = 1; j<s;j++)
        {
            for(i = 0;i<(s-j);i++)
            {
            y[j][i]=(y[j-1][i+1]-y[j-1][i])/(x[i+j]-x[i]);
            }
        }
        cout << "DIVIDED DIFFERENCE TABLE\n";
    }
    for(i = 0; i<s;i++)
    {
        if(i==0)
        cout<<"x\ty\t";
        else
        cout<<"Δ"<<i<<"y\t";
    }
    cout<<endl;
    for(j = 0; j<s; j++)
    {
        cout<<x[j]<<"\t";
        for(i = 0; i<(s-j); i++)
        {   
            cout<<y[i][j]<<"\t";
        }
        cout<<endl;
    }
    return 0;
}