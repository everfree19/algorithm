// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include <vector>
#include <functional>
#include <algorithm>

int sum(int num) {
	if(num==0) return num;
	return num + sum(num-1);
}


string solution(int A, int B, int C, int D) {
    // write your code in C++14 (g++ 6.2.0)
	vector<int> candidates;
	candidates.push_back(A);
	candidates.push_back(B);
	candidates.push_back(C);
	candidates.push_back(D);

	sort ( candidates.begin(), candidates.end() , greater<int>() );

	int len = candidates.size();
	int total = sum(len-1);
	string ret;
	char buf[100] = {0,};

	for(int first=0; first<len;first++) {
			if(candidates[first] > 2){
				continue;
			}
			for(int second=0; second<len; second++) {
				if(first == second || (candidates[first] == 2 && candidates[second] > 3)) {
					continue;
				}
				for(int third=0; third<len; third++) {
					if(first == third || second == third || candidates[third] > 5) {
						continue;
					}
					sprintf ( buf, "%d%d:%d%d" , 
						candidates[first], 
						candidates[second], 
						candidates[third],
						candidates[total-first-second-third] ) ;
					ret = buf;
					return ret;
				}
			}
		}
		return "NOT POSSIBLE";
}

