//
//CSVDataInfo�N���X�̎�����
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include "CSVDataInfo.h"


//�R���X�g���N�^
CSVDataInfo:: CSVDataInfo()
{

}
//�R���X�g���N�^
CSVDataInfo::CSVDataInfo(string filePath, vector<string> lines) 
{
    this->fileName = filePath;
    this->lines = lines;
}

//�f�X�g���N�^
CSVDataInfo::~CSVDataInfo()
{
    for (unsigned int i = 0; i < this->lines.size(); ++i)
    {
        if (NULL != this->lines[i].c_str())
        {
            lines[i].c_str() == NULL;
        }
    }
}

CSVDataInfo* CSVDataInfo::ReadCSV(string* filePath)
{
    vector<string> lineArray(NULL);

    std::ifstream ifs;  // �t�@�C���ǂݎ��p�X�g���[��
    ifs.open(*filePath);	// �t�@�C���I�[�v��


    if (ifs.fail())
    {
        // �t�@�C���I�[�v���Ɏ��s�����炻���ŏI��
        cout << "�t�@�C�����J���܂���" << endl;

        //return lineArray; //�x�������o���āA��̔z���Ԃ�
    }

    while (!ifs.eof())
    {
        string* tmpStr = new string[30];
        getline(ifs, *tmpStr);
        lineArray.push_back(*tmpStr);
    }

    return  new CSVDataInfo(*filePath, lineArray);

}
