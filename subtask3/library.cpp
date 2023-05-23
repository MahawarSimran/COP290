#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include "/opt/intel/mkl/include/mkl.h"
#include<fstream>
#include"dnn_weights.h"
#include<math.h>
#include"library.h"
#include<string>

using namespace std;


int m,n,k ;
float relu(float number)
{
    if(number < 0) return 0;
    return number ;
}

pred_t* large_three(float * F, pred_t* pred)
{
    float third = -999, first= -999, second = -999;
    int index_first = -9999, index_second = -9999, index_third = -9999;
    int i=0;
    while(i<12){
        if (F[i] > first){
            third = second;
            second = first;
            first = F[i];
            index_third = index_second;
            index_second = index_first;
            index_first = i;}
        else if (F[i] > second){
            third = second;
            second = F[i];
            index_third = index_second;
            index_second = i; 
        }
        else if (F[i] > third){
             third = F[i];
             index_third = i;
         }  
         i++; 
    }
    pred[0].label = index_first;
    pred[0].prob = (float)first;
    pred[1].label = index_second;
    pred[1].prob = (float)second;
    pred[2].label = index_third;
    pred[2].prob = (float)third;
    return pred ;
}
pred_t* libaudioAPI(const char* audiofeatures, pred_t* pred)
{
    float weight1[] = IP1_WT ;
    float weight2[] = IP2_WT ;
    float weight3[] = IP3_WT ;
    float weight4[] = IP4_WT ;

    ifstream file(audiofeatures);
    float * features;
    features = (float *)malloc( 250 * sizeof(float));
    int i =0;
    while(!file.eof())
    {
        file>>features[i];
        i++;
    }
    float C[] = IP1_BIAS;
    cblas_sgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans, 1, 144, 250, 1, features, 250, weight1, 144, 1, C, 144);
    for(int i = 0; i<144; i++)
    {
        C[i] = relu(C[i]);
    }

    float D[] = IP2_BIAS;
    cblas_sgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans, 1, 144, 144, 1, C, 144, weight2, 144, 1, D, 144);
    for(int i = 0; i<144; i++)
    {
        D[i] = relu(D[i]);
    }
    //FC3
    
    float E[] = IP3_BIAS;
    cblas_sgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans, 1, 144, 144, 1, D, 144, weight3, 144, 1, E, 144);
    for(int i = 0; i<144; i++)
    {
        E[i] = relu(E[i]);
    }
    float F[] = IP4_BIAS;

    cblas_sgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans, 1, 12, 144, 1, E, 144, weight4, 12, 1, F, 12);
//    softmax(F , 12);
    float sum;
    for(int i =0; i<12 ; i++)
    {
        F[i] = exp(F[i]);
        sum = sum + F[i];
    }
    for(int i =0 ;i < 12; i++)
    {
        F[i] = F[i] / sum ;
    }

    pred = large_three(F,pred);

    return pred;
}

