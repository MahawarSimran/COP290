#include <iostream>
#include <fstream>
#include "help.h"
#include <string>
#include <chrono>
#include <cmath>
using namespace std;
void meansd(float val[]) {

   float sum = 0.0, mean, variance = 0.0, stdDeviation;
   int i;
   for(i = 0; i < 100; ++i)
   sum += val[i];
   mean = sum/100;
   for(i = 0; i < 100; ++i)
   variance += pow(val[i] - mean, 2);
   variance=variance/100;
   stdDeviation = sqrt(variance);

   cout<<"The mean of these values is "<<mean <<" microseconds."<< endl;  
   cout<<"The standard deviation of these values is "<<stdDeviation << endl;
}
int main(int argc, char* argv[]){

try{if(argv[1]==string("fullyconnected")){
    try{
    	if(argc==7){
    	ofstream file;
        if(argv[6]==string("normal")){
    	file.open("runtimenormal.txt", ios::app);
    	}
        if(argv[6]==string("mkl")){
    	file.open("runtimemkl.txt", ios::app);
    	}
        if(argv[6]==string("openblas")){
    	file.open("runtimeopenblas.txt", ios::app);
    	}
        
        int k=0;
        float val[100];
        while(k<100){
        auto start = std::chrono::high_resolution_clock::now();
        if(argv[6]==string("normal")){
        	fullyconnected_normal(argv[2],argv[3],argv[4],argv[5]);
        }
        if(argv[6]==string("mkl")){
        	fullyconnected_mkl(argv[2],argv[3],argv[4],argv[5]);
        }
        if(argv[6]==string("openblas")){
        	fullyconnected_openblas(argv[2],argv[3],argv[4],argv[5]);
        }

        auto stop = std::chrono::high_resolution_clock::now();
 
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
 
  
	file <<duration.count() << "\t" << 10 << endl;
        val[k] = duration.count();
        k +=1;
        }
        meansd(val);}

        else { throw 1;}

    }
    catch(int i){cout<<"wrong number of arguments"<<endl;}
   }
   else{ throw 4;}}
catch(int i){cout<<"invalid command"<<endl;}
}
