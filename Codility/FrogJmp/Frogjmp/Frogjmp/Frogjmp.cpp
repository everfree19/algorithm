// Frogjmp.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"


int solution(int X, int Y, int D) {
    // write your code in C++14 (g++ 6.2.0)
    int distance = Y - X;
    if ( distance < 0 ) 
        return 0;

    return distance % D == 0 ? distance / D : distance / D + 1;
}


int _tmain(int argc, _TCHAR* argv[])
{
	int ret = solution ( 1,5,2);
	return 0;
}

