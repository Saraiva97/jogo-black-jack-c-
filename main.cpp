#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Função para calcular o valor da mão do jogador/computador
int calcularValorMao(int mao[], int tamanho) {
    int valor = 0;
    int ases = 0;
    for (int i = 0; i < tamanho; i++) {
        if (mao[i] == 1) { // Se a carta for um ás
            valor += 11;
            ases++;
        } else if (mao[i] >= 10) { // Se a carta for uma carta de figura
            valor += 10;
        } else {
            valor += mao[i];
        }
    }
    while (valor > 21 && ases > 0) { // Se houver estouro e houver ás
        valor -= 10;
        ases--;
    }
    return valor;
}

// Função para mostrar as cartas do jogador/computador
void mostrarCartas(int mao[], int tamanho) {
    cout << endl;
    cout << "                    Cartas: ";
    
    for (int i = 0; i < tamanho; i++) {
        cout << mao[i] << " ";
    }
    cout << " (Total: " << calcularValorMao(mao, tamanho) << ")" << endl;
}

int main() {
    srand(time(0)); // Seed para números aleatórios

    char jogarNovamente;
    
    do {
        int baralho[52]; // Array para representar o baralho

        // Inicializar baralho com valores de 1 a 10 (4 cópias de cada)
        for (int i = 0; i < 52; i++) {
            baralho[i] = (i % 13) + 1;
        }

        // Variáveis para representar as mãos do jogador e do computador
        int maoJogador[12];
        int maoComputador[12];

        int cartasJogador = 0;
        int cartasComputador = 0;

        // Distribuir cartas iniciais
        maoJogador[cartasJogador++] = baralho[rand() % 52];
        maoJogador[cartasJogador++] = baralho[rand() % 52];
        maoComputador[cartasComputador++] = baralho[rand() % 52];
        maoComputador[cartasComputador++] = baralho[rand() % 52];

        // Mostrar cartas do jogador
        cout << endl;
        cout << endl;
        cout << endl;
        cout << "                -------SARAIVA--------";
        cout << endl;
        cout << endl;
        cout << " ----------------------------------------------------";
        cout << endl;
        cout << "   -----------"; cout << "  ------BLACK JACK------"; cout << "  -----------";
        cout << endl;
        cout << " ----------------------------------------------------";
        cout << endl;
        cout << endl;

        cout << "                    Suas cartas: ";
        cout << endl;
        cout << endl;

        mostrarCartas(maoJogador, cartasJogador);

        // Mostrar uma carta do computador
        cout << endl;
        cout << "                    Carta do Computador: " << maoComputador[0] << endl;
        cout << endl;
        cout << "  ----------------------------------------------------";
        
        // Loop principal do jogo
        char escolha;
        while (true) {
            // Perguntar ao jogador se ele deseja 'hit' (receber outra carta) ou 'stand' (ficar com sua mão atual)
            cout << endl;
            cout << endl;
            cout << "          Deseja  'pedir [X] ' ou 'Parar [S]' ?  (X/S): ";
            cout << endl;
            cout << endl;
            cin >> escolha;

            if (escolha == 'x') { // Jogador pede outra carta
                maoJogador[cartasJogador++] = baralho[rand() % 52];
                cout << endl;
                cout << endl;
                cout << "                    Sua carta: " << maoJogador[cartasJogador - 1] << endl;
                cout << endl;
                
                mostrarCartas(maoJogador, cartasJogador);
                // Se a mão do jogador estourar 21, ele perde
                if (calcularValorMao(maoJogador, cartasJogador) > 21) {
                        cout << endl;
                        cout << endl;
                        cout << endl;
                        cout << endl;
                        cout << " -----------------------------------------------------";
                        cout << endl;
                        cout << "   -----------Estourou! Voce perdeu.----------------" << endl;
                        cout << " -----------------------------------------------------";
                        cout << endl;
                        cout << endl;
                        cout << endl;
                        cout << endl;
                    return 0;
                }
            } else if (escolha == 's') { // Jogador fica com sua mão atual
                break;
            }
        }

        // Computador joga
        while (calcularValorMao(maoComputador, cartasComputador) < 17) {
            maoComputador[cartasComputador++] = baralho[rand() % 52];
        }

        // Mostrar as mãos finais
        cout << "                    Sua mao: ";
        cout << endl;
        mostrarCartas(maoJogador, cartasJogador);
        cout << endl;
        cout << "                    Mao do Computador: ";
        cout << endl;
        mostrarCartas(maoComputador, cartasComputador);

        // Calcular valores das mãos
        int valorJogador = calcularValorMao(maoJogador, cartasJogador);
        int valorComputador = calcularValorMao(maoComputador, cartasComputador);

        // Mostrar resultado
        if (valorJogador > valorComputador || valorComputador > 21) {
            cout << endl;
            cout << endl;
            cout << endl;
            cout << "  ----------------------------------------------------";
            cout << endl;
            cout << "    ----------------VOCE-GANHOU!--------------------" << endl;
            cout << "  ----------------------------------------------------";
            cout << endl;
            cout << endl;
            cout << endl;
            cout << endl;

        } else if (valorJogador < valorComputador) {
            cout << endl;
            cout << endl;
            cout << endl;
            cout << "  ----------------------------------------------------";
            cout << endl;
            cout << "    ----------------VOCE-PERDEU!--------------------" << endl;
            cout << endl;
            cout << "  ----------------------------------------------------";
            cout << endl;
            cout << endl;
            cout << endl;
            cout << endl;
        } else {
            cout << endl;
            cout << "  ----------------------------------------------------";
            cout << endl;
            cout << "    -------------------EMPATE!-----------------------" << endl;
            cout << endl;
            cout << "  ----------------------------------------------------";
            cout << endl;
            cout << endl;
            cout << endl;
            cout << endl;
            cout << endl;
        }
        
        // Perguntar ao jogador se deseja jogar novamente
        cout << "         Deseja jogar novamente? (S/N): ";
        cin >> jogarNovamente;
    } while (jogarNovamente == 's' || jogarNovamente == 'S');

    return 0;
}
