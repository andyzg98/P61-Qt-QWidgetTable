#include "personadialog.h"
#include "ui_personadialog.h"

PersonaDialog::PersonaDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PersonaDialog)
{
    ui->setupUi(this);
}

PersonaDialog::~PersonaDialog() //destructor
{
    delete ui;
}

void PersonaDialog::on_buttonBox_accepted()
{
    //variables de validacion
    bool valido=false,val_Nombre = true, val_Apellido = true;
    QString nombre = ui->inNombre->text();
    QString apellido = ui->inApellido->text();
    QString telefono = ui->inTelefono->text();
    QString email = ui->inEmail->text();
    //condicion validacion
    if(nombre.length() == 0 || apellido.length() == 0 || telefono.length() == 0 || email.length() == 0){
        QMessageBox::warning(this, "Atento", "Es necesario completar todos los campos para guardar..!");
        return;
    }
    for(int i = 0; i < nombre.length(); i++){
        if(nombre[i].isDigit()){
            val_Nombre = false;
        }
    }
    if(val_Nombre == false){
        QMessageBox::warning(this, "Atento", "El nombre, solo contiene letras");
        return;
    }
    for(int i = 0; i < apellido.length(); i++){
        if(apellido[i].isDigit()){
            val_Apellido = false;
        }
    }
    if(val_Apellido == false){
        QMessageBox::warning(this, "Atento", "El apellido, solo contiene letras");
        return;
    }

    for(int i = 0; i < email.length(); i++){
        if(email[i] == '@'){
            for(int j = i; j < email.length(); j++){
                if(email[j] == '.'){
                    valido = true;
                }
            }
        }
    }
    if(valido == false){
        QMessageBox::warning(this, "Atento", "verifica tu correo");
        return;
    }
    this->m_persona = new Persona(nombre, apellido, telefono, email);
    accept();
}


void PersonaDialog::on_buttonBox_rejected()
{
    reject(); //salio sin guardar
}

Persona *PersonaDialog::persona() const
{
    return m_persona;
}


void PersonaDialog::on_inNombre_editingFinished()
{
    //tipo de variable
    QString nombre = ui->inNombre->text();
    bool validNom = true;
    if(nombre.length() == 0){
        QMessageBox::warning(this, "atento", "completar todos los campos para guardar");
        return;
    }
    for(int i = 0; i < nombre.length(); i++){
        if(nombre[i].isDigit()){
            validNom = false;
        }
    }
    if(!validNom){
        ui->inNombre->setStyleSheet("background-color: rgb(55, 105, 180)");
    }
    else{
        ui->inNombre->setStyleSheet("background-color: rgb(53, 193, 241)");
    }

}


void PersonaDialog::on_inApellido_editingFinished()
{
    QString apellido = ui->inApellido->text();
    bool validApe = true;
    if(apellido.length() == 0){
        QMessageBox::warning(this, "Atento", "completar todos los campos para guarda");
        return;
    }
    for(int i = 0; i < apellido.length(); i++){
        if(apellido[i].isDigit()){
            validApe = false;
        }
    }
    if(!validApe){
        ui->inApellido->setStyleSheet("background-color: rgb(55, 105, 180)");
    }
    else{
        ui->inApellido->setStyleSheet("background-color: rgb(53, 193, 241)");
    }
}


void PersonaDialog::on_inTelefono_editingFinished()
{
    QString telefono = ui->inTelefono->text();
    if(telefono.length() == 0){
        QMessageBox::warning(this, "Atento", "Completar todos los campos para guardar");
        return;
    }
}


void PersonaDialog::on_inEmail_editingFinished()
{
    QString email = ui->inEmail->text();
    bool valid = false;
    if(email.length() == 0){
        QMessageBox::warning(this, "Atento", "completar todos los campos para guardar");
        return;
    }

    for(int i = 0; i < email.length(); i++){
        if(email[i] == '@'){
            for(int j = i; j < email.length(); j++){
                if(email[j] == '.'){
                    valid = true;
                }
            }
        }
    }
    if(valid == false){
        QMessageBox::warning(this, "Advertencia", "Ingrese un formato de correo valido..!");
        return;
    }
}

void PersonaDialog::set_datos(QString nom, QString ape, QString tel, QString email)
{
    ui->inNombre->setText(nom);
    ui->inApellido->setText(ape);
    ui->inTelefono->setValue(tel.toInt());
    ui->inEmail->setText(email);
}
