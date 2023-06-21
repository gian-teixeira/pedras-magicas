# Pedras mágicas 

Esse programa foi desenvolvido como um trabalho prático da disciplina de Algoritmos e Estruturas de Dados III da Universidade 
Federal de São João del-Rei (UFSJ). As especificaçoes detalhadas da atividade estão presentes no arquivo *Especificacoes.pdf*,
e a documentação técnica, no arquivo *docs/PedrasMagicas.pdf*.

## Compilação 

```bash
make
```

## Execução 

```bash
./tp2 <arquivoEntrada> <estratégia>
```

Podem ser escolhidas entre três estratégias de casamento exato de caracteres

1. bruteforce
2. boyer moore hospool
3. shiftAND

### Arquivo de entrada

Em um mesmo arquivo, por meio do formato abaixo, é possível definir vários casos de teste.

| nomeEntrada <img width=100/> | 
| ------------------------ |
| t </br>P<sub>1</sub>&nbsp;T<sub>1</sub> </br>P<sub>2</sub>&nbsp;T<sub>2</sub> </br> ... </br>P<sub>t</sub>&nbsp;T<sub>t</sub> |

- t: número de casos de teste
- P: poder (padrão)
- T: pedra (texto)

### Saída

É criado um arquivo *nomeEntrada.out*, que contém o caractere inicial da primeira ocorrência de um poder em uma determinada pedra.
Além disso, na saída padrão, são listados os próprios resultados, o tempo de usuário, o tempo de sistema e o tempo total de relógio
gastos para a execução do programa.
