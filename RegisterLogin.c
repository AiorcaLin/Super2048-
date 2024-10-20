#define MAX_PLAYERS 20
#define MAX_PLAYERNAME_LENGTH 20
#define MAX_PASSWORD_LENGTH 20
#include <conio.h>
#include <stdio.h>
#include<stdlib.h> 
#include <string.h>
int available=1;//控制不同情景下的语句输出

typedef struct {
    char playername[MAX_PLAYERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    int score;
} Player;//结构体

Player players[MAX_PLAYERS];
int theNumberOfPlayer = 0;//用户数

//为结构体赋值，加载用户信息
void loadPlayers() {
    FILE *file = fopen("players.txt", "r");
    if (file == NULL) {
        printf("无法打开文件。\n");
        return;
    }

    while (fscanf(file, "%s %s %d", players[theNumberOfPlayer].playername, players[theNumberOfPlayer].password, &players[theNumberOfPlayer].score) != EOF) {
        theNumberOfPlayer++;
        if (theNumberOfPlayer >= MAX_PLAYERS) {
            break;
        }
    }

    fclose(file);
}

//注册
int registerPlayer() {
    if (theNumberOfPlayer >= MAX_PLAYERS) {
        printf("已达到最大用户数，无法注册新用户。\n");
        return 0;
    }

    printf("请输入用户名：");
    char playername[MAX_PLAYERNAME_LENGTH];
    scanf("%s", playername);

    // 检查用户名是否已存在
    for (int i = 0; i < theNumberOfPlayer; i++) {
        if (strcmp(playername, players[i].playername) == 0) {
            printf("用户名已存在，请重新注册。\n");
            available=0;
            return 0;
        }
    }

    printf("请输入密码：");
    char password[MAX_PASSWORD_LENGTH];
    char password2[MAX_PASSWORD_LENGTH];

    //scanf("%s", password);
    // 使用 getch() 逐个读取密码字符，并显示星号
    int i = 0;
    while (1) {
        char c = getch();
        if (c == '\r' || c == '\n') { // 回车键结束输入
            password[i] = '\0';//
            break;
        }
        else if (c == 8 && i > 0) { // 退格键(ascii码是8）删除字符
            i--;
            printf("\b \b");
        } else {
            password[i] = c;
            i++;
            printf("*");
        }
    }
    printf("\n请再次输入密码：");
    // 使用 getch() 逐个读取密码字符，并显示星号
     i = 0;
    while (1) {
        char c = getch();
        if (c == '\r' || c == '\n') { // 回车键结束输入
            password2[i] = '\0';//
            break;
        }
        else if (c == 8 && i > 0) { // 退格键(ascii码是8）删除字符
            i--;
            printf("\b \b");
        } else {
            password2[i] = c;
            i++;
            printf("*");
        }
    }
    printf("\n");
    if(strcmp(password,password2)==0)
    {
        // 创建新用户
        strcpy(players[theNumberOfPlayer].playername, playername);
        strcpy(players[theNumberOfPlayer].password, password);
        players[theNumberOfPlayer].score = 0;
        theNumberOfPlayer++;

        // 将用户信息写入文件
        FILE *file = fopen("players.txt", "a");
        if (file == NULL) {
            printf("无法打开文件。\n");
            return 0;
        }
        fprintf(file, "%s %s %d\n", playername, password, 0);
        fclose(file);

        printf("注册成功！\n");
        printf("恭喜您成为\"Super2048\"的第%d位玩家！\n",theNumberOfPlayer);
        return 1;
    }
    else {
        printf("两次密码输入不一致，请重新注册。\n");
        available=0;
        return 0;
    }

}

//登录


int login() {
    printf("请输入用户名：");
    char playername[MAX_PLAYERNAME_LENGTH];
    scanf("%s", playername);

    printf("请输入密码：");
    char password[MAX_PASSWORD_LENGTH];

    // 使用 getch() 逐个读取密码字符，并显示星号
    int i = 0;
    while (1) {
        char c = getch();
        if (c == '\r' || c == '\n') { // 回车键结束输入
            password[i] = '\0';//
            break;
        }
        else if (c == 8 && i > 0) { // 退格键(ascii码是8）删除字符
            i--;
            printf("\b \b");
        } else {
            password[i] = c;
            i++;
            printf("*");
        }
    }

    // 打开用户文件
    FILE *file = fopen("players.txt", "r");
    if (file == NULL) {
        printf("无法打开文件。\n");
        return 0;
    }

    int authentic = 0;
    int score = 0;

    // 逐行读取文件中的用户、密码和分数信息，并与用户输入进行比较
    while (fscanf(file, "%s %s %d", players[theNumberOfPlayer].playername, players[theNumberOfPlayer].password, &players[theNumberOfPlayer].score) != EOF) {
        if (strcmp(playername, players[theNumberOfPlayer].playername) == 0 && strcmp(password, players[theNumberOfPlayer].password) == 0) {
            authentic = 1;
            score = players[theNumberOfPlayer].score;
            break;
        }
    }

    fclose(file);

    if (authentic) {
        printf("\n登录成功！\n");
        printf("Welcome, %s!!!\n", playername);
        printf("最高分：%d\n", score);
        available = 1;
        return 1;
    } else {
        printf("\n用户名或密码错误，请再次尝试。\n");
        available = 0;
    }

    return 0;
}



//主要的
void registerLogin() {
    loadPlayers();

    int choice=0;
    int state=0;

    while (!state) {//非1退出循环
        switch(available){
            case 1:
                printf("欢迎使用！This is 2048！\n");
            case 0:
                printf("1. 注册(REGISTER)\n");
                printf("2. 登录(LOGIN)\n");
                printf("3. 退出(EXIT)\n");
                printf("请选择操作：");
                break;
            default:
                printf("available=%d",available);
                break;
        }

        scanf("%d", &choice);
        //读取操作
        switch (choice) {
            case 1:
                state=registerPlayer();
                break;
            case 2:
                state=login();
                break;
            case 3:
                printf("已退出。\n");
                available=1;
                exit(1);
            default:
                getchar();//消除无效的输入
                printf("无效的选择。请重新选择：\n");
                available=0;
                break;
        }
    }

    return ;
}
