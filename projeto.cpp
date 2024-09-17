#include <iostream>
#include <cmath>
#include <string>

using namespace std;

// Classe nó
class Node{
public:
     double chave; // Chave
    string dado; // Valor
    Node* prox; // Ponteiro para o proximo nó
    

    Node( double num, string nome) {
        this->chave = num;
        this->dado = nome;
        this->prox = nullptr;
    }; // Metodo construtor
};




// Classe Tabela Hash
class TabelaHashEncadeada {
public:
   int tamanho;
   Node** tabela;
   bool tabelacriada;
   bool tabeladestruida;
   bool tabelavisualizada;
   int contador=0;


    /**
     * @brief Método construtor da TabelaHashEncadeada
     * 
     * @param tam int com o tamanho da tabela
     */
 TabelaHashEncadeada(int tam) : tamanho(tam), tabelacriada(false) {
        tabela = new Node*[tamanho]();
        for (int i = 0; i < tamanho; ++i) tabela[i] = nullptr;
        if(tamanho>0)tabelacriada = true;    
    }
    /**
     * @brief Método destrutor da TabelaHashEncadeada
     * 
     */
 ~TabelaHashEncadeada() {
        for (int i = 0; i < tamanho; ++i) {
            Node* atual = tabela[i];
            while (atual != nullptr) {
                Node* prox = atual->prox;
                delete atual;
                atual = prox;
            }
        }
        delete[] tabela;
        contador=0;
        tabeladestruida = true;
        
    }


   /**
     * @brief funcao para mapear a chave para uma lista determinada
     * 
     * @param chave string com a Chave do nó,
     * @param dado Valor relacionado a chave do nó, dado correspondente
     *@return int posiçao da tabela que representa a lista encadeada onde a chave será acessada;
     */
   int funcaoHash( double chave, int tam) {
        
        int indice;
        double parteinteira = double (int(chave)); 
        int c=0; 
        int d=0;
        double resto=fmod(chave , parteinteira);

        if(parteinteira == 0){
            chave = chave+1;
            parteinteira = parteinteira+1;
        }  

        //cout << parteinteira << endl;
            //  para garantir uma boa disperçao das chaves , é calculado dentro da condiçao do if quantas casas decimais há no numero 
            //  e convertido para um numero muito grande sem casas decimais  em que será calculado o modulo .
            if( resto >= 0.100000) {
                c  = ((tam * (10 * resto))/10) + (resto*1000000); // caso tenha 2 casa decimais.
                d =  (tam * 3)/10;
               // cout << d << "<->" <<  c << endl ;

                }
            else if(resto >= 0.01) {
                c  = (tam * (100 * resto))/10 + (resto*1000000); // caso tenha 2 casa decimais.
                d =  (tam * 3)/10;
                //cout << d << "<->" <<  c << endl ;

                }
            else if(resto >= 0.001){
                 c  = (tam * (1000 * resto))/10 + (resto*1000000); // caso tenha 3 casa decimais.
                 d =  (tam * 5)/10;
                //cout << d << "<->" <<  c << endl ;

                }
            else if(resto >= 0.0001){
                 c  = (tam * (10000 * resto))/10 + (resto*1000000); // caso tenha 4 casa decimais.
                 d =  (tam * 7)/10;
                }
            else if(resto >= 0.00001) {
                c  = (tam * (100000 * resto))/10 + (resto*1000000);// caso tenha 5 casa decimais.
                d =  (tam * 8)/10;
                //cout << d << "<->" <<  c << endl ;

                }
            else if(resto >= 0.000001) {
                c = (tam * (1000000 * resto))/10 + (resto*1000000); // caso tenha 6 casa decimais.
                d =  (tam * 9)/10;

               // cout << d << "<->" <<  c << endl ;
                }
            // sem casas decimais.
        
        

        //cout << "-----" << chave << endl;

      

        

      
        // transforma a chave double em um numero inteiro , arredondamento para baixo em todos os casos;
        int chaveint = int(chave);  //truncamento das casas decimais

        
        indice = ((chaveint % tam)+ ((c + d)/2))% tam;// mod entre a chave e o tamanho do array , para definir a posicao;
        //cout << "-----" << c << endl;
        
        //cout << "-----" << c << "+" << (chaveint % tam) << "=" << indice << endl;

    return indice;
    }


       /**
     * @brief   exibir no terminal a Tabela Hash criada com todos seus elementos;
     * Posicao n : 
       posicao n+1 : 
                (chave:x , dado:xd)
                (chave:y, dado:yd)
        posicao tamanho - 1:
                (chave:w, dado:wd)         
     */
    void showtable(){

        cout << "___________________________________________________________________________________________________________" << endl;
        for (int i = 0; i < tamanho; ++i) {
            cout << "|  Posicao " << i << ": " << endl;; 
            Node* atual = tabela[i];
            while (atual != nullptr) {
                cout << "|       (Chave: " << atual->chave << ", Dado: " << atual->dado << ") " << endl;
                atual = atual->prox;
            }
            cout << "|" << endl;
        }
        cout << "|__________________________________________________________________________________________________________" << endl;

        tabelavisualizada = true;

    }

 /**
     * @brief percorre todos os elementos da tabela usando dois loops de repetição, contando os elementos presentes;
     * @param tabela hash
     *@return int , cardinalidade da tabela 
     */
    
    int sizetable(){
        int contador = 0;
        for (int i = 0; i < tamanho; ++i) {
            Node* atual = tabela[i];
            while (atual != nullptr) {
                contador++;
                atual = atual->prox;
            }
        }
        return contador;    
    }



    /**
     * @brief Insere um novo nó na fila encadeada, com a chave igual ao primeiro parametro e valor igual ao segudo parametro, 
     * 
     * @param chave string com a Chave do nó, 
     * @param dado Valor relacionado a chave do nó, dado correspondente
     *@return int retorna o indice da lista encadeada em que o elemento foi inserido, ou -1 caso já exista a chave;
     */
  void inserir( double chave, string dado){
        int indice = this->funcaoHash(chave, this->tamanho);
        Node* novoNode = new Node(chave, dado);


        if(tabela[indice] == nullptr){
            tabela[indice] = novoNode;
            cout << "Chave: " << chave << " e Dado: " << dado << " inseridos." << endl;
            return;
        } else {
            Node* atual = tabela[indice];
            if(atual->chave == chave){
                cout << "A chave " << chave << " ja se encontra na tabela" << endl;
                return;
            }// elemento já existente na tabela 
            while(atual->prox != nullptr){
                if(atual->chave == chave || atual->prox->chave == chave){
                    
                    cout << "A chave " << chave << " ja se encontra na tabela" << endl;
                    return;
                }  // elemento já existente na tabela 
                atual = atual->prox;
            }
            atual->prox = novoNode;
            cout << "Chave: " << chave << " e Dado: " << dado << " inseridos." << endl;
            return;
        }
   }


    /**
     * @brief Procura o elemento guardado a partir da chave 
     * 
     * @param chave numero double da chave;
     * @return string , dado correspondente;
     */
    string procurarChave(double chave){
        int indice = this->funcaoHash(chave, this->tamanho);
        Node* atual = tabela[indice];

        while(atual != nullptr){
            if(atual->chave == chave){
                return atual->dado;
            }
            atual = atual->prox;
        }

        return "Error74027";
    }

     /** FUNÇAO EXTRA
     * @brief percorre toda a lista contando quantas chaves existem atreladas a determinado dado
     * com o objetivo de sondar e definir a abordagem com que a informação será apresentada
     * @param dado string contendo o dado que deseja ser procurado;
     * @return int , retorna a quantidade de chave encontradas , se for 0 não exite a chave;
     */
    int procurarSet(string dado){
        
        int contador=0;
        for (int i = 0; i < tamanho; ++i) {
            Node* atual = tabela[i];
            while (atual != nullptr) {
                if(atual->dado == dado){
                    // cout << atual->chave  << endl;;
                    contador++;
                }
                atual = atual->prox;
            }
        }

        return contador;
    }

      /**
     * @brief percorre toda a lista e imprimir no terminal as chaves atrelados ao dado solicitado;
     * @param dado string contendo o dado que deseja ser procurado;
     */
    void procurarDado(string dado){

        for (int i = 0; i < tamanho; ++i) {
            Node* atual = tabela[i];
            while (atual != nullptr) {
                if(atual->dado == dado){
                    cout << "      ( Dado: " << atual->dado << ", Chave: " << atual->chave << " )" << endl;
                }
                atual = atual->prox;
            }
        }
    }


    /**
     * @brief procura na string a chave desejada e remove-a, reajustando a ordem dentro da lista encadeada;
     * 
     * @param chave numero double utilizada para mapear a posição da lista
     *@return double retorna a chave que foi removida, ou -1 caso nao exista a chave na tabela; 
     */
    double removerChave(double chave){
        int indice = this->funcaoHash(chave, this->tamanho);
        Node* atual = tabela[indice];
        Node* anterior = nullptr;

        while(atual != nullptr){
            if(atual->chave == chave){
                if(anterior != nullptr){
                    anterior->prox = atual->prox;
                } else {
                    tabela[indice] = atual->prox;
                }
                delete atual;
                return chave;
            }
            anterior = atual;
            atual = atual->prox;
        }
        return -1;
        
    }

  /**
     * @brief procura na string a chave desejada e remove-a, reajustando a ordem dentro da lista encadeada;
     * 
     * @param chave numero double utilizada para mapear a posição da lista
     */
    void removerDado(string dado){
         for (int i = 0; i < tamanho; ++i) {
            Node* atual = tabela[i];
            while (atual != nullptr) {
                if(atual->dado == dado){
                    cout << "Chave: " << atual->chave << " removida."  << endl;//print
                    this->removerChave(atual->chave);// chave a funcao removerchave para apagar a chave com o dado e ajustar a lista
                  
                }
                atual = atual->prox;
            }
        }
        
    }

};

int main(){

    cout <<"--------------//----------------- BEM VINDO! --------------//-----------------"  << endl;
    
    while(1){

        cout <<  endl <<"--------------Menu de operacoes: quais das funcionalidades deseja realizar ?(digite o numero da opcao) " << endl << endl;
        
        int loop1;

        cout << "(0) Encerrar o Programa. ( Finalizar )" << endl;; 
        cout << "(1) Criar a Tabela Hash. ( Make-Table(T) )" << endl;
        cout << endl;
        cin >> loop1;
        cout << endl;

        if(loop1 == 0)return 0;// acaba o programa.(nao existem tabelas)
        else if (loop1 == 1){
            
            cout << "Qual a dimensao desejada ? (deve ser maior do que zero)" << endl;
            cout << endl;

            int dimensao;
            cin >> dimensao;

            while(dimensao<=0){
                            cout << "valor de dimensao invalido, nescessita ser maior que zero, digite novamente:" << endl;
                            cin >> dimensao;
            }
            
            TabelaHashEncadeada *tabelaHash = new TabelaHashEncadeada(dimensao);
            cout << endl;

            // Verificar se a tabela foi criada com sucesso
            if (tabelaHash->tabelacriada) {
                cout << "Tabela criada com sucesso!" << endl;
            } else {
                cout << "Erro ao criar a tabela!" << endl;
                return 1;  // Encerrar o programa indicando falha
            }

            int nottable=0;
            while(1){ // segundo menu com as opções pedidas.
                if (nottable == 1) break;
                cout << endl <<  "--------------Menu de operacoes: quais das funcionalidades deseja realizar ?(digite o numero da opcao) " << endl << endl;

                cout << "(0) Encerrar o Programa. -------------- ( Finalizar )" << endl; 
                cout << "(1) Inserir um Preset ja definidos para testes. --------------  ( Exemplo: 12 insercoes )" << endl;
                cout << "(2) Inserir na tabela hash. --------------  ( Insert-Table(T, x, dados) )" << endl; 
                cout << "(3) Mostrar tabela hash. -------------- ( Show-Table(T) )" << endl; 
                cout << "(4) Calcular a cardinalidade da tabela hash. -------------- ( Size-Table(T) )" << endl;
                cout << "(5) Destruir a tabela hash. -------------- ( Destroy-Table(T) )" << endl; 
                cout << "(6) Procurar chave na tabela e mostrar seus dados. --------------  ( Search-Table(T, x) )" << endl; 
                cout << "(7) Procurar dados na tabela e retorna as chaves correspondentes. -------------- ( Search-Table(T, dados) )" << endl;
                cout << "(8) Remover a chave e seus dados da tabela. -------------- ( Remove-Table(T, x) )" << endl; 
                cout << "(9) Remover todas as chaves atreladas a um determinado dado da tabela. -------------- ( Remove-Table(T, dados) )" << endl;

                int numero;
                double chave;
                string dado;
                int tam;
                int achados;
                double removida;

                cout << endl;
                cin >> numero;
                cout << endl;
                
                switch (numero) {
                    case 0: // encerrar o programa depois de liberar a tabela;______________________________________
                        delete tabelaHash;
                        if (tabelaHash->tabeladestruida) {
                            cout << "Tabela destruida!" << endl << endl;
                            nottable = 1;
                        } else {
                            cout << "Erro ao destruir a tabela!" << endl;
                            return 1;  // Encerrar o programa indicando falha
                        }
                        return 0;

                    case 1: // testes; ______________________________________________________________________________
                        
                        tabelaHash->inserir(1.000001, "Anderson");
                        tabelaHash->inserir(1.000010, "Isabela");
                        tabelaHash->inserir(1.000100, "Thiago");
                        tabelaHash->inserir(1.001000, "Gustavo");
                        tabelaHash->inserir(1.010000, "Wanderley");
                        tabelaHash->inserir(1.1, "Wanderley");
                        
                        tabelaHash->inserir(12345678.100001, "Ana");
                        tabelaHash->inserir(12345678.200002, "Michelle");
                        tabelaHash->inserir(12345678.300003, "Thiago");
                        tabelaHash->inserir(12345678.400004, "Brenna");
                        tabelaHash->inserir(12345678.500005, "Jaum Gui");
                        tabelaHash->inserir(12345678.100006, "Lemos");

                        break;

                    case 2: // Inserir elementos na tabela; ___________________________________________________________
                        
                        cout << "Qual a chave que deseja inserir?" << endl;
                        cout << endl;
                        cin >> chave;
                        cout << endl;
                        while(chave<0.000001 || chave> 99999999.999999){
                            cout << "valor de chave invalida, ela deve esta no intervalo [0.000001, 99999999.999999], digite novamente:" << endl;
                            cin >> chave;
                        }

                        cout << "Qual o dado que deseja inserir para a chave " << chave << "?" << endl;
                        cout << endl;
                        cin >> dado;
                        cout << endl;
                        
                        tabelaHash->inserir(chave,dado);
                        
                        break;

                    case 3 : // SHOW-TABLE_______________________________________________________________
                        tabelaHash->showtable();
                        if(!tabelaHash->tabelavisualizada)cout << "Error ao exibir tabela hash." << endl;
                        break;

                    case 4 : // Size-Table(T)__________________________________________________________________
                        
                        tam = tabelaHash->sizetable();
                        cout << "A tabela possui " << tam << " elemento(s)." << endl;
                        break;

                    case 5 : //  Destroy-Table(T)
                        delete tabelaHash;
                         // Verificar se a tabela foi destruida com sucesso
                         if (tabelaHash->tabeladestruida) {
                            cout << "Tabela destruida com sucesso!" << endl;
                            nottable = 1;
                        } else {
                            cout << "Erro ao destruir a tabela!" << endl;
                            return 1;  // Encerrar o programa indicando falha
                        }
                        break;

                    case 6 : // Search-Table(T, x)___________________________________________________________________
                        
                        cout << "Qual a chave que deseja pesquisar?" << endl;
                        cout << endl;
                        cin >> chave;

                        cout << endl;
                        dado = tabelaHash->procurarChave(chave);
                        if(dado == "Error74027") cout << "A chave " << chave << " nao esta presente na tabela," << endl;
                        else {
                            cout << "Chave encontrada!" << endl;
                            cout << "      ( Chave: " << chave << ", Dado: " << dado << " )" << endl;
                        }
                        break;

                    case 7 : // Search-Table(T, dados) ______________________________________________________________
                        
                        cout << "Qual o dado que deseja pesquisar?" << endl;
                        cout << endl;
                        cin >> dado;
                        cout << endl;
                       
                        achados = tabelaHash->procurarSet(dado);

                        if(achados == 0)cout << "O dado pesquisado nao pertence a tabela." << endl;
                        else{
                            cout << "Dado encontrado!:" << endl;
                            tabelaHash->procurarDado(dado);
                        }
                        break;

                    case 8 : //Remove-Table(T, x)___________________________________________________________________________

                        cout << "Qual o chave que deseja remover?" << endl;
                        cout << endl;
                        cin >> chave;

                        cout << endl;
                        removida = tabelaHash->removerChave(chave);

                        if(removida == -1)cout << "A chave " << chave << " nao pertence a tabela." << endl;
                        else {
                            cout << "A chave " << removida << " foi removida da tabela." << endl;
                        }

                        break;

                    case 9 : // Remove-Table(T, dados) _______________________________________________________________________
                        
                        cout << "Qual o dado que deseja remover?" << endl;
                       cout << endl;
                        cin >> dado;

                        cout << endl;
                        achados = tabelaHash->procurarSet(dado);

                        if(achados == 0)cout << "o dado pesquisado nao pertence a tabela." << endl;
                        else{
                            cout << "Dado encontrado! Chave(s) removida(s):" << endl;
                            tabelaHash->removerDado(dado);
                        }
                        break;

                    default:
                        std::cout << "Numero fora do intervalo de 0 a 9" << std::endl;
                        break;
                }
            }
        }
        else cout << "opcao invalida" << endl;
    }
}