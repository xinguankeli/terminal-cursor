#include "mycursor.h"
#include <QDebug>
#include <QPainter>
MyCursor::MyCursor(QWidget *parent) : QWidget(parent),m_changeSign(false)
{
    m_timer = new QTimer;
    m_timer->setInterval(500);
    connect(m_timer, &QTimer::timeout, this, [&]{
        //将颜色替换成透明颜色，paintevent
        m_changeSign = !m_changeSign;
        update();
    });
    m_timer->start();
    setWindowFlags(Qt::Dialog |Qt::FramelessWindowHint);
    setAttribute(Qt::WA_TranslucentBackground, true);
    m_animation = new QPropertyAnimation(this, "pos");
    m_animation->setDuration(50);
    m_animation->setEasingCurve(QEasingCurve::OutCubic);
    connect(m_animation, &QPropertyAnimation::finished, this, [&]{
        m_timer->start();
    });
}

void MyCursor::moveNext()
{
    //设置为黑色背景
    m_timer->stop();
    m_changeSign = false;
    update();
    m_animation->setStartValue(m_startPoint);
    m_animation->setEndValue(m_endPoint);
    m_animation->start();
}


void MyCursor::setStartPoint(const QPoint &sp)
{
    m_startPoint = sp;
}

void MyCursor::setEndPoint(const QPoint &ep)
{
    m_endPoint = ep;
}

void MyCursor::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event)
    QPainter painter(this);
    QColor col;
    if(m_changeSign == true)
    {
        col = QColor(85, 170, 255, 0);
    }else{
        col = Qt::black;
    }
    painter.fillRect(rect(), col);
}
