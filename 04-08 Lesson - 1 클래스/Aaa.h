#pragma once
class Aaa
{
private:
	int a;
public:
	int b;
	Aaa();
	~Aaa();
};

class Bbb : public Aaa
{
public: 
	Bbb();
	void a();
};