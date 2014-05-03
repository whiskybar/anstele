<?php

/**
  * Plugin to log sender. Set http_received_header_encrypt in 
  * config/main.inc.php to encrypt
  *
  * @version 1.0
  * @author Cor Bosman
  */

class log_sender extends rcube_plugin 
{
  function init()
  {
    $this->add_hook('outgoing_message_headers', array($this, 'log'));
  }

  function log($args)
  {
    $rcmail = rcmail::get_instance();
    $user = $rcmail->user->data['username'];

    if($rcmail->config->get('http_received_header_encrypt') == 'true') {
      $user = $rcmail->encrypt($user);
    }
    $args['headers']['X-Sender']  = "$user";
    
    return($args);
  }
}
?>
