#ifndef TIMEZONE_SELECTOR_H
#define TIMEZONE_SELECTOR_H

#include <QWidget>
#include <QComboBox>
#include <QDBusConnection>
#include <QDBusMessage>

class timezone_selector : public QWidget
{
    Q_OBJECT
public:
    explicit timezone_selector(QWidget *parent = nullptr);

private slots:
    void onTimezoneChanged(const QString &timezone);

private:
    QComboBox *timezoneDropdown;

};

#endif // TIMEZONE_SELECTOR_H
