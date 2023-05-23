#include "help.h"
#include <iostream>
#include <fstream>
#include <math.h>
#include <vector>
#include <chrono>
#include "/opt/intel/mkl/include/mkl.h"
#include <string>
using namespace std;

void fullyconnected_mkl(string inputmatrix, string weightmatrix,string biasmatrix, string output){
    ifstream Read(inputmatrix);

    try{if(!Read){throw 1;}}
    catch(int i){cout<<"file not found"<<endl;}
    ofstream Write(output);
    string col;
    getline(Read,col);
    int c1=stoi(col);

    string row;
    getline(Read,row);
    int r1=stoi(row);
 
    float mat1[r1*c1];
    for(int j=0;j<c1;j++){
        for(int i=0;i<r1;i++)
        {
            string e;
            getline(Read,e);
            float ee=stof(e);
            mat1[i*c1 + j]=ee;


        }

        
    }
//------------------------------
ifstream Read2(weightmatrix);

    try{if(!Read2){throw 1;}}
    catch(int i){cout<<"file not found"<<endl;}
string col2;
    getline(Read2,col2);
    int c2=stoi(col2);
    // Write<<c2<<endl;
    string row2;
    getline(Read2,row2);
    int r2=stoi(row2);
    // Write<<r2<<endl; 
try{if(!(c1==r2)){throw 7;}}
catch(int i){cout<<"columns in input matrix not equal to rows on weight matrix"<<endl;}
    float mat2[r2*c2];
    for(int j=0;j<c2;j++){
        for(int i=0;i<r2;i++)
        {
            string e;
            getline(Read2,e);
            float ee=stof(e);
            mat2[i*c2 + j]=ee;
            
        }

    }

    //-------------------------------------
    ifstream Read3(biasmatrix);

    try{if(!Read3){throw 1;}}
    catch(int i){cout<<"file not found"<<endl;}
    string col3;
    getline(Read3,col3);
    int c3=stoi(col3);
    Write<<c3<<endl;
    string row3;
    getline(Read3,row3);
    int r3=stoi(row3);
    Write<<r3<<endl; 
    float mat3[r3*c3];
    try{if(!(r3==r1)){throw 7;}}
catch(int i){cout<<"columns in input matrix not equal to rows on weight matrix"<<endl;}
    try{if(!(c3==c2)){throw 7;}}
catch(int i){cout<<"columns in input matrix not equal to rows on weight matrix"<<endl;}


    for(int j=0;j<c3;j++){
        for(int i=0;i<r3;i++)
        {
            string e;
            getline(Read3,e);
            float ee=stof(e);
            mat3[i*c3 + j]=ee;
            // Write<< mat[i][j]<<endl;

        }

    }
    cblas_sgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans, r1, c2, c1, 1, mat1, c1, mat2, c2, 1, mat3, c2);

    float ans[r3][c3];
    for(int i=0;i<r3;i++){
        for(int j=0;j<c3;j++){
            ans[i][j]= mat3[i*c3 + j];
        }
    }
    for(int j=0;j<c3;j++){
        for(int i=0;i<r3;i++){
            Write<<ans[i][j]<<endl;
        }
    }
}


