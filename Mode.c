#define ALLTIME 30//设定总时间
#include "rank.c"
//无尽模式
int endless2048(){
    //srand(time(0));//随机数种子
    time_t startTime;
    startTime=time(NULL);
    printf("\nHi,this is endless!");
    printf("\n您能按Q建退出游戏。祝你游戏愉快！！");
    loadHighScore("endless2048.txt");

    initialize();
    addRandomNumber();
    addRandomNumber();

    int can = 1;

    while (1) {
        if(can){
            printf("\n游戏时间：%ld秒\n" ,time(NULL) -startTime);
            printBoard();
        }


        if (isGameOver()) {
            endless2048();
            break;//退出循环
        }

        char move='w';
        printf("移动方向：");
        scanf(" %c", &move);

        if(move=='q'){
            printf("已退出无尽模式。\n");
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
                printf("无效的移动方向！\n");
        }
        if (can) {
            addRandomNumber();
            system("cls"); //system("cls"); // 用于清空控制台（适用于Windows）
        } else {
            printf("不能移动！请重新输入移动方向。\n");
        }
    }

    return 0;
}
//极限挑战
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
    printf("\n您能按Q建退出游戏。祝你游戏愉快！！");

    while (1) {
        int ftl=1;//控制是否输出表格的标志
        if (can)
            printf("\n游戏时间：%ld秒\n" ,ALLTIME-time(NULL) +startTime);
        if(ftl)
            printBoard();

        if (isGameOver()||ALLTIME-time(NULL) +startTime<=0) {
            printf("游戏结束！\n");
            saveScore("tl2048.txt");
            break;
        }

        char move = 'w';
        printf("移动方向：");
        scanf(" %c", &move);

        if (move == 'q') {
            saveScore("tl2048.txt");
            printf("已退出极限挑战。\n");
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
                printf("无效的移动方向！\n");
                ftl=0;
        }
        if (can) {
            addRandomNumber();
            system("cls"); //system("cls"); // 用于清空控制台（适用于Windows）
        } else {
            printf("不能移动！请重新输入移动方向。\n");
        }
    }
}

int devour2048() {//随机情况下，数字消失
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
            printf("游戏结束！\n");
            saveScore("devour.txt");
            break;
        }

        char move = 'w';
        printf("移动方向：");
        scanf(" %c", &move);

        if (move == 'q') {
            saveScore("devour.txt");
            printf("已退出吞噬模式。\n");
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
                printf("无效的移动方向！\n");
        }
        if (can) {
            addRandomNumber();
            system("cls"); //system("cls"); // 用于清空控制台（适用于Windows）
        } else {
            printf("不能移动！请重新输入移动方向。\n");
        }

    }
}

    int mode() {
        while(1){
            printf("\nThis is SUPER2048!");
            printf("\n2-0-4-8---MODES:\n");
            printf("输入6退出游戏\n");
            printf("1. 经典模式\t2. 无尽模式\n");
            printf("3. 限时挑战\t4. 吞噬模式\n");
            printf("5.查阅玩家排名\t26.退出\n");
            printf("\n请选择游戏模式：");
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
                    printf("已退出游戏。欢迎下次再来呀~~~");
                    return 0;
                default:
                    printf("\n无效输入！请重新输入.");
            }

        }
    }
