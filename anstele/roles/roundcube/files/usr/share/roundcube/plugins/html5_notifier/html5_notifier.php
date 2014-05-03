<?php
/**
 * html5_notifier
 * Shows a desktop notification every time a new (recent) mail comes in
 * Works only with Google Chrome/SRWare Iron
 *
 * @version 0.2 - 31.08.2011
 * @author Tilman Stremlau <tilman@stremlau.net>
 * @website stremlau.net/html5_notifier
 * @licence GNU GPL
 *
 **/

class html5_notifier extends rcube_plugin
{
    public $task = '?(?!login|logout).*';

    function init()
    {
        $RCMAIL = rcmail::get_instance();
        
        if(file_exists("./plugins/html5_notifier/config/config.inc.php"))
        {
            $this->load_config('config/config.inc.php');
        }

        $this->add_hook('preferences_list', array($this, 'prefs_list'));
        $this->add_hook('preferences_save', array($this, 'prefs_save'));

        if ($RCMAIL->config->get('html5_notifier_duration').'' != '0')
        {
            $this->add_hook('new_messages', array($this, 'show_notification'));
            $this->include_script("html5_notifier.js");
            if ($RCMAIL->action != 'check-recent')
            {
                $this->add_texts('localization', array('notification_title', 'ok_notifications', 'no_notifications', 'check_ok', 'check_fail', 'check_fail_blocked')); //PRÄZESIEREN
            }
        }
    }

    function show_notification($args)
    {
        $RCMAIL = rcmail::get_instance();

        (array) $uids = $RCMAIL->imap->search_once($args['mailbox'], 'RECENT', true);
        foreach($uids as $uid) {
            $message = new rcube_message($uid);
		
		    $from = $message->sender['name'] ? $message->sender['name'] : $message->sender['mailto'];
		    $subject = $message->subject;
		
            if(strtolower($_SESSION['username']) == strtolower($RCMAIL->user->data['username']))
            {
                $RCMAIL->output->command("plugin.showNotification", array(
                    'duration' => $RCMAIL->config->get('html5_notifier_duration'),
                    'subject' => $subject,
                    'from' => $from,
                    'uid' => $uid
                ));
            }
        }
    }
    
    function prefs_list($args)
    {
        if($args['section'] == 'mailbox')
        {
            $RCMAIL = rcmail::get_instance();
              
            $field_id = 'rcmfd_html5_notifier'; 
            $select = new html_select(array('name' => '_html5_notifier_duration', 'id' => $field_id));
            $select->add($this->gettext('off'), '0');
            $times = array('3', '5', '8', '10', '12', '15', '20', '25', '30');
            foreach ($times as $time)
                $select->add($time.' '.$this->gettext('seconds'), $time);
            $select->add($this->gettext('durable'), -1);
            $content = $select->show($RCMAIL->config->get('html5_notifier_duration').'');
            $content .= html::a(array('href' => '#', 'id' => 'rcmfd_html5_notifier_browser_conf', 'onclick' => 'rcmail_browser_notifications(); return false;'), $this->gettext('conf_browser')).' ';
            $content .= html::a(array('href' => '#', 'onclick' => 'rcmail_browser_notifications_test(); return false;'), $this->gettext('test_browser'));
            $args['blocks']['new_message']['options']['html5_notifier'] = array( 
                'title' => html::label($field_id, Q($this->gettext('shownotifies'))), 
                'content' => $content,
            );
            
            $RCMAIL->output->add_script("$(document).ready(function(){ rcmail_browser_notifications_colorate(); });");            
        }
        return $args;
    }

    function prefs_save($args)
    {
        if($args['section'] == 'mailbox')
        {
            $args['prefs']['html5_notifier_duration'] = get_input_value('_html5_notifier_duration', RCUBE_INPUT_POST);
            return $args;
        }
    }
}
?>