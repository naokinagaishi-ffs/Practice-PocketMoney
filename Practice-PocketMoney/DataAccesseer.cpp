//DataAccess�N���X�̎�����

#include "stdafx.h"
#include "DataAccesser.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <stdexcept>
#include <Windows.h>
#include <locale> 
#include <codecvt> 
#include <cstdio>
#include <cctype>
#include <algorithm>
#include "CSVDataInfo.h"
#include "ErrorManager.h"

using namespace std;

//
//�R���X�g���N�^
//
DataAccesser::DataAccesser()
{
	//������
    this->workerArray_=NULL;
}

//
//�f�X�g���N�^
//
DataAccesser::~DataAccesser()
{
    delete[] this->workerArray_;
    this->workerArray_ = NULL;

}

//
//�I�u�W�F�N�g�̔z�����郁�\�b�h
vector<FFGWorker*> DataAccesser::CreatWorkerDataArray(vector<FFGWorker*> workerArray)
{
    //string dirPath = "C:\\�����������K_ShiftJis_";//�R�}���h���C��������͂���悤�ɂ��ƂŕύX
    string dirPath = "C:\\�����������K_ShiftJis";
    //string dirPath = "C:\\���������K_ShiftJis_";


    vector<string> filePaths(NULL);
    //cout << "�t�H���_�p�X����͂��Ă�������" << endl; 
    //cin >> dirPath ;

    //�t�H���_���̑S�Ă�txt�t�@�C���̃p�X���擾
    filePaths = SearchFiles(dirPath);
    if (filePaths.empty())
    {
        string mesg = "�t�H���_�܂��̓t�@�C�������݂��܂���.\n";
        cout << mesg;
        ErrorManager::WriteErrotTxt(mesg);
        return vector<FFGWorker*>();
    }


    //�t�@�C���C���X�^���X���쐬���Avector�Ńn���h�����O�B
    vector<CSVDataInfo*> csvDataInfos(NULL);
    for (int i = 0; i < filePaths.size(); ++i)
    {
        csvDataInfos.push_back(CSVDataInfo::ReadCSV(&filePaths[i]));
    }

    //����ȃt�@�C���C���X�^���X����̂�Worker�f�[�^���쐬
    for (int i = 0; i < csvDataInfos.size(); ++i)
    {
        vector<string> tmpLines = csvDataInfos[i]->lines;
        if (CheckOneLine(tmpLines))
        {
            int lineNum = tmpLines.size();
            for (int j = 0; j < lineNum; ++j)
            {
                workerArray.push_back((CreatFFGWorker(tmpLines[j])));
            }
        }
        else
        {
            string mesg = csvDataInfos[i]->fileName + "���s���ȃt�@�C���ł�\n";
            cout << mesg << endl;
            ErrorManager::WriteErrotTxt(mesg);
        }

    }

    return workerArray;
}


//
//�w��t�H���_������txt�t�@�C�����������郁�\�b�h�B�P�v�f�ɂP�t�@�C���̃p�X���܂�
//
vector<string>DataAccesser::SearchFiles(string& dirPath)
{

	HANDLE hFind;
	WIN32_FIND_DATA win32fd;

	vector<string> fileNames(NULL);   
	string extention = "txt";
     
	string searchName = dirPath + "\\*." + extention;


     hFind = FindFirstFile(searchName.c_str(), &win32fd);
     
     if (hFind == INVALID_HANDLE_VALUE)
     {
         //�t�@�C���p�X���Ȃ��ꍇ�́A�����������Ȃ��B
     }
     else
     {
         do
         {
             fileNames.push_back(dirPath + "\\" + win32fd.cFileName);

         } while (FindNextFile(hFind, &win32fd));
     }

     FindClose(hFind);

     return fileNames;
}

//
//data����FFGWorker1�l���̃C���X�^���X���쐬���郁�\�b�h
//
FFGWorker* DataAccesser::CreatFFGWorker(string strWorkerInfo)
{
    vector<string> data(NULL);
    data = Split(strWorkerInfo, ',');
    workerArray_->iD = data[0];
    workerArray_->name = data[1];
    workerArray_->pocketMoney = atoi(data[2].c_str());

    return workerArray_;

}


//
//delimeter��؂�ŁA�������vector�ɕۑ����ĕԂ����\�b�h
//
vector<string> DataAccesser::Split(const string& input, char delimiter)
{
    istringstream stream(input);

    string field;
    vector<string> result;
    while (getline(stream, field, delimiter)) {
        result.push_back(field);
    }
    return result;
}

//
//�t�@�C����s���̃`�F�b�N���s�����\�b�h
//
bool DataAccesser::CheckOneLine(vector<string> lines)
{
    const int ELEMENTNUMBER = 3;
    string mesg = "";

    for (int i = 0; i < lines.size(); ++i)
    {
        vector<string> oneLine = Split(lines[i], ',');

        //�v�f���̃`�F�b�N
        if (oneLine.size() != ELEMENTNUMBER)
        {
            mesg = "�f�[�^�̃t�B�[���h�����s���ł��B";
            cout << mesg << endl;
            ErrorManager::WriteErrotTxt(mesg);
            return false;
        }

        //�f�[�^���Ɍ��������邩�̃`�F�b�N
        for (int j = 0; j < ELEMENTNUMBER; ++j)
        {
            if (oneLine[j].empty())
            {
                mesg = "�f�[�^���ɋ�̃t�B�[���h��������܂��B";
                cout << mesg ;
                ErrorManager::WriteErrotTxt(mesg);
                return false;
            }
        }

        //���l�ϊ��ł��邩�̃`�F�b�N
        //if (!all_of(oneLine[2].cbegin(), oneLine[2].cend(), isdigit))
        //{
        //    mesg = "�����𐔒l�ɕϊ��ł��܂���B";
        //    cout << mesg ;
        //    ErrorManager::WriteErrotTxt(mesg);
        //    return false;

        //}

    }

    return true;
}

