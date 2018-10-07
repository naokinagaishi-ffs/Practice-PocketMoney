//DataAccess�N���X�̎�����

#include "stdafx.h"
#include "WorkerCreater.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <stdexcept>
#include <cctype>
#include <algorithm>
#include "CSVDataInfo.h"
#include "CSVAccesser.h"
#include "ErrorManager.h"
using namespace std;

//
//�R���X�g���N�^
//
WorkerCreater::WorkerCreater()
{
	//������
    this->workerArray_=NULL;
}

//
//�f�X�g���N�^
//
WorkerCreater::~WorkerCreater()
{
    delete[] this->workerArray_;
    this->workerArray_ = NULL;

}

//
//�I�u�W�F�N�g�̔z�����郁�\�b�h
vector<FFGWorker*> WorkerCreater::CreatWorkerDataArray(vector<FFGWorker*> workerArray)
{
    string dirPath = "";
    vector<string> filePaths(NULL);
    cout << "�t�H���_�p�X����͂��Ă�������" << endl; 
    cin >> dirPath ;

    //�t�H���_���̑S�Ă�txt�t�@�C���̃p�X���擾
    filePaths = CSVAccesser::SearchFiles(dirPath);
    if (filePaths.empty())
    {
        string mesg = "�t�H���_�܂��̓t�@�C�������݂��܂���.\n";
        std::cout << mesg;
        ErrorManager::WriteErrotTxt(mesg);
        return vector<FFGWorker*>(NULL);
    }

    //�t�@�C���C���X�^���X���쐬���Avector�Ńn���h�����O�B
    vector<CSVDataInfo*> csvDataInfos(NULL);
    for (int i = 0; i < filePaths.size(); ++i)
    {
        csvDataInfos.push_back(CSVAccesser::ReadCSV(&filePaths[i]));
    }

    //FFGWorker�̃C���X�^���X�𐶐�
    for (int i = 0; i < csvDataInfos.size(); ++i)
    {
        vector<string> fileLines = csvDataInfos[i]->lines;
        for (int j = 0; j < fileLines.size(); ++j)
        {
            FFGWorker* tmpWorker = CreatFFGWorker(fileLines[j]);
            if (tmpWorker != NULL)
            {
                workerArray.push_back(tmpWorker);
            }
            else
            {
                string mesg = "�s���f�[�^���܂ރt�@�C����" + csvDataInfos[i]->fileName + "�@�ł�\n";
                cout << mesg << endl;
                ErrorManager::WriteErrotTxt(mesg);
            }
        }

    }
    return workerArray;
}


//
//FFGWorker1�l���̃C���X�^���X���쐬���郁�\�b�h
//
FFGWorker* WorkerCreater::CreatFFGWorker(string strWorkerInfo)
{
    workerArray_ = new FFGWorker[strWorkerInfo.size()];
    vector<string> data(NULL);
    data = Split(strWorkerInfo, ',');
    if (!CheckOneLine(data))
    {
        return NULL;
    }
    try
    {
        workerArray_->iD = data[0];
        workerArray_->name = data[1];
        workerArray_->pocketMoney = atoi(data[2].c_str());
    }
    catch (...)
    {
        return NULL;
    }

    return workerArray_;

}


//
//delimeter��؂�ŁA�������vector�ɕۑ����ĕԂ����\�b�h
//
vector<string> WorkerCreater::Split(const string& input, char delimiter)
{
    istringstream stream(input);

    string field;
    vector<string> result;
    while (getline(stream, field, delimiter))
    {
        result.push_back(field);
    }
    return result;
}

//
//�t�@�C����s���̃`�F�b�N���s�����\�b�h
//
bool WorkerCreater::CheckOneLine(vector<string> line)
{
    const int ELEMENTNUMBER = 3;
    string mesg = "";

    //�v�f���̃`�F�b�N
    if (line.size() != ELEMENTNUMBER)
    {
        mesg = "�f�[�^�̃t�B�[���h�����s���ł��B�f�[�^�����O���܂����B";
        cout << mesg << endl;
        ErrorManager::WriteErrotTxt(mesg);
        return false;
    }

    //�f�[�^���Ɍ��������邩�̃`�F�b�N
    for (int j = 0; j < ELEMENTNUMBER; ++j)
    {
        if (line[j].empty())
        {
            mesg = "�f�[�^���ɋ�̃t�B�[���h��������܂��B�f�[�^�����O���܂����B";
            cout << mesg << endl;
            ErrorManager::WriteErrotTxt(mesg);
            return false;
        }
    }

    //���l�ϊ��ł��邩�̃`�F�b�N
    if (!all_of(line[2].cbegin(), line[2].cend(), isdigit))
    {
        mesg = "�����𐔒l�ɕϊ��ł��܂���B�f�[�^�����O���܂����B";
        cout << mesg << endl;
        ErrorManager::WriteErrotTxt(mesg);
        return false;

    }

    return true;
}

