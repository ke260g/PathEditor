#include "qpathlist.h"

#include <QtWidgets>
#include <QVector>
#include <QPair>

// #include <QDebug>

// color >>
class QPathList::color {
public:
    static QColor selectedBackground;// = QColor(Qt::magenta);
    static QColor selectedForeground;// = QColor(Qt::black);
    static QColor ordinaryBackground;// = QColor(Qt::black);
    static QColor ordinaryForeground;// = QColor(Qt::green);
};

QColor QPathList::color::selectedBackground = QColor(Qt::magenta);
QColor QPathList::color::selectedForeground = QColor(Qt::black);
QColor QPathList::color::ordinaryBackground = QColor(Qt::black);
QColor QPathList::color::ordinaryForeground = QColor(Qt::green);
// color <<

// ActionTracer >>
class QPathList::ActionTracer {
public:
    ActionTracer () {
        flagLock = 0;
        idx = -1;
    }

    void doClear() {
        if(flagLock > 0)
            return;
        actHistory.clear();
        idx = -1;
    }

    void doPush(/*in*/QStringList & strList, int & row) {
        if(flagLock > 0)
            return;

        ++idx;
        if(idx == actHistory.size())
            actHistory.push_back(qMakePair(row, strList));
        else
            actHistory[idx] = qMakePair(row, strList);
    }

    bool toPrev(/*out*/ QStringList & strList, int & row) {
        if(flagLock > 0)
            return false;

        if(idx == 0 || actHistory.size() == 0)
            return false;

        idx--;
        row = actHistory[idx].first;
        strList = actHistory[idx].second;
        return true;
    }

    bool toNext(/*out*/ QStringList & strList, int & row) {
        if(flagLock > 0)
            return false;

        if(idx == (actHistory.size() - 1))
            return false;

        ++idx;
        row = actHistory[idx].first;
        strList = actHistory[idx].second;
        return true;
    }

private:
    int idx;
    // pair<currentRow, stringlist>
    QVector<QPair<int, QStringList>> actHistory;

    void lock() { ++flagLock; }
    void unlock() {
        if(flagLock > 0)
            --flagLock;
    }
    int flagLock;
    friend void QPathList::setAll(const QStringList &strList);
    friend void QPathList::undo();
    friend void QPathList::redo();
};
// ActionTracer <<

QPathList::QPathList() {
    connect(this, &QListWidget::currentItemChanged,
            this, &QPathList::on_currentItemChanged);

    connect(this->itemDelegate(), &QAbstractItemDelegate::commitData,
            this, &QPathList::editPathItem);

    connect(this, &QPathList::doubleClicked,
            this, &QPathList::on_doubleClicked);

    mActionTracer = new ActionTracer;
}

QPathList::~QPathList() {
    delete mActionTracer;
}

void QPathList::setAll(/*in*/const QStringList & strList) {
    clear();
    mActionTracer->lock();

    for(const QString & str: strList)
        addPathItem(str);

    mActionTracer->unlock();

    exec();
}

void QPathList::getAll(/*out*/QStringList & strList) const {
    strList.clear();
    auto cnt = count();
    for(int i = 0; i < cnt; ++i)
        strList.append(item(i)->text());
}

void QPathList::getCurrentStr(/*out*/QString & item) const { // get current select
    item = currentItem()->text();
}

void QPathList::toClipBoard() const {
    QStringList strList;
    getAll(strList);
    QApplication::clipboard()->setText(strList.join(';'));
}

// private slots >>
void QPathList::on_currentItemChanged(
                QListWidgetItem * current,
                QListWidgetItem * previous) {
    if(previous != nullptr) {
        previous->setBackgroundColor(color::ordinaryBackground);
        previous->setForeground(QBrush(color::ordinaryForeground));
    }
    if(current != nullptr) {
        current->setBackgroundColor(color::selectedBackground);
        current->setForeground(QBrush(color::selectedForeground));
    }
}

// edit-begin-signal detect
void QPathList::on_doubleClicked(const QModelIndex &index) {
    itemStrRestore = item(index.row())->text();
}
// private slots <<

// action >>
void QPathList::addPathItem(/*in*/const QString str) {
    QListWidgetItem * item = new QListWidgetItem(str);

    Qt::ItemFlags iFlag = item->flags();
    iFlag |= Qt::ItemIsEditable;
    item->setFlags(iFlag);

    item->setBackgroundColor(color::ordinaryBackground);
    item->setForeground(QBrush(color::ordinaryForeground));

    addItem(item);
    setCurrentItem(item);

    exec();
}

void QPathList::delPathItem() {
    auto row = currentRow();
    if(row > -1 && row < count()) {
        auto pt = takeItem(row);
        delete pt;
        exec();
    }
}

void QPathList::movePathItemUp() {
    int rowIdx = currentRow();
    if(rowIdx <= 0)
        return;
    QListWidgetItem * item = takeItem(rowIdx);
    --rowIdx;
    insertItem(rowIdx, item);
    setCurrentRow(rowIdx);
    exec();
}

void QPathList::movePathItemDown() {
    int rowIdx = currentRow();
    if(rowIdx >= count() - 1)
        return;
    QListWidgetItem * item = takeItem(rowIdx);
    ++rowIdx;
    insertItem(rowIdx, item);
    setCurrentRow(rowIdx);
    exec();
}

void QPathList::undo() {
    QStringList strList;
    int row;
    bool retval = mActionTracer->toPrev(strList, row);
    if(retval) {
        mActionTracer->lock();
        setAll(strList);
        mActionTracer->unlock();

        setCurrentRow(row);

        emit newModification();
    }
}

void QPathList::redo() {
    QStringList strList;
    int row;
    if(mActionTracer->toNext(strList, row)) {
        mActionTracer->lock();
        setAll(strList);
        mActionTracer->unlock();

        setCurrentRow(row);

        emit newModification();
    }
}

// edit-finish-signal detect
void QPathList::editPathItem(/*in*/const QWidget * editor) {
    QString strNewText = reinterpret_cast<const QLineEdit *>(editor)->text();
    if(itemStrRestore != strNewText)
        exec();
}
// action <<

// action trace
void QPathList::exec() {
    int row = currentRow();

    QStringList strList;
    getAll(strList);

    mActionTracer->doPush(strList, row);

    emit newModification();
}
