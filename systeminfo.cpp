#include "systeminfo.h"
#include <QStorageInfo>
SystemInfo::SystemInfo(QObject *parent)
    : QObject{parent}
{
    qDebug() << "Operating System Name: " << QSysInfo::prettyProductName();
    qDebug() << "Operating System Version: " << QSysInfo::productVersion();
    qDebug() << "Operating System Type: " << QSysInfo::productType();
    QByteArray username = qgetenv("USER");
    qDebug() << "User: " << username;
    qDebug() << "CPU Architecture: " << QSysInfo::currentCpuArchitecture();

    QList<QStorageInfo> drives = QStorageInfo::mountedVolumes();
    foreach (const QStorageInfo &drive, drives) {
        qDebug() << "Drive: " << drive.rootPath();
        qDebug() << "File System Type: " << drive.fileSystemType();
        qDebug() << "Total Size: " << drive.bytesTotal() << " bytes";
        qDebug() << "Free Size: " << drive.bytesFree() << " bytes";
    }
}
