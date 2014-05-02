from ansible.constants import p, get_config
from functools import wraps
import MySQLdb


def single_column(f):
    @wraps(f)
    def wrapper(*args, **kwargs):
        return [row[0] for row in f(*args, **kwargs)]
    return wrapper

def mapping_columns(f):
    @wraps(f)
    def wrapper(*args, **kwargs):
        return dict(f(*args, **kwargs))
    return wrapper

def raw_columns(f):
    @wraps(f)
    def wrapper(*args, **kwargs):
        return list(f(*args, **kwargs))
    return wrapper

def named_columns(header):
    def outer(f):
         @wraps(f)
         def wrapper(*args, **kwargs):
             return map(header._asdict, map(header._make, f(*args, **kwargs)))
         return wrapper
    return outer

def database(name):
    def query(f):
        @wraps(f)
        def wrapper(*args, **kwargs):
            cursor = cursors[name]
            cursor.execute(f(*args, **kwargs))
            return cursor
        return wrapper
    return query


class Cursors(object):
    def __init__(self, option_file):
        self.option_file = option_file
        self.cursors = {}

    def __getitem__(self, database):
        try:
            return self.cursors[database]
        except KeyError:
            self.cursors[database] = result = MySQLdb.connect(db=database, read_default_file=self.option_file, charset='utf8').cursor()
            return result
	

MYSQL_OPTION_FILE = get_config(p, 'python_vars', 'mysql_option_file', 'MYSQL_OPTION_FILE', '~/.my.cnf')
cursors = Cursors(MYSQL_OPTION_FILE)
