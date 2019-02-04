#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    current = 0;
    newPeople = false;

    //FOR TEST
       //testPeoples
       testPeoples = new people[10];
       QDate temp;

       //1
       testPeoples[0].setFullName("Трофимов Яков Сергеевич");
       testPeoples[0].setGender(genders::male);
       temp.setDate(1000,1,1);
       testPeoples[0].setBirthday(temp);
       //2
       testPeoples[1].setFullName("Суворова Ираида Игоревна");
       testPeoples[1].setGender(genders::female);
       temp.setDate(1100,1,1);
       testPeoples[1].setBirthday(temp);
       //3
       testPeoples[2].setFullName("Быков Варлам Мэлорович");
       testPeoples[2].setGender(genders::male);
       temp.setDate(1200,1,1);
       testPeoples[2].setBirthday(temp);
       //4
       testPeoples[3].setFullName("Комиссаров Ефим Федосеевич");
       testPeoples[3].setGender(genders::male);
       temp.setDate(1300,1,1);
       testPeoples[3].setBirthday(temp);
       //5
       testPeoples[4].setFullName("Федотова Ксения Станиславовна");
       testPeoples[4].setGender(genders::female);
       temp.setDate(1400,1,1);
       testPeoples[4].setBirthday(temp);
       //6
       testPeoples[5].setFullName("Михайлов Эдуард Степанович");
       testPeoples[5].setGender(genders::male);
       temp.setDate(1500,1,1);
       testPeoples[5].setBirthday(temp);
       //7
       testPeoples[6].setFullName("Соловьёв Андрей Станиславович");
       testPeoples[6].setGender(genders::male);
       temp.setDate(1600,1,1);
       testPeoples[6].setBirthday(temp);
       //8
       testPeoples[7].setFullName("Якушева Алина Серапионовна");
       testPeoples[7].setGender(genders::female);
       temp.setDate(1700,1,1);
       testPeoples[7].setBirthday(temp);
       //9
       testPeoples[8].setFullName("Блинов Серапион Ильяович");
       testPeoples[8].setGender(genders::female);
       temp.setDate(1800,1,1);
       testPeoples[8].setBirthday(temp);
       //10
       testPeoples[9].setFullName("Григорьева Валерия Матвеевна");
       testPeoples[9].setGender(genders::female);
       temp.setDate(1900,1,1);
       testPeoples[9].setBirthday(temp);

       fill = new QPushButton("Заполнить");
       connect(fill, &QPushButton::clicked, [this]()->void {
                   for (int i = 0; i < 10; i++) {
                        peoples.push_back(testPeoples[i]);
                        updateTable();
                       groupEdit->setEnabled(true);
                       buttonDelete->setEnabled(true);
                   }
               });

    //END FOR TEST

   //Labels
   labelFullName = new QLabel(tr("ФИО:"));
   labelFullName->setFixedWidth(110);
   labelFather = new QLabel(tr("Отец:"));
   labelFather->setFixedWidth(105);
   labelMother = new QLabel(tr("Мать:"));
   labelMother->setFixedWidth(105);
   labelBirthday = new QLabel(tr("Дата рождения:"));
   labelBirthday->setFixedWidth(110);
   labelAlive = new QLabel(tr("Жив:"));;
   labelAlive->setFixedWidth(110);
   labelDeathDay = new QLabel(tr("Дата смерти:"));
   labelDeathDay->setFixedWidth(110);
   labelGender = new QLabel(tr("Пол:"));
   labelGender->setFixedWidth(110);
   labelNationality = new QLabel(tr("Гражданство:"));
   labelNationality->setFixedWidth(110);
   labelArmy = new QLabel(tr("Состоял(а) на\nвоенной службе:"));
   labelArmy->setFixedWidth(110);

   //lists
   listColumn = new QStringList;
   listColumn->push_back(tr("ФИО"));
   listColumn->push_back(tr("Дата рождения"));
   listColumn->push_back(tr("Дата смерти"));
   listColumn->push_back(tr("Родители"));

   listNationality = new QStringList;
   listNationality->push_back(tr("Не задано"));
   listNationality->push_back(tr("Россия"));
   listNationality->push_back(tr("Украина"));
   listNationality->push_back(tr("Польша"));
   listNationality->push_back(tr("Германия"));

   //Buttons
   buttonAdd = new QPushButton(tr("Создать"));
   buttonFix = new QPushButton(tr("Внести изменения"));
   buttonFix->setShortcut(Qt::Key_Return);
   buttonDelete = new QPushButton(tr("Удалить"));
   buttonExit = new QPushButton(tr("Выход"));

   //Table for base
   baseTable = new QTableWidget;
   baseTable->setMinimumWidth(500);
   baseTable->setColumnCount(4);
   baseTable->setShowGrid(true);
   baseTable->setSelectionBehavior(QAbstractItemView::SelectRows);
   baseTable->setHorizontalHeaderLabels(*listColumn);
   baseTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
   baseTable->setEditTriggers(QAbstractItemView::NoEditTriggers);


   //ComboBoxes
   comboFather = new QComboBox;
   comboFather->setFixedWidth(200);
   comboFather->addItem(tr("Не задано"));

   comboMother = new QComboBox;
   comboMother->setFixedWidth(200);
   comboMother->addItem(tr("Не задано"));

   comboNationality = new QComboBox;
   comboNationality->setFixedWidth(200);
   comboNationality->addItems(*listNationality);

   //LineEditors
   lineFullName = new QLineEdit;
   lineFullName->setFixedWidth(200);

   //RegExp
   regExpFullName = new QRegularExpression("(^[A-Z]{1}[a-z]+ [A-Z]{1}[a-z]+ [A-Z]{1}[a-z]+$)|(^[А-Я]{1}[а-я]+ [А-Я]{1}[а-я]+ [А-Я]{1}[а-я]+$)");

   //CheckBoxes
   checkAlive = new QCheckBox;
   checkAlive->setChecked(true);
   checkArmy = new QCheckBox;

   //dataEditors
   dWasBorn = new QDateEdit(QDate::currentDate());
   dWasBorn->setDisplayFormat("dd.MM.yyyy");
   dWasBorn->setMaximumDate(QDate::currentDate());
   dWasDeath = new QDateEdit(QDate::currentDate());
   dWasDeath->setDisplayFormat("dd.MM.yyyy");
   dWasDeath->setMaximumDate(QDate::currentDate());
   dWasDeath->setEnabled(false);

   //RadioButtons
   radioMale = new QRadioButton(tr("М"));
   radioMale->setChecked(true);
   radioFemale = new QRadioButton(tr("Ж"));

   //Group of gender
   groupGender = new QGroupBox;
   layoutGender = new QHBoxLayout;
   groupGender->setFlat(false);
   layoutGender->addWidget(radioMale);
   layoutGender->addWidget(radioFemale);
   groupGender->setFixedWidth(110);
   groupGender->setFixedHeight(45);
   groupGender->setLayout(layoutGender);


   //Group of parents
   groupParents = new QGroupBox(tr("Родители:"));
   layoutParents = new QGridLayout;
   groupParents->setFlat(false);
   layoutParents->addWidget(labelFather, 0, 0, Qt::AlignLeft);
   layoutParents->addWidget(comboFather, 0, 1, Qt::AlignLeft);
   layoutParents->addWidget(labelMother, 1, 0, Qt::AlignLeft);
   layoutParents->addWidget(comboMother,1, 1, Qt::AlignLeft);
   groupParents->setFixedWidth(330);
   groupParents->setFixedHeight(100);
   groupParents->setLayout(layoutParents);

   //Group of editing
   groupEdit = new QGroupBox;
   layoutEdit = new QGridLayout;
   groupEdit->setFlat(true);
   layoutEdit->addWidget(labelFullName, 0, 0);
   layoutEdit->addWidget(lineFullName, 0, 1, Qt::AlignLeft);
   layoutEdit->addWidget(groupParents,1, 0, 1, 2);
   layoutEdit->addWidget(labelBirthday, 3, 0);
   layoutEdit->addWidget(dWasBorn, 3, 1, Qt::AlignLeft);
   layoutEdit->addWidget(labelAlive, 4, 0);
   layoutEdit->addWidget(checkAlive, 4, 1, Qt::AlignLeft);
   layoutEdit->addWidget(labelDeathDay, 5, 0);
   layoutEdit->addWidget(dWasDeath, 5, 1, Qt::AlignLeft);
   layoutEdit->addWidget(labelGender, 6, 0);
   layoutEdit->addWidget(groupGender, 6, 1, Qt::AlignLeft);
   layoutEdit->addWidget(labelNationality, 7, 0);
   layoutEdit->addWidget(comboNationality, 7, 1, Qt::AlignLeft);
   layoutEdit->addWidget(labelArmy, 8, 0);
   layoutEdit->addWidget(checkArmy, 8, 1, Qt::AlignLeft);
   groupEdit->setFixedSize(350,400);
   groupEdit->setLayout(layoutEdit);
   groupEdit->setFlat(true);

   //Group of buttons
   groupButtons = new QGroupBox;
   layoutButtons = new QVBoxLayout;
   layoutButtons->addWidget(buttonAdd);
   layoutButtons->addWidget(buttonFix);
   layoutButtons->addWidget(buttonDelete);
   layoutButtons->addWidget(buttonExit);
   layoutButtons->addWidget(fill);
   groupButtons->setLayout(layoutButtons);
   groupButtons->setFlat(true);

   //Group of panel
   groupPanel = new QGroupBox;
   layoutPanel = new QVBoxLayout;
   layoutPanel->addWidget(groupEdit);
   layoutPanel->addWidget(groupButtons);
   groupPanel->setLayout(layoutPanel);
   groupPanel->setFlat(false);


   //mainWidget
   mainWidget = new QWidget();
   setCentralWidget(mainWidget);
   mainLayout = new QGridLayout;
   mainLayout->addWidget(baseTable, 0, 0);
   mainLayout->addWidget(groupPanel, 0, 1, Qt::AlignTop);
   mainWidget->setLayout(mainLayout);

   groupEdit->setEnabled(false);
   buttonDelete->setEnabled(false);
   buttonFix->setEnabled(false);

   //connect
   connect(buttonAdd, &QPushButton::clicked, this, &MainWindow::slotCreatePeople);
   connect(buttonFix, &QPushButton::clicked, this, &MainWindow::slotSavePeople);
   connect(buttonDelete, &QPushButton::clicked, this, &MainWindow::slotDeletePeople);
   connect(buttonExit, &QPushButton::clicked, this, &qApp->quit);
   connect(checkAlive,&QCheckBox::clicked, [this] () -> void {
       dWasDeath->isEnabled()?dWasDeath->setEnabled(false):dWasDeath->setEnabled(true);});
   connect(baseTable, &QTableWidget::currentCellChanged, [this](int row, int, int, int) -> void {
       if (row > -1)
       {
           current = row;
           loadPeople();
       }
   });
   connect(lineFullName, &QLineEdit::textChanged, [this](){buttonFix->setEnabled(true);});
   connect(dWasBorn, &QDateEdit::dateChanged, [this](){buttonFix->setEnabled(true);});
   connect(dWasDeath, &QDateEdit::dateChanged, [this](){buttonFix->setEnabled(true);});
   connect(checkAlive, &QCheckBox::clicked,[this](){buttonFix->setEnabled(true);});
   connect(radioMale, &QRadioButton::toggled,[this](){buttonFix->setEnabled(true);});
   connect(checkArmy, &QCheckBox::clicked, [this](){buttonFix->setEnabled(true);});
   connect(comboFather, static_cast<void(QComboBox::*)(int)>(&QComboBox::currentIndexChanged),
           [this](int){buttonFix->setEnabled(true);});
   connect(comboMother, static_cast<void(QComboBox::*)(int)>(&QComboBox::currentIndexChanged),
           [this](int){buttonFix->setEnabled(true);});
   connect(comboNationality, static_cast<void(QComboBox::*)(int)>(&QComboBox::currentIndexChanged),
           [this](int){buttonFix->setEnabled(true);});

}

MainWindow::~MainWindow()
{

}

void MainWindow::clearForm() {
    lineFullName->clear();
    comboFather->setCurrentIndex(0);
    comboMother->setCurrentIndex(0);
    dWasBorn->setDate(QDate::currentDate());
    checkAlive->setChecked(true);
    dWasDeath->setDate(QDate::currentDate());
    dWasDeath->setEnabled(false);
    radioMale->setChecked(true);
    radioFemale->setChecked(false);
    comboNationality->setCurrentIndex(0);
    checkArmy->setChecked(0);
}

void MainWindow::getPeopleFromForm(people &outputPeople) {
    outputPeople.setFullName(lineFullName->text());
    outputPeople.setFather(comboFather->currentText());
    outputPeople.setMother(comboMother->currentText());
    outputPeople.setBirthday(dWasBorn->date());
    outputPeople.setAlive(checkAlive->isChecked());
    outputPeople.setDayOfDeath(dWasDeath->date());
    if (radioMale->isChecked())
        outputPeople.setGender(genders::male);
    else
        outputPeople.setGender(genders::female);
    outputPeople.setNationality(static_cast<countries>(comboNationality->currentIndex()));
    outputPeople.setArmy(checkArmy->isChecked());
}

void MainWindow::updateTable() {
    baseTable->clear();
    baseTable->setRowCount(0);
    baseTable->setHorizontalHeaderLabels(*listColumn);
    baseTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    for (int i = 0; i < peoples.length(); i++) {
        baseTable->insertRow(i);
        QTableWidgetItem *tempItem;
        tempItem = new QTableWidgetItem (peoples[i].getFullName());
        baseTable->setItem(i,0,tempItem);
        tempItem = new QTableWidgetItem (peoples[i].getBirthday().toString("dd.MM.yyyy"));
        baseTable->setItem(i,1,tempItem);
        if (peoples[i].getAlive()) {
            tempItem = new QTableWidgetItem(tr("Жив"));
            baseTable->setItem(i,2,tempItem);
        } else {
            tempItem = new QTableWidgetItem (peoples[i].getDayOfDeath().toString("dd.MM.yyyy"));
            baseTable->setItem(i,2,tempItem);
        }
        tempItem = new QTableWidgetItem(peoples[i].getFather()+", "+peoples[i].getMother());
        baseTable->setItem(i,3,tempItem);
    }
}

void MainWindow::loadPeople() {
    updateAvaliableParents();
    lineFullName->setText(peoples[current].getFullName());
    comboFather->setCurrentText(peoples[current].getFather());
    comboMother->setCurrentText(peoples[current].getMother());
    dWasBorn->setDate(peoples[current].getBirthday());
    checkAlive->setChecked(peoples[current].getAlive());
    dWasDeath->setDate(peoples[current].getDayOfDeath());
    if (peoples[current].getGender()==genders::male)
        radioMale->setChecked(true);
    else
        radioFemale->setChecked(true);
    comboNationality->setCurrentIndex (static_cast<int>(peoples[current].getNationality()));
    checkArmy->setChecked(peoples[current].getArmy());
    buttonFix->setEnabled(false);
}

void MainWindow::updateAvaliableParents() {
    comboFather->clear();
    comboMother->clear();   
    QStringList avaliableFathers;
    QStringList avaliableMothers;
    for (int i = 0; i < peoples.length(); i++) {
        if (!newPeople && peoples[i].getFullName() == peoples[current].getFullName())
           continue;
        if (peoples[i].getGender() == genders::male)
             avaliableFathers.push_back(peoples[i].getFullName());
        else
            avaliableMothers.push_back(peoples[i].getFullName());
    }
    avaliableFathers.sort();
    avaliableMothers.sort();
    avaliableFathers.push_front(tr("Не задано"));
    avaliableMothers.push_front(tr("Не задано"));
    comboFather->addItems(avaliableFathers);
    comboMother->addItems(avaliableMothers);

}

void MainWindow::slotCreatePeople() {
    newPeople = true;
    baseTable->setCurrentCell(-1,0);
    updateAvaliableParents();
    groupEdit->setEnabled(true);
    buttonDelete->setEnabled(true);
    buttonFix->setEnabled(true);
    clearForm();
    tempPeople = new people;
}

void MainWindow::slotSavePeople() {
    if (newPeople) {
        getPeopleFromForm(*tempPeople);
        if (!validationPeople(*tempPeople))
            return;
    } else {
        getPeopleFromForm(*tempPeople);
        if (!validationPeople(*tempPeople))
            return;
        if (peoples[current].getGender() == genders::male) {
            for (int i=0; i < peoples.length(); i++)
                if (static_cast<size_t>(i) != current && peoples[current].getFullName() == peoples[i].getFather())
                    peoples[i].setFather(tempPeople->getFullName());
        } else {
            for (int i=0; i < peoples.length(); i++)
                if (static_cast<size_t>(i) != current && peoples[current].getFullName() == peoples[i].getMother())
                    peoples[i].setMother(tempPeople->getFullName());
        }
        peoples.remove(current);
    }
        int insertPos = 0;
        while (insertPos < peoples.length() && *tempPeople < peoples[insertPos])
            insertPos++;
        peoples.insert(peoples.begin()+insertPos,*tempPeople);
        newPeople = false;
        current = insertPos;
        updateTable();
        baseTable->setCurrentCell(insertPos,0);
        buttonFix->setEnabled(false);
}

void MainWindow::slotDeletePeople() {
    if (peoples.length() && !newPeople) {
    if (peoples[current].getGender() == genders::male) {
        for (int i=0; i < peoples.length(); i++)
            if (static_cast<size_t>(i) != current && peoples[current].getFullName() == peoples[i].getFather())
                peoples[i].setFather(tr("Не задано"));
    } else {
        for (int i=0; i < peoples.length(); i++)
            if (static_cast<size_t>(i) != current && peoples[current].getFullName() == peoples[i].getMother())
                peoples[i].setMother(tr("Не задано"));
    }
    peoples.remove(current);
    clearForm();
    updateTable();
    baseTable->setCurrentCell(0,0);
    }
    if (!peoples.length()) {
        clearForm();
        groupEdit->setEnabled(false);
        buttonDelete->setEnabled(false);
        buttonFix->setEnabled(false);
    }
    if (newPeople) {
        clearForm();
        buttonFix->setEnabled(false);
        baseTable->setCurrentCell(0,0);
        newPeople=false;
    }
}

bool MainWindow::validationPeople(const people &verifiablePeople) const {
    auto match = regExpFullName->match(verifiablePeople.getFullName());
    std::function<bool(const people &)>uniqueName = [this](const people &verifiablePeople)->bool{
            for (int i = 0; i < peoples.length();i++)
                if(peoples[i].getFullName() == verifiablePeople.getFullName())
                    return false;
            return true;
};
    if (!(match.hasMatch() && verifiablePeople.getFullName().length()<46)) {
        QMessageBox::critical(0,tr("Ошибка!"), tr("Имя введено неверно!"));
        return false;
    }
    if (!uniqueName(verifiablePeople) && newPeople) {
        QMessageBox::critical(0,tr("Ошибка!"), tr("Имя повторяется!"));
        return false;
    }
    for (int i=0; i<peoples.length();i++)
        if (peoples[i].getFullName() == verifiablePeople.getFather())
            if (peoples[i].getBirthday().daysTo(verifiablePeople.getBirthday()) <= 5475) {
                QMessageBox::critical(0,tr("Ошибка!"), tr("Отец слишком молод!"));
                return false;
            }
    for (int i=0; i<peoples.length();i++)
        if (peoples[i].getFullName() == verifiablePeople.getMother())
            if (peoples[i].getBirthday().daysTo(verifiablePeople.getBirthday()) <= 5475) {
                QMessageBox::critical(0,tr("Ошибка!"), tr("Мать слишком молода!"));
                return false;
            }
    if (tempPeople->getDayOfDeath() <= tempPeople->getBirthday() && !tempPeople->getAlive()) {
        QMessageBox::critical(0,tr("Ошибка!"), tr("Нельзя умереть не родившись!"));
        return false;
    }
    return true;
}
