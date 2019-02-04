#include "people.h"

people::people() {
    setFullName("");
    setMother("Не задано");
    setFather("Не задано");
    setBirthday(QDate::currentDate());
    setAlive(true);
    setDayOfDeath(QDate::currentDate());
    setGender(genders::male);
    setNationality(countries::notdef);
    setArmy(false);
}

void people::setFullName (QString fullName) {
    this->fullName=fullName;
}
QString people::getFullName () const {
    return fullName;
}
void people::setMother (QString motherName) {
    this->parents.Mother = motherName;
}
QString people::getMother () const {
    return parents.Mother;
}
void people::setFather (QString fatherName) {
    this->parents.Father = fatherName;
}
QString people::getFather () const {
    return parents.Father;
}
void people::setBirthday (QDate date) {
    this->birthday = date;
}
QDate people::getBirthday () const {
    return birthday;
}
void people::setAlive (bool isAlive) {
    this->isAlive = isAlive;
}
bool people::getAlive () const {
    return isAlive;
}
void people::setDayOfDeath (QDate date) {
    this->dayOfDeath = date;
}
QDate people::getDayOfDeath () const {
    return dayOfDeath;
}
void people::setGender (genders gender) {
    this->gender = gender;
}
genders people::getGender () const {
    return gender;
}
void people::setNationality(countries nationality) {
    this->nationality = nationality;
}
countries people::getNationality () const {
    return nationality;
}
void people::setArmy (bool isArmy) {
    this->isArmy = isArmy;
}
bool people::getArmy () const {
    return isArmy;
}
bool operator <(const people &left, const people &right){
    if (left.getBirthday() > right.getBirthday())
        return true;
    else
        return (left.getBirthday() == right.getBirthday() && left.getFullName() > right.getFullName());
}
