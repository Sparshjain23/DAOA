#include<stdio.h>
#include<stdlib.h>
int fractionalKnapsack(int weight[],int values[],int n,int capacity){
    int total=0;
    for(int i=0;i<n&& capacity>0;i++){
        int fraction;
        if(capacity<weight[i]){
            fraction=capacity/weight[i];
        }
        else{
            fraction=1;
        }
        total+=fraction*values[i];
        capacity-=weight[i]*fraction;
    }
    return total;
}
int main(){
    int weights[]={10,20,30};
    int values[] = {60, 100, 120};
    int n = sizeof(weights) / sizeof(weights[0]);
    int capacity = 50;
    printf("Maximum value that can be obtained:%d\n",fractionalKnapsack(weights, values, n, capacity));
    return 0;

}