from _mysql_helpers import single_column, mapping_columns, database
from _mysql_hosting import single, mapping


@mapping_columns
@database('hosting')
def trash():
    return 'SELECT domain, domaintrash FROM domains WHERE domaintrash != ""'

def run(host):
    return {
        'mail': {
            'recipients': single('mailrecipients', 'recipient'),
            'nospamhosts': single('nospamhosts', 'host'),
            'nospamrecipients': single('nospamrecipients', 'recipient'),
            'spam': single('spam', 'text'),
            'aliases': mapping('mailaliases', 'source', 'destination'),
            'redirects': mapping('mailredirects', 'source', 'destination'),
            'trash': trash(),
        },
    }
