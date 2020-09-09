#ifndef DISPLAYWINDOW_H
#define DISPLAYWINDOW_H
#include <QQuickItem>
#include <QQuickWindow>

class DisplayWindow : public QQuickItem
{
    Q_OBJECT
    Q_PROPERTY(QQuickItem * source READ source WRITE setSource NOTIFY sourceChanged)

public:
    DisplayWindow(QQuickItem *parent = nullptr);
    void setSource(QQuickItem *source);
    QQuickItem * source() const;

    QSGNode *updatePaintNode(QSGNode *, UpdatePaintNodeData *);
signals:
    void sourceChanged();

private:
    QQuickItem *m_source = nullptr;
};
#endif // DISPLAYWINDOW_H
