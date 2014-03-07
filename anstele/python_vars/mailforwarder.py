from _mysql_hosting import mapping


def run(host):
    return {
        'mail': {
            'forwarder': mapping('mailforwarder', 'source', 'destination'),
        },
    }
