from _mysql_helpers import single_column, database


@single_column
@database('mydns')
def zones(host):
    return '''
        SELECT LEFT(origin, LENGTH(origin) - 1)
        FROM soa JOIN rr ON soa.id = rr.zone AND rr.type = "NS"
        WHERE data = "%s." ORDER BY origin
    ''' % host.name


def run(host):
    return {
        'zones': zones(host),
    }
