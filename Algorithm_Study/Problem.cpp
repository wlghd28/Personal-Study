#include "Problem.h"

/*
	문제의 정답코드 구현함수 정의
*/
#define MAXDATALENGTH 100

void Solution()
{

}


/*
	문제를 풀 때 쓰일 함수 정의
*/
int Compare(const void* first, const void* second)
{
	//return strcmp((char*)first, (char*)second);
	return *(int*)first - *(int*)second;
}
   