#include "imgprovider.h"

#include <QFile>
#include <QDebug>
#include <qopenglfunctions.h>
#include <qqmlfile.h>
QImage ImgProvider::requestImage(const QString &id, QSize *size, const QSize &requestedSize)
{
    Q_UNUSED(requestedSize);
    QImage ret;

    QUrl url = QUrl(id);
    if (url.isRelative() && !m_baseUrl.isEmpty())
        url = m_baseUrl.resolved(url);
    QString path = QQmlFile::urlToLocalFileOrQrc(url);
    ret.load(path);
    *size = ret.size();

    return ret;
}

void ImgProvider::setBaseUrl(const QUrl &base)
{
    m_baseUrl = base;
}
