
#include<stdio.h>
#include<string.h>
#include<windows.h>

void Print(char* str1, const char* str2)
{
    printf("<%s,%s>\n", str1, str2);
}

char getLetter(char* pstr) {
 /*   char* str = (char*)malloc(strlen(pstr));
    if (!str)
    {
        fprintf(stderr, "\nRan out of memory!\n");
    }
    else return *str
    */
    return *pstr;
}

int isLetter(char n) {
        if (n >= 'A' && n <= 'Z' || n >= 'a' && n <= 'z') {
            return 0;
        }
        else {
            return 1;
        }   
}

int isNum(char str) {
    if (str >= '0' || str <= '9')return 1;
    else return 0;

}

void Judge(char* s, int flength) {
    char ch = NULL;
    char stringbuffer[100];
    int state = 0;
    int i = 0;
    int num = 0;

    const char* keyword[10] = { "main","void","int","char","printf","scanf","else","if","return" };


    while (num<flength) {
        num++;
        switch (state) {
        case 0:
            ch = getLetter(s++);
            switch (ch) {
            case '[':
            case ']':
            case '(':
            case ')':
            case ';':
            case ',':
            case '{':
            case '}':
            case '#':
            case '<':
            case '>':
            case '.':
            case '"':
                stringbuffer[i++] = ch;
                stringbuffer[i] = '\0';
                Print(stringbuffer, "界符");
                state = 0;
                i = 0;
                break;

            case ' ':
                state = 0;
                break;
            case '\t':
                state = 0;
                break;
            case '+':
                stringbuffer[i++] = ch;
                ch = getLetter(s++);
                if (ch != '+' && ch != '=') {
                    s--;
                    stringbuffer[i] = '\0';
                    i = 0;
                    Print(stringbuffer, "运算符");

                }
                else {
                    stringbuffer[i++] = ch;
                    stringbuffer[i] = '\0';
                    Print(stringbuffer, "运算符");
                    i = 0;
                    state = 0;

                }
                break;

            case '-':
                stringbuffer[i++] = ch;
                ch = getLetter(s++);
                if (ch != '-' && ch != '=') {
                    s--;
                    stringbuffer[i] = '\0';
                    i = 0;
                    Print(stringbuffer, "运算符");
                }
                else {
                    stringbuffer[i++] = ch;
                    stringbuffer[i] = '\0';
                    Print(stringbuffer, "运算符");
                    i = 0;
                    state = 0;
                }
                break;

            case '=':
                stringbuffer[i++] = ch;
                ch = getLetter(s++);
                if (ch != '=') {
                    s--;
                    stringbuffer[i] = '\0';
                    i = 0;
                    Print(stringbuffer, "运算符");
                }
                else {
                    stringbuffer[i++] = ch;
                    stringbuffer[i] = '\0';
                    Print(stringbuffer, "运算符");
                    i = 0;
                    state = 0;
                }
                break;

            case '&':
                stringbuffer[i++] = ch;
                ch = getLetter(s++);
                if (ch != '&') {
                    s--;
                    stringbuffer[i] = '\0';
                    i = 0;
                    Print(stringbuffer, "运算符");
                }
                else {
                    stringbuffer[i++] = ch;
                    stringbuffer[i] = '\0';
                    Print(stringbuffer, "运算符");
                    i = 0;
                    state = 0;
                }
                break;

            case '|':
                stringbuffer[i++] = ch;
                ch = getLetter(s++);
                if (ch != '|') {
                    s--;
                    stringbuffer[i] = '\0';
                    i = 0;
                    Print(stringbuffer, "运算符");
                }
                else {
                    stringbuffer[i++] = ch;
                    stringbuffer[i] = '\0';
                    Print(stringbuffer, "运算符");
                    i = 0;
                    state = 0;
                }
                break;

            case '*':
                stringbuffer[i++] = ch;
                ch = getLetter(s++);
                if (ch != '=') {
                    s--;
                    stringbuffer[i] = '\0';
                    i = 0;
                    Print(stringbuffer, "运算符");
                }
                else {
                    stringbuffer[i++] = ch;
                    stringbuffer[i] = '\0';
                    Print(stringbuffer, "运算符");
                    i = 0;
                    state = 0;
                }
                break;


            case '/':
                stringbuffer[i++] = ch;
                ch = getLetter(s++);
                if (ch != '=') {
                    s--;
                    stringbuffer[i] = '\0';
                    i = 0;
                    Print(stringbuffer, "运算符");
                }
                else {
                    stringbuffer[i++] = ch;
                    stringbuffer[i] = '\0';
                    printf(stringbuffer, "运算符");
                    i = 0;
                    state = 0;
                }
                break;

            default:
                if ((ch == '_') || (isLetter(ch == 0))) {
                    stringbuffer[i++] = ch;
                    state = 1;

                }
                else if (isNum(ch) == 0) {
                    stringbuffer[i++] = ch;
                    state = 2;

                }
                else {
                    printf("输入不符合规范!");

                }
            }
            break;


        case 1:     //判断字母
            ch = getLetter(s++);
            if ((ch == '_') || (isNum(ch) == 0) || (isLetter(ch) == 0)) {
                stringbuffer[i++] = ch;
                state = 1;
            }
            else {
                s--;
                stringbuffer[i] = '\0';
                i = 0;
                int j = 0;
                for (j = 0; j < 9; j++) {
                    if ((strcmp(stringbuffer, keyword[j])) == 0) {
                        Print(stringbuffer, "关键字");
                        state = 0;
                        break;
                    }
                    else {
                        Print(stringbuffer, "标识符");
                        state = 0;
                        break;
                    }
                }

            }
            break;

        case 2:     //判断数字

            ch = getLetter(s++);
            if (isNum(ch) == 0) {
                stringbuffer[i++] = ch;
            }
            else if (ch == '.') {
                stringbuffer[i++] = ch;
                state = 3;
            }
            else if (ch == 'E' || ch == 'e') {
                stringbuffer[i++] = ch;
                state = 4;
            }
            else {
                s--;
                stringbuffer[i] = '\0';
                Print(stringbuffer, "数字");
                i = 0;
            }
            break;

        case 3:
            ch = getLetter(s++);
            if (isNum(ch) == 0) {
                stringbuffer[i++] = ch;
                state = 5;
            }
            else {
                printf("输入格式有错！");

            }
            break;

        case 4:
            ch = getLetter(s++);
            if (isNum(ch) == 0) {
                stringbuffer[i++] = ch;
            }
            else {
                s--;
                stringbuffer[i] = '\0';
                Print(stringbuffer, "数字");
                i = 0;

            }
            break;

        case 5:
            ch = getLetter(s++);
            if (isNum(ch) == 0) {
                stringbuffer[i++] = ch;
            }
            else if (ch == 'E' || ch == 'e') {
                stringbuffer[i++] = ch;
                state = 4;
            }
            else {
                s--;
                stringbuffer[i] = '\0';
                Print(stringbuffer, "数字");
                i = 0;
            }
            break;
        }
    }

}

int main()
{
    FILE* fp;
    fp = fopen("D:/电子书/编译原理/C和Java语言实现_虎书_全集/现代编译原理C语言描述_虎书/从官方网站下载的全书代码/全书代码/chapter1/slp.c","r");
    fseek(fp, 0L, SEEK_END);
    int length = ftell(fp);
    char file_content[8092];
    memset(file_content, 0, 8092);
    fseek(fp, 0L, SEEK_SET);
    fread(file_content, length, 1, fp);
    Judge(file_content,length);
}

