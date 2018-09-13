#ifndef WORKER_H
#define WORKER_H

#include <QDebug>
#include <QTime>
#include <QThread>
#include <QMutexLocker>

class Worker : public QObject
{
    Q_OBJECT

    QThread m_thread;
    double m_x, m_y;
public:
    Worker(double deltaX, double deltaY)
        : m_x{deltaX}
        , m_y{deltaY}
    {
        startTimer(1);
        moveToThread(&m_thread);
        m_thread.start();
    }

signals:
    void move(qreal x, qreal y);

private:
    void timerEvent(QTimerEvent*) override
    {
        move(m_x, m_y);
    }
};

#endif // WORKER_H
