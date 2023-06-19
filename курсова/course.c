#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>

char* sort(char word[]); //сортує символи в лексикографічному порядку.
int printInstruction(); //вивід інструкції на екран
int main()

{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
    int variant=0; //для вибору варіанта користувачем
    char s[11]; //для збереження введеного слова
    while (variant!=3){ //вивід меню і очікування вибору варіанту
        printf("Виберіть дію:\n\t1 -Ввести слово;\n\t2 - Інструкція;\n\t3 - Вихід;\n>");
        scanf("%d",&variant);
        switch (variant)
        {
        case 1:
            scanf("%s",&s);
            if (strlen(s)>10){ //якщо довжина більше 10 символів виводиться помилка
                printf("Дуже довге слово\n");
                break;
            }
            strcpy(s,sort(s));
            printf("%s\n",s);
            break;
        case 2:
            printInstruction(); //вивід на екран інструкції
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
            if (word[m]>word[j]) //Якщо знаходиться символ, який менший, ніж поточний символ , оновлюється значення змінної m на індекс цього символу
            {
                m=j;
            }
        }
        if (m!=i){ //перевіряється, чи була знайдена нова позиція для поточного елемента
            char t = word[m];
            word[m]=word[i];
            word[i]=t;
        }
    }
    return word;
}
int printInstruction() //вивід інструкції
{
    char text[] = "Пункт 1. Слово вводити англійською мовою\n\ Пункт 2. Слово має містити не більше 10 символів\n\ ";
    printf("%s\n",text);
    return 0;

}

