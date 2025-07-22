#include "Desenvolvedor.h"

Desenvolvedor::Desenvolvedor(std::string nome, float salarioBase, int id, int quantidadeDeProjetos)
    : Funcionario(nome, salarioBase, id), quantidadeDeProjetos(quantidadeDeProjetos) {}

void Desenvolvedor::setQuantidadeDeProjetos(int projetos) {
    this->quantidadeDeProjetos = projetos;
}

int Desenvolvedor::getQuantidadeDeProjetos() const {
    return quantidadeDeProjetos;
}

float Desenvolvedor::calcularSalarioFinal() const {
    return salarioBase + (500.0 * quantidadeDeProjetos);
}

void Desenvolvedor::exibirInformacoes() const {
    Funcionario::exibirInformacoes(); 
    std::cout << "Cargo: Desenvolvedor" << std::endl;
    std::cout << "Quantidade de Projetos: " << quantidadeDeProjetos << std::endl;
    std::cout << "Salário Final: R$ " << std::fixed << std::setprecision(2) << calcularSalarioFinal() << std::endl;
}

Desenvolvedor::~Desenvolvedor() {
}