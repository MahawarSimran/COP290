#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
using namespace std;
int main(){
    int n,m,f;
    f =2;
    fstream newfile;
    newfile.open("inputmatrix.txt",ios::in); //open a file to perform read operation using file object
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
    
    newfile.open("avgpool.txt",ios::out);  // open a file to perform write operation using file object
    if(newfile.is_open()){
        int a =n/2, b = m/2;
        newfile <<a<< "\n";   //inserting text        
        newfile <<b<< "\n";
        float final[a][b];
        int i =0,j=0;
        while(i < a){
            while( j < b){
                float sum = 0.0;
                for(int f1 =0;f1 < f;f1++){
                    for(int f2=0;f2 < f; f2++){
                        sum += matrix1[f*i+f1][f*j+ f2];
                    }
                }
                final[i][j] = sum/(f*f);
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
