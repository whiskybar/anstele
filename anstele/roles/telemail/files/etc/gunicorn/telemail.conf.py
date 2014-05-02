bind = 'unix:/var/run/telemail.sock'
workers = 2
worker_class = 'gevent'
user = 'hosting'
group = 'hosting'
umask = 0
pythonpath = '/etc/telemail'
raw_env = 'DJANGO_SETTINGS_MODULE=settings'
