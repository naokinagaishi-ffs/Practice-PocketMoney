#pragma once
#ifndef RUNNER_H
#define RUNNER_H

#include "Worker.h"
#include "FFGWorker.h"
#include <iostream>
using namespace std;

//Ruuner�N���X�̐錾
class Runner
{
public:
	Runner();	//�@�R���X�g���N�^
	~Runner();	//�@�f�X�g���N�^

	//�����̎��s
	void Run();
	
	void Show(const Worker& worker);

};
#endif // !RUNNER_H
