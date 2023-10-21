#include "systemtheme.h"

SystemTheme::SystemTheme(QObject *parent)
    : QObject{parent}
{
    m_wallpaper = "images/background.jpg";
    m_solidColor = "transparent";
}

QString SystemTheme::wallpaper() const
{
    return m_wallpaper;
}

void SystemTheme::setWallpaper(const QString &newWallpaper)
{
    if (m_wallpaper == newWallpaper)
        return;
    m_wallpaper = newWallpaper;
    emit wallpaperChanged();
}

QString SystemTheme::solidColor() const
{
    return m_solidColor;
}

void SystemTheme::setSolidColor(const QString &newSolidColor)
{
    if (m_solidColor == newSolidColor)
        return;
    m_solidColor = newSolidColor;
    emit solidColorChanged();
}
