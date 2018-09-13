// QtThreadFight -- simple threaded GUI example
// see README.md for description.

// This code was written on Qt 5.11.1 on Windows 10.  It may run on OS X and Linux with
// modifications but we haven't done that.

// This code is copyright 2018 inhabited.systems, and is shared under the MIT license.
// (See file MIT-License.txt)  This code is unsupported.

#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
  , mSceneWidth(600)
  , mSceneHeight(600)
  , mGraphicsScene(Q_NULLPTR)
  , mGraphicsView(Q_NULLPTR)
  , mEllipseItem(Q_NULLPTR)
  , mCircleSize(100)
  , mAppLoopUpdateInterval(5) // in milliseconds
{
    setGeometry(0,0,mSceneWidth,mSceneHeight);
    QWidget *centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);
    mGraphicsScene = new QGraphicsScene(parent);
    mGraphicsView = new QGraphicsView(mGraphicsScene);
    mGraphicsView->setGeometry(0,0,mSceneWidth,mSceneHeight);

    QLayout *mylayout = new QHBoxLayout();
    centralWidget->setLayout(mylayout);
    mylayout->addWidget(mGraphicsView);

    QPen mypen;
    QBrush mybrush;
    mypen.setColor(QColor(Qt::transparent));
    mypen.setWidth(1);
    mypen.setStyle(Qt::PenStyle(1));
    mybrush.setColor(QColor(0,0,0));

    // set a background color
    QGraphicsRectItem *rect_item1 = mGraphicsScene->addRect(0, 0, mSceneWidth, mSceneHeight);
    rect_item1->setBrush(QColor(255, 243, 230)); // light tan
    // create a reference square on the screen to help see where the circle ends up
    QGraphicsRectItem *rect_item2 = mGraphicsScene->addRect(mSceneWidth/4+mCircleSize/1.35, mSceneHeight/4+mCircleSize/1.35, mSceneWidth/4, mSceneHeight/4);

    // add the circle that is going to animate
    mEllipseItem = new QGraphicsEllipseItem(0,0,mCircleSize,mCircleSize);
    mGraphicsScene->addItem(mEllipseItem);
    auto locx = 30;
    auto locy = (mSceneHeight/2) - (mCircleSize/2);
    mGraphicsScene->addEllipse(locx,locy,mCircleSize,mCircleSize,mypen,mybrush);

    // For some reason, the previous addEllipse doesn't seem to setX,setY to locx,locy
    // so we have to do it explicitly:
    mEllipseItem->setX(locx);
    mEllipseItem->setY(locy);
}

MainWindow::~MainWindow()
{
}

void MainWindow::moveCircle(qreal x, qreal y)
{
    mEllipseItem->setX(mEllipseItem->x() + x);
    //mEllipseItem->setY(mEllipseItem->y() + y);
}
