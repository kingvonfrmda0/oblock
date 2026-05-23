#ifndef REGISTRATIONFORM_H
#define REGISTRATIONFORM_H

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QCheckBox>
#include <QLabel>
#include <QStringList>

// Поле ввода с очисткой текста по двойному клику
class ClickableLineEdit : public QLineEdit {
    Q_OBJECT
public:
    explicit ClickableLineEdit(QWidget *parent = nullptr) : QLineEdit(parent) {}
protected:
    void mouseDoubleClickEvent(QMouseEvent *event) override {
        this->clear();
        QLineEdit::mouseDoubleClickEvent(event);
    }
};

class RegistrationForm : public QWidget {
    Q_OBJECT

public:
    RegistrationForm(QWidget *parent = nullptr);
    ~RegistrationForm() = default;

private slots:
    void selectPhoto();
    void processRegistration();

private:
    ClickableLineEdit *leFirstName;
    ClickableLineEdit *leLastName;
    ClickableLineEdit *leNickname;
    ClickableLineEdit *leIdKey;
    ClickableLineEdit *leEmail;
    ClickableLineEdit *lePassword;

    QCheckBox *cbEurope;
    QCheckBox *cbAsia;
    QCheckBox *cbAmerica;

    QLabel *lblPhotoPreview;
    QString selectedPhotoPath;

    QPushButton *btnLoadPhoto;
    QPushButton *btnRegister;

    QStringList existingNicknames;

    bool validateFields();
    QString encryptPassword(const QString &password);
};

#endif // REGISTRATIONFORM_H
