// binaryGap.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"

#define MAX(a,b) a>b?a:b
int solution(int N) {
    // write your code in C++14 (g++ 6.2.0)
	int lot = N;
	int nGapCount = 0;
	int nMaxGap = 0;
	bool bOpen = false;
	while ( lot != 1 ) {
		if ( lot % 2 == 0 ) {
			if ( bOpen )
				nGapCount++;
		} else {
			nMaxGap = MAX(nMaxGap, nGapCount);
			nGapCount = 0;
			bOpen = true;
		}
		lot /= 2;
	}
	return MAX(nMaxGap, nGapCount);
}


int _tmain(int argc, _TCHAR* argv[])
{

	int result = solution ( 1041  );

	return 0;
}

