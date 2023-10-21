#ifndef APPSMODEL_H
#define APPSMODEL_H

#include <QAbstractListModel>
#include <QList>

#include "apps.h"

class Apps;
class AppsModel : public QAbstractListModel
{
    enum AppRole{
        NameRole = Qt::UserRole +1,
        IconRole
    };

public:
    explicit AppsModel(QObject *parent = nullptr);
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    QHash<int,QByteArray> roleNames() const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;

    void AddApp(Apps *app);

private:
    QList<Apps*> mApps;
};

#endif // APPSMODEL_H
