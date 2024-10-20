#include <stdio.h>
#include <string.h>

#define MAX_PLAYERNAME_LENGTH 50
#define MAX_PASSWORD_LENGTH 50
#define MAX_PLAYERS 100

typedef struct {
    char playername[MAX_PLAYERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    int score;
} Player3;

void sortPlayersByScore() {
    FILE* file = fopen("players.txt", "r");
    if (file == NULL) {
        printf("无法打开文件。\n");
        return;
    }

    Player3 players[MAX_PLAYERS];
    int numPlayers = 0;

    // 读取玩家信息到数组
    Player3 player;
    while (fscanf(file, "%s %s %d", player.playername, player.password, &player.score) != EOF) {
        players[numPlayers] = player;
        numPlayers++;
    }

    fclose(file);

    // 使用冒泡排序按分数排序玩家
    for (int i = 0; i < numPlayers - 1; i++) {
        for (int j = 0; j < numPlayers - i - 1; j++) {
            if (players[j].score < players[j + 1].score) {
                // 交换位置
                Player3 temp = players[j];
                players[j] = players[j + 1];
                players[j + 1] = temp;
            }
        }
    }

    // 输出排序后的玩家分数
    for (int i = 0; i < numPlayers; i++) {
        printf("第%d名 玩家：%s\t分数：%d\n", i+1,players[i].playername, players[i].score);
    }
}

int rank() {
    sortPlayersByScore();

    return 0;
}
