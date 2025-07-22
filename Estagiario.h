#ifndef ESTAGIARIO_H
#define ESTAGIARIO_H

#include "Funcionario.h"

class Estagiario : public Funcionario {
private:
    int horasTrabalhadas;

public:
    Estagiario(std::string nome, float salarioBase, int id, int horasTrabalhadas);

    void setHorasTrabalhadas(int horas);
    int getHorasTrabalhadas() const;

    float calcularSalarioFinal() const override;
    void exibirInformacoes() const override;


    ~Estagiario() override;
};

#endif