FROM alpine:3.17

# cache 없이 설치, 캐시를 사용한다면 업데이트할 때 이점

RUN apk update; \
	apk add --no-cache nginx openssl tini

COPY ./conf/nginx.conf /etc/nginx/http.d

RUN  mkdir -p /etc/nginx/ssl
# x509 : 인증서 생성 관리 표준
# Version	인증서의 버전 (3.0)
# SerialNumber	인증서의 고유숫자
# Signature	발급자 서명	필수 
# Issuer	발급자 정보 (DN 형식)
# Validator	인증서의 유효기간, 시작/종료 날짜
# Subject	주체의 정보 (DN 형식)
# SubjectPublicKeyInfo	주체의 공개키

RUN  openssl req -x509 \ 
     # 개인키 비암호화 no DES (DES : Data Encryption Standard), 평문 개인키를 얻을 수 있음
     -nodes \
     # 유효기간 365일
     -days 365 \
     # RSA 암호 사용, 2048비트 개인키 생성
     -newkey rsa:2048 \
     -keyout /etc/ssl/private/seunghso.42.fr.key \
     -out /etc/ssl/certs/seunghso.42.fr.crt \
     # 인증서에 포함될 정보 :  국가(C), 지역(ST,L), 조직(O), 부서(OU), 일반 이름(CN) -> DN 형식
     -subj "/C=KR/ST=Seoul/L=Gaepo/O=42Seoul/OU=Develop/CN=Seunghso's"

# 443 포트에서 호스트와 연결
EXPOSE 443
# 컨테이너의 시작점으로 Tini를 사용
ENTRYPOINT ["/sbin/tini", "--"]
# 컨테이너가 시작되면 Nginx를 데몬 모드로 실행
CMD ["nginx", "-g", "daemon off;"]