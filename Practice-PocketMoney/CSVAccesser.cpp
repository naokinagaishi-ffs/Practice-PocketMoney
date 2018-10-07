//
//CSVAccesser�N���X�̎�����
//
#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <Windows.h>
#include <locale> 
#include <codecvt> 
#include <cstdio>
#include "ErrorManager.h"
#include "CSVAccesser.h"


//
//�R���X�g���N�^
//
CSVAccesser::CSVAccesser()
{
}

//
//�f�X�g���N�^
//
CSVAccesser::~CSVAccesser()
{
}


//
//�t�@�C���p�X����C���X�^���X�𐶐����ĕԂ����\�b�h
//
CSVDataInfo* CSVAccesser::ReadCSV(string* filePath)
{
    vector<string> lineArray(NULL);

    std::ifstream ifs;
    ifs.open(*filePath);

    if (ifs.fail())
    {
        string mesg = "�t�@�C�����J���܂���B�@";
        mesg += filePath->c_str();
        cout << mesg << endl;
        ErrorManager::WriteErrotTxt(mesg);
        ifs.close();
        return false;
    }

    //��s����lineArray�Ɋi�[���A�ŏI�s�܂œǂݍ��ށB
    while (!ifs.eof())
    {
        string* tmpStr = new string[100];
        getline(ifs, *tmpStr);
        if (!tmpStr->empty())
        {
            lineArray.push_back(*tmpStr);
        }
    }

    return  new CSVDataInfo(*filePath, lineArray);

}

//
//�w��t�H���_������txt�t�@�C�����������郁�\�b�h�B
//�߂�l��vector�ɂ́A�P�v�f�ɂP�t�@�C���̃p�X���܂�
//
vector<string>CSVAccesser::SearchFiles(string& dirPath)
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



