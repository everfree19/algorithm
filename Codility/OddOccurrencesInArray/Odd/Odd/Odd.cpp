// Odd.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"

#include <set>
#include <vector>

using namespace std;
int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    
    set<int> s;
    set< int >::iterator fi ;
    for ( vector<int>::iterator it = A.begin(); it != A.end(); it++ ) {
        fi = s.find ( *it );
         if(fi == s.end())
            s.insert(*it);
         else 
            s.erase(*it);
    }
    return *s.begin();
}

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

