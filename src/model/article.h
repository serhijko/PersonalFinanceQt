#ifndef ARTICLE_H
#define ARTICLE_H

#include "icommon.h"

class Article : public ICommon
{
    QString title;

public:
    Article() = default;
    Article(const QString &title);
    ~Article() = default;

    QString getTitle() const;
    void setTitle(const QString &title);

    QTextStream &operator<<(QTextStream &stream) const override;
    QString toString() const override;
    bool equals(const ICommon* obj) const override;
    const QString &getValueForComboBox() const override;
};

#endif // ARTICLE_H
