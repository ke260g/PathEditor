#ifndef QPATHLIST_H
#define QPATHLIST_H

#include <QWidget>
#include <QStringList>
#include <QListWidget>


class QPathList : public QListWidget {
    Q_OBJECT
public:
    explicit QPathList();
    ~QPathList();

    void setAll(/*in*/const QStringList & strList); // first time means init
    void getAll(/*out*/QStringList & strList);
    void getCurrentStr(/*out*/QString & str); // get current select
    void toClipBoard();

    // action
    void addPathItem(/*in*/const QString str = "");
    void delPathItem(); // del current select
    void movePathItemUp();
    void movePathItemDown();
    void undo();
    void redo();

private:
    class color;

    // an action, and also a slot
    void editPathItem(/*in*/const QWidget * editor);

    // restore item string before being edited
    QString itemStrRestore;

    // to implement undo/redo
    class ActionTracer;
    ActionTracer * mActionTracer;
    void exec(); // record action

private slots:
    void on_currentItemChanged(
                    QListWidgetItem * current,
                    QListWidgetItem * previous);
    void on_doubleClicked(const QModelIndex &index);
};

#endif // QPATHLIST_H
