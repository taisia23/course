#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>

char* sort(char word[]); //����� ������� � ����������������� �������.
int printInstruction(); //���� ���������� �� �����
int main()

{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
    int variant=0; //��� ������ ������� ������������
    char s[11]; //��� ���������� ��������� �����
    while (variant!=3){ //���� ���� � ���������� ������ �������
        printf("������� ��:\n\t1 -������ �����;\n\t2 - ����������;\n\t3 - �����;\n>");
        scanf("%d",&variant);
        switch (variant)
        {
        case 1:
            scanf("%s",&s);
            if (strlen(s)>10){ //���� ������� ����� 10 ������� ���������� �������
                printf("���� ����� �����\n");
                break;
            }
            strcpy(s,sort(s));
            printf("%s\n",s);
            break;
        case 2:
            printInstruction(); //���� �� ����� ����������
            break;
        }
    }
    return 0;
}
char* sort(char word[])
{
    int col = strlen(word);
    for (int i=0;i<col-1;i++)
    {
        int m=i;
        for (int j=i+1;j<col;j++)
        {
            if (word[m]>word[j]) //���� ����������� ������, ���� ������, �� �������� ������ , ����������� �������� ����� m �� ������ ����� �������
            {
                m=j;
            }
        }
        if (m!=i){ //������������, �� ���� �������� ���� ������� ��� ��������� ��������
            char t = word[m];
            word[m]=word[i];
            word[i]=t;
        }
    }
    return word;
}
int printInstruction() //���� ����������
{
    char text[] = "����� 1. ����� ������� ���������� �����\n\ ����� 2. ����� �� ������ �� ����� 10 �������\n\ ";
    printf("%s\n",text);
    return 0;

}

