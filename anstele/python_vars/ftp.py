from collections import namedtuple
from _mysql_helpers import database, named_columns


FTP = namedtuple('FTP', ['username', 'password', 'homedir', 'quota'])

@named_columns(FTP)
@database('hosting')
def accounts(host):
    return '''
        SELECT 
            userid, 
            ENCRYPT(passwd, CONCAT("$6$", SUBSTRING(SHA(RAND()), -16))), 
            homedir, 
            quota * 1024 * 1024 
        FROM domains
        WHERE server = "%s"
        ORDER BY userid
    ''' % host.name.split('.', 1)[0]

def run(host):
    return {
        'ftp': {
            'accounts': accounts(host),
        },
    }

