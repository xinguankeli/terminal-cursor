#include "widget.h"
#include "ui_widget.h"
#include <QVBoxLayout>
#include <QDebug>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    m_cursor = new MyCursor;
    m_cursor->setFixedSize(2, 18);
    QVBoxLayout *la = new QVBoxLayout;
    la->addWidget(m_cursor);
    setLayout(la);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::keyPressEvent(QKeyEvent *event)//获取键盘事件
{
    Q_UNUSED(event)
    if(event->key() == Qt::Key_Backspace)
    {
        QPoint p = m_cursor->pos();
        QPoint sp = p;
        QPoint ep = p;
        ep.setX(sp.x() - 10);
        m_cursor->setStartPoint(sp);
        m_cursor->setEndPoint(ep);
        m_cursor->moveNext();
    }else{
        QPoint p = m_cursor->pos();
        QPoint sp = p;
        QPoint ep = p;
        ep.setX(sp.x() +10);
        m_cursor->setStartPoint(sp);
        m_cursor->setEndPoint(ep);
        m_cursor->moveNext();
    }

}

