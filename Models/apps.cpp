#include "apps.h"
#include <QDebug>
Apps::Apps(QString name,QString icon,QObject *parent)
    : QObject{parent},
    m_name{name},
    m_icon{icon}
{

}

QString Apps::name() const
{
    return m_name;
}

void Apps::setName(const QString &newName)
{
    if (m_name == newName)
        return;
    m_name = newName;
    emit nameChanged();
}

QString Apps::icon() const
{
    return m_icon;
}

void Apps::setIcon(const QString &newIcon)
{
    if (m_icon == newIcon)
        return;
    m_icon = newIcon;
    emit iconChanged();
}
