#pragma once
#ifndef FFGWORKER_
#define FFGWORKER_

#include "Worker.h"
using namespace std;


class FFGWorker :public Worker
{
public:
	FFGWorker(string iD_, string name_);
	~FFGWorker();

	//void Show();

	//string GetID() { return iD; }
	//void  SetID(string iD_) { iD = iD_; }

public:
	string iD;
};

#endif // !FFGWORKER_
