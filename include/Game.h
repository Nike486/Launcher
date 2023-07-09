#pragma once

#include <iostream>

class Game
{
private:
    std::string name;

public:
    Game()
    {
        name = "";
    }

    Game(std::string _name) : name(std::move(_name)) {};


    /// ���������� ��� ����
    std::string getName();

    /// �������� ��� ��������� ��� ����
    void setName(std::string setName);

    /// ������ ����� ��� ������ ����� ���� � ������ (���������� ����������� ����� ������ ����� ����)
    void classClear();

    /// �������� ���������� ����
    void gameInfo ();

};