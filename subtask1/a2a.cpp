#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main(){
    int n,m;
    fstream newfile;
    newfile.open("matrix.txt",ios::in); //open a file to perform read operation using file object
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
        while(i < n){
            while(j < m && newfile >> tp){
                matrix1[i][j] = tp;
                j += 1;
            }
            i +=1;
            j =0;
        }
        newfile.close(); //close the file object.
    
    newfile.open("relu.txt",ios::out);  // open a file to perform write operation using file object
    if(newfile.is_open()){
        newfile <<n << "\n";   //inserting text        
        newfile <<m << "\n";
        float final[n][m];
        int i =0,j=0;
        while(i < n){
            while( j < m){
                if(matrix1[i][j] <0){
                    final[i][j] = 0.0;
                }
                else{
                    final[i][j] = matrix1[i][j];
                }
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
