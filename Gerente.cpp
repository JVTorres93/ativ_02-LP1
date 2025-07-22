#include "Gerente.h"

Gerente::Gerente(std::string nome, float salarioBase, int id, float bonusMensal)
    : Funcionario(nome, salarioBase, id), bonusMensal(bonusMensal) {}

void Gerente::setBonusMensal(float bonus) {
    this->bonusMensal = bonus;
}

float Gerente::getBonusMensal() const {
    return bonusMensal;
}

float Gerente::calcularSalarioFinal() const {
    return salarioBase + bonusMensal;
}

void Gerente::exibirInformacoes() const {
    Funcionario::exibirInformacoes();
    std::cout << "Cargo: Gerente" << std::endl;
    std::cout << "Bônus Mensal: R$ " << std::fixed << std::setprecision(2) << bonusMensal << std::endl;
    std::cout << "Salário Final: R$ " << std::fixed << std::setprecision(2) << calcularSalarioFinal() << std::endl;
}

Gerente::~Gerente() {
}