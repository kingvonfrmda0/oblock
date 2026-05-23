#include <QApplication>
#include "registrationform.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    
    RegistrationForm form;
    form.show();
    
    return app.exec();
}
