FROM alpine:3.17

# MariaDB의 소켓파일 저장위치
RUN mkdir -p /run/mysqld
# data 저장위치
RUN mkdir -p /var/lib/mysql
# MariaDB, mariadb-client, tini 설치
RUN apk update && apk upgrade && apk add --no-cache mariadb mariadb-client tini

COPY ./conf/create_db.sh /tmp/create_db.sh
# /run/mysqld 디렉토리의 소유자와 그룹을 mysql로 변경
RUN chown -R mysql:mysql /run/mysqld

RUN chmod 777 /var/run/mysqld; \
	echo 'bind-address=0.0.0.0' > /etc/my.cnf.d/docker.cnf

# skip-networking을 0으로 변경 ( 네트워크 연결 허용 )
RUN  sed -i "s|skip-networking|skip-networking=0|g" /etc/my.cnf.d/mariadb-server.cnf

RUN mysql_install_db \
				# mysql 사용자를 지정
				--user=mysql \
                # /usr 디렉토리를 기준으로 설정
				--basedir=/usr \
                # 데이터 디렉터리 설정
				--datadir=/var/lib/mysql

# 3306 포트에서 호스트와 연결    
EXPOSE 3306
# /tmp/create_db.sh 파일에 실행 권한을 부여
RUN chmod +x /tmp/create_db.sh
# 컨테이너의 시작점으로 Tini를 사용
ENTRYPOINT ["/sbin/tini", "--"]
# 컨테이너가 시작되면 /tmp/create_db.sh 스크립트를 실행
CMD ["sh", "/tmp/create_db.sh"]