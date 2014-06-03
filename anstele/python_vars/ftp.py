from collections import namedtuple
from _mysql_helpers import database, named_columns


FTP = namedtuple('FTP', ['username', 'password', 'homedir', 'quota'])

@named_columns(FTP)
@database('hosting')
def accounts(host):
    return '''
        SELECT 
            login,
            ENCRYPT(pass, CONCAT("$6$", SUBSTRING(SHA(RAND()), -16))), 
            homedir, 
            quota * 1024 * 1024 
        FROM ftphosting
        WHERE server = "%s"
        ORDER BY login
    ''' % host.name.split('.', 1)[0]

def run(host):
    return {
        'ftp': {
            'accounts': accounts(host),
        },
    }

