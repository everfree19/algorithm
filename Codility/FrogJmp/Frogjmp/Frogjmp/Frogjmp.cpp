// Frogjmp.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
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

