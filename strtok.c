#include <stdio.h>
#include <string.h>


// strtok 구현하기 

char *m_strtok(char *str, const char *delimiters)
{
    // 함수 재호출시 새로운 시작 주소값
    static char *next;

    // delimiters의 주소값
    char *finish = str;

    // 문자열 시작 주소값
    char *start = str;

    // NULL의 인자를 가지고 함수가 재호출 되었을 때
    if(str == NULL)
    {
        start = next;
	finish = next;
    }

    // 문자열을 다 나누었을 때
    if(finish == NULL && next == NULL)
        return NULL;

    while(1)
    {
        //문자열에 문자가 더이상 없을 때
        if(*finish == '\0')
	{
	    next = NULL;
	    break;
	}

        // 문자열의 문자와 delimiters의 값이 같을 때
	if(*finish == *delimiters)
	{
	    *finish = '\0';
	    next = finish + 1;
	    break;
	}

	finish++;
    }

    return start;
}

int main()
{
    char *result;

    char str[50] = "Basic System Programming";
    
    result = m_strtok(str, " ");
    
    while(result != NULL)
    {
        printf("%s\n", result);
	result = m_strtok(NULL, " ");
    }

}
