#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

// Estrutura de um elemento da roleta
typedef struct Roleta {
    int valor;              // Número armazenado na posição da roleta
    struct Roleta* prox;    // Ponteiro para o próximo elemento
    struct Roleta* ant;     // Ponteiro para o elemento anterior
} Roleta;

typedef struct Roleta* RoletaPtr;

// Primeiro elemento da lista circular
RoletaPtr INICIO = NULL;


// Verifica se a roleta está vazia
bool listaVazia() {

    return INICIO == NULL;
}


// Adiciona um número na roleta

void montarRoleta(int valor) {

    RoletaPtr p = new Roleta;

    p->valor = valor;

    // Caso seja o primeiro elemento
    if (listaVazia()) {

        INICIO = p;

        // O elemento aponta para ele mesmo,
        // formando uma lista circular
        p->prox = p;
        p->ant = p;

    } else {

        // Último elemento atual da lista
        RoletaPtr ultimo = INICIO->ant;

        // Conecta o novo elemento entre o último e o início
        p->prox = INICIO;
        p->ant = ultimo;

        ultimo->prox = p;
        INICIO->ant = p;
    }
}


// Realiza o sorteio do número da roleta
int sortearNumero() {

    if (INICIO == NULL)
        return -1;

    // Gera uma posição aleatória entre 0 e 36
    int aleatorio = rand() % 37;

    RoletaPtr p = INICIO;

    // Percorre a lista até a posição sorteada
    for (int i = 0; i < aleatorio; i++) {

        p = p->prox;
    }

    return p->valor;
}


// Atualiza o saldo do jogador
void atualizarSaldo(int* saldo, int resultado) {

    *saldo += resultado;
}


// Exibe o menu principal
int menu() {

    int opcao;

    cout << "\n1. Inserir saldo";
    cout << "\n2. Apostar em um número específico";
    cout << "\n3. Apostar em par ou ímpar";
    cout << "\n0. Sair";

    cout << "\nDigite uma opção: ";
    cin >> opcao;

    return opcao;
}

// Libera a memória utilizada pela roleta
void liberarRoleta() {

    if (INICIO == NULL)
        return;

    RoletaPtr p = INICIO->prox;

    while (p != INICIO) {

        RoletaPtr aux = p;

        p = p->prox;

        delete aux;
    }

    delete INICIO;

    INICIO = NULL;
}

int main() {

    // Inicializa a geração de números aleatórios
    srand(time(NULL));

    // Ordem real dos números da roleta europeia
    int ordemRoleta[] = {
        0, 32, 15, 19, 4, 21, 2, 25, 17,
        34, 6, 27, 13, 36, 11, 30, 8, 23,
        10, 5, 24, 16, 33, 1, 20, 14, 31,
        9, 22, 18, 29, 7, 28, 12, 35, 3, 26
    };

    // Monta a estrutura da roleta
    for (int i = 0; i < 37; i++) {

        montarRoleta(ordemRoleta[i]);
    }

    int saldoAtual = 0;
    int aposta = 0;
    int escolha;
    int numeroSorteado;

    int opcao = menu();

    while (opcao != 0) {

        // Inserir saldo
        if (opcao == 1) {

            int valor;

            cout << "\nQuanto deseja inserir: ";
            cin >> valor;

            saldoAtual += valor;

        } 

        else {

            // Verifica se o jogador possui saldo
            if (saldoAtual > 0) {

                do {

                    cout << "\nQuanto deseja apostar: ";
                    cin >> aposta;

                } while (aposta <= 0 || aposta > saldoAtual);


                // Retira a aposta antes do resultado
                saldoAtual -= aposta;

                switch (opcao) {

                // Apostar em número específico
                case 2:

                    do {

                        cout << "\nEscolha um número (0-36): ";
                        cin >> escolha;

                    } while (escolha < 0 || escolha > 36);

                    numeroSorteado = sortearNumero();

                    cout << "\nNúmero sorteado: "
                         << numeroSorteado << endl;

                    if (escolha == numeroSorteado) {

                        cout << "\nVocê ganhou!";

                        // Pagamento de 35:1 + valor apostado
                        atualizarSaldo(
                            &saldoAtual,
                            aposta * 36
                        );

                    } else {

                        cout << "\nVocê perdeu!";
                    }

                    break;

                // Apostar em par ou ímpar
                case 3:

                    do {

                        cout << "\n1 - Ímpar";
                        cout << "\n2 - Par";
                        cout << "\nOpção: ";

                        cin >> escolha;

                    } while (escolha != 1 && escolha != 2);

                    numeroSorteado = sortearNumero();

                    cout << "\nNúmero sorteado: "
                         << numeroSorteado << endl;

                    // O número zero não participa de par ou ímpar
                    if (numeroSorteado != 0 &&
                        ((numeroSorteado % 2 == 0 && escolha == 2) ||
                         (numeroSorteado % 2 != 0 && escolha == 1))) {

                        cout << "\nVocê ganhou!";

                        // Pagamento de 1:1 + valor apostado
                        atualizarSaldo(
                            &saldoAtual,
                            aposta * 2
                        );

                    } else {

                        cout << "\nVocê perdeu!";
                    }

                    break;
                }

                cout << "\nSaldo atual: "
                     << saldoAtual << endl;

            } else {

                cout << "\nSaldo insuficiente!";
            }
        }

        opcao = menu();
    }

    cout << "\nObrigada por jogar!" << endl;
    cout << "\nSaldo final: "
         << saldoAtual << endl;

    liberarRoleta();

    return 0;
}