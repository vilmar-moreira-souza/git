como alterar a pasta padrão do Xampp para qualquer pasta que desejar, veja o passo a passo:

Acessando o Arquivo httpd.conf
Acesse o arquivo httpd.conf que esta dentro da pasta xampp/apache/conf da unidade em que o servidor local foi instalado.

Alterando Parâmetros
Dentro do arquivo httpd.conf temos que alterar duas linhas de código, são elas:
DocumentRoot "C:/xampp/htdocs" e <Directory "C:/xampp/htdocs">
Altere estes caminhos para o caminho da pasta que desejar.

Exemplo: 


DocumentRoot "D:/Projetos "
<Directory "D:\Projetos">

Pronto, seus projetos já estão há salvo ;


link ajuda :http://www.mauricioprogramador.com.br/posts/alterar-pasta-padrao-do-xampp
