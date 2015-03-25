#include <iostream>

using namespace std;

int main()
{
	char c;
	int n1;
	float n2;
	bool b;
	int n3;

	cout << "말하는대로 입력하시오." << endl;
	cout << "'Y' 혹은 'N'을 입력하고 엔터를 치시오." << endl;
	cout << "입력 : ";

	cin >> c;

	//여러개 입력하면 쥬르륵 지나가서 찾아보니 입력된 값을 다음으로 넘기지 않고 지우는 코드랍니다.
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cin.clear();

	if (c == 'Y')
	{
		cout << "'Y'를 입력하였소." << endl;
	}
	else if (c == 'N')
	{
		cout << "'N'를 입력하였소." << endl;
	}
	else
	{
		cout << "망했소." << endl;
		//return 0;
	}

	cout << endl << "숫자 두개를 입력받을 것이오. 하나는 5 ~ 15사이의 정수를, 다른 하나는 1.1 ~ 1.9 사이의 실수를 입력하시오." << endl;
	cout << "정수 입력 : ";
	cin >> n1;

	//여러개 입력하면 쥬르륵 지나가서 찾아보니 입력된 값을 다음으로 넘기지 않고 지우는 코드랍니다.
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cin.clear();

	cout << "실수 입력 : ";
	cin >> n2;

	//여러개 입력하면 쥬르륵 지나가서 찾아보니 입력된 값을 다음으로 넘기지 않고 지우는 코드랍니다.
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cin.clear();

	if ((n1 >= 5 && n1 < 15) && (n2 >= 1.1 && n2 < 1.9))
	{
		cout << "정수는 " << n1 << ", 실수는 " << n2 << "를 입력하였군. 아주 잘하였소." << endl;
	}
	else if (n1 >= 5 && n1 < 15)
	{
		cout << "정수는 " << n1 << "로 잘 입력하였으나 실수를 " << n2 << "로 입력하였군. 하나는 봐줌세." << endl;
	}
	else if (n2 >= 1.1 && n2 < 1.9)
	{
		cout << "실수는 " << n2 << "로 잘 입력하였으나 정수를 " << n1 << "로 입력하였군. 하나는 봐줌세." << endl;
	}
	else
	{
		cout << "망했소." << endl;
	}

	cout << endl << "이번엔 진실 혹은 거짓이오. 알아서 입력하시오." << endl;
	cout << "입력 : ";
	cin >> b;

	//여러개 입력하면 쥬르륵 지나가서 찾아보니 입력된 값을 다음으로 넘기지 않고 지우는 코드랍니다.
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cin.clear();
	
	if (b)
	{
		cout << "참을 입력하였군." << endl;
	}
	else
	{
		cout << "거짓을 입력하였군." << endl;
	}

	cout << endl << "마지막이오. 당신의 키를 입력하시오." << endl;
	cout << "입력 : ";
	cin >> n3;

	//여러개 입력하면 쥬르륵 지나가서 찾아보니 입력된 값을 다음으로 넘기지 않고 지우는 코드랍니다.
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cin.clear();

	if (n3 < 0)
	{
		cout << "당신의 키는 마이너스 인겁니까.." << endl;
	}
	else if (n3 >= 0 && n3 < 100)
	{
		cout << "엄지공주 ~ 난쟁이" << endl;
	}
	else if (n3 >= 100 && n3 < 150)
	{
		cout << "화이팅.." << endl;
	}
	else if (n3 >= 150 && n3 < 180)
	{
		cout << "good" << endl;
	}
	else{
		cout << "크다." << endl;
	}

	return 0;
}
/*
 * 난수란?
 * 규칙성 없는 임의의 수를 뽑아오는것.
 *
 * switch란?
 * 하나의 변수의 값에 따라 코드를 분기시킴!! 많은 if ~ else if ~ else이 사용될때 대용으로 사용 할 수 있다.
 *
 * switch(변수){
 * case 값1:
 *		변수값이 값1일때 처리
 *		break;
 * case 값2:
 *		변수값이 값2일때 처리
 *		break;
 * defualt :
 *		변수값이 case들의 값에 해당없을때.
 *
 * }
 */