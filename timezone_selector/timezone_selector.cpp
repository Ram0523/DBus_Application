#include "timezone_selector.h"
#include <QVBoxLayout>
#include <QLabel>
#include <QFont>
#include <QDBusConnection>
#include <QDBusMessage>

timezone_selector::timezone_selector(QWidget *parent)
    : QWidget(parent), timezoneDropdown(new QComboBox(this)) {

    // Add timezone options with improved labels
    // timezoneDropdown->addItems({"Asia/Kolkata", "America/New_York", "America/Los_Angeles", "Europe/Berlin"});
    timezoneDropdown->addItems({"Etc/UTC", "America/New_York", "America/Los_Angeles", "Europe/Berlin", "Asia/Calcutta"});
    timezoneDropdown->setFixedSize(300, 50);
    timezoneDropdown->setStyleSheet("font-size: 18px; padding: 5px;");

    QLabel *title = new QLabel("Select Timezone", this);
    QFont titleFont("Arial", 24, QFont::Bold);
    title->setFont(titleFont);
    title->setAlignment(Qt::AlignCenter);

    // Layout with spacing
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(title);
    layout->addWidget(timezoneDropdown);
    layout->setSpacing(20);
    layout->setContentsMargins(30, 30, 30, 30);

    // Register the D-Bus service, object path, and interface
    QDBusConnection sessionBus = QDBusConnection::sessionBus();
    sessionBus.registerService("com.example.clock");
    sessionBus.registerObject("/clock", this, QDBusConnection::ExportAllSlots);

    // Connect timezone selection to signal emission
    connect(timezoneDropdown, &QComboBox::currentTextChanged, this, &timezone_selector::onTimezoneChanged);
}

void timezone_selector::onTimezoneChanged(const QString &timezone) {
    QDBusMessage msg = QDBusMessage::createSignal(
        "/clock", "com.example.clock", "TimezoneChanged");
    msg << timezone;
    QDBusConnection::sessionBus().send(msg);
}
