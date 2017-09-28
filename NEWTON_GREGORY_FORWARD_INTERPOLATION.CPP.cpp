//Newton's Forward interpolation Polynomial
#include<iostream>
using namespace std;
double fact(int i)
{
  if(i>1)
  return i*fact(i-1);
  else
  return 1;
}
double ux(int i, double u)
{
  if(i==0)
  {
    return 1;
  }
  if(i==1)
  {
    return u;
  }
  else
  {
    double ux = u;
  while(i!=1)
  {
      ux *= (u-(i-1)); i--;
  }
    return ux;
  }
}
int main()
{
  cout<<"Enter Size: ";
  int s = 7;
  cin>>s;
  double x[s][s];
  double y[s][s];
  cout<<"Enter X:"<<endl;
  for(int i = 0; i<s;i++)
  {
    cout<<"x>> ";
    cin>>x[0][i];
  }
  cout<<"Enter Y:"<<endl;
  for(int i = 0; i<s;i++)
  {
    cout<<"y>> ";
    cin>>y[0][i];
  }
  cout<<"You Entered: \nX Y"<<endl;
  for(int i = 0;i<s;i++)
  {
    cout<<x[0][i]<<" "<<y[0][i]<<endl;
  }
  cout<<"Calculation"<<endl;
  for(int j = 1; j<s; j++)
  {
    for(int i = 0;i<s-j; i++)
    {
      y[j][i]=y[j-1][i+1]-y[j-1][i];
    }
  }
  for(int j = 0; j<s; j++)
  {
    for(int i = 0; i<s-j; i++)
    {
      cout<<y[i][j]<<"\t";
    }
    cout<<endl;
  }
  double ix;
   cout<<"Enter Interpolate of x: ";
   cin>>ix;
  int h = x[0][1]-x[0][0];
  double u = (ix-x[0][0])/h;
  cout<<endl<<u;
  double fx = 0;
  cout<<endl;

  double uxa;
  for(int i=0;i<s;i++)
  {
    uxa = ux(i, u);
    fx+= (uxa/fact(i))*y[i][0];
    cout<<(uxa/fact(i))*y[i][0]<<" + ";
  } cout<<endl<<"f(x): "<<fx<<"*"<<endl<<"* APPROXIMATELY";

  return 0;
}
