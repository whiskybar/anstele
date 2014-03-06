from _mysql_hosting import single, mapping


def run(host):
    return {
        'mail': {
            'relayfromhosts': single('servers', 'fqdn'),
            'accounts': mapping('mailaccounts', 'login', 'ENCRYPT(pass, CONCAT("$6$", SUBSTRING(SHA(RAND()), -16)))'),
        },
    }
