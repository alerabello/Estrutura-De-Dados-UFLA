/* Enunciado 4 - Parte Teorica - REO1
Alexandre Rabello Santana 

Uma organização não governamental (ONG) que acolhe cães e gatos abandonados tem recebido, ao longo dos anos, várias doações, de várias 
pessoas e instituições,
 que ficam sensibilizadas com o trabalho desenvolvido. Entretanto, caso fosse necessário indicar qual instituição que mais apoiou a ONG 
 em valores reais
(maior montante recebido), seus dirigentes não teriam como fornecer essa informação. Dessa forma, além do registro dos animais, que 
armazena o nome dado ao animal,
a espécie, o local e a data em que foi resgatado, eles também passaram a fazer o cadastro de seus benfeitores, armazenando o nome, o tipo 
(se pessoa física ou jurídica), 
e o valor da doação (caso a doação seja em material de limpeza, ração ou outros produtos, é registrado o valor estimado da doação).
Agora é possível cadastrar novos animais, cadastrar novas doações e procurar pelas doações feitas por um determinado benfeitor.
Analise a descrição acima, identifique quais são as entidades a serem tratadas como classes, quais os atributos de cada uma delas e qual 
o comportamento esperado 
(os métodos) de cada entidade. Com base nesse planejamento feito, implemente uma solução para esse problema. Sua implementação deve ser 
orientada a objetos,
com a definição de cada uma das classes, utilizando as diretivas de visibilidade adequadas, os métodos que representem o comportamento de 
cada classe e um 
pequeno programa (main) que as utilize para solucionar o problema apresentado. Você deve tomar as decisões de projeto que achar adequada 
(definição de tamanho de arranjos, tipo da variável, etc.) e indicar essas decisões no cabeçalho do código. Você deverá entregar o 
planejamento realizado 
(atividade manual) e o código desenvolvido (atividade prática)

 - Foram feitas alterações nas classes e em seus comportamentos juntos com seu metodos e nas quantidades em relação informada pela primera 
 etapa, pelo  motivo que após desenvolvimento consegui mesclar e juntas algumas estruturas melhorando meu entendimento e facilitando o 
 desenvolvimento ao meu olhar. 
*/


#include <iostream>
#include <string>
using namespace std;

struct ong
{
	string nomeProdutoDoado;
	float doacoes;
	void printOpcoes();
};

struct benfeitor
{
	string nomeBenfeitor;
	string docBenfeitor;
	string listaDoacoes;
};

struct animalCad
{
	string nomeAnimal;
	string infoAnimal;
	string localResgate;
	string dataResgate;
};

class adocao{
		friend class info;
	private:
		animalCad *itensAnimal;
		int totalAnimais;
		string nomeAdotador;
		string localEncontroAnimal;
	public:
		adocao();
		~adocao();
		void listarCadastroAnimais();
		int cadastrarAdocao(int t);
};

adocao::adocao(){
	totalAnimais = 0;
	nomeAdotador.clear();
	localEncontroAnimal.clear();
};

adocao::~adocao(){
	delete [] itensAnimal;
	localEncontroAnimal.clear();
	nomeAdotador.clear();
};

int adocao::cadastrarAdocao(int t){ // Realiza o cadastro da adção(informa local, nome do benfeitor), algo que foi doado, identifica se foi item e sua quantidade, ou dinheiro e sua quantidade.
	totalAnimais = t;
	itensAnimal = new animalCad[totalAnimais];
	for(int i=0; i<totalAnimais; i++){
		cout <<"-------------------------------------------------------------"<<endl;
		cout<<"NOME ANIMAL: "<<endl;
		cin>>itensAnimal[i].nomeAnimal;
		cout<<"ESPECIE ANIMAL: "<<endl;
		cin>>itensAnimal[i].infoAnimal;
		cout<<"LOCAL DE RESGATE: "<<endl;
		cin>>itensAnimal[i].localResgate;
		cout<<"DATA DE RESGATE: "<<endl;
		cin>>itensAnimal[i].dataResgate;
		totalAnimais = totalAnimais, (itensAnimal[i].nomeAnimal,itensAnimal[i].infoAnimal,itensAnimal[i].localResgate,itensAnimal[i].dataResgate);
		cout <<"-------------------------------------------------------------"<<endl;
	}	
};
void adocao :: listarCadastroAnimais(){
	for (int i = 0;i<totalAnimais;i++){
		cout <<"-------------------------------------------------------------"<<endl;
		cout << "NOME ANIMAL: " << itensAnimal[i].nomeAnimal <<endl;
		cout << "ESPECIE ANIMAL: " << itensAnimal[i].infoAnimal <<endl;
		cout << "LOCAL RESGATE " << itensAnimal[i].localResgate <<endl;
		cout << "DATA RESGATE " << itensAnimal[i].dataResgate <<endl;
		cout <<"-------------------------------------------------------------"<<endl;
	}
}

class info{
	private:
		benfeitor *benfeitorCadastrado;
		int totalBenfeitorAdocao;
	public:
		info();
		~info();
		int cadastrarBenfeitor(int c);
		void listarBenfeitoresCadastrados();
		void buscarBenfeitor(string nome);
};

info :: info(){
 	totalBenfeitorAdocao=0;
};

info ::~info(){
	delete [] benfeitorCadastrado;
};

int info :: cadastrarBenfeitor(int c){ // Realiza o cadastro do benfeitor, junto identifica o documento. (CPF ou CNPj) e sua doacao.
	totalBenfeitorAdocao = c;
	benfeitorCadastrado = new benfeitor [totalBenfeitorAdocao];
		for(int i=0; i<totalBenfeitorAdocao;i++){
			cout <<"-------------------------------------------------------------"<<endl;
			cout<<"NOME BENFEITOR / EMPRESA: "<<endl;
			cin>>benfeitorCadastrado[i].nomeBenfeitor;
			cout<<"DOCUMENTO BENFEITOR: (informe se e CPF ou CNPJ) "<<endl;
			cout<<"Exemplo: cpf"<<endl;
			cin>>benfeitorCadastrado[i].docBenfeitor;
			cout<<"DOACAO REALIZADA: "<<endl;
			cin>>benfeitorCadastrado[i].listaDoacoes;
			totalBenfeitorAdocao = totalBenfeitorAdocao , (benfeitorCadastrado[i].nomeBenfeitor, benfeitorCadastrado[i].docBenfeitor,benfeitorCadastrado[i].listaDoacoes);
			cout <<"-------------------------------------------------------------"<<endl;
		}
};
void info :: listarBenfeitoresCadastrados(){
	for (int i = 0;i<totalBenfeitorAdocao;i++){
		cout <<"-------------------------------------------------------------"<<endl;
		cout << "NOME BENFEITPOR: " << benfeitorCadastrado[i].nomeBenfeitor <<endl;
		cout << "DOCUMENTO BENFEITPOR: " << benfeitorCadastrado[i].docBenfeitor <<endl;
		cout << "DOACOES DO BENFEITOR: " << benfeitorCadastrado[i].listaDoacoes <<endl;
		cout <<"-------------------------------------------------------------"<<endl;
	}
};

void info :: buscarBenfeitor(string nome){
	for(int i=0; i<totalBenfeitorAdocao;i++){
		if(benfeitorCadastrado[i].nomeBenfeitor == nome){
			cout <<"-------------------------------------------------------------"<<endl;
			cout << "NOME BENFEITPOR: " << benfeitorCadastrado[i].nomeBenfeitor <<endl;
			cout << "DOCUMENTO BENFEITPOR: " << benfeitorCadastrado[i].docBenfeitor <<endl;
			cout << "DOACOES DO BENFEITOR: " << benfeitorCadastrado[i].listaDoacoes <<endl;
			cout <<"-------------------------------------------------------------"<<endl;
		}
	}
}

int main(){

	char opc;
	cout <<"-------------------------------------------------------------"<<endl;
	cout << "A - Cadastrar Adocao: " << endl;
	cout << "B - Cadastrar Beifentor: " << endl;
	cout << "C - Total Benfeitores: " << endl;
	cout << "D - Total Animais Adotados: " << endl;
	cout << "E - Buscar por um determinado Benfeitor: " << endl;
	cout << "Z - Sair" << endl;
	cout <<"-------------------------------------------------------------"<<endl;
	cin >> opc;
	adocao Adocao;
	info Info;
	string busca;
	while (opc != 'Z'){	
		switch(opc){
			case 'A':
				int t;
				cout << "INFORME QUANTOS CADASTROS DESEJA REALIZAR NA ONG: ";
				cin >> t;
				Adocao.cadastrarAdocao(t);
				break;
			case 'B':
				int c;
				cout << "INFORME QUANTOS CADASTROS DESEJA REALIZAR NA ONG: ";
				cin >> c;
				Info.cadastrarBenfeitor(c);
				break;
			case 'C':
				Info.listarBenfeitoresCadastrados();
				break;
			case 'D':
				Adocao.listarCadastroAnimais();
				break;
			case 'E':
				cout << "DIGITE O NOME DO BEIFENTOR: ";
				cin >> busca;
				Info.buscarBenfeitor(busca);
				break;
			case 'Z':
				break;
			default:
				cout << "Comando invalido";
		}
		cout <<"-------------------------------------------------------------"<<endl;
		cout << "A - Cadastrar Adocao: " << endl;
		cout << "B - Cadastrar Beinfeitor: " << endl;
		cout << "C - Total de Benfeitores: " << endl;
		cout << "D - Todos de Animais Cadastrados: " << endl;
		cout << "E - Buscar por um determinado Benfeitor: " << endl;
		cout << "Z - Sair" << endl;
		cin >> opc;
		cout <<"-------------------------------------------------------------"<<endl;
	}
};