from _mysql_helpers import single_column, mapping_columns, database


@single_column
@database('hosting')
def single(table, column):
    return 'SELECT %s FROM %s' % (column, table)

@mapping_columns
@database('hosting')
def mapping(table, source, destination):
    return 'SELECT %s, %s FROM %s' % (source, destination, table)


