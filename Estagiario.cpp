#include "Estagiario.h"

Estagiario::Estagiario(std::string nome, float salarioBase, int id, int horasTrabalhadas)
    : Funcionario(nome, salarioBase, id), horasTrabalhadas(horasTrabalhadas) {}

void Estagiario::setHorasTrabalhadas(int horas) {
    this->horasTrabalhadas = horas;
}

int Estagiario::getHorasTrabalhadas() const {
    return horasTrabalhadas;
}

float Estagiario::calcularSalarioFinal() const {
    return salarioBase * (static_cast<float>(horasTrabalhadas) / 160.0f);
}

void Estagiario::exibirInformacoes() const {
    Funcionario::exibirInformacoes();
    std::cout << "Cargo: Estagiário" << std::endl;
    std::cout << "Horas Trabalhadas: " << horasTrabalhadas << "h" << std::endl;
    std::cout << "Salário Final: R$ " << std::fixed << std::setprecision(2) << calcularSalarioFinal() << std::endl;
}

Estagiario::~Estagiario() {
}