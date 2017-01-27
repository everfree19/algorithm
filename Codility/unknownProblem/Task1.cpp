// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include <regex>
#define MAX(a,b) a>b?a:b

#if 1
int solution(string &S) 
{
	regex numRegx("[0-9+]");
	regex upperAtleastOne ("[A-Z]\\w+");
	
	regex_token_iterator<string::iterator> iter(S.begin(), S.end(), numRegx, -1);
	regex_token_iterator<string::iterator> end;
	
	vector<string> strings;
	while ( iter != end ) 
		strings.push_back(*iter++);
	
	smatch match;
	int maxLength = -1;
	for ( vector<string>::iterator it = strings.begin(); it != strings.end(); it++ ) {
		if ( regex_match ( *it , match, upperAtleastOne ) ) {
			if ( (int)(*it).length() > maxLength )
				maxLength = (*it).length();
		}
	}
	return maxLength;
}

#else 
bool isDigit ( char ch ) {
	return  ch <= '9' && ch >= '0' ;
}

bool isUppercase( char ch ) {
	return ch <= 'Z' && ch >= 'A' ;
}

bool isUppercase( string str ) {
	for ( unsigned int ii = 0; ii < str.length() ; ii ++ ) {
		if ( isUppercase ( str[ii] ) )
			return true; 
	}
	return false;
}

int solution(string &S) 
{
	unsigned int ret = 0;
	string substring; 
	for ( unsigned int i = 0; i < S.length(); i++ ) {
		if ( isDigit( S[i] ) && substring.length() != 0) {
			if ( isUppercase ( substring ) )
				ret = MAX ( substring.length(), ret ); 
			substring.clear();
		}
		else {
			if ( !isDigit( S[i]))
				substring+=S[i];
		}	
	}
	
	if ( !substring.empty() ) {  
		if ( isUppercase ( substring[0] ) )
			ret = MAX ( substring.length(), ret ); 
	}  

	return ret > 0 ? ret : -1 ;  // return length of value 
}

#endif 