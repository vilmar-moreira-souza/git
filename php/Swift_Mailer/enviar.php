<?php
require_once 'vendor/autoload.php';

// Create the Transport
$transport = (new Swift_SmtpTransport('smtp.example.org', 25))
  ->setUsername('your username')
  ->setPassword('your password')
;

// Create the Mailer using your created Transport
$mailer = new Swift_Mailer($transport);

// Create a message
$message = (new Swift_Message('Wonderful Subject'))//assunto
  ->setFrom(['john@doe.com' => 'John Doe']) //remetente
  ->setTo(['receiver@domain.org', 'other@domain.org' => 'A name']) // destinatario
  ->setBody('Here is the message itself') //mensagem
  ;

// Send the message
$result = $mailer->send($message);
?>