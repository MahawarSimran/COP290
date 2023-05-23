#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main(){
   int n,m,a,b,c,d;
   fstream newfile;
   newfile.open("matrix1.txt",ios::in); //open a file to perform read operation using file object
   if (newfile.is_open()){   //checking whether the file is open
      float tp;
      if(newfile >> tp){
         n = tp;
      }
      if(newfile >> tp){
         m = tp;
      }
      else{
         cout << "Incorrect Input ";
         return EXIT_FAILURE;
      }
      float matrix1[n][m];
      int i=0,j=0;
      while(i < n ){
         while(j < m && newfile >> tp){
            matrix1[i][j] = tp;
            j += 1;
         }
         i +=1;
         j =0;
      }
      newfile.close(); //close the file object.

   newfile.open("matrix2.txt",ios::in); //open a file to perform read operation using file object
   if (newfile.is_open()){   //checking whether the file is open
      float tp;
      if(newfile >> tp){
         a = tp;
      }
      if(newfile >> tp){
         b = tp;
      }
      else{
         cout << "Incorrect Input ";
         return EXIT_FAILURE;
      }
      float matrix2[a][b];
      int i=0,j=0;
      while(i < a ){
         while(j < b && newfile >> tp){
            matrix2[i][j] = tp;
            j += 1;
         }
         i +=1;
         j =0;
      }
      newfile.close(); //close the file object.
   newfile.open("matrix3.txt",ios::in); //open a file to perform read operation using file object
   if (newfile.is_open()){   //checking whether the file is open
      float tp;
      if(newfile >> tp){
         c = tp;
      }
      if(newfile >> tp){
         d = tp;
      }
      else{
         cout << "Incorrect Input ";
         return EXIT_FAILURE;
      }
      float matrix3[c][d];
      int i=0,j=0;
      while(i < c ){
         while(j < d && newfile >> tp){
            matrix3[i][j] = tp;
            j += 1;
         }
         i +=1;
         j =0;
      }
      newfile.close();
      newfile.open("finalmatrix.txt",ios::out);  // open a file to perform write operation using file object
      if(newfile.is_open()){
      newfile <<n << "\n";   //inserting text
      newfile <<b << "\n";
      float final[n][b];
      i =0,j=0;
      while(i < n){
         while( j < b){
            for(int k = 0; k < m;k++)
            {
               final[i][j] += matrix1[i][k] * matrix2[k][j];
            }
            cout << final[i][j] << endl;
            final[i][j] += matrix3[i][j];
            newfile << final[i][j] << "\n";
            j+=1;
         }
         i+=1;
         j=0;
      }
      newfile.close();    //close the file object
      }
   }
   }
   }
}
