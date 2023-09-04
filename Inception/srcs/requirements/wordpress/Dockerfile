FROM alpine:3.17

RUN apk update;	\
	# PHP (서버 사이드 스크립트 언어)
	# PHP fpm (FastCGI Process Manager) - PHP를 FastCGI로 실행하기 위한 프로세스 관리자, 
	# CGI = Common Gateway Interface (동적인 페이지 구현 프로그램에 클라이언트 요청을 전달해주는 역할)
    # PHP MySQLi - MySQL 데이터베이스에 연결하기 위한 확장
    # PHP cURL (Client URL) - URL을 통해 데이터를 전송하기 위한 확장
    # PHP Phar 확장 - PHP 아카이브 파일(.phar)을 실행하기 위한 확장
    # PHP Iconv 확장 - 문자 인코딩 변환을 위한 확장
    # MariaDB 클라이언트 - MariaDB 데이터베이스에 접속하기 위한 클라이언트

    apk add \
			php81			\ 
			php81-fpm		\
    		php81-mysqli    \
    		php81-curl      \
			php81-phar      \
    		php81-iconv     \
		    mariadb-client

# curl - URL을 통해 데이터를 전송하기 위한 명령 줄 도구
RUN apk update && apk add curl
# Tini 패키지 설치
RUN apk update && apk add --no-cache curl tini

WORKDIR /tmp
# WP-CLI를 설치
RUN curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar
RUN mv wp-cli.phar /usr/local/bin
RUN chmod +x /usr/local/bin/wp-cli.phar

# wp 명령을 /usr/local/bin 디렉토리에 생성하여 사용할 수 있도록 설정
RUN ln -sf /usr/local/bin/wp-cli.phar /usr/local/bin/wp

#기본 설정 폴더 변경, p옵션 - 경로에 존재하지 않는 디렉토리 자동 생성
RUN mkdir -p /var/www/html
WORKDIR /var/www/html

#PHP-FPM 작업폴더 /var/www/html 디렉토리를 작업 디렉토리로 설정
RUN sed -i 's/;chdir = \/var\/www/chdir = \/var\/www\/html/g' /etc/php81/php-fpm.d/www.conf

# listen = 127.0.0.1:9000와 같이 설정된 경우, PHP-FPM은 로컬 호스트(127.0.0.1)의 9000 포트에서만 연결을 수신
#PHP-FPM은 모든 네트워크 인터페이스(로컬 루프백 및 외부 네트워크 인터페이스)에서 9000 포트로 들어오는 연결을 수신
# 웹 서버나 다른 시스템에서 PHP-FPM과 연결 가능해짐
RUN sed -i 's/listen = 127.0.0.1:9000/listen = 0.0.0.0:9000/g' /etc/php81/php-fpm.d/www.conf

COPY ./conf/wp.sh /tmp/wp.sh
# /tmp/wp.sh파일에 실행 권한을 부여
RUN chmod +x /tmp/wp.sh

# 9000 포트에서 호스트와 연결  
EXPOSE 9000
# 컨테이너의 시작점으로 Tini를 사용
ENTRYPOINT ["/sbin/tini", "--"]
# 컨테이너가 시작되면 /tmp/wp.sh 스크립트를 실행
CMD ["sh", "/tmp/wp.sh"]