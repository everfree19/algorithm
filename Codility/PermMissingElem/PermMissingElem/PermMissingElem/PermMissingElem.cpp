// PermMissingElem.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"


#include <vector>

using namespace std;
#include <set>
int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    if ( A.empty() )
		return 1;

    set<int> s;
    for ( vector<int>::iterator it = A.begin(); it != A.end(); it++ ) {
        s.insert(*it);   
    }
    
	int start = 1;
    for ( set<int>::iterator sit = s.begin(); sit != s.end(); sit++ ) {
        if ( *sit != start ) 
            break;
        start++;
    }
    return start;
}


int _tmain(int argc, _TCHAR* argv[])
{
	vector<int> A;
	//A.push_back(2);
	//A.push_back(3);
	A.push_back(1);
	//A.push_back(5);
	int ret = solution (A) ;
	return 0;
}

