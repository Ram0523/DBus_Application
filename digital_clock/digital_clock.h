#ifndef DIGITAL_CLOCK_H
#define DIGITAL_CLOCK_H

#include <QWidget>
#include <QLCDNumber>
#include <QTimer>
#include <QTimeZone>
#include <QDBusConnection>

class digital_clock : public QWidget
{
    Q_OBJECT
public:
    explicit digital_clock(QWidget *parent = nullptr);

public slots:
    void updateTime();
    void onTimezoneChanged(const QString &timezone);

private:
    QLCDNumber *clockDisplay;
    QTimer *timer;
    QTimeZone currentZone;
};

#endif // DIGITAL_CLOCK_H
