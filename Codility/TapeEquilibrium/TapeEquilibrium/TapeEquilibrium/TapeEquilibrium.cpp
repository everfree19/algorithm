// TapeEquilibrium.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"

using namespace std;
#include <vector>
#include <set>
#include <algorithm>
#include <math.h>
#include <algorithm>
#include <math.h>

#define MIN(a,b) a<b?a:b

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    if ( A.empty() )
        return 0;
        
    if ( A.size() == 1 )
        return abs(A[0]);
    else if ( A.size() == 2 )
        return abs(A[1] - A[0]);
    
    int decrement = 0;
    int increment = 0;
    int min = 100000;
    for ( vector<int>::iterator it = A.begin(); it != A.end(); it++)
        decrement += *it;
    
    
    for ( unsigned int ii = 0; ii < A.size() ; ii++)
    {
		if ( ii == A.size() - 2)
			break;
        increment += A[ii];
        decrement -= A[ii];
        min = MIN ( abs ( decrement - increment ), min );
    }
    
    return min; 
}

int _tmain(int argc, _TCHAR* argv[])
{
	vector<int> test;
	test.push_back(-10);
	test.push_back(-20);
	test.push_back(-30);
	test.push_back(-40);
	test.push_back(100);

	int min = solution (test);
	return 0;
}

