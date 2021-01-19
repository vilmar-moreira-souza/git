exemplo 

https://www.vivaolinux.com.br/dica/Criando-diretorio-no-git-via-browser

CRIANDO DIRETÓRIO NO GIT VIA BROWSER



 

Seguinte, todos nós estamos acostumados a criar arquivos, diretórios e sub-diretórios via terminal e usar os comandos git para fazer o commit e o push das mudanças criadas. No entanto, quando você não quer criar diretórios em algum repositório e não deseja fazer o clone do repo para isso, uma alternativa é fazer a tarefa desejada direto no repositório utilizando o navegador. 

A questão é que essa tarefa não fica explícita no repositório. Então, segue a dica: 

1. Você vai logar em sua conta no github; 

2. Clique no repositório desejado; 

3. Clique em Create new file; 

4. Na caixa de texto "Name your file..." você deve digitar o nome do diretório a ser criado, seguido de "/", por exemplo, <mydir/>. Após digitar a /, o diretório já aparece na hierarquia de diretórios; 

5. Finalmente, digite o nome do arquivo desejado, escreva o seu conteúdo e, por fim, no final da página clique em Commit new file. 


6 -REMOVER um branch local do git

Para remover um branch local, você pode usar um dos seguintes comandos git.
git branch -d feature/001

Ou
git branch -D feature/001

    Note que feature/001 é o nome do branch 

A opção -d (–delete) removerá o branch local se você já a tiver enviado e mesclado às ramificações remotas.

A opção -D (–delete –force) removerá o branch local, independentemente de você ter enviado e mesclado com as ramificações remotas.
Remover um branch remoto do git

Você pode remover um branch remoto usando o seguinte comando git:

git push origin --delete feature/001

O retorno será:

To https://github.com/receitas-de-codigo/demo-jms.git
 - [deleted]         feature/001

    Note que precisa especificar o nome do branch remoto origin e o nome do branch local feature/001.

Como alternativa, você também pode usar o seguinte comando Git para fazer o mesmo:

git push origin :feature/001
