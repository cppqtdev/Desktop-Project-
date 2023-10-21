#include "appsmodel.h"
#include <QDebug>
AppsModel::AppsModel(QObject *parent)
    : QAbstractListModel{parent}
{
    AddApp(new Apps("Home","../Icons/apps/home.svg"));
    AddApp(new Apps("Music","../Icons/apps/Music.png"));
    AddApp(new Apps("Settings","../Icons/apps/settings.svg"));
    AddApp(new Apps("Call","../Icons/apps/Phone.svg"));
    AddApp(new Apps("Camera","../Icons/apps/camera.svg"));
    AddApp(new Apps("Clock","../Icons/apps/clock.svg"));

    AddApp(new Apps("Calculator","../Icons/apps/calculator.svg"));
    AddApp(new Apps("Compass","../Icons/apps/compass.svg"));
    AddApp(new Apps("Files","../Icons/apps/files.svg"));

    AddApp(new Apps("Safari","../Icons/apps/safari.svg"));
    AddApp(new Apps("Photos","../Icons/apps/photos.svg"));
    AddApp(new Apps("Message","../Icons/apps/Message.svg"));

    AddApp(new Apps("TV","../Icons/apps/tv.svg"));
    AddApp(new Apps("iTune","../Icons/apps/itune.svg"));
    AddApp(new Apps("Remainders","../Icons/apps/remainders.svg"));
}

int AppsModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return mApps.size();
}

QHash<int, QByteArray> AppsModel::roleNames() const
{
    QHash<int, QByteArray>  roles;
    roles[NameRole] = "appName";
    roles[IconRole] = "iconUrl";
    return roles;
}

QVariant AppsModel::data(const QModelIndex &index, int role) const
{
    if(!index.isValid() || index.row() > mApps.size()){
        return QVariant();
    }
    Apps *apps = mApps[index.row()];
    switch (role) {
    case NameRole:
        return apps->name();
        break;
    case IconRole:
        return apps->icon();
        break;
    default:
        break;
    }
    return QVariant();
}

void AppsModel::AddApp(Apps *app)
{
    const int size = mApps.size();
    beginInsertRows(QModelIndex(),size,size);
    mApps.append(app);
    endInsertRows();
}
