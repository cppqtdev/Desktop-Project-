#ifndef IMGPROVIDER_H
#define IMGPROVIDER_H

#include <QQuickImageProvider>
#include <qopengl.h>
#include <QtQuick/QSGTexture>
#include <QUrl>
class ImgProvider : public QQuickImageProvider
{
public:
    ImgProvider() : QQuickImageProvider(QQuickImageProvider::Image)
    {}

    QImage requestImage(const QString &id, QSize *size, const QSize &requestedSize);
    void setBaseUrl(const QUrl &base);

private:
    QUrl m_baseUrl;
};

#endif // IMGPROVIDER_H
