//
//ErrorManager�N���X�̐錾
//Error���̃��b�Z�[�W�����O�ɏ������ށB
//
//����
//�ُ�n���o�邽�тɁA�t�@�C���փA�N�Z�X����̂͗ǂ��Ȃ��B
//�@���@�V���O���g���ŁA�G���[�����n���h�����O���A�Ō�ɃG���[���������ނׂ��B
//      �V���O���g����׋����Ă���A�ύX���邱�ƁA�A�A�A�A

#pragma once
#ifndef ERROEMANAGER_
#define ERROEMANAGER_

#include "Runner.h"

using namespace std;
class ErrorManager
{
public:
    ErrorManager();
    ~ErrorManager();

    //
    //�e�L�X�g�ɃG���[���b�Z�[�W���������ރN���X
    //
    static void WriteErrotTxt(string mesg);
    
    //
    //�t�@�C���𐶐�����N���X�B�쐬����ꏊ��C�h���C�u�����B
    //�v���O�����̈�ԍŏ��ɌĂ΂��B
    //
    static void CreatLogFile();

};

#endif//ERROEMANAGER_
