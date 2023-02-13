#ifndef PRINCIPAL_H
#define PRINCIPAL_H

#include <QWidget>//clase base para todos los objetos de la interfaz de usuario,
#include <QFile>//QFile es un dispositivo para leer y escribir archivos y recursos de texto y binarios.
#include <QMessageBox>//ofrece cuadros de diálogos con un breve mensaje, un icono y botones dependiendo de su funcionalidad

#include "personadialog.h"
#include "persona.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Principal; }
QT_END_NAMESPACE

class Principal : public QWidget
{
    Q_OBJECT

public:
    Principal(QWidget *parent = nullptr);
    ~Principal();

private slots:
    void on_btnAgregar_clicked();

    void on_btnGuardar_clicked();

    void on_btnEliminar_clicked();

    void on_btnEditar_2_clicked();

private:
    Ui::Principal *ui;
    const QString ARCHIVO = "agenda.csv";
    enum Columna
    {
        NOMBRE, APELLIDO, TELEFONO, EMAIL
    };

    void cargarContactos();
};
#endif // PRINCIPAL_H
