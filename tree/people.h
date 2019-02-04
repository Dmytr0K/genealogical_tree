#ifndef PEOPLE_H
#define PEOPLE_H

#include <QString>
#include <QDate>


enum class genders{male,female};
enum class countries{notdef,russia,ukraine,poland,germany};

class people
{
private:
    QString fullName;
    struct {
        QString Father;
        QString Mother;
    } parents;
    QDate birthday;
    bool isAlive;
    QDate dayOfDeath;
    genders gender;
    countries nationality;
    bool isArmy;
public:
    people();
    void setFullName (QString fullName);
    QString getFullName () const;
    void setMother (QString motherName);
    QString getMother () const;
    void setFather (QString fatherName);
    QString getFather () const;
    void setBirthday (QDate date);
    QDate getBirthday () const;
    void setAlive (bool isAlive);
    bool getAlive () const;
    void setDayOfDeath (QDate date);
    QDate getDayOfDeath () const;
    void setGender (genders gender);
    genders getGender () const;
    void setNationality(countries nationality);
    countries getNationality () const;
    void setArmy (bool isArmy);
    bool getArmy () const;
    friend bool operator <(const people &left, const people &right);
};

#endif // PEOPLE_H
