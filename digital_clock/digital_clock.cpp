#include "digital_clock.h"
#include <QVBoxLayout>
#include <QDateTime>
#include <QFont>
#include <QLabel>
#include <QDBusConnection>

digital_clock::digital_clock(QWidget *parent)
    : QWidget(parent), clockDisplay(new QLCDNumber(this)), timer(new QTimer(this)) {

    // Set up LCD display with larger font and better appearance
    clockDisplay->setDigitCount(8);
    clockDisplay->setSegmentStyle(QLCDNumber::Flat);
    clockDisplay->setFixedSize(400, 150);
    clockDisplay->setStyleSheet("background-color: black; color: green; border: 2px solid gray;");

    QLabel *title = new QLabel("Digital Clock", this);
    QFont titleFont("Arial", 24, QFont::Bold);
    title->setFont(titleFont);
    title->setAlignment(Qt::AlignCenter);

    // Layout with spacing
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(title);
    layout->addWidget(clockDisplay);
    layout->setSpacing(20);
    layout->setContentsMargins(30, 30, 30, 30);

    // Connect the timer to update the time every second
    connect(timer, &QTimer::timeout, this, &digital_clock::updateTime);
    timer->start(1000);

    // Register the D-Bus service and connect to signal
    QDBusConnection sessionBus = QDBusConnection::sessionBus();
    // sessionBus.registerService("com.example.clock");
    // sessionBus.registerObject("/clock", this, QDBusConnection::ExportAllSlots);

    sessionBus.connect(
        QString(), "/clock", "com.example.clock",
        "TimezoneChanged", this, SLOT(onTimezoneChanged(QString))
        );

    // Initialize the time display
    updateTime();
}

void digital_clock::updateTime() {
    QDateTime current = QDateTime::currentDateTime().toTimeZone(currentZone);
    clockDisplay->display(current.toString("hh:mm:ss"));
}

void digital_clock::onTimezoneChanged(const QString &timezone) {
    currentZone = QTimeZone(timezone.toUtf8());
    updateTime();
}


