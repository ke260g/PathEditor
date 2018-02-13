#ifndef QPATHLIST_H
#define QPATHLIST_H

#include <QObject>
#include <QWidget>
#include <QStringList>
#include <QListWidget>

class QPathList : public QListWidget
{
    Q_OBJECT
public:
    QPathList();
    ~QPathList();

    void setFromQStringList(/*in*/QStringList & strList);
    void getToQStringList(/*out*/QStringList & strList);
    void getToClipBoard();

    void addPathItem(QString & str);
    void addPathItem();
    void delPathItem(); // del current select
    void getPathItem(QString & item); // get current select

    void setCursorFollow();

private:

private slots:
#if 0
    void on_currentItemChanged(
            QListWidgetItem * current,
            QListWidgetItem * previous);
    void on_currentRowChanged( int currentRow);
#endif

};

#endif // QPATHLIST_H
