#define ALLTIME 30//�趨��ʱ��
#include "rank.c"
//�޾�ģʽ
int endless2048(){
    //srand(time(0));//���������
    time_t startTime;
    startTime=time(NULL);
    printf("\nHi,this is endless!");
    printf("\n���ܰ�Q���˳���Ϸ��ף����Ϸ��죡��");
    loadHighScore("endless2048.txt");

    initialize();
    addRandomNumber();
    addRandomNumber();

    int can = 1;

    while (1) {
        if(can){
            printf("\n��Ϸʱ�䣺%ld��\n" ,time(NULL) -startTime);
            printBoard();
        }


        if (isGameOver()) {
            endless2048();
            break;//�˳�ѭ��
        }

        char move='w';
        printf("�ƶ�����");
        scanf(" %c", &move);

        if(move=='q'){
            printf("���˳��޾�ģʽ��\n");
            saveScore("endless2048.txt");
            score=0;
highScore=0;
            break;
        }

        can = 0;
        switch (move) {
            case 'w':
                can = moveUp();
                break;
            case 's':
                can = moveDown();
                break;
            case 'a':
                can = moveLeft();
                break;
            case 'd':
                can = moveRight();
                break;
            default:
                printf("��Ч���ƶ�����\n");
        }
        if (can) {
            addRandomNumber();
            system("cls"); //system("cls"); // ������տ���̨��������Windows��
        } else {
            printf("�����ƶ��������������ƶ�����\n");
        }
    }

    return 0;
}
//������ս
void tl2048(){
    //srand(time(NULL));
    time_t startTime;
    startTime=time(NULL);
    loadHighScore("tl2048.txt");

    initialize();
    addRandomNumber();
    addRandomNumber();

    int can = 1;
    printf("\nWelcome !!!");
    printf("\n���ܰ�Q���˳���Ϸ��ף����Ϸ��죡��");

    while (1) {
        int ftl=1;//�����Ƿ�������ı�־
        if (can)
            printf("\n��Ϸʱ�䣺%ld��\n" ,ALLTIME-time(NULL) +startTime);
        if(ftl)
            printBoard();

        if (isGameOver()||ALLTIME-time(NULL) +startTime<=0) {
            printf("��Ϸ������\n");
            saveScore("tl2048.txt");
            break;
        }

        char move = 'w';
        printf("�ƶ�����");
        scanf(" %c", &move);

        if (move == 'q') {
            saveScore("tl2048.txt");
            printf("���˳�������ս��\n");
            score=0;
            highScore=0;
            break;
        }

        can = 0;
        switch (move) {
            case 'w':
                can = moveUp();
                ftl=1;
                break;
            case 's':
                can = moveDown();
                ftl=1;
                break;
            case 'a':
                can = moveLeft();
                ftl=1;
                break;
            case 'd':
                can = moveRight();
                ftl=1;
                break;
            default:
                printf("��Ч���ƶ�����\n");
                ftl=0;
        }
        if (can) {
            addRandomNumber();
            system("cls"); //system("cls"); // ������տ���̨��������Windows��
        } else {
            printf("�����ƶ��������������ƶ�����\n");
        }
    }
}

int devour2048() {//�������£�������ʧ
    //srand(time(NULL));

    loadHighScore("devour.txt");

    initialize();
    addRandomNumber();
    addRandomNumber();

    int can = 1;

    while (1) {
        if (can) {
            int row, col;
            row = rand() % SIZE;
            col = rand() % SIZE;
            score-=board[row][col];
            board[row][col] = 0;
            printBoard();
        }

        if (isGameOver()) {
            printf("��Ϸ������\n");
            saveScore("devour.txt");
            break;
        }

        char move = 'w';
        printf("�ƶ�����");
        scanf(" %c", &move);

        if (move == 'q') {
            saveScore("devour.txt");
            printf("���˳�����ģʽ��\n");
            score=0;
highScore=0;
            break;
        }

        can = 0;
        switch (move) {
            case 'w':
                can = moveUp();
                break;
            case 's':
                can = moveDown();
                break;
            case 'a':
                can = moveLeft();
                break;
            case 'd':
                can = moveRight();
                break;
            default:
                printf("��Ч���ƶ�����\n");
        }
        if (can) {
            addRandomNumber();
            system("cls"); //system("cls"); // ������տ���̨��������Windows��
        } else {
            printf("�����ƶ��������������ƶ�����\n");
        }

    }
}

    int mode() {
        while(1){
            printf("\nThis is SUPER2048!");
            printf("\n2-0-4-8---MODES:\n");
            printf("����6�˳���Ϸ\n");
            printf("1. ����ģʽ\t2. �޾�ģʽ\n");
            printf("3. ��ʱ��ս\t4. ����ģʽ\n");
            printf("5.�����������\t26.�˳�\n");
            printf("\n��ѡ����Ϸģʽ��");
            int choice;
            scanf("%d", &choice);
            system("cls");

            switch (choice) {
                case 1:
                    Classical2048();
                    break;
                case 2:
                    endless2048();
                    break;
                case 3:
                    tl2048();
                    break;
                case 4:
                    devour2048();
                    break;
                case 5:
                    rank();
                    break;
                case 6:
                    printf("���˳���Ϸ����ӭ�´�����ѽ~~~");
                    return 0;
                default:
                    printf("\n��Ч���룡����������.");
            }

        }
    }
