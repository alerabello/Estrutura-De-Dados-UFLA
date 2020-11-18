/* 

Um sistema em desenvolvimento permite controlar o vencimento de itens de um armazém. 
No momento, ele só permite a inserção e busca de produtos. Falta implementar, 
inclusive, o redimensionamento do vetor de itens. O redimensionamento ocorrerá de 
acordo com a estratégia que foi sorteada para você. Além disso, foi desenvolvida 
uma função externa à classe para verificar a existência de itens próximos ao vencimento.
A função já está testada e não pode ser alterada. Entretanto, o uso dessa função 
gera falha de segmentação. A interface do programa (a função main()) também não pode 
ser alterada, bem como os atributos privados da classe. Sua tarefa é corrigir o problema
com essa função externa, bem como implementar o redimensionamento do vetor de itens.
 
    armazem.cpp - aplicação para desenvolvimento de atividade
    de Tipo Abstrado de Dados

    Atividade de  GCC216 - Estruturas de Dados, 2020

    Solução de: Alexandre Rabello
*/

#include <algorithm>
#include <iostream>

using namespace std;

struct item {
    string nomeDoProduto;
    int validadeEmDias;
    int quantidadeEmQuilos;
    item();
};

item::item() {
    nomeDoProduto.clear();
    validadeEmDias = 0;
    quantidadeEmQuilos = 0;
}

class armazem {
    private:
        // *** AVISO: Não altere os atributos privados da classe *** 
        item* listaDeItens;
        int quantidadeDeItens;
        int capacidadeMaxima;
    public:
        armazem(int capacidade);
        armazem(const armazem& armazem);
        ~armazem();
        void inserirNovoItem(const item& umItem);
        bool buscarItem(const string& nome, item& umItem);
        void redimensionarCapacidade();
        int quantidadeDeItem(){return quantidadeDeItens;}
        int capacidadeMax(){return capacidadeMaxima;}
        item* listaDeItem(){return listaDeItens;}
        
        friend void verificarItensPertoDoVencimento(armazem umArmazem, int dias);
};

armazem::armazem(int capacidade) {
    //cout << "CONSTRUTOR PADRAO" << endl;
    quantidadeDeItens = 0;
    capacidadeMaxima = capacidade;
    listaDeItens = new item[capacidadeMaxima];
}

armazem::armazem(const armazem& armazem) {
    //cout << "CONSTRUTOR DE COPIA CHAMADO" << endl;
    quantidadeDeItens = armazem.quantidadeDeItens;
    capacidadeMaxima = armazem.capacidadeMaxima;
    listaDeItens = new item[capacidadeMaxima];
    copy(&armazem.listaDeItens[0],&armazem.listaDeItens[capacidadeMaxima],&listaDeItens[0]);
}


armazem::~armazem() {
    //cout << "DESTRUTOR CHAMADO" << endl;
    delete [] listaDeItens;
}

void armazem::inserirNovoItem(const item& umItem) {
    if (quantidadeDeItens == capacidadeMaxima) { // vetor cheio, precisa redimensionar
        redimensionarCapacidade();
    }
    listaDeItens[quantidadeDeItens] = umItem;
    quantidadeDeItens++;
}

bool armazem::buscarItem(const string& nome, item& umItem) {
    int posicaoAtual = 0;

    while (posicaoAtual < quantidadeDeItens and 
           listaDeItens[posicaoAtual].nomeDoProduto != nome) 
        posicaoAtual++;

    // se posicaoAtual não for menor que quantidade de produtos, é porque não encontrou
    if (posicaoAtual < quantidadeDeItens) {
        umItem = listaDeItens[posicaoAtual];
        return true;
    }

    return false;
}

void armazem::redimensionarCapacidade() {
    //cout << "ARRAY FOI EXPANDIDO" << endl;
    int novaCapacidade = capacidadeMaxima*2;
    item* tempLista = new item[novaCapacidade];
    //cout << "MAXIMO ANTES: " << capacidadeMaxima << endl;
    copy(&listaDeItens[0],&listaDeItens[capacidadeMaxima],&tempLista[0]);
    capacidadeMaxima = novaCapacidade;
    delete [] listaDeItens;
    listaDeItens =tempLista;
    //cout << "MAXIMO DEPOIS: " << capacidadeMaxima << endl;
    //#warning implemente este metodo!
}

void verificarItensPertoDoVencimento(armazem umArmazem, int dias) {
    // *** AVISO: Não altere esta função *** 
    for (int i = 0; i < umArmazem.quantidadeDeItens; i++) {
        if (umArmazem.listaDeItens[i].validadeEmDias <= dias) 
            cout << umArmazem.listaDeItens[i].nomeDoProduto << endl;
    }
    cout << endl;
}


int main() {
    // *** AVISO: Não altere a função principal, o main() *** 
    int capacidadeInicial;

    cout << "Armazem - Aplicativo para Controlar Vencimento de Produtos\n" 
         << "Entre com capacidade maxima inicial: ";
    cin >> capacidadeInicial;

    armazem meuArmazem(capacidadeInicial);

    cout << "Armazem - Escolha a Opcao:\n"
         << "i - inserir novo item\n"
         << "b - buscar por um dado item a partir do nome\n"
         << "v - verificar itens próximo do vencimento\n"
         << "s - para sair do programa" << endl;

    char opcaoDoMenu;
    item umItem;
    string nome;
    int dias;

    cin >> opcaoDoMenu;

    while (opcaoDoMenu != 's') {
        switch(opcaoDoMenu) {
            case 'i' : 
                cout << "Entre com dados do item (nome, validade em dias, quantidade em Kg):" << endl;
                cin >> umItem.nomeDoProduto
                    >> umItem.validadeEmDias
                    >> umItem.quantidadeEmQuilos;
                meuArmazem.inserirNovoItem(umItem);
                break;

            case 'b' :
                cout << "Entre com nome do item para busca: ";
                cin >> nome;
                
                if (meuArmazem.buscarItem(nome, umItem)) 
                    cout << umItem.nomeDoProduto << " "
                         << umItem.validadeEmDias << " "
                         << umItem.quantidadeEmQuilos << endl << endl;
                else 
                    cout << "Item nao encontrado!" << endl << endl;
                break;

            case 'v' : 
                cout << "Entre com quantidade de dias para verificacao: ";
                cin >> dias;
                verificarItensPertoDoVencimento(meuArmazem,dias);
                break;

            case 's' : // não faz nada, espera retorno ao while para sair 
                break;

            default:
                cout << "Opção invalida!" << endl;
                break;

        }
        cout << "Armazem - Escolha a Opcao:\n"
            << "i - inserir novo item\n"
            << "b - buscar por um dado item a partir do nome\n"
            << "v - verificar itens proximo do vencimento\n"
            << "s - para sair do programa" << endl;
        cin >> opcaoDoMenu;
    }

    return 0;
}
