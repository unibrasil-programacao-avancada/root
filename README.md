# Programação Avançada

## Ferramentas para Desenvolvimento - Windows
- [IDE Code::Blocks](https://www.fosshub.com/Code-Blocks.html?dwl=codeblocks-20.03mingw-setup.exe#)
- [Git](https://github.com/git-for-windows/git/releases/download/v2.48.1.windows.1/Git-2.48.1-64-bit.exe)

### Instalação e Configuração da Biblioteca MPI - Windows

- Faça o download dos dois instaladores _msmpisdk.msi_ e _msmpisetup.exe_ da biblioteca através do link [Microsoft MPI v10.0](https://www.microsoft.com/en-us/download/details.aspx?id=57467)
- Para configurar a biblioteca no Code::Blocks, siga o tutorial em vídeo disponível no [YouTube - Installing MPI Library on CodeBlocks](https://www.youtube.com/watch?v=eFKLxnbAhWk) 

#### Testando a Biblioteca

- Crie um projeto C no Code::Blocks. Siga o tutorial disponível no [vídeo](https://www.youtube.com/watch?v=OE3VbaqGQWM).
- Copie o código C disponível no [gist](https://gist.github.com/tnas/cd596149bdc28ec564017387bf90d05c).
- Cole o código no arquivo `main.c` gerado na criação do projeto C.
- Compile e execute o código.

#### Executando Múltiplos Processos

- Acesse o diretório `bin\Debug` do projeto pela linha de comando.
- Execute o comando `mpiexec -n 4 <NOME DO ARQUIVO .EXE>`. Serão executados 4 processos do programa.
    - Altere o valor do parâmetro `-n` para a quantidade de processos que queira executar.

### Configuração da Biblioteca OpenMP no Code::Blocks - Windows

- Abra a janela de configuração em `Settings > Compiler... > Linker settings`
- Acione o botão "Add"
- Localize a biblioteca no caminho `C:\Program Files\CodeBlocks\MinGW\lib\gcc\x86_64-w64-mingw32\8.1.0\libgomp.dll.a`

## Warm-Up

Para compilar o código:

`gcc -Wall warmup.c solver/warmup_solver.c -o warmup`

Para executar o código:

`./warmup`
