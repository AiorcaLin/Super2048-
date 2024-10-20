#include<string.h>
#include "Classical2048.c"
#include "Mode.c"
#include "RegisterLogin.c"

//下一步改进方向  2，ui设计 3。联网更新注册人数 
int main(){
    system("title SUPER2048"); //设置cmd窗口的名字
    system("mode con cols=100 lines=50"); //设置cmd窗口的大小
    registerLogin();//注册或登录
    mode();//选择模式并开始游戏
    return 0;
}
