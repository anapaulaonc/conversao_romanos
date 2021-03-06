## Conversâo para Numero Romano

Utilizar o desenvolvimento orientado a testes (TDD) para
resolver o problema de conversão de algarismos romanos para algarismos arábicos. O
número em algarismos romanos poderá ser no máximo 3000. A função deverá pegar uma
string de tamanho até 30 caracteres e retornar um inteiro correspondente ao número
romano. Deverá retornar -1 se o número romano for inválido. Todas as strings
correspondentes a números romanos válidos devem retornar o valor correto (ex. XXX deve
retornar 30). Todas as strings correspondentes a números romanos inválidos devem retornar
-1 (ex. XXXX, VV, VX, etc. devem retornar -1 ) 

Compilar:

```sh
make
```

Verificar testes de memoria (valgrind e cppcheck):

```sh
make verificar
```

Remove todos os arquivos executaveis:

```sh
make clean
```

##Testes

- **TEST (testa_valores, valores_basicos)**:
Verifica se a função *roman_to_arabic* converte as unidades básicas dos números romanos 
[I, V, X, L, C, D, M].
- **TEST (testa_valores, valores_validos)**:
Verifica se a função *validar* converte números corretamente.
- **TEST (converter_arabico, valores_invalido)**:
Verifica se a função *validar* reconhece números romanos inválidos.
    - **"CCXCIVI"**: "**IVI**" detectado.
    - **"XXXX"**: 4 algarismos iguais detectado.
    - **"MMMI"**: número romano acima de 3000 detectado.
    - **"DD"**:  **(VV, LL, DD)** detectado.
    - **"XM"**: sequência entre dois números sem relação.
    - **"xvv"**: caracteres com letras minúsculas.
    - **"IIIIIIIIIIIIIIIIIIIIIIIIIIIIIII"**: número de algarismos romanos maior que 30 detectado.
    - **"LUI"**: caracteres fora do padrão romano detectados.