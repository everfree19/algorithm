// CyclicRotation.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <algorithm>
#include <vector>

using namespace std;

int next (  vector<int> &A, int start, int K ) 
{
    return ( start + K ) % A.size();
}


void shiftIndex ( vector<int> &A, vector<int> &B, int K )
{
    for ( unsigned int ii = 0; ii < A.size(); ii++ ) {
        B[ii] = next ( A, ii, K );   
    }
}

vector<int> solution(vector<int> &A, int K) {
    // write your code in C++14 (g++ 6.2.0)
    
    vector<int> shiftIndexArr(A.size());
    shiftIndex ( A, shiftIndexArr, K );
    
    vector<int> newArray(A.size());
    for (unsigned int ii = 0 ; ii < A.size(); ii++ ) {
        newArray[shiftIndexArr[ii]] = A[ii];
    }
    return newArray;
}

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

