#include "Aaa.h"

void main()
{
	Aaa a;
	Bbb* b = (Bbb*)&a;

	b->b = 100;
	//delete a;

}