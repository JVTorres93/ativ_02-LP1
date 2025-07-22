#include "Funcionario.h"

Funcionario::Funcionario() : nome(""), salarioBase(0.0), id(0) {}

Funcionario::Funcionario(std::string nome, float salarioBase, int id)
    : nome(nome), salarioBase(salarioBase), id(id) {}

void Funcionario::setNome(std::string novoNome) {
    nome = novoNome;
}

void Funcionario::setSalarioBase(float novoSalarioBase) {
    salarioBase = novoSalarioBase;
}

void Funcionario::setId(int novoId) {
    id = novoId;
}

std::string Funcionario::getNome() const {
    return nome;
}

float Funcionario::getSalarioBase() const {
    return salarioBase;
}

int Funcionario::getId() const {
    return id;
}

void Funcionario::exibirInformacoes() const {
    std::cout << "ID: " << std::setfill('0') << std::setw(3) << id << std::endl;
    std::cout << "Nome: " << nome << std::endl;
    std::cout << "Salário Base: R$ " << std::fixed << std::setprecision(2) << salarioBase << std::endl;
}

Funcionario::~Funcionario() {
}