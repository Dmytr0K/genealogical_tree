#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QApplication>
#include <QMainWindow>
#include <QLineEdit>
#include <QLabel>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QGroupBox>
#include <QTableWidget>
#include <QComboBox>
#include <QDateEdit>
#include <QCheckBox>
#include <QRadioButton>
#include <QHeaderView>
#include <QPushButton>
#include <QVector>
#include <QRegularExpression>
#include <QMessageBox>
#include <functional>
#include "people.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
private:
    //labels
    QLabel *labelFullName;
    QLabel *labelFather;
    QLabel *labelMother;
    QLabel *labelBirthday;
    QLabel *labelAlive;
    QLabel *labelDeathDay;
    QLabel *labelGender;
    QLabel *labelNationality;
    QLabel *labelArmy;

    //table
    QTableWidget *baseTable;

    //comboboxes
    QComboBox *comboFather;
    QComboBox *comboMother;
    QComboBox *comboNationality;

    //parents
    QGroupBox *groupParents;
    QGridLayout *layoutParents;

    //gender
    QGroupBox *groupGender;
    QHBoxLayout *layoutGender;

    //edit
    QGroupBox *groupEdit;
    QGridLayout *layoutEdit;

    //buttons
    QGroupBox *groupButtons;
    QVBoxLayout *layoutButtons;

    //panel
    QGroupBox *groupPanel;
    QVBoxLayout *layoutPanel;

    //main
    QGridLayout  *mainLayout;
    QWidget *mainWidget;

    //lineEdits
    QLineEdit *lineFullName;

    //dateEditors
    QDateEdit *dWasBorn;
    QDateEdit *dWasDeath;

    //Checkboxes
    QCheckBox *checkAlive;
    QCheckBox *checkArmy;

    //radioButtons
    QRadioButton *radioMale;
    QRadioButton *radioFemale;

    //StringLists
    QStringList *listColumn;
    QStringList *listNationality;

    //PushButtons
    QPushButton *buttonAdd;
    QPushButton *buttonFix;
    QPushButton *buttonDelete;
    QPushButton *buttonExit;

    //bdObj
    size_t current;
    bool newPeople;
    QVector<people>peoples;
    people *tempPeople;
    QTableWidgetItem *tempItem;
    QRegularExpression *regExpFullName;

    //forTest
    people *testPeoples;
    QPushButton *fill;
    //END


    void clearForm();
    void getPeopleFromForm(people&);
    void addCurrentToTable();
    void updateTable();
    void loadPeople();
    void updateAvaliableParents();
    bool validationPeople(const people &) const;

private slots:
    void slotCreatePeople();
    void slotSavePeople();
    void slotDeletePeople();

};

#endif // MAINWINDOW_H
