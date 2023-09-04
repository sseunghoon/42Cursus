#!/bin/sh

# 사용자 생성 및 모든 권한 설정
# root 사용자의 비밀번호 설정
# 
cat > /tmp/create_db_sql << EOF
USE mysql;
FLUSH PRIVILEGES;
CREATE DATABASE IF NOT EXISTS $MYSQL_DB_NAME;
CREATE USER IF NOT EXISTS '$MYSQL_USER'@'%' IDENTIFIED BY '$MYSQL_PASSWORD';
GRANT ALL PRIVILEGES ON $MYSQL_DB_NAME.* TO '$MYSQL_USER'@'%';
ALTER USER 'root'@'localhost' IDENTIFIED BY '$MYSQL_ROOT_PASSWORD';
FLUSH PRIVILEGES;
EOF

# init.sql 실행
/usr/bin/mysqld --user=mysql --bootstrap < /tmp/create_db_sql

# MySQL 서버 시작
/usr/bin/mysqld -u mysql