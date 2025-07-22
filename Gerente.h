#ifndef GERENTE_H
#define GERENTE_H

#include "Funcionario.h"

class Gerente : public Funcionario {
private:
    float bonusMensal;

public:
    Gerente(std::string nome, float salarioBase, int id, float bonusMensal);

    void setBonusMensal(float bonus);
    float getBonusMensal() const;

    float calcularSalarioFinal() const override;
    void exibirInformacoes() const override;

    ~Gerente() override;
};

#endif