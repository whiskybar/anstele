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

function rcmail_show_notification(message)
{
    if (use_notifications)
    {
        var popup = window.webkitNotifications.createNotification('./plugins/html5_notifier/images/new_mail.png', rcmail.gettext('notification_title', 'html5_notifier').replace('[from]', message.from), message.subject);
        popup.onclick = function()
        {
            window.open('?_task=mail&_action=show&_uid='+message.uid);
            this.cancel();
        }
        popup.show();
        if (parseInt(message.duration) > 0)
        {
            setTimeout(function(){ popup.cancel(); }, (parseInt(message.duration)*1000));
        }
    }
}

function rcmail_browser_notifications()
{
    if (window.webkitNotifications) {
        if (window.webkitNotifications.checkPermission() == 0)
        {
            rcmail.display_message(rcmail.gettext('ok_notifications', 'html5_notifier'), 'notice');
        }
        else
        {
            window.webkitNotifications.requestPermission(rcmail_check_notifications);
        }
    }
    else
    {
        rcmail.display_message(rcmail.gettext('no_notifications', 'html5_notifier'), 'error');
    }
}

function rcmail_browser_notifications_test() {
    if (use_notifications)
    {
        rcmail.display_message(rcmail.gettext('check_ok', 'html5_notifier'), 'notice');
        var message = new Object();
        message.duration = 8;
        message.uid = 0;
        message.subject = 'It Works!';
        message.from = 'TESTMAN';
        rcmail_show_notification(message);
    }
    else
    {
        if (window.webkitNotifications)
        {
            if (window.webkitNotifications.checkPermission() == 2)
            {
                rcmail.display_message(rcmail.gettext('check_fail_blocked', 'html5_notifier'), 'error');
                return false;
            }
        }
        rcmail.display_message(rcmail.gettext('check_fail', 'html5_notifier'), 'error');
    }
}

function rcmail_browser_notifications_colorate() {
    if (window.webkitNotifications)
    {
        var broco = $('#rcmfd_html5_notifier_browser_conf');
        if (broco)
        {
            switch (window.webkitNotifications.checkPermission())
            {
                case 0: broco.css('color', 'green'); break;
                case 1: broco.css('color', 'orange'); break;
                case 2: broco.css('color', 'red'); break;
            }
        }
    }
}

var use_notifications = false;

var rcmail_check_notifications = function(e)
{
    if (window.webkitNotifications)
    {
        if (window.webkitNotifications.checkPermission() == 0) {
            use_notifications = true;
        }
    }
    rcmail_browser_notifications_colorate();
}

if (window.rcmail)
{
    rcmail.addEventListener('plugin.showNotification', rcmail_show_notification);
    rcmail.addEventListener('init', rcmail_check_notifications);
}