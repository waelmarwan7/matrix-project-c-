#include <iostream>
#include <cmath>
#include <string>
#include<iomanip>
using namespace std;

void matrix_inputs (int  matrix_c[10][10],int x,int y);  //take matrix inputs from user
void matrix_summ  (int matrix_A[10][10],int matrix_B[10][10],long double matrix_c[10][10], int x,int y); /* summation of matrices
                                                                                                                 XD  XD   */
void matrix_subtruction  (int matrix_A[10][10],int matrix_B[10][10],long double matrix_c[10][10], int x,int y);   /* subtraction of matrices the same thing gg
                                                                                                                 XD  XD   */
void matrix_multiplication (int matrix_A[10][10],int matrix_B[10][10],long double matrix_c[10][10], int x,int y,int z); // multiplication of matrices so easy LOL
double matrix_determent  (long double matrix_A[10][10],int x);
  int main ()
  {
   int d1,d2,d3,d4,x, matrix_A[10][10],matrix_B[10][10];


   cout<<"Please enter dimensions of Matrix A:\n";
   cin>>d1>>d2;
   cout<<"Please enter dimensions of Matrix B:\n";
   cin>>d3>>d4;
   cout<<"Please enter values of Matrix A:\n";
   matrix_inputs( matrix_A,d1,d2);
   cout<<"Please enter values of Matrix B:\n";
   matrix_inputs( matrix_B,d3,d4);
   do
    {
    long double matrix_c[10][10]={0}; // inialization of the result matrix not to save the old memory.
     cout<<"Please choose operation type(1: A+B, 2: A-B, 3: AxB, 4: A*inverse(B), 5: |A|, 6: |B|, 7: quit):\n";
     cin>>x;
     if(x==1)
     {
         if (d1!=d3||d2!=d4)
        cout<<"The operation you chose is invalid for the given matrices.\n";
         else
         matrix_summ(matrix_A,matrix_B,matrix_c,d1,d2);
     }
     else if (x==2)
     {
        if (d1!=d3||d2!=d4)
         cout<<"The operation you chose is invalid for the given matrices.\n";
         else
         matrix_subtruction(matrix_A,matrix_B,matrix_c,d1,d2);
     }
     else if (x==3)
     {
         if (d2 != d3)
         cout<<"The operation you chose is invalid for the given matrices.\n";
        else
         matrix_multiplication (matrix_A,matrix_B,matrix_c,d1,d2,d4);


     }
     else if(x==4)
     {

     }
     else if(x==5)
     {
       if (d1!=d2)
          cout<<"The operation you chose is invalid for the given matrices.\n";
       else
      {
        for(int i=0;i<d1;i++)   // to copy variables in A TO MATRIX_C NOT TO CHANGE VARIABLES IN MATRIX_A IN CONVERTING triangular form process.
         {
           for(int j=0;j<d2;j++)
            matrix_c[i][j]=matrix_A[i][j];
         }
        cout<<matrix_determent(matrix_c,d1)<<endl;
      }
     }
     else if(x==6)
     {
       if (d3!=d4)
          cout<<"The operation you chose is invalid for the given matrices.\n";
       else
      {
        for(int i=0;i<d1;i++)   // to copy variables in B TO MATRIX_C NOT TO CHANGE VARIABLES IN MATRIX_B IN CONVERTING triangular form process.
         {
           for(int j=0;j<d2;j++)
            matrix_c[i][j]=matrix_B[i][j];
         }
        cout<<matrix_determent(matrix_c,d3)<<endl;
      }
     }
     else if (x==7)
     {
         cout<<"Thank you!";
     }
     else
         cout<<"invalid..! please enter a valid number from 1 to 6 or 7 to exit \n";
     }while (x!=7);

      return 0;
  }








  void matrix_inputs (int matrix_A[10][10], int x,int y)
  {
    for(int i=0;i<x;i++)
      {
          for(int j=0;j<y;j++)
          {
            cin>> matrix_A[i][j];

          }
      }
  }



void matrix_summ  (int matrix_A[10][10], int matrix_B[10][10],long double matrix_c[10][10], int x,int y)  //must the two matrices be with same dimension
{
   for(int i=0;i<x;i++)
      {
          for(int j=0;j<y;j++)
          {
          matrix_c[i][j]= matrix_A[i][j]+ matrix_B[i][j];
           cout <<matrix_c[i][j];
           if (j==(y-1))
            cout<<"\n";
           else
            cout<<" ";
          }
      }
}

void matrix_subtruction  (int matrix_A[10][10],int matrix_B[10][10],long double matrix_c[10][10], int x,int y) //must the two matrices be with same dimension
{
   for(int i=0;i<x;i++)
      {
          for(int j=0;j<y;j++)
          {
          matrix_c[i][j]= matrix_A[i][j]- matrix_B[i][j];
           cout <<matrix_c[i][j];
           if (j==(y-1))
            cout<<"\n";
           else
            cout<<" ";
          }
      }
}


void matrix_multiplication (int matrix_A[10][10],int matrix_B[10][10],long double matrix_c[10][10], int x,int y,int z) /*   x=d1  ,,  y=d2 or d3 ,,  z=d4                                                                                                                       (ixj) * (jxk)  j must be the same     */
{
 for(int i=0;i<x;i++)
 {
    for (int k=0;k<z;k++)
    {
        for(int j=0;j<y;j++)
        {
            matrix_c[i][k]+=matrix_A[i][j]*matrix_B[j][k];
        }
     cout <<matrix_c[i][k];
       if (k==(z-1))
        cout<<"\n";
       else
        cout<<" ";
    }
 }

}

double matrix_determent(long double matrix_A[10][10],int x) // its idea is dependent on converting the normal matrix to upper triangular matrix then multiply the primary diagonal of matrix to get determent.
{
int sign =1,counter=1;
 for(int d=1;d<x;d++)
  {
    for(int k=0;k<d;k++)
    {
      if(matrix_A[k][k]==0)
       {
         for(int n=k;n<x;n++)
         {
           if(matrix_A[n][k]!=0)
            {
             for(int j=0;j<x;j++) // swap loop
             {
              int y=matrix_A[n][j];
              matrix_A[n][j]=matrix_A[k][j];
              matrix_A[k][j]=y;
             }
             sign *=-1;
           }
          else
            counter++;
          if(counter==x)
            return 0;
         }
       }
          cout<< setprecision(100);
         long double ratio=matrix_A[d][k]/matrix_A[k][k];

         for(int j=0;j<x;j++)
          {
             cout<< setprecision(100);
            matrix_A[d][j]=matrix_A[d][j]-ratio*matrix_A[k][j];

          }
     }
    }
     long double det=1;
      for(int z=0;z<x;z++)
      {
       det*=matrix_A[z][z];
       if(matrix_A[z][z]==0)
        return 0;
      }
        return (sign*det);

}













