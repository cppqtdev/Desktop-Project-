#include "shortcuts.h"

Shortcuts::Shortcuts(QObject *parent)
    : QObject{parent}
{
    m_quite = "Ctrl+Q";
    m_maximized = "Ctrl+M";
    m_minimized = "Ctrl+D";
    m_show = "Ctrl+N";
}

QString Shortcuts::quite() const
{
    return m_quite;
}

void Shortcuts::setQuite(const QString &newQuite)
{
    if (m_quite == newQuite)
        return;
    m_quite = newQuite;
    emit quiteChanged();
}

QString Shortcuts::maximized() const
{
    return m_maximized;
}

void Shortcuts::setMaximized(const QString &newMaximized)
{
    if (m_maximized == newMaximized)
        return;
    m_maximized = newMaximized;
    emit maximizedChanged();
}

QString Shortcuts::minimized() const
{
    return m_minimized;
}

void Shortcuts::setMinimized(const QString &newMinimized)
{
    if (m_minimized == newMinimized)
        return;
    m_minimized = newMinimized;
    emit minimizedChanged();
}

QString Shortcuts::show() const
{
    return m_show;
}

void Shortcuts::setShow(const QString &newShow)
{
    if (m_show == newShow)
        return;
    m_show = newShow;
    emit showChanged();
}
