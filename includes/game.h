#define _CRT_SECURE_NO_WARNINGS // ����� vs �� ���������
#include <glew.h> // ���� ����������
#include <glfw3.h>// ���� ����������
#include <time.h>//����� 
#include <windows.h>//api ����� ������� based 
#define STB_IMAGE_IMPLEMENTATION // �� ���� �����, �� ����� ��� ��������� �����
#include <stb_image.h> // ��������� ����������� ����������� �������� ( ������� ���������� ��� ���������������)
GLFWwindow* window; // � ��� ���� ������� 
int m_press = 0; // ����� ��� ����� �� 1, ����� ��� 2
int gamemode = 0; // ����� ���� 
double xpos, ypos; // ��������� ���� (�� ��������)
int gameover = 0; // ��������� ����
float sdwg;// �����, ����� ����� ��� ������� �� ������ ����
struct square // ��������� ���������
{
    int is_open; // ��������/�������� ��������� ������
    int min;// ��� ������ ����?
    int bombs_around; // ����� ������ ������
    int flag;// ����� �� ����
    float color;// ��������� ����� ������
    int close;
}; struct square field[15][15]; // ������� ����
int texturs [5]; // ��������
float colorchange[] = { 1,1,1,1 }; // ��������� ����� ������ � ����
int refresh = 0; // ���� ������
int flag_stay = 0; // ����� ������� ������
int m_press_first = 0; // ���� �� ������ ������� � ����
int FHIGHT; // ��������� ������ ����
int FLENGHT;// ��������� ����� ����
int whenhelp = 0;
int mincounter;
///�������
void helpmin();
void saveload();
void save();