// ConsoleApplication1.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include <string>
using namespace std;
#include <vector> 

// �迭�� �־����� �ش� �迭 ���� ������ ������ ���ϴ� ����
#define MAX(a,b) a>b?a:b


int output[4][4]; 
bool  visit[4];
int rowCnt = 0;
void reset () 
{
	for ( int ii = 0; ii < 4; ii++ ) 
		visit[ii] = false;

	for ( int r = 0; r < 4; r++ ) 
		for ( int c = 0; c < 4; c++ )
			output[r][c] = 0;
}


int solution_MaxTime()
{
	
	reset () ;

	vector<int>  input; 
	input.push_back(1);
	input.push_back(2);
	input.push_back(3);
	input.push_back(4);

	int max = 0;
	for ( int ii = 0; ii < 4; ii++) {
		max = MAX(nextTime( input, input[ii], 0 ) , max );
		rowCnt++;
	}

	return max;
}

bool checksum ( int val, int pos ) 
{
	if ( pos == 0 ) { // ��1/ 0 ~ 2
		return val >= 0 && val <= 2;
	} else if ( pos == 1 ) { // ��2  0~9 
		return val >= 0 && val <= 9;
	} else if ( pos == 2 ) { // ��1  // 0 ~ 5
		return val >= 0 && val <= 5;
	} else if ( pos == 3 ) { // ��2 // 0 ~ 9
		return val >= 0 && val <= 9;
	}
	return false;
}

int weight( int val, int pos ) {
	if ( pos == 0 ) { // ��1/ 0 ~ 2
		return val*10*60;
	} else if ( pos == 1 ) { // ��2  0~9 
		return val*60;
	} else if ( pos == 2 ) { // ��1  // 0 ~ 5
		return val * 10;
	} else if ( pos == 3 ) { // ��2 // 0 ~ 9
		return val;
	}
	return 0;
}

int nextTime ( vector<int>& A, int val, int pos ) 
{
	if ( !checksum (val, pos) ) {
		
		return 0;
	}

	if ( visit[pos] == true ) 
		return 0;

	visit[pos] = true;
	output[rowCnt][pos] = val;
	return weight(val, pos) + nextTime(A, A[pos+1], pos++ );
}

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

