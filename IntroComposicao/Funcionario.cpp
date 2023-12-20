#include <iostream>
#include <sstream>

using namespace std;

class Data {
private:
    int dia;
    int mes;
    int ano;

public:
    Data(int d = 0, int m = 0, int a = 0) : dia(d), mes(m), ano(a) {}

    int obtemDia() { return dia; }
    int obtemMes() { return mes; }
    int obtemAno() { return ano; }

    void defineDia(int d) { dia = d; }
    void defineMes(int m) { mes = m; }
    void defineAno(int a) { ano = a; }

    string str() {
        stringstream ss;
        ss << dia << "/" << mes << "/" << ano;
        return ss.str();
    }
};

class Funcionario {
private:
    string nomeFunc;
    double salario;
    Data dataAdm;

public:
    Funcionario(string nf = "", double s = 0.0, Data da = Data()) : nomeFunc(nf), salario(s), dataAdm(da) {}

    string obtemNome() { return nomeFunc; }
    double obtemSalario() { return salario; }
    Data obtemDataAdm() { return dataAdm; }

    void defineNome(string nf) { nomeFunc = nf; }
    void defineSalario(double s) { salario = s; }
    void defineDataAdm(Data da) { dataAdm = da; }

    string str() {
        stringstream ss;
        ss << "Funcionário: " << nomeFunc << endl
           << "Salário: " << salario << endl
           << "Admissão: " << dataAdm.str() << endl;
        return ss.str();
    }
};

class Empresa {
private:
    string nomeEmp;
    string cnpj;
    Funcionario* funcionarios;
    int numFuncionarios;

public:
    Empresa(string ne = "", string c = "") : nomeEmp(ne), cnpj(c), funcionarios(nullptr), numFuncionarios(0) {}

    string obtemNomeEmp() { return nomeEmp; }
    string obtemCNPJ() { return cnpj; }

    void defineNomeEmp(string ne) { nomeEmp = ne; }
    void defineCNPJ(string c) { cnpj = c; }

    void adicionarFuncionario(Funcionario funcionario) {
        Funcionario* novoFuncionarios = new Funcionario[numFuncionarios + 1];

        for (int i = 0; i < numFuncionarios; ++i) {
            novoFuncionarios[i] = funcionarios[i];
        }

        novoFuncionarios[numFuncionarios] = funcionario;

        delete[] funcionarios;

        funcionarios = novoFuncionarios;
        ++numFuncionarios;
    }

    void mostrarFuncionarios() {
        cout << "Funcionarios da empresa " << nomeEmp << " (CNPJ: " << cnpj << "):\n";
        for (int i = 0; i < numFuncionarios; ++i) {
            cout << funcionarios[i].str() << endl;
        }
    }

    string str() {
        stringstream ss;
        ss << "Empresa: " << nomeEmp << endl
           << "CNPJ: " << cnpj << endl;
        return ss.str();
    }

    ~Empresa() {
        delete[] funcionarios;
    }
};

int main() {
    string nomeEmpresa, cnpjEmpresa;
    cout << "Informe o nome da empresa: ";
    getline(cin, nomeEmpresa);
    cout << "Informe o CNPJ da empresa: ";
    getline(cin, cnpjEmpresa);

    Empresa empresa(nomeEmpresa, cnpjEmpresa);

    int numFuncionarios;
    cout << "Quantos funcionarios deseja adicionar? ";
    cin >> numFuncionarios;

    for (int i = 0; i < numFuncionarios; ++i) {
        string nomeFuncionario;
        double salario;
        int dia, mes, ano;

        cin.ignore();

        cout << "Informe o nome do funcionario " << i + 1 << ": ";
        getline(cin, nomeFuncionario);

        cout << "Informe o salario do funcionario " << i + 1 << ": ";
        cin >> salario;

        cout << "Informe a data de admissao do funcionario " << i + 1 << " (DD MM AAAA): ";
        cin >> dia >> mes >> ano;

        Data dataAdmissao(dia, mes, ano);
        Funcionario funcionario(nomeFuncionario, salario, dataAdmissao);
        empresa.adicionarFuncionario(funcionario);
    }

    cout << empresa.str() << endl;
    empresa.mostrarFuncionarios();

    return 0;
}