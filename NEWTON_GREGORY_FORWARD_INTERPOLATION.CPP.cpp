//Newton's Forward interpolation Polynomial
#include<iostream>
using namespace std;
//FACTORIAL: 2!, 3!, 4! ...... n!
double fact(int i)
{
  if(i>1)
  return i*fact(i-1);
  else
  return 1;
}
// u(u-1)(u-2)(u-3)....
double ux(int i, double u)
{
  if(i==0)
      return 1;
  if(i==1)
    return u;
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
  cout<<"Enter Size: ";                               //NUMBER OF ELEMENT (X,Y) YOU WANT TO ENTER
  int s = 7;
  cin>>s;
  double x[s];
  double y[s][s];
  cout<<"Enter X:"<<endl;
  for(int i = 0; i<s;i++)
  {
    cout<<"x>> ";
    cin>>x[i];
  }
  cout<<"Enter Y:"<<endl;
  for(int i = 0; i<s;i++)
  {
    cout<<"y>> ";
    cin>>y[0][i];
  }
  if (x[1] - x[0] != x[2] - x[1])                         //CHECKING WHETHER IT IS EQUEAL INTERVAL OR NOT
  {
    cout<<endl<<"Unequal Interval....!! /nEnter Equal Intervals and Try Again"; exit(0); 
  }
  cout<<"You Entered: \nX Y"<<endl;
  for(int j = 1; j<s; j++)
  {
    for(int i = 0;i<s-j; i++)
    {
      y[j][i] = y[j - 1][i + 1] - y[j - 1][i];            //DIFFERENCE TABLE ALGORITHM
    }
  }
  cout<<"Difference Table"<<endl;
  for(int i = 0;i<s;i++)
  {
    if(i==0)
    cout<<"x\ty\t";                                       //PRINTING X Y HEADING
    else
      cout << "Δ" << i << "y\t";                          //PRINTING FURTEHER ΔY
  }
  cout<<endl;
  for(int j = 0; j<s; j++)
  { 
    cout<<x[j]<<"\t";                                     //PRINTING X ELEMENT
    for(int i = 0; i<s-j; i++)
    {
      cout<<y[i][j]<<"\t";
    }
    cout<<endl;
  }
  double ix;
  cout<<"Enter Interpolate of x: ";
  cin>>ix;
  int h = x[1]-x[0];
  double u = (ix-x[0])/h;
  cout<<endl<<"h: "<<h<<endl<<"u: "<<u;
  double fx = 0;
  cout<<endl;

  double uxa;
  cout<<"f(x): ";
  for(int i=0;i<s;i++)
  {
    uxa = ux(i, u);
    fx+= (uxa/fact(i))*y[i][0];                           //CALCULATION
    if(i>0)                                               //PREVENTING EXTRA '+' IN FORMAT
    cout<<" + ";
    cout<<fx;
  } 
  cout<<endl<<"f(x): "<<fx<<"*"<<endl<<"* APPROXIMATELY";

  return 0;
}
