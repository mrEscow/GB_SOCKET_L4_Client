// IN PRO FILE: LIBS += D:\Qt\QT6\Tools\mingw1120_64\x86_64-w64-mingw32\lib\libws2_32.a  !!!

#include <QApplication>

#include <winsock2.h>

#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    WSAData wsaData;
    WORD DllVersion = MAKEWORD(2,2);
    if(WSAStartup(DllVersion, &wsaData) !=0){
        qDebug() << "Error: WSAStartup";
        return a.exec();
    }

    SOCKADDR_IN addr;
    addr.sin_addr.S_un.S_addr =inet_addr("127.0.0.1");
    addr.sin_port = htons(1989);
    addr.sin_family = AF_INET;

    SOCKET Connection = socket(AF_INET,SOCK_STREAM,NULL);
    // connect != Qt connect because function is reset! :)
    if(connect(Connection,(SOCKADDR*)&addr,sizeof(addr)) != 0){
        qDebug() << "Error: failed connect to server";
        return a.exec();
    }
    qDebug() << "Connected!";

    return a.exec();
}
