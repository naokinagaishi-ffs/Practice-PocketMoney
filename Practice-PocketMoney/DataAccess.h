#pragma once
#ifndef DATAACCESS
#define DATAACCESS

#include "Worker.h"
#include "FFGWorker.h"

//�f�[�^�ɃA�N�Z�X����N���X�̐錾

class DataAccess
{
public:
	//�R���X�g���N�^
	DataAccess() ;

	//�f�X�g���N�^
	~DataAccess();

	//Worker�^�̃f�[�^�z�����郁�\�b�h
	Worker* CreatWorkerData();

	//�t�@�C������f�[�^���擾���郁�\�b�h
	string* ReadCSV(string* filPpath);


public:
	int dataCount;			//�z��̐��@=�@�l��
	FFGWorker* workerArray; //worker�^�̃|�C���^�B���I�z��Ɏg���B	

};
#endif // !DATAACCESS
