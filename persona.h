#ifndef PERSONA_H
#define PERSONA_H

#include <QObject> //LIBRERIA UI(INTERFAZ USER)/manejos comunicación fluida de objetos llamado señales y ranuras
//class Nomb_clase_hija : public Nomb_clase_padre
class Persona : public QObject
{
    Q_OBJECT
public: //metodos()-atributos;
    explicit Persona(QObject *parent = nullptr);
    //metodo constructor
    Persona(const QString &nombre, const QString &apellido, const QString &telefono, const QString &email);
    //variables  &referencia a el metodos
    const QString &nombre() const;
    const QString &apellido() const;
    const QString &telefono() const;
    const QString &email() const;
    //
signals:
//atributos privados de la clase persona
private:
    QString m_nombre;
    QString m_apellido;
    QString m_telefono;
    QString m_email;
};

#endif // PERSONA_H
