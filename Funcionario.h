#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

#include <string>
#include <iostream>
#include <iomanip> 

class Funcionario {
protected:
    std::string nome;
    float salarioBase;

private:
    int id;

public:
    Funcionario();
    Funcionario(std::string nome, float salarioBase, int id);

    void setNome(std::string novoNome);
    void setSalarioBase(float novoSalarioBase);
    void setId(int novoId);

    std::string getNome() const;
    float getSalarioBase() const;
    int getId() const;

    virtual void exibirInformacoes() const;
    virtual float calcularSalarioFinal() const = 0;

    virtual ~Funcionario();
};

#endif 