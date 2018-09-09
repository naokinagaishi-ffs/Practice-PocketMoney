#pragma once
#ifndef FFGWORKER_
#define FFGWORKER_
#include "Worker.h"

class FFGWorker :public Worker
{
public:
	FFGWorker();
	~FFGWorker();

	string GetID() { return iD; }
	void  SetID(string iD_) { iD = iD_; }

private:
	string iD;
};

#endif // !FFGWORKER_
