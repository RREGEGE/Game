#pragma once
#include "Yut.h"

class Stone :public Yut
{
public:
	Stone();
	~Stone();
	int Move(Yut* yut);
	void SetTogether(bool together);
public:
	int location;
private:
	bool isTogether; // 함께 이동하는지 여부
};

