#include "article.h"
#include "modelexception.h"

Article::Article(const QString &title)
{
    if (title.length() == 0) throw new ModelException(ModelException::Code::TITLE_EMPTY);
    this->title = title;
}

QString Article::getTitle() const
{
    return this->title;
}

void Article::setTitle(const QString &title)
{
    this->title = title;
}

QTextStream &Article::operator<<(QTextStream &stream) const
{
    return stream << "Article(title=" << this->title << ')';
}

QString Article::toString() const
{
    return "Article(title=" + this->title + ')';
}

bool Article::equals(const ICommon* obj) const
{
    if (this == obj) {
        return true;
    }
    if (obj == nullptr) {
        return false;
    }
    const Article* other = dynamic_cast<const Article*>(obj);
    if (other == nullptr) {
        return false;
    }
    if (this->title != other->title) {
        return false;
    }
    return true;
}

const QString &Article::getValueForComboBox() const
{
    return this->title;
}
