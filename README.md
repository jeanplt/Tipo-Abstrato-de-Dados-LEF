# Tipo-Abstrato-de-Dados-LEF
Este repositório contém um programa modular em C que implementa e testa uma TAD Lista de Eventos Futuros (LEF), utilizando uma das formas de se implementar uma fila de prioridades. A implementação utiliza uma lista ligada com nodo cabeça que implementa a seguinte política: os elementos são inseridos em ordem crescente pelo campo tempo. A remoção é sempre no início.

O programa modular que cria e testa a TAD LEF é composto pelos seguintes arquivos:

- lef.h: protótipos das funções, que criam, modificam e destroem a LEF. Este arquivo foi desenvolvido pelo professor Luis Carlos Erpen de Bona, do departamento de informática da Universidade Federal do Paraná.
- lef.c: implementação de todas as funções existentes em lef.h, feito por Jean Pablo Lopes Teixeira.
- testa_lef.c: desenvolvido pelo professor Carlos Maziero, testa as implementações de lef.c verificando se a LEF é criada corretamente, se os dados são obtidos sem problemas de ponteiros, se a LEF manipula corretamente seus dados no topo (prioridades) e se a LEF entende que está vazia ou não.

Por fim, este programa tem o propósito apenas de testar a criação da LEF, mas pode ser adaptado para utilizar a LEF em outros contextos que envolvam utilização de lista de prioridades.
