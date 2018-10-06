//
//CSVDataInfo�N���X�̎�����
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include "CSVDataInfo.h"
#include "ErrorManager.h"


//
//�R���X�g���N�^
//
CSVDataInfo:: CSVDataInfo()
{
    this->lines.clear();
    this->lines.resize(0);
}

//
//�R���X�g���N�^
//
CSVDataInfo::CSVDataInfo(string filePath, vector<string> lines) 
{
    this->fileName = filePath;
    
    for (int i = 0; i < lines.size(); ++i)
    {
        this->lines.push_back(lines[i]);
    }
}

//
//�f�X�g���N�^
//
CSVDataInfo::~CSVDataInfo()
{
    
    for (unsigned int i = 0; i < this->lines.size(); ++i)
    {
        if (NULL != this->lines[i].c_str())
        {
            delete this->lines[i].c_str();
            lines[i].c_str() == NULL;
        }
    }
}

//
//�t�@�C���p�X����C���X�^���X�𐶐����ĕԂ����\�b�h
//
CSVDataInfo* CSVDataInfo::ReadCSV(string* filePath)
{
    vector<string> lineArray(NULL);
    
    std::ifstream ifs;  // �t�@�C���ǂݎ��p�X�g���[��
    ifs.open(*filePath);	// �t�@�C���I�[�v��


    if (ifs.fail())
    {
        string mesg =  "�t�@�C�����J���܂���B�@";
        mesg += filePath->c_str();
        cout << mesg << endl;
        ErrorManager::WriteErrotTxt(mesg);
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

