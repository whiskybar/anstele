DROP TABLE IF EXISTS domains;
CREATE TABLE domains (
  userid varchar(100) NOT NULL DEFAULT '',
  passwd varchar(20) DEFAULT NULL,
  quota int(11) NOT NULL DEFAULT '0',
  homedir varchar(100) NOT NULL DEFAULT '',
  PRIMARY KEY (userid)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

