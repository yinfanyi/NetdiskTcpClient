#include "friend.h"

Friend::Friend(QWidget *parent)
    : QWidget{parent}
{
    m_pShowMsgTE = new QTextEdit;
    m_pFriendListWidget = new QListWidget;
    m_pInputMsgLE = new QLineEdit;
    m_pDelFriendPB = new QPushButton("删除好友");
    m_pFlushFriendPB = new QPushButton("刷新好友");
    m_pShowOnlineUsrPB = new QPushButton("显示在线");
    m_pSearchUsrPB = new QPushButton("查找用户");
    m_pMsgSendPB = new QPushButton("发送信息");
    m_pPrivateChatPB = new QPushButton("私聊");

    QVBoxLayout *pRightPBVL = new QVBoxLayout;
    pRightPBVL->addWidget(m_pDelFriendPB);
    pRightPBVL->addWidget(m_pFlushFriendPB);
    pRightPBVL->addWidget(m_pShowOnlineUsrPB);
    pRightPBVL->addWidget(m_pSearchUsrPB);
    pRightPBVL->addWidget(m_pPrivateChatPB);

    QHBoxLayout *pTopHBL = new QHBoxLayout;
    pTopHBL->addWidget(m_pShowMsgTE);
    pTopHBL->addWidget(m_pFriendListWidget);
    pTopHBL->addLayout(pRightPBVL);

    QHBoxLayout *pMsgHBL = new QHBoxLayout;
    pMsgHBL->addWidget(m_pInputMsgLE);
    pMsgHBL->addWidget(m_pMsgSendPB);

    m_pOnline = new online;

    QVBoxLayout *pMain = new QVBoxLayout;
    pMain->addLayout(pTopHBL);
    pMain->addLayout(pMsgHBL);
    pMain->addWidget(m_pOnline);

    m_pOnline->hide();

    setLayout(pMain);

    connect(m_pShowOnlineUsrPB,SIGNAL(clicked(bool))
            ,this,SLOT(showOnline()));

}

//Friend::~Friend()
//{   delete(m_pShowMsgTE);
//    delete(m_pFriendListWidget);
//    delete(m_pInputMsgLE);
//    delete(m_pDelFriendPB);
//    delete(m_pFlushFriendPB);
//    delete(m_pShowOnlineUsrPB);
//    delete(m_pSearchUsrPB);
//    delete(m_pMsgSendPB);
//    delete(m_pPrivateChatPB);
//}

void Friend::showOnline()
{
    if(m_pOnline->isHidden()){
        m_pOnline->show();
    }else{
        m_pOnline->hide();
    }
}