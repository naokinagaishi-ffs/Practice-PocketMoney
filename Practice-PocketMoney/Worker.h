#pragma once
#ifndef WORKER_
#define WORKER_
#include "stdafx.h"
#include <iostream>
using namespace std;
class Worker 
{
public:
	Worker();				//�R���X�g���N�^
	Worker(string name_);	//�R���X�g���N�^
	~Worker();				//�f�X�g���N�^

	string GetName() { return name; }
	void  SetName(string name_) { name = name_; }

private:
	string name;

};
#endif // !WORKER_
