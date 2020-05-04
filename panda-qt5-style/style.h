#ifndef STYLE_H
#define STYLE_H

#include <QProxyStyle>
#include <QStyleOptionTab>
#include <QTextOption>

#include "global.h"
#include "blurhelper.h"

class PROXYSTYLESHARED_EXPORT Style : public QProxyStyle
{
    Q_OBJECT

public:
    explicit Style();

    void polish(QWidget *w);
    void unpolish(QWidget *w);
    void polish(QApplication *app);

    void polish(QPalette &palette);

    void drawPrimitive(QStyle::PrimitiveElement pe, const QStyleOption *option, QPainter *painter, const QWidget *widget) const;
    void drawControl(QStyle::ControlElement element, const QStyleOption *option, QPainter *painter, const QWidget *widget) const;
    QRect subControlRect(QStyle::ComplexControl cc, const QStyleOptionComplex *opt, QStyle::SubControl sc, const QWidget *w) const;

    void drawComplexControl(ComplexControl control, const QStyleOptionComplex *option,
                                      QPainter *painter, const QWidget *widget) const;

    int styleHint(QStyle::StyleHint sh, const QStyleOption *opt, const QWidget *w, QStyleHintReturn *shret) const;
    int pixelMetric(QStyle::PixelMetric metric, const QStyleOption *option, const QWidget *widget) const;

private:
    // helper functions...

    bool drawTabBar(QPainter *painter, const QStyleOptionTab *tab, const QWidget *widget) const;
    bool drawTabBarLabel(QPainter *painter, const QStyleOptionTab *tab, const QWidget *widget) const;
    void drawMenu(const QStyleOption *option, QPainter *painter, const QWidget *widget) const;
    void drawMenuItem(const QStyleOption *option, QPainter *painter, const QWidget *widget) const;

    // utils
    QString calculateElidedText(const QString &text, const QTextOption &textOption,
                                const QFont &font, const QRect &textRect, const Qt::Alignment valign,
                                Qt::TextElideMode textElideMode, int flags,
                                bool lastVisibleLineShouldBeElided, QPointF *paintStartPosition) const;
    void viewItemDrawText(QPainter *p, const QStyleOptionViewItem *option, const QRect &rect) const;

private:
    BlurHelper *m_blurHelper;
};

#endif