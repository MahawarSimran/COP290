#include <iostream>
#include "helper.h"
#include <cmath>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
float sigm(float x){
    float a;
    a = exp(-x);
    return 1.0/(a+1.0);
}
void sigmoid() {
    int n;
    fstream newfile;
    newfile.open("vector.txt",ios::in); //open a file to perform read operation using file object
    if (newfile.is_open()){   //checking whether the file is open
        float tp;
        if(newfile >> tp){
            n = tp;
        }

        vector<float> vec;
        int i=0;
        while(i < n && newfile >> tp){
            vec.push_back(tp);
            i +=1;
        }
        newfile.close(); //close the file object.
    
    newfile.open("sigmoid.txt",ios::out);  // open a file to perform write operation using file object
    if(newfile.is_open()){
        newfile <<n << "\n";   //inserting text        

        vector<float> final;
        int i =0;
        float sum = 0.0;
        while(i < n){
            float z = sigm(vec[i]);
            final.push_back(z);
            newfile << final[i]<< "\n";
            i+=1;
        }
        newfile.close();    //close the file object
    }
    }
}
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
