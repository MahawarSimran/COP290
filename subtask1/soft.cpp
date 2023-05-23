#include <iostream>
#include <cmath>
#include "helper.h"
#include <fstream>
#include <string>
#include <vector>
using namespace std;
void softmax(){
    int n;
    fstream newfile;
    newfile.open("vector.txt",ios::in); //open a file to perform read operation using file object
    if (newfile.is_open()){   //checking whether the file is open
        float tp;
        if(newfile >> tp){
            n = tp;
        }
        else{
            cout << "Incorrect Input ";
        }
        vector<float> vec;
        int i=0;
        while(i < n && newfile >> tp){
            vec.push_back(tp);
            i +=1;
        }
        newfile.close(); //close the file object.
    
    newfile.open("softmax.txt",ios::out);  // open a file to perform write operation using file object
    if(newfile.is_open()){
        newfile <<n << "\n";   //inserting text        
        vector<float> sig;
        vector<float> final;
        int i =0;
        float sum = 0.0;
        while(i < n){
            float z = exp(vec[i]);
            sig.push_back(z);
            sum += z;
            i+=1;
        }
        i =0;
        while(i < n){
            final.push_back(sig[i]/sum);
            newfile << final[i]<< "\n";
            i+=1;
        }
        newfile.close();    //close the file object
    }
    }

}
