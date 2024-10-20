#define MAX_PLAYERS 20
#define MAX_PLAYERNAME_LENGTH 20
#define MAX_PASSWORD_LENGTH 20
#include <conio.h>
#include <stdio.h>
#include<stdlib.h> 
#include <string.h>
int available=1;//���Ʋ�ͬ�龰�µ�������

typedef struct {
    char playername[MAX_PLAYERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    int score;
} Player;//�ṹ��

Player players[MAX_PLAYERS];
int theNumberOfPlayer = 0;//�û���

//Ϊ�ṹ�帳ֵ�������û���Ϣ
void loadPlayers() {
    FILE *file = fopen("players.txt", "r");
    if (file == NULL) {
        printf("�޷����ļ���\n");
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

//ע��
int registerPlayer() {
    if (theNumberOfPlayer >= MAX_PLAYERS) {
        printf("�Ѵﵽ����û������޷�ע�����û���\n");
        return 0;
    }

    printf("�������û�����");
    char playername[MAX_PLAYERNAME_LENGTH];
    scanf("%s", playername);

    // ����û����Ƿ��Ѵ���
    for (int i = 0; i < theNumberOfPlayer; i++) {
        if (strcmp(playername, players[i].playername) == 0) {
            printf("�û����Ѵ��ڣ�������ע�ᡣ\n");
            available=0;
            return 0;
        }
    }

    printf("���������룺");
    char password[MAX_PASSWORD_LENGTH];
    char password2[MAX_PASSWORD_LENGTH];

    //scanf("%s", password);
    // ʹ�� getch() �����ȡ�����ַ�������ʾ�Ǻ�
    int i = 0;
    while (1) {
        char c = getch();
        if (c == '\r' || c == '\n') { // �س�����������
            password[i] = '\0';//
            break;
        }
        else if (c == 8 && i > 0) { // �˸��(ascii����8��ɾ���ַ�
            i--;
            printf("\b \b");
        } else {
            password[i] = c;
            i++;
            printf("*");
        }
    }
    printf("\n���ٴ��������룺");
    // ʹ�� getch() �����ȡ�����ַ�������ʾ�Ǻ�
     i = 0;
    while (1) {
        char c = getch();
        if (c == '\r' || c == '\n') { // �س�����������
            password2[i] = '\0';//
            break;
        }
        else if (c == 8 && i > 0) { // �˸��(ascii����8��ɾ���ַ�
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
        // �������û�
        strcpy(players[theNumberOfPlayer].playername, playername);
        strcpy(players[theNumberOfPlayer].password, password);
        players[theNumberOfPlayer].score = 0;
        theNumberOfPlayer++;

        // ���û���Ϣд���ļ�
        FILE *file = fopen("players.txt", "a");
        if (file == NULL) {
            printf("�޷����ļ���\n");
            return 0;
        }
        fprintf(file, "%s %s %d\n", playername, password, 0);
        fclose(file);

        printf("ע��ɹ���\n");
        printf("��ϲ����Ϊ\"Super2048\"�ĵ�%dλ��ң�\n",theNumberOfPlayer);
        return 1;
    }
    else {
        printf("�����������벻һ�£�������ע�ᡣ\n");
        available=0;
        return 0;
    }

}

//��¼


int login() {
    printf("�������û�����");
    char playername[MAX_PLAYERNAME_LENGTH];
    scanf("%s", playername);

    printf("���������룺");
    char password[MAX_PASSWORD_LENGTH];

    // ʹ�� getch() �����ȡ�����ַ�������ʾ�Ǻ�
    int i = 0;
    while (1) {
        char c = getch();
        if (c == '\r' || c == '\n') { // �س�����������
            password[i] = '\0';//
            break;
        }
        else if (c == 8 && i > 0) { // �˸��(ascii����8��ɾ���ַ�
            i--;
            printf("\b \b");
        } else {
            password[i] = c;
            i++;
            printf("*");
        }
    }

    // ���û��ļ�
    FILE *file = fopen("players.txt", "r");
    if (file == NULL) {
        printf("�޷����ļ���\n");
        return 0;
    }

    int authentic = 0;
    int score = 0;

    // ���ж�ȡ�ļ��е��û�������ͷ�����Ϣ�������û�������бȽ�
    while (fscanf(file, "%s %s %d", players[theNumberOfPlayer].playername, players[theNumberOfPlayer].password, &players[theNumberOfPlayer].score) != EOF) {
        if (strcmp(playername, players[theNumberOfPlayer].playername) == 0 && strcmp(password, players[theNumberOfPlayer].password) == 0) {
            authentic = 1;
            score = players[theNumberOfPlayer].score;
            break;
        }
    }

    fclose(file);

    if (authentic) {
        printf("\n��¼�ɹ���\n");
        printf("Welcome, %s!!!\n", playername);
        printf("��߷֣�%d\n", score);
        available = 1;
        return 1;
    } else {
        printf("\n�û���������������ٴγ��ԡ�\n");
        available = 0;
    }

    return 0;
}



//��Ҫ��
void registerLogin() {
    loadPlayers();

    int choice=0;
    int state=0;

    while (!state) {//��1�˳�ѭ��
        switch(available){
            case 1:
                printf("��ӭʹ�ã�This is 2048��\n");
            case 0:
                printf("1. ע��(REGISTER)\n");
                printf("2. ��¼(LOGIN)\n");
                printf("3. �˳�(EXIT)\n");
                printf("��ѡ�������");
                break;
            default:
                printf("available=%d",available);
                break;
        }

        scanf("%d", &choice);
        //��ȡ����
        switch (choice) {
            case 1:
                state=registerPlayer();
                break;
            case 2:
                state=login();
                break;
            case 3:
                printf("���˳���\n");
                available=1;
                exit(1);
            default:
                getchar();//������Ч������
                printf("��Ч��ѡ��������ѡ��\n");
                available=0;
                break;
        }
    }

    return ;
}
