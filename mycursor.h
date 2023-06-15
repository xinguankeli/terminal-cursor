#ifndef MYCURSOR_H
#define MYCURSOR_H

#include <QWidget>
#include <QRect>
#include <QTimer>
#include <QPaintEvent>
#include <QMutex>
#include <QPropertyAnimation>
#include <QPoint>
class MyCursor : public QWidget
{
    Q_OBJECT
public:
    explicit MyCursor(QWidget *parent = nullptr);
    void moveNext();//移动到下一个
    void moveFront();//移动到前一个
    void setStartPoint(const QPoint &sp);
    void setEndPoint(const QPoint &ep);
protected:
    void paintEvent(QPaintEvent *event) override;
private:
    QTimer *m_timer;
    bool m_changeSign;
    QPropertyAnimation *m_animation;//移动动画
    QPoint m_startPoint;//移动的点
    QPoint m_endPoint;//
};

#endif // MYCURSOR_H
