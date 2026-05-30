# Sistema de Monitoramento de Missão Espacial

## Descrição

Este projeto foi desenvolvido em linguagem C para simular o monitoramento de uma missão espacial.

O sistema permite registrar informações da nave, verificar seu funcionamento e mostrar alertas quando algum problema é encontrado.

Durante o desenvolvimento foram utilizados conceitos básicos de programação, como funções, estruturas de decisão, laços de repetição, vetores e structs.

---

## Objetivo

Criar um programa capaz de:

- Registrar dados da missão;
- Monitorar a temperatura da nave;
- Monitorar o nível de energia;
- Verificar a comunicação;
- Emitir alertas quando necessário;
- Armazenar um histórico das leituras;
- Exibir informações sobre a missão.

---

## Funcionalidades

### Inserção de dados

O usuário pode informar:

- Temperatura da nave;
- Nível de energia;
- Status da comunicação.

### Verificação automática

O sistema analisa os dados informados e apresenta avisos quando:

| Condição | Resultado |

| Temperatura maior que 80°C  | Alerta de superaquecimento
| Temperatura maior ou igual a 60°C  | Aviso de temperatura alta
| Energia menor que 20%  | Alerta de energia baixa
| Energia menor que 40%  | Aviso de energia reduzida
| Comunicação igual a 0  | Falha de comunicação

### Status atual

Mostra a última leitura registrada e a situação atual da missão.

### Análise completa

Mostra:

- Total de leituras registradas;
- Maior temperatura;
- Menor temperatura;
- Média das temperaturas;
- Média da energia;
- Quantidade de alertas de temperatura;
- Quantidade de alertas de energia;
- Quantidade de falhas de comunicação;
- Histórico completo das leituras.

---

## Tecnologias utilizadas

- Linguagem C
- GCC
- Terminal

---

## Conceitos utilizados

- Variáveis
- If e Else
- Switch
- For
- Do While
- Vetores
- Structs
- Funções

## Explicação da lógica utilizada

### Struct

Foi utilizada uma struct para guardar os dados de cada leitura da missão. Dentro dela ficam armazenadas a temperatura, a energia e o status da comunicação. Isso ajuda a organizar melhor as informações.

### Vetor

Foi utilizado um vetor para armazenar todas as leituras realizadas. Assim, o sistema consegue guardar um histórico de até 50 registros e utilizar esses dados nas análises.

### Funções

O programa foi dividido em várias funções para deixar o código mais organizado. Cada função possui uma tarefa específica, como inserir dados, mostrar o menu, exibir o status da missão ou realizar análises.

### If e Else

As estruturas `if` e `else` foram utilizadas para verificar as condições da missão. Elas são responsáveis por identificar situações como temperatura alta, energia baixa ou falha na comunicação e mostrar os alertas necessários.

### Switch

O `switch` foi utilizado no menu principal. Ele verifica a opção escolhida pelo usuário e executa a função correspondente.

### Do While

O `do while` foi utilizado para manter o menu em execução até que o usuário escolha a opção de sair do sistema.

### For

O `for` foi utilizado para percorrer todas as leituras armazenadas no histórico. Com ele, o programa consegue calcular médias, encontrar temperaturas máximas e mínimas e contar a quantidade de alertas registrados.

### Validação de dados

Foi feita uma validação no valor da energia para garantir que ela fique entre 0 e 100. Isso evita que valores inválidos sejam armazenados.

### Cálculo das médias

Na análise completa, o programa soma todos os valores de temperatura e energia e depois divide pela quantidade de leituras para encontrar as médias.

### Histórico de leituras

Todas as leituras inseridas pelo usuário são armazenadas durante a execução do programa. Isso permite consultar informações anteriores e gerar relatórios mais completos sobre a missão.