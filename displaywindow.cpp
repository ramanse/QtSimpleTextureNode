#include "displaywindow.h"
#include <QSGSimpleTextureNode>
#include <QtQuick/private/qquickshadereffectsource_p.h>
#include <QtQuick/private/qsgdefaultlayer_p.h>
DisplayWindow::DisplayWindow(QQuickItem *parent)
{
    setFlag(QQuickItem::ItemHasContents, true);
}

void DisplayWindow::setSource(QQuickItem *source)
{
    m_source = source;
    emit sourceChanged();
}

QQuickItem *DisplayWindow::source() const
{
    return m_source;
}

QSGNode *DisplayWindow::updatePaintNode(QSGNode *oldNode, QQuickItem::UpdatePaintNodeData *)
{

    QSGSimpleTextureNode * node = new QSGSimpleTextureNode();
    QQuickShaderEffectSource* sourceItem = qobject_cast<QQuickShaderEffectSource*>(m_source);
    QSGTextureProvider* provider = sourceItem->textureProvider();
    QSGTexture* texture = provider->texture();
    QSGDefaultLayer* layer = qobject_cast<QSGDefaultLayer*>(texture);
    layer->updateTexture();
    qCritical()<<"TextureId  "<<texture->textureId();
    node->setTexture(texture);
    node->setRect(boundingRect());


    return node;
}
