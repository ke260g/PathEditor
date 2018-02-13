#include "qpathlist.h"
#include <QtWidgets>

#include <QListWidgetItem>
#include <QDebug>
#include <QPoint>
#include <QCursor>

namespace color {
auto selectedBackground = QColor(Qt::gray) ;
auto selectedForeground = QColor(Qt::darkYellow);
auto ordinaryBackground = QColor(Qt::black);
auto ordinaryForeground = QColor(Qt::green);
}


QPathList::QPathList() {
    this->setDragDropMode(QAbstractItemView::InternalMove);
}

QPathList::~QPathList() { }

void QPathList::setFromQStringList(/*in*/QStringList & strList) {
    this->clear();
    for(QString & str: strList) {
        this->addPathItem(str);
    }

}

void QPathList::getToQStringList(/*out*/QStringList & strList) {
    strList.clear();
    auto cnt = this->count();
    for(int i = 0; i < cnt; ++i) {
        strList.append(this->item(i)->text());
    }
}

void QPathList::addPathItem(QString & str) {
    QListWidgetItem * item = new QListWidgetItem(str);
#if 1 //
    Qt::ItemFlags iFlag = item->flags();
    iFlag |= Qt::ItemIsEditable;
    item->setFlags(iFlag);
    item->setBackgroundColor(color::ordinaryBackground);
    item->setForeground(QBrush(color::ordinaryForeground));
#endif
    this->addItem(item);
    this->setCurrentItem(item);
}

void QPathList::addPathItem() {
    QString str("");
    addPathItem(str);
}

void QPathList::delPathItem() {
    auto row = this->currentRow();
    if(row > -1) {
        auto pt = this->takeItem(row);
        delete pt;
    }
}

void QPathList::setCursorFollow() {
    // QListWidgetItem * item = this->currentItem();
#if 0
    QWidget * widget = this->itemWidget(item);
    QPoint point =  widget->mapTo(this, QPoint(0, 0));
    QCursor::setPos(this->mapToGlobal(point));
#endif
}
#if 0
void QPathList::on_currentItemChanged(
        QListWidgetItem * current,
        QListWidgetItem * previous) {
    previous->setBackgroundColor(color::ordinaryBackground);
    previous->setForeground(QBrush(color::ordinaryForeground));
}

void QPathList::on_currentRowChanged(
        int currentRow) {
    if(currentRow != -1) {
        QListWidgetItem * item = this->item(currentRow);
        item->setBackgroundColor(color::selectedBackground);
        item->setForeground(QBrush(color::selectedForeground));
    }
}
#endif

void QPathList::getToClipBoard() {
    QClipboard *clipboard = QApplication::clipboard();
    QStringList strList;
    this->getToQStringList(strList);
    QString str = strList.join(';');
    clipboard->setText(str);
}

void QPathList::getPathItem(QString & item) { // get current select
    item = this->currentItem()->text();
}
