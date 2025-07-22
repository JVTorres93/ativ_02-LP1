#include <iostream>
#include <vector>
#include <limits>
#include <cctype>
#include <iomanip>
#include <windows.h>

#include "Funcionario.h"
#include "Desenvolvedor.h"
#include "Gerente.h"
#include "Estagiario.h"

using namespace std;

// verificador de ID
bool existeId(const vector<Funcionario*>& funcionarios, int idProcurado) {
    for (const auto& func : funcionarios) {
        if (func->getId() == idProcurado) {
            return true;
        }
    }
    return false;
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    vector<Funcionario*> funcionarios;
    const int MAX_FUNCIONARIOS = 10;

    int opcaoMenuPrincipal;

    do {
        cout << "\n--- Menu Principal ---" << endl;
        cout << "1. Cadastrar novo funcionário" << endl;
        cout << "2. Relatório de funcionários" << endl;
        cout << "3. Sair" << endl;
        cout << "Opção: ";

        // Validador de entrada
        while (!(cin >> opcaoMenuPrincipal) || (opcaoMenuPrincipal < 1 || opcaoMenuPrincipal > 3)) {
            cout << "Opção inválida.\n";
            cout << "Opção: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (opcaoMenuPrincipal) {
            case 1: { // Cadastrar novo funcionário
                if (funcionarios.size() >= MAX_FUNCIONARIOS) {
                    cout << "\nLimite " << MAX_FUNCIONARIOS << " funcionários atingido. Não é possível cadastrar mais funcionários. Por favor, não sobrecarregue o RH" << endl;
                    break;
                }

                string nome;
                float salarioBase;
                int id;
                int tipoFuncionario;

                cout << "\n---------------------------------" << endl;
                cout << "Cadastrando Funcionário #" << funcionarios.size() + 1 << endl;

                // VAlidador de ID
                bool idValido = false;
                while (!idValido) {
                    cout << "ID (000-999): ";
                    if (!(cin >> id)) {
                        cout << "Entrada inválida. Insira um valor numérico.\n";
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        continue;
                    }
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');

                    if (id < 0 || id > 999) {
                        cout << "ID fora do intervalo.\n";
                        continue;
                    }

                    if (existeId(funcionarios, id)) {
                        cout << "ID já existente.\n";
                        continue;
                    }

                    idValido = true;
                }


                cout << "Nome: ";
                getline(cin, nome);

                cout << "Salário Base: R$ ";
                while (!(cin >> salarioBase)) {
                    cout << "Entrada inválida. Insira um valor numérico.\n";
                    cout << "Salário Base: R$ ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                Funcionario* novoFuncionario = nullptr;

                // Validador de entrada
                bool cargoValido = false;
                while (!cargoValido) {
                    cout << "Cargo:" << endl;
                    cout << "1. Desenvolvedor" << endl;
                    cout << "2. Gerente" << endl;
                    cout << "3. Estagiário" << endl;
                    cout << "Opção: ";
                    if (!(cin >> tipoFuncionario) || (tipoFuncionario < 1 || tipoFuncionario > 3)) {
                        cout << "Entrada inválida." << endl;
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        continue;
                    }
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');

                    switch (tipoFuncionario) {
                        case 1: { // Desenvolvedor
                            int qtdProjetos;
                            cout << "Projetos: ";
                            while (!(cin >> qtdProjetos)) {
                                cout << "Entrada inválida. Insira um valor numérico.\n ";
                                cout << "Projetos: ";
                                cin.clear();
                                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            }
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            novoFuncionario = new Desenvolvedor(nome, salarioBase, id, qtdProjetos);
                            cargoValido = true;
                            break;
                        }
                        case 2: { // Gerente
                            float bonus;
                            cout << "Bônus mensal: R$ ";
                            while (!(cin >> bonus)) {
                                cout << "Entrada inválida. Insira um valor numérico.\n";
                                cout << "Bônus mensal: R$ ";
                                cin.clear();
                                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            }
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            novoFuncionario = new Gerente(nome, salarioBase, id, bonus);
                            cargoValido = true;
                            break;
                        }
                        case 3: { // Estagiário
                            int escolhaHoras;
                            int horas = 0;
                            bool horasValidas = false;

                            // Validador de entrada
                            while (!horasValidas) {
                                cout << "Carga horária mensal:" << endl;
                                cout << "1. 80h" << endl;
                                cout << "2. 120h" << endl;
                                cout << "3. 160h" << endl;
                                cout << "Opção: ";
                                if (!(cin >> escolhaHoras) || (escolhaHoras < 1 || escolhaHoras > 3)) {
                                    cout << "Opção inválida.\n" << endl;
                                    cout << "Opção: ";
                                    cin.clear();
                                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                    continue;
                                }
                                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpa buffer

                                switch (escolhaHoras) {
                                    case 1: horas = 80; break;
                                    case 2: horas = 120; break;
                                    case 3: horas = 160; break;
                                }
                                horasValidas = true;
                            }
                            novoFuncionario = new Estagiario(nome, salarioBase, id, horas);
                            cargoValido = true;
                            break;
                        }
                    }
                }

                if (novoFuncionario != nullptr) {
                    funcionarios.push_back(novoFuncionario);
                    cout << "\nFuncionário cadastrado com sucesso! Total: " << funcionarios.size() << " funcionário(s)." << endl;
                }
                break;
            }

            case 2: { // Relatório de funcionários
                cout << "\n--- Relatório de Funcionários ---" << endl;
                if (funcionarios.empty()) {
                    cout << "Nenhum funcionário cadastrado." << endl;
                } else {
                    for (const auto& func : funcionarios) {
                        cout << "\n---------------------------------" << endl;
                        func->exibirInformacoes();
                    }
                }
                break;
            }

            case 3: { // Sair
                cout << "\nEncerrando o programa. Seu terminal já pode ser encerrado com segurança." << endl;
                break;
            }

            default:
                break;
        }

    } while (opcaoMenuPrincipal != 3);

    for (const auto& func : funcionarios) {
        delete func;
    }
    funcionarios.clear();

    return 0;
}