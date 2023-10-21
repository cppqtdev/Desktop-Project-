#ifndef APPS_H
#define APPS_H

#include <QObject>

class Apps : public QObject
{
    Q_OBJECT
public:
    explicit Apps(QString name,QString icon,QObject *parent = nullptr);
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged FINAL)
    Q_PROPERTY(QString icon READ icon WRITE setIcon NOTIFY iconChanged FINAL)

    QString name() const;
    QString icon() const;

public slots:
    void setName(const QString &newName);
    void setIcon(const QString &newIcon);
signals:
    void nameChanged();
    void iconChanged();

private:
    QString m_name;
    QString m_icon;
};

#endif // APPS_H
