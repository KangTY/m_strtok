#include <stdio.h>
#include <string.h>


// strtok 구현하기 

char *m_strtok(char *str, const char *delimiters)
{
    char *start = str; // 문자열 시작 주소값

    while(1)
    {
         str++;

	 if(*str == *delimiters) // 문자열의 문자와  delimiters가 같으면
	 {
	     *str = '\0'; // delimiters를 NUL로 변경
	     break;
	 }
    }

    return start;
}

int main()
{
    char *result;  // 결과값 저장 변수

    char str[50] = "Basic System Programming";
    
    result = m_strtok(str, " ");
    printf("%s\n", result);
}
