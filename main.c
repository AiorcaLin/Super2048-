#include<string.h>
#include "Classical2048.c"
#include "Mode.c"
#include "RegisterLogin.c"

//��һ���Ľ�����  2��ui��� 3����������ע������ 
int main(){
    system("title SUPER2048"); //����cmd���ڵ�����
    system("mode con cols=100 lines=50"); //����cmd���ڵĴ�С
    registerLogin();//ע����¼
    mode();//ѡ��ģʽ����ʼ��Ϸ
    return 0;
}
