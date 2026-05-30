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