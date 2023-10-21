#ifndef SYSTEMTHEME_H
#define SYSTEMTHEME_H

#include <QObject>

class SystemTheme : public QObject
{
    Q_OBJECT
public:
    explicit SystemTheme(QObject *parent = nullptr);
    Q_PROPERTY(QString wallpaper READ wallpaper WRITE setWallpaper NOTIFY wallpaperChanged FINAL)
    Q_PROPERTY(QString solidColor READ solidColor WRITE setSolidColor NOTIFY solidColorChanged FINAL)

    QString wallpaper() const;
    QString solidColor() const;

public slots:
    void setWallpaper(const QString &newWallpaper);
    void setSolidColor(const QString &newSolidColor);
signals:
    void wallpaperChanged();
    void solidColorChanged();

private:
    QString m_wallpaper;
    QString m_solidColor;
};

#endif // SYSTEMTHEME_H
