#pragma once
#ifndef WORKER_
#define WORKER_
#include "stdafx.h"
#include <iostream>
using namespace std;
class Worker 
{
public:
	Worker();				//コンストラクタ
	Worker(string name_);	//コンストラクタ
	~Worker();				//デストラクタ

	string GetName() { return name; }
	void  SetName(string name_) { name = name_; }

private:
	string name;

};
#endif // !WORKER_
