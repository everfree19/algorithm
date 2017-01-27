// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

#include <algorithm>
bool solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
     // write your code in C++14 (g++ 6.2.0)
	vector<int> ordered_Vector;
	for ( vector<int>::iterator it = A.begin(); it != A.end(); it++ ) {
		ordered_Vector.push_back ( *it );
	}
    
	if ( ordered_Vector.size() != A.size() )
		return false;


	sort(ordered_Vector.begin(), ordered_Vector.end());

	int diffCnt = 0;
	for ( unsigned int ii = 0; ii < A.size(); ii++ ) {
		if ( ordered_Vector[ii] != A[ii] )
			diffCnt++;
	}

	return  ( diffCnt == 2 || diffCnt == 0 ) ? true : false; 
    
}