#ifndef SHORTCUTS_H
#define SHORTCUTS_H

#include <QObject>

class Shortcuts : public QObject
{
    Q_OBJECT
public:
    explicit Shortcuts(QObject *parent = nullptr);
    Q_PROPERTY(QString quite READ quite WRITE setQuite NOTIFY quiteChanged FINAL)
    Q_PROPERTY(QString maximized READ maximized WRITE setMaximized NOTIFY maximizedChanged FINAL)
    Q_PROPERTY(QString minimized READ minimized WRITE setMinimized NOTIFY minimizedChanged FINAL)
    Q_PROPERTY(QString show READ show WRITE setShow NOTIFY showChanged FINAL)


    QString quite() const;
    QString maximized() const;
    QString minimized() const;
    QString show() const;

public slots:
    void setQuite(const QString &newQuite);
    void setMaximized(const QString &newMaximized);
    void setMinimized(const QString &newMinimized);
    void setShow(const QString &newShow);
signals:
    void quiteChanged();
    void maximizedChanged();
    void minimizedChanged();
    void showChanged();

private:

    QString m_quite;
    QString m_maximized;
    QString m_minimized;
    QString m_show;
};

#endif // SHORTCUTS_H
