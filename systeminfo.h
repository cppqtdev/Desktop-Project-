#ifndef SYSTEMINFO_H
#define SYSTEMINFO_H

#include <QObject>
#include <QSysInfo>
#include <QCoreApplication>
#include <QDebug>


class SystemInfo : public QObject
{
    Q_OBJECT
public:
    explicit SystemInfo(QObject *parent = nullptr);

signals:

};

#endif // SYSTEMINFO_H
