//str 함수
//strlen 문자열 길이를 구함
//strcmp 두개의 문자열을 비교함
//strcpy 문자열을 복사함
//strcat 문자열을 이어 붙임
//strtok 문자열을 특정 문자를 기준으로 나눔
//strtol 문자열에서 숫자를 추출해서 long형 숫자로 변환

//구조체로 가족 만들기.
#include <iostream>

using namespace std;

struct Family
{
	char name[10];
	int age;
	float height;
};

int main()
{
	Family me;
	Family brother;

	strcpy_s(me.name, "박진한");
	me.age = 25;
	me.height = 183.5;

	strcpy_s(brother.name, "박아무개");
	brother.age = 22;
	brother.height = 175.3;

	cout << "제 이름은 " << me.name << ", 나이는 " << me.age << ", 키는 " << me.height << endl;
	cout << "제 동생의 이름은 " << brother.name << ", 나이는 " << brother.age << ", 키는 " << brother.height << endl;

	return 0;
}