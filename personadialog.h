#ifndef PERSONADIALOG_H
#define PERSONADIALOG_H

#include <QDialog> //cuadro de diálogo usan como ventanas secundarias que presentan al usuario opciones y elecciones. Se crean heredando de QDialog y utilizan widgets y diseños para implementar la interfaz de usuario.
#include <QDebug>
#include <QMessageBox> //mensaje rapido

#include "persona.h" //INCLUYO CLASE

namespace Ui { //INTERFAZ
class PersonaDialog;
}

class PersonaDialog : public QDialog
{
    Q_OBJECT

public:
    explicit PersonaDialog(QWidget *parent = nullptr); //METDO EXPLICITO
    ~PersonaDialog();//DESTRUCTOR
    //CLASEPERSONA APUNTEME OBJETOSPEROSNA
    Persona *persona() const;
    void set_datos(QString nom, QString ape, QString tel, QString email);

//METODOS SLOTS DE LOS BOTONES
private slots: //Slot: es una función C++ que es invocada en respuesta a un signal,
    void on_buttonBox_accepted();
    void on_buttonBox_rejected();
//metodos de validacion
    void on_inNombre_editingFinished();

    void on_inApellido_editingFinished();

    void on_inTelefono_editingFinished();

    void on_inEmail_editingFinished();

private:
    Ui::PersonaDialog *ui;//CLASE INTERFAS ASIGNEME::PERSONADIALOG APUTEME OBJETO UI
    Persona *m_persona; //CLASE CREO OBJETO APUNTEMEA MPERSONAS
};

#endif // PERSONADIALOG_H
