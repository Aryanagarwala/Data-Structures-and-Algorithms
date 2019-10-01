#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
//Euclidean Algorithm is an algorithm to find GCD of two numbers in O(LogN)
int GCD(int a, int b){
    if(a==0) return b;
    return (b%a, a);
}