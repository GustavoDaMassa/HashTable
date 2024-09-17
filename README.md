# Tabela Hash Encadeada com Interface de Terminal

Este projeto foi desenvolvido para a disciplina de Algoritmos e Estruturas de Dados II (AED2), aplicando os conceitos de tabelas e funções hash. Ele implementa uma tabela hash com tratamento de colisões por encadeamento e possui uma interface interativa via terminal, permitindo que o usuário insira, remova, visualize e procure dados na tabela.

## Estrutura do Código

### Classes

- **Node**: Representa cada nó da tabela hash. Contém uma chave do tipo `double`, um dado do tipo `string`, e um ponteiro para o próximo nó.
  
- **TabelaHashEncadeada**: Implementa a tabela hash com tratamento de colisões por encadeamento. Contém métodos para inserir, remover e procurar elementos, além de um método para exibir a tabela completa.

### Funções Principais

1. **funcaoHash**: Aplica a função hash para mapear uma chave para um índice na tabela.
   
2. **inserir**: Insere um par chave/valor na tabela. Caso a chave já exista, o valor não é inserido.

3. **removerChave**: Remove um nó da tabela baseado na chave fornecida.

4. **removerDado**: Remove todos os nós que possuem o dado fornecido.

5. **showtable**: Exibe todos os pares chave/valor presentes na tabela, indicando a posição na tabela hash.

6. **sizetable**: Retorna a cardinalidade da tabela, ou seja, a quantidade de elementos presentes.

7. **procurarChave**: Retorna o dado associado a uma chave.

8. **procurarDado**: Exibe todas as chaves associadas a um dado.

### Interface de Usuário

A interface é baseada em um menu interativo via terminal. O usuário pode escolher entre as diferentes funcionalidades e interagir com a tabela de maneira intuitiva.

## Exemplo de Execução

Ao rodar o programa, o usuário é recebido com um menu inicial:

![image](https://github.com/user-attachments/assets/2bc88d5f-040c-44bc-9a23-dd770eca391d)


Após a criação da tabela, o usuário pode acessar outras funcionalidades, como inserção, visualização e remoção de elementos:

![image](https://github.com/user-attachments/assets/91243b6a-1748-433d-8c4c-96dd5c0b4806)

## Compilação e Execução

### Compilação

Para compilar o programa, utilize um compilador compatível com C++ (por exemplo, `g++`):

```bash
g++ main.cpp -o tabelaHash
```

### Execução

Após a compilação, o programa pode ser executado diretamente no terminal:

```bash
./tabelaHash
```

## Observações

- O programa foi desenvolvido com foco em eficiência e possui um tratamento cuidadoso para garantir uma boa dispersão de chaves através da função hash personalizada.
- A implementação considera o uso de números decimais como chaves, o que oferece flexibilidade no mapeamento de dados.

Ao criar uma tabela hash com dimensão 15 e outra tabela com 20, e inserindo um preset com doze inserções(1) podemos observa como cada entrada é alocada de forma espaçada na Tabela.
  - tabela de tamanho 15:
    
      ![image](https://github.com/user-attachments/assets/19317dde-81ac-4274-affe-d4efdddb4de5)
    
  - tabela de tamanho 20:
    
      ![image](https://github.com/user-attachments/assets/bd22c99e-02c2-4a9b-a843-6fc28ded03cb)

