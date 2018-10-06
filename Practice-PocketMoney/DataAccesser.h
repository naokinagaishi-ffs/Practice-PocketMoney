//
//DataAccess�N���X�̐錾
//�f�[�^�A�N�Z�X�Ɋւ��鏈���͂��̃N���X�̐Ӗ�
//
#pragma once
#ifndef DATAACCESSER
#define DATAACCESSER

#include "Worker.h"
#include "FFGWorker.h"
#include <vector>



class DataAccesser
{
public:
     //
	//�R���X�g���N�^
     //
	DataAccesser() ;


     //
	//�f�X�g���N�^
     //
	~DataAccesser();

#pragma region public���\�b�h
     //
     //Worker�^�̃f�[�^�z�����郁�\�b�h
     //
     vector<FFGWorker*>  CreatWorkerDataArray(vector<FFGWorker*> workerArray);

#pragma endregion

#pragma region private ���\�b�h
private:
    //
    //�w��t�H���_����.txt�t�@�C�����������郁�\�b�h
    //
    vector<string> SearchFiles(string& dirPath);

    //
    //�����񂩂�FFGWorker�̃C���X�^���X���쐬���郁�\�b�h
    //
    FFGWorker*  CreatFFGWorker(string strWorkerInfo);

    //
    //delimeter��؂�ŁA�������vector�ɕۑ����ĕԂ����\�b�h
    //
    vector<string> Split(const std::string& input, char delimiter);

    //
    //�t�@�C����s���̃`�F�b�N���s�����\�b�h
    //
    bool CheckOneLine(vector<string> lineData);


#pragma endregion


#pragma region �����o�ϐ�
private:

    //
    //�z��̐擪�|�C���^�BFFGWorker�̃C���X�^���X��ێ�
    //Getter�̂�
    FFGWorker* workerArray_;

#pragma endregion

#pragma region Getter
public:
    //
    //FFGworker�z��̐擪�|�C���^��Ԃ�
    //
    FFGWorker* WorekrArray() { return workerArray_; }

#pragma endregion

};
#endif // !DATAACCESS
