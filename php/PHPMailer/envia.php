<?php 


     
require_once ("PHPMailerAutoload.php");
require_once ("class.phpmailer.php");
require_once ("class.smtp.php");




//habilitar smtp
   $mail = new PHPMailer;        
    
    $mail->Port = 587;
    $mail->SMTPSecure = 'tls';
    
$mail->isSMTP();
 $mail->Host = 'smtp.gmail.com';
   $mail->SMTPAuth = true;

$mail->Username = 'contato2bsantos@gmail.com';
    $mail->Password = 'vilmar97324674';

     //remetente
    $mail->From =('contato2bsantos@gmail.com');
    $mail->fromname =("vilmar");
//destinatario
    $mail->addAddress('vilmarmoreira2010@gmail.com',"vilmar");
     
    $mail->isHTML(true);
     
    $mail->Subject = ("teste");
    $mail->Body    = ("teste envio");
   $enviado = $mail->send();
     
    if($enviado) {
        echo ' mensagem enviada.<br>';
        
    } else {
        echo(" nao enviado");
         
        echo 'Erro: ' . $mail->ErrorInfo;
    }
        ?>
