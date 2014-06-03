DELIMITER @@

DROP TRIGGER IF EXISTS ftphosting_create@@ 
CREATE TRIGGER ftphosting_create
AFTER INSERT ON ftphosting
FOR EACH ROW
BEGIN
  INSERT INTO events (type, command)
  SELECT 'local', CONCAT_WS(' ',
    'ansible-playbook',
    '-l',
    fqdn,
    '/usr/share/anstele/ftp-sync.yml')
  FROM servers
  WHERE name = NEW.server AND name = 'ftp4';
END;
@@

DROP TRIGGER IF EXISTS ftphosting_update@@ 
CREATE TRIGGER ftphosting_update
AFTER UPDATE ON ftphosting
FOR EACH ROW
BEGIN
  INSERT INTO events (type, command)
  SELECT 'local', CONCAT_WS(' ',
    'ansible-playbook',
    '-l',
    fqdn,
    '/usr/share/anstele/ftp-sync.yml')
  FROM servers
  WHERE name = NEW.server AND name = 'ftp4';
END;
@@

DROP TRIGGER IF EXISTS ftphosting_delete@@
CREATE TRIGGER ftphosting_delete
AFTER DELETE ON ftphosting
FOR EACH ROW
BEGIN
  INSERT INTO events (type, command)
  SELECT 'local', CONCAT_WS(' ',
    'ansible-playbook',
    '-l',
    fqdn,
    '/usr/share/anstele/ftp-sync.yml')
  FROM servers
  WHERE name = OLD.server AND name = 'ftp4';
END;
@@

DELIMITER ;

